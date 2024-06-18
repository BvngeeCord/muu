#include <nlohmann/json.hpp>
#include <Magick++.h>

#include <cam/hct.h>
#include <dynamiccolor/dynamic_scheme.h>
#include <dynamiccolor/material_dynamic_colors.h>
#include <quantize/celebi.h>
#include <quantize/wsmeans.h>
#include <scheme/scheme_tonal_spot.h>
#include <score/score.h>
#include <utils/utils.h>

#include <ctime>
#include <cstdint>
#include <format>
#include <iomanip>
#include <iostream>
#include <string>

using json = nlohmann::json;
namespace mcu = material_color_utilities;

void one(auto img){
  std::vector<mcu::Argb> argbs{};

  clock_t begin_time = clock();

  for (size_t i = 0; i < img.rows(); i++) {
    for (size_t j = 0; j < img.columns(); j++) {
      Magick::ColorRGB rgb(img.pixelColor(i, j));
      const uint8_t r = rgb.red() * 0xFF;
      const uint8_t g = rgb.green() * 0xFF;
      const uint8_t b = rgb.blue() * 0xFF;
      argbs.push_back(
        mcu::Argb((0xFF << 24) | (r << 16) | (g << 8) | (b << 0))
      );
    }
  }

  mcu::QuantizerResult res = mcu::QuantizeCelebi(argbs, 4);
  std::vector<mcu::Argb> colors = mcu::RankedSuggestions(res.color_to_count);
  for (auto c : colors) {
    std::cout << std::setfill('0') << std::setw(8) << std::hex << c << std::endl;
  }

  std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
}

void two(auto img) {
  std::vector<mcu::Argb> argbs2{};

  clock_t begin_time = clock();

  const Magick::Quantum *pixels = img.getConstPixels(0, 0, img.columns(), img.rows());
  for (size_t i = 0; i < img.rows(); i++) {
    for (size_t j = 0; j < img.columns(); j++) {
      const Magick::Quantum *pixel(pixels++);
      uint8_t r = *(pixel + 0 * sizeof(Magick::Quantum)) * 0xFF;
      uint8_t g = *(pixel + 1 * sizeof(Magick::Quantum)) * 0xFF;
      uint8_t b = *(pixel + 2 * sizeof(Magick::Quantum)) * 0xFF;
      argbs2.push_back(
        mcu::Argb((0xFF << 24) | (r << 16) | (g << 8) | (b << 0))
      );
    }
  }

  mcu::QuantizerResult res2 = mcu::QuantizeCelebi(argbs2, 4);
  std::vector<mcu::Argb> colors2 = mcu::RankedSuggestions(res2.color_to_count);
  for (auto c : colors2) {
    std::cout << std::setfill('0') << std::setw(8) << std::hex << c << std::endl;
  }

  std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << std::endl;
}

int main(int argc, char *argv[]) {
  Magick::InitializeMagick(argv[0]);
  /* const std::string argv0(argv[0]); */
  const Magick::Image img(argv[1]);

  one(img);
  two(img);
  two(img);
  one(img);
}

/* //QuantizerResult r = QuantizeWsmeans(std::vector<Argb>{},
 * std::vector<Argb>{}, 10); */
/**/
/* json palette = json::object(); */
/**/
/* const DynamicScheme s = SchemeTonalSpot(Hct(Argb(0xFFFFFF)), true, 0.0); */
/**/
/* palette["PrimaryPaletteKeyColor"] =
 * HexFromArgb(MaterialDynamicColors::PrimaryPaletteKeyColor().GetArgb(s)); */
/* palette["SecondaryPaletteKeyColor"] =
 * HexFromArgb(MaterialDynamicColors::SecondaryPaletteKeyColor().GetArgb(s)); */
/* palette["TertiaryPaletteKeyColor"] =
 * HexFromArgb(MaterialDynamicColors::TertiaryPaletteKeyColor().GetArgb(s)); */
/* palette["NeutralPaletteKeyColor"] =
 * HexFromArgb(MaterialDynamicColors::NeutralPaletteKeyColor().GetArgb(s)); */
/* palette["NeutralVariantPaletteKeyColor"] =
 * HexFromArgb(MaterialDynamicColors::NeutralVariantPaletteKeyColor().GetArgb(s));
 */
/* palette["Background"] =
 * HexFromArgb(MaterialDynamicColors::Background().GetArgb(s)); */
/* palette["OnBackground"] =
 * HexFromArgb(MaterialDynamicColors::OnBackground().GetArgb(s)); */
/* palette["Surface"] =
 * HexFromArgb(MaterialDynamicColors::Surface().GetArgb(s)); */
/* palette["SurfaceDim"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceDim().GetArgb(s)); */
/* palette["SurfaceBright"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceBright().GetArgb(s)); */
/* palette["SurfaceContainerLowest"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceContainerLowest().GetArgb(s)); */
/* palette["SurfaceContainerLow"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceContainerLow().GetArgb(s)); */
/* palette["SurfaceContainer"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceContainer().GetArgb(s)); */
/* palette["SurfaceContainerHigh"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceContainerHigh().GetArgb(s)); */
/* palette["SurfaceContainerHighest"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceContainerHighest().GetArgb(s)); */
/* palette["OnSurface"] =
 * HexFromArgb(MaterialDynamicColors::OnSurface().GetArgb(s)); */
