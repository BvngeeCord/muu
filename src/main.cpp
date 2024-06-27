#include "Magick++/Functions.h"
#include "Magick++/Geometry.h"
#include "Magick++/Image.h"
#include "nlohmann/json.hpp"

#include "cam/hct.h"
#include "dynamiccolor/dynamic_scheme.h"
#include "dynamiccolor/material_dynamic_colors.h"
#include "quantize/celebi.h"
#include "quantize/wsmeans.h"
#include "scheme/scheme_tonal_spot.h"
#include "score/score.h"
#include "utils/utils.h"

#include <bits/types/clock_t.h>
#include <cstdint>
#include <ctime>
#include <format>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using json = nlohmann::json;
namespace mcu = material_color_utilities;

int main(int argc, char *argv[]) {
  Magick::InitializeMagick(argv[0]); // should only be needed on Windows/MacOS, kept anyways

  Magick::Image img(argv[1]);

  clock_t time = clock();
  /* img.filterType(Magick::FilterType::LanczosFilter); */
  img.filterType(Magick::FilterType::GaussianFilter);
  img.resize(Magick::Geometry(128, 128));
  std::cout << "downsize: " << float(clock() - time) / CLOCKS_PER_SEC << "\n";

  std::vector<mcu::Argb> argbs{};

  time = clock();
  for (size_t i = 0; i < img.rows(); i++) {
    for (size_t j = 0; j < img.columns(); j++) {
      Magick::ColorRGB rgb(img.pixelColor(j, i));
      uint8_t a = rgb.alpha() * 0xFF;
      uint8_t r = rgb.red() * 0xFF;
      uint8_t g = rgb.green() * 0xFF;
      uint8_t b = rgb.blue() * 0xFF;
      argbs.push_back(mcu::Argb((a << 24) | (r << 16) | (g << 8) | (b << 0)));
    }
  }
  std::cout << "extract pixels: " << float(clock() - time) / CLOCKS_PER_SEC << "\n";

  time = clock();
  mcu::QuantizerResult res = mcu::QuantizeCelebi(argbs, 4);
  std::cout << "QuantizeCelebi: " << float(clock() - time) / CLOCKS_PER_SEC << "\n";

  time = clock();
  std::vector<mcu::Argb> colors = mcu::RankedSuggestions(res.color_to_count, {.desired = 4, .fallback_color_argb = 0x0});
  std::cout << "RankedSuggestions: " << float(clock() - time) / CLOCKS_PER_SEC << "\n";

  /* std::ios fmt(nullptr); */
  /* fmt.copyfmt(std::cout); */
  /**/
  /* std::cout << std::setfill('0') << std::setw(8) << std::hex; */
  /* for (const auto c : colors) { */
  /*   std::cout << c << std::endl; */
  /* } */
  /**/
  /* std::cout.copyfmt(fmt); */

  json obj = json::object();

  for (auto source_color : colors) {
    using namespace mcu;
    const DynamicScheme s = SchemeTonalSpot(Hct(Argb(source_color)), true, 0.0);

    std::string hex_source_color = "#" + HexFromArgb(source_color).substr(2);
    obj[hex_source_color] = {};

    #define add_color(NAME) \
      obj[hex_source_color][#NAME] = "#" + HexFromArgb(MaterialDynamicColors::NAME().GetArgb(s)).substr(2)

    add_color(PrimaryPaletteKeyColor);
    add_color(SecondaryPaletteKeyColor);
    add_color(TertiaryPaletteKeyColor);
    add_color(NeutralPaletteKeyColor);
    add_color(NeutralVariantPaletteKeyColor);
    add_color(Background);
    add_color(OnBackground);
    add_color(Surface);
    add_color(SurfaceDim);
    add_color(SurfaceBright);
    add_color(SurfaceContainerLowest);
    add_color(SurfaceContainerLow);
    add_color(SurfaceContainer);
    add_color(SurfaceContainerHigh);
    add_color(SurfaceContainerHighest);
    add_color(OnSurface);
    add_color(SurfaceVariant);
    add_color(OnSurfaceVariant);
    add_color(InverseSurface);
    add_color(InverseOnSurface);
    add_color(Outline);
    add_color(OutlineVariant);
    add_color(Shadow);
    add_color(Scrim);
    add_color(SurfaceTint);
    add_color(Primary);
    add_color(OnPrimary);
    add_color(PrimaryContainer);
    add_color(OnPrimaryContainer);
    add_color(InversePrimary);
    add_color(Secondary);
    add_color(OnSecondary);
    add_color(SecondaryContainer);
    add_color(OnSecondaryContainer);
    add_color(Tertiary);
    add_color(OnTertiary);
    add_color(TertiaryContainer);
    add_color(OnTertiaryContainer);
    add_color(Error);
    add_color(OnError);
    add_color(ErrorContainer);
    add_color(OnErrorContainer);
    add_color(PrimaryFixed);
    add_color(PrimaryFixedDim);
    add_color(OnPrimaryFixed);
    add_color(OnPrimaryFixedVariant);
    add_color(SecondaryFixed);
    add_color(SecondaryFixedDim);
    add_color(OnSecondaryFixed);
    add_color(OnSecondaryFixedVariant);
    add_color(TertiaryFixed);
    add_color(TertiaryFixedDim);
    add_color(OnTertiaryFixed);
    add_color(OnTertiaryFixedVariant);
  }
  /* std::cout << std::setw(2) << obj << std::endl; */
}
