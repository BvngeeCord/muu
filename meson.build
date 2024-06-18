project('muu', 'cpp', version: '0.0.1',
  default_options: [
    'cpp_std=c++20',
  ]
)

material_color_utilities = subproject('material-color-utilities')
material_color_utilities_dep = material_color_utilities.get_variable('material_color_utilities_dep')

json = dependency('nlohmann_json')

magick = dependency('Magick++')
# magick_cppflags = run_command('Magick++-config', '--cppflags', check: true) # --cxxflags
# magick_ldflags = run_command('Magick++-config', '--ldflags', check: true) # --libs
# add_project_arguments(magick_cppflags.stdout().replace('\n', '').split(' '), language: 'cpp')
# add_project_link_arguments(magick_ldflags.stdout().replace('\n', '').split(' '), language: 'cpp')

# add_project_link_arguments('-v', language: 'cpp')

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
