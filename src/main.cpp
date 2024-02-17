#include "cam/hct.h"
#include "utils/utils.h"
#include <dynamiccolor/dynamic_scheme.h>
#include <format>
#include <iostream>
#include <nlohmann/json.hpp>
#include <scheme/scheme_tonal_spot.h>
#include <dynamiccolor/material_dynamic_colors.h>

using json = nlohmann::json;
using namespace material_color_utilities;

int main(int argc, char *argv[]) {
  std::cout << "hi\n";

  const DynamicScheme s = SchemeTonalSpot(Hct(Argb(0xFFFFFF)), true, 0.0);

  std::cout << std::format("{}: {}", "PrimaryPaletteKeyColor", MaterialDynamicColors::PrimaryPaletteKeyColor().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SecondaryPaletteKeyColor", MaterialDynamicColors::SecondaryPaletteKeyColor().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "TertiaryPaletteKeyColor", MaterialDynamicColors::TertiaryPaletteKeyColor().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "NeutralPaletteKeyColor", MaterialDynamicColors::NeutralPaletteKeyColor().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "NeutralVariantPaletteKeyColor", MaterialDynamicColors::NeutralVariantPaletteKeyColor().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Background", MaterialDynamicColors::Background().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnBackground", MaterialDynamicColors::OnBackground().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Surface", MaterialDynamicColors::Surface().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceDim", MaterialDynamicColors::SurfaceDim().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceBright", MaterialDynamicColors::SurfaceBright().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceContainerLowest", MaterialDynamicColors::SurfaceContainerLowest().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceContainerLow", MaterialDynamicColors::SurfaceContainerLow().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceContainer", MaterialDynamicColors::SurfaceContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceContainerHigh", MaterialDynamicColors::SurfaceContainerHigh().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceContainerHighest", MaterialDynamicColors::SurfaceContainerHighest().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSurface", MaterialDynamicColors::OnSurface().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceVariant", MaterialDynamicColors::SurfaceVariant().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSurfaceVariant", MaterialDynamicColors::OnSurfaceVariant().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "InverseSurface", MaterialDynamicColors::InverseSurface().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "InverseOnSurface", MaterialDynamicColors::InverseOnSurface().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Outline", MaterialDynamicColors::Outline().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OutlineVariant", MaterialDynamicColors::OutlineVariant().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Shadow", MaterialDynamicColors::Shadow().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Scrim", MaterialDynamicColors::Scrim().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SurfaceTint", MaterialDynamicColors::SurfaceTint().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Primary", MaterialDynamicColors::Primary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnPrimary", MaterialDynamicColors::OnPrimary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "PrimaryContainer", MaterialDynamicColors::PrimaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnPrimaryContainer", MaterialDynamicColors::OnPrimaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "InversePrimary", MaterialDynamicColors::InversePrimary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Secondary", MaterialDynamicColors::Secondary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSecondary", MaterialDynamicColors::OnSecondary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SecondaryContainer", MaterialDynamicColors::SecondaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSecondaryContainer", MaterialDynamicColors::OnSecondaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Tertiary", MaterialDynamicColors::Tertiary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnTertiary", MaterialDynamicColors::OnTertiary().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "TertiaryContainer", MaterialDynamicColors::TertiaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnTertiaryContainer", MaterialDynamicColors::OnTertiaryContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "Error", MaterialDynamicColors::Error().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnError", MaterialDynamicColors::OnError().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "ErrorContainer", MaterialDynamicColors::ErrorContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnErrorContainer", MaterialDynamicColors::OnErrorContainer().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "PrimaryFixed", MaterialDynamicColors::PrimaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "PrimaryFixedDim", MaterialDynamicColors::PrimaryFixedDim().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnPrimaryFixed", MaterialDynamicColors::OnPrimaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnPrimaryFixedVariant", MaterialDynamicColors::OnPrimaryFixedVariant().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SecondaryFixed", MaterialDynamicColors::SecondaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "SecondaryFixedDim", MaterialDynamicColors::SecondaryFixedDim().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSecondaryFixed", MaterialDynamicColors::OnSecondaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnSecondaryFixedVariant", MaterialDynamicColors::OnSecondaryFixedVariant().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "TertiaryFixed", MaterialDynamicColors::TertiaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "TertiaryFixedDim", MaterialDynamicColors::TertiaryFixedDim().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnTertiaryFixed", MaterialDynamicColors::OnTertiaryFixed().GetArgb(s)) << "\n";
  std::cout << std::format("{}: {}", "OnTertiaryFixedVariant", MaterialDynamicColors::OnTertiaryFixedVariant().GetArgb(s)) << "\n";
}
