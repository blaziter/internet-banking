project(
  'internet-banking',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++11'],
)

subdir('include')
subdir('src')

dependencies = [
  dependency('sqlitecpp', required: true, fallback : ['sqlitecpp', 'sqlitecpp_dep']),
]

sources = [
  'main.cpp',
  src_sources,
]

exe = executable(
  'internet-banking',
  sources,
  dependencies : dependencies,
  include_directories: [
    include,
    src,
  ],
  install : true,
)

test('basic', exe)
