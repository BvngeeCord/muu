#include <Magick++.h>
#include <string>

int main(int argc, char *argv[]) {
    Magick::InitializeMagick(*argv);
    std::string file_name(argv[1]);
    Magick::Image image("test.jpg");
    return 0;
}

#if false

#include <cpp/cam/hct.h>
#include <cpp/dynamiccolor/dynamic_scheme.h>
#include <cpp/dynamiccolor/material_dynamic_colors.h>
#include <cpp/scheme/scheme_tonal_spot.h>
#include <cpp/utils/utils.h>
#include <cstdint>
#include <format>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <cpp/quantize/wsmeans.h>

#include <Magick++.h>

using json = nlohmann::json;
namespace mcu = material_color_utilities;

int main(int argc, char *argv[]) {
  Magick::InitializeMagick(*argv);
  const std::string argv0(argv[0]);
  const auto img = Magick::Image(argv0);

  std::vector<mcu::Argb> argbs = {};
  std::cout << "Guessed size: " << sizeof(mcu::Argb) * img.rows() * img.columns() << "\n";

  const Magick::Quantum *pixels = img.getConstPixels(0, 0, img.columns(), img.rows());
  for (size_t i = 0; i < img.rows(); i++) {
    for (size_t j = 0; j < img.columns(); j++) {
      // does this even work? Not sure yet. cursed
      uint8_t r = *reinterpret_cast<uint8_t*>((float*)pixels++);
      uint8_t g = *reinterpret_cast<uint8_t*>((float*)pixels++);
      uint8_t b = *reinterpret_cast<uint8_t*>((float*)pixels++);
      pixels++; // ignore alpha
      argbs.push_back(mcu::Argb(
        (r << 8) | (g << 4) | (b << 0)
      ));
    }
  }
  for (mcu::Argb argb : argbs) {
      std::cout << mcu::HexFromArgb(argb) << "\n";
  }

  std::cout << "Real final size: " << argbs.size() << "\n";
}

  /* //QuantizerResult r = QuantizeWsmeans(std::vector<Argb>{}, std::vector<Argb>{}, 10); */
  /**/
  /* json palette = json::object(); */
  /**/
  /* const DynamicScheme s = SchemeTonalSpot(Hct(Argb(0xFFFFFF)), true, 0.0); */
  /**/
  /* palette["PrimaryPaletteKeyColor"] = HexFromArgb(MaterialDynamicColors::PrimaryPaletteKeyColor().GetArgb(s)); */
  /* palette["SecondaryPaletteKeyColor"] = HexFromArgb(MaterialDynamicColors::SecondaryPaletteKeyColor().GetArgb(s)); */
  /* palette["TertiaryPaletteKeyColor"] = HexFromArgb(MaterialDynamicColors::TertiaryPaletteKeyColor().GetArgb(s)); */
  /* palette["NeutralPaletteKeyColor"] = HexFromArgb(MaterialDynamicColors::NeutralPaletteKeyColor().GetArgb(s)); */
  /* palette["NeutralVariantPaletteKeyColor"] = HexFromArgb(MaterialDynamicColors::NeutralVariantPaletteKeyColor().GetArgb(s)); */
  /* palette["Background"] = HexFromArgb(MaterialDynamicColors::Background().GetArgb(s)); */
  /* palette["OnBackground"] = HexFromArgb(MaterialDynamicColors::OnBackground().GetArgb(s)); */
  /* palette["Surface"] = HexFromArgb(MaterialDynamicColors::Surface().GetArgb(s)); */
  /* palette["SurfaceDim"] = HexFromArgb(MaterialDynamicColors::SurfaceDim().GetArgb(s)); */
  /* palette["SurfaceBright"] = HexFromArgb(MaterialDynamicColors::SurfaceBright().GetArgb(s)); */
  /* palette["SurfaceContainerLowest"] = HexFromArgb(MaterialDynamicColors::SurfaceContainerLowest().GetArgb(s)); */
  /* palette["SurfaceContainerLow"] = HexFromArgb(MaterialDynamicColors::SurfaceContainerLow().GetArgb(s)); */
  /* palette["SurfaceContainer"] = HexFromArgb(MaterialDynamicColors::SurfaceContainer().GetArgb(s)); */
  /* palette["SurfaceContainerHigh"] = HexFromArgb(MaterialDynamicColors::SurfaceContainerHigh().GetArgb(s)); */
  /* palette["SurfaceContainerHighest"] = HexFromArgb(MaterialDynamicColors::SurfaceContainerHighest().GetArgb(s)); */
  /* palette["OnSurface"] = HexFromArgb(MaterialDynamicColors::OnSurface().GetArgb(s)); */
  /* palette["SurfaceVariant"] = HexFromArgb(MaterialDynamicColors::SurfaceVariant().GetArgb(s)); */
  /* palette["OnSurfaceVariant"] = HexFromArgb(MaterialDynamicColors::OnSurfaceVariant().GetArgb(s)); */
  /* palette["InverseSurface"] = HexFromArgb(MaterialDynamicColors::InverseSurface().GetArgb(s)); */
  /* palette["InverseOnSurface"] = HexFromArgb(MaterialDynamicColors::InverseOnSurface().GetArgb(s)); */
  /* palette["Outline"] = HexFromArgb(MaterialDynamicColors::Outline().GetArgb(s)); */
  /* palette["OutlineVariant"] = HexFromArgb(MaterialDynamicColors::OutlineVariant().GetArgb(s)); */
  /* palette["Shadow"] = HexFromArgb(MaterialDynamicColors::Shadow().GetArgb(s)); */
  /* palette["Scrim"] = HexFromArgb(MaterialDynamicColors::Scrim().GetArgb(s)); */
  /* palette["SurfaceTint"] = HexFromArgb(MaterialDynamicColors::SurfaceTint().GetArgb(s)); */
  /* palette["Primary"] = HexFromArgb(MaterialDynamicColors::Primary().GetArgb(s)); */
  /* palette["OnPrimary"] = HexFromArgb(MaterialDynamicColors::OnPrimary().GetArgb(s)); */
  /* palette["PrimaryContainer"] = HexFromArgb(MaterialDynamicColors::PrimaryContainer().GetArgb(s)); */
  /* palette["OnPrimaryContainer"] = HexFromArgb(MaterialDynamicColors::OnPrimaryContainer().GetArgb(s)); */
  /* palette["InversePrimary"] = HexFromArgb(MaterialDynamicColors::InversePrimary().GetArgb(s)); */
  /* palette["Secondary"] = HexFromArgb(MaterialDynamicColors::Secondary().GetArgb(s)); */
  /* palette["OnSecondary"] = HexFromArgb(MaterialDynamicColors::OnSecondary().GetArgb(s)); */
  /* palette["SecondaryContainer"] = HexFromArgb(MaterialDynamicColors::SecondaryContainer().GetArgb(s)); */
  /* palette["OnSecondaryContainer"] = HexFromArgb(MaterialDynamicColors::OnSecondaryContainer().GetArgb(s)); */
  /* palette["Tertiary"] = HexFromArgb(MaterialDynamicColors::Tertiary().GetArgb(s)); */
  /* palette["OnTertiary"] = HexFromArgb(MaterialDynamicColors::OnTertiary().GetArgb(s)); */
  /* palette["TertiaryContainer"] = HexFromArgb(MaterialDynamicColors::TertiaryContainer().GetArgb(s)); */
  /* palette["OnTertiaryContainer"] = HexFromArgb(MaterialDynamicColors::OnTertiaryContainer().GetArgb(s)); */
  /* palette["Error"] = HexFromArgb(MaterialDynamicColors::Error().GetArgb(s)); */
  /* palette["OnError"] = HexFromArgb(MaterialDynamicColors::OnError().GetArgb(s)); */
  /* palette["ErrorContainer"] = HexFromArgb(MaterialDynamicColors::ErrorContainer().GetArgb(s)); */
  /* palette["OnErrorContainer"] = HexFromArgb(MaterialDynamicColors::OnErrorContainer().GetArgb(s)); */
  /* palette["PrimaryFixed"] = HexFromArgb(MaterialDynamicColors::PrimaryFixed().GetArgb(s)); */
  /* palette["PrimaryFixedDim"] = HexFromArgb(MaterialDynamicColors::PrimaryFixedDim().GetArgb(s)); */
  /* palette["OnPrimaryFixed"] = HexFromArgb(MaterialDynamicColors::OnPrimaryFixed().GetArgb(s)); */
  /* palette["OnPrimaryFixedVariant"] = HexFromArgb(MaterialDynamicColors::OnPrimaryFixedVariant().GetArgb(s)); */
  /* palette["SecondaryFixed"] = HexFromArgb(MaterialDynamicColors::SecondaryFixed().GetArgb(s)); */
  /* palette["SecondaryFixedDim"] = HexFromArgb(MaterialDynamicColors::SecondaryFixedDim().GetArgb(s)); */
  /* palette["OnSecondaryFixed"] = HexFromArgb(MaterialDynamicColors::OnSecondaryFixed().GetArgb(s)); */
  /* palette["OnSecondaryFixedVariant"] = HexFromArgb(MaterialDynamicColors::OnSecondaryFixedVariant().GetArgb(s)); */
  /* palette["TertiaryFixed"] = HexFromArgb(MaterialDynamicColors::TertiaryFixed().GetArgb(s)); */
  /* palette["TertiaryFixedDim"] = HexFromArgb(MaterialDynamicColors::TertiaryFixedDim().GetArgb(s)); */
  /* palette["OnTertiaryFixed"] = HexFromArgb(MaterialDynamicColors::OnTertiaryFixed().GetArgb(s)); */
  /* palette["OnTertiaryFixedVariant"] = HexFromArgb(MaterialDynamicColors::OnTertiaryFixedVariant().GetArgb(s)); */
  /**/
  /* std::cout << std::setw(2) << palette << std::endl; */

#endif
