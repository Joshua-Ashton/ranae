util_src = [
  'util_env.cpp',
  'util_string.cpp',
  
  'log/log.cpp',
]

if ranae_platform == 'windows'
  util_src += [
    'platform/win32/util_env_win32.cpp'
  ]
else
  error('Unsupported platform for util')
endif

util_lib = static_library('util', util_src,
  include_directories : [ ranae_include_path ],
  override_options    : ['cpp_std='+ranae_cpp_std])

util_dep = declare_dependency(
  link_with           : [ util_lib ])
