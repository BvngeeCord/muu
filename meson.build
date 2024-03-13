project('muu', 'cpp', version: '0.0.1',
  default_options: [
    'cpp_std=c++20',
    'buildtype=release',
  ]
)

material_color_utilities = subproject('material-color-utilities')
material_color_utilities_dep = material_color_utilities.get_variable('material_color_utilities_dep')

json = dependency('nlohmann_json')
magick = dependency('Magick++', static: false)

muu_sources = files(
  'src/main.cpp',
)
include_dirs = include_directories('src')

executable('muu',
  muu_sources, 
  include_directories: include_dirs,
  dependencies: [
    json,
    magick,
    material_color_utilities_dep,
  ],
  install: false
)
