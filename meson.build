project('muu', 'cpp', version: '0.0.1')

json = dependency('nlohmann_json')

muu_sources = files(
  'src/main.cpp'
)
include_directories = [
  'subprojects'
]
executable('muu',
  muu_sources, 
  include_directories: include_directories,
  dependencies: [json],
  install: false
)
