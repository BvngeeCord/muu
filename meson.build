project('muu', 'cpp', version: '0.0.1',
  default_options: [
    'optimization=3',
    'cpp_std=c++20',
  ]
)

json = dependency('nlohmann_json')

globber = run_command('sh', '-c', 'find . -name "*.cpp" | sort', check: true)
src = globber.stdout().strip().split('\n')
muu_sources = files(
  'src/main.cpp',
)
include_directories = include_directories(
  'include/material-color-utilities/cpp',
  'include/material-color-utilities/', # needed for the mcu headers
  'include', 
)
executable('muu',
  muu_sources, 
  include_directories: include_directories,
  dependencies: [json],
  install: false
)
