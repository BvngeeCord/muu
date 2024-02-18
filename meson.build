project('muu', 'cpp', version: '0.0.1',
  default_options: [
    'cpp_std=c++20',
    'buildtype=release',
    'default_library=static',
  ]
)

material_color_utilities = subproject('material-color-utilities')
material_color_utilities_dep = material_color_utilities.get_variable('material_color_utilities_dep')

json = dependency('nlohmann_json')

muu_sources = files(
  'src/main.cpp',
)
include_directories = include_directories('src')

executable('muu',
  muu_sources, 
  include_directories: include_directories,
  dependencies: [json, material_color_utilities_dep],
  install: false
)
