project(
  'internet-banking',
  'cpp',
  meson_version: '>= 1.3.0',
  version: '0.1',
  default_options: ['warning_level=3', 'cpp_std=c++11'],
)

subdir('include')
subdir('src')

dependencies = [
  dependency(
    'sqlitecpp',
    default_options: ['default_library=static'],
    required: true,
    fallback: ['sqlitecpp', 'sqlitecpp_dep'],
  ),
  dependency(
    'openssl',
    default_options: ['default_library=static'],
    required: true,
    fallback: ['openssl', 'openssl_dep'],
  ),
]

sources = [
  'main.cpp',
  src_sources,
]

exe = executable(
  'internet-banking',
  sources,
  dependencies: dependencies,
  include_directories: [
    include,
    src,
  ],
  install: true,
  link_args: ['-static'],
)

test('basic', exe)