/* palette["SurfaceVariant"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceVariant().GetArgb(s)); */
/* palette["OnSurfaceVariant"] =
 * HexFromArgb(MaterialDynamicColors::OnSurfaceVariant().GetArgb(s)); */
/* palette["InverseSurface"] =
 * HexFromArgb(MaterialDynamicColors::InverseSurface().GetArgb(s)); */
/* palette["InverseOnSurface"] =
 * HexFromArgb(MaterialDynamicColors::InverseOnSurface().GetArgb(s)); */
/* palette["Outline"] =
 * HexFromArgb(MaterialDynamicColors::Outline().GetArgb(s)); */
/* palette["OutlineVariant"] =
 * HexFromArgb(MaterialDynamicColors::OutlineVariant().GetArgb(s)); */
/* palette["Shadow"] = HexFromArgb(MaterialDynamicColors::Shadow().GetArgb(s));
 */
/* palette["Scrim"] = HexFromArgb(MaterialDynamicColors::Scrim().GetArgb(s)); */
/* palette["SurfaceTint"] =
 * HexFromArgb(MaterialDynamicColors::SurfaceTint().GetArgb(s)); */
/* palette["Primary"] =
 * HexFromArgb(MaterialDynamicColors::Primary().GetArgb(s)); */
/* palette["OnPrimary"] =
 * HexFromArgb(MaterialDynamicColors::OnPrimary().GetArgb(s)); */
/* palette["PrimaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::PrimaryContainer().GetArgb(s)); */
/* palette["OnPrimaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::OnPrimaryContainer().GetArgb(s)); */
/* palette["InversePrimary"] =
 * HexFromArgb(MaterialDynamicColors::InversePrimary().GetArgb(s)); */
/* palette["Secondary"] =
 * HexFromArgb(MaterialDynamicColors::Secondary().GetArgb(s)); */
/* palette["OnSecondary"] =
 * HexFromArgb(MaterialDynamicColors::OnSecondary().GetArgb(s)); */
/* palette["SecondaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::SecondaryContainer().GetArgb(s)); */
/* palette["OnSecondaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::OnSecondaryContainer().GetArgb(s)); */
/* palette["Tertiary"] =
 * HexFromArgb(MaterialDynamicColors::Tertiary().GetArgb(s)); */
/* palette["OnTertiary"] =
 * HexFromArgb(MaterialDynamicColors::OnTertiary().GetArgb(s)); */
/* palette["TertiaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::TertiaryContainer().GetArgb(s)); */
/* palette["OnTertiaryContainer"] =
 * HexFromArgb(MaterialDynamicColors::OnTertiaryContainer().GetArgb(s)); */
/* palette["Error"] = HexFromArgb(MaterialDynamicColors::Error().GetArgb(s)); */
/* palette["OnError"] =
 * HexFromArgb(MaterialDynamicColors::OnError().GetArgb(s)); */
/* palette["ErrorContainer"] =
 * HexFromArgb(MaterialDynamicColors::ErrorContainer().GetArgb(s)); */
/* palette["OnErrorContainer"] =
 * HexFromArgb(MaterialDynamicColors::OnErrorContainer().GetArgb(s)); */
/* palette["PrimaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::PrimaryFixed().GetArgb(s)); */
/* palette["PrimaryFixedDim"] =
 * HexFromArgb(MaterialDynamicColors::PrimaryFixedDim().GetArgb(s)); */
/* palette["OnPrimaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::OnPrimaryFixed().GetArgb(s)); */
/* palette["OnPrimaryFixedVariant"] =
 * HexFromArgb(MaterialDynamicColors::OnPrimaryFixedVariant().GetArgb(s)); */
/* palette["SecondaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::SecondaryFixed().GetArgb(s)); */
/* palette["SecondaryFixedDim"] =
 * HexFromArgb(MaterialDynamicColors::SecondaryFixedDim().GetArgb(s)); */
/* palette["OnSecondaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::OnSecondaryFixed().GetArgb(s)); */
/* palette["OnSecondaryFixedVariant"] =
 * HexFromArgb(MaterialDynamicColors::OnSecondaryFixedVariant().GetArgb(s)); */
/* palette["TertiaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::TertiaryFixed().GetArgb(s)); */
/* palette["TertiaryFixedDim"] =
 * HexFromArgb(MaterialDynamicColors::TertiaryFixedDim().GetArgb(s)); */
/* palette["OnTertiaryFixed"] =
 * HexFromArgb(MaterialDynamicColors::OnTertiaryFixed().GetArgb(s)); */
/* palette["OnTertiaryFixedVariant"] =
 * HexFromArgb(MaterialDynamicColors::OnTertiaryFixedVariant().GetArgb(s)); */
/**/
/* std::cout << std::setw(2) << palette << std::endl; */
