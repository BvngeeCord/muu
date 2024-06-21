project('material-color-utilities', 'cpp',
  default_options: []
)

# bad practice but I'm lazy
src_globber = run_command('sh', '-c', 'find ./cpp -type f -name "*.cc" | grep -vE ".*test\.cc" | sort', check: true)
mcu_src = files(src_globber.stdout().strip().split('\n'))
# TODO: make includes referenced via "mcu/..." (maybe by symlink?)
mcu_header_dirs = include_directories('./cpp')

#googletest = dependency('gtest')
absl_flat_hash_map = dependency('absl_flat_hash_map')
absl_strings = dependency('absl_strings')

mcu = static_library('material-color-utilities', mcu_src,
  dependencies: [absl_strings, absl_flat_hash_map],
  implicit_include_directories: false,
  include_directories: mcu_header_dirs,
)

material_color_utilities_dep = declare_dependency(
  link_with: mcu,
  include_directories: mcu_header_dirs,
)

#meson.override_dependency('material-color-utilities', material_color_utilities_dep)
