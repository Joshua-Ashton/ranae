ranae_res = wrc_generator.process('version.rc')

ranae_src = [
  'ranae_loader.cpp'
]

ranae_dll = shared_library('vulkan-1', ranae_src, ranae_res,
  name_prefix         : '',
  dependencies        : [ util_dep, lib_dxgi ],
  include_directories : ranae_include_path,
  install             : true,
  override_options    : ['cpp_std='+ranae_cpp_std])

ranae_dep = declare_dependency(
  link_with           : [ ranae_dll ],
  include_directories : [ ranae_include_path ])
