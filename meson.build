project('ranae', ['c', 'cpp'], version : 'v0.0.0', meson_version : '>= 0.46')

cpu_family = target_machine.cpu_family()

add_project_arguments('-DNOMINMAX', language : 'cpp')

ranae_compiler = meson.get_compiler('cpp')
if ranae_compiler.get_id() == 'msvc'
  ranae_cpp_std='c++latest'
  ranae_msvc=true
else
  ranae_cpp_std='c++17'
  ranae_msvc=false
endif

if ranae_compiler.get_id() == 'msvc'
  add_project_arguments('/std:' + ranae_cpp_std, language : 'cpp')
endif

ranae_include_path = include_directories('./include')

if (cpu_family == 'x86_64')
  ranae_library_path = meson.source_root() + '/lib'
else
  ranae_library_path = meson.source_root() + '/lib32'
endif

if ranae_compiler.get_id() == 'msvc'
  wrc = find_program('rc')
else
  wrc = cpu_family == 'x86_64' ? find_program('x86_64-w64-mingw32-windres') : find_program('i686-w64-mingw32-windres')
endif
if cpu_family == 'x86'
  if ranae_compiler.has_link_argument('-Wl,--add-stdcall-alias')
    add_global_link_arguments('-Wl,--add-stdcall-alias', language: 'cpp')
  endif
  if ranae_compiler.has_link_argument('-Wl,--enable-stdcall-fixup')
    add_global_link_arguments('-Wl,--enable-stdcall-fixup', language: 'cpp')
  endif
endif

lib_dxgi    = ranae_compiler.find_library('dxgi')

if ranae_compiler.get_id() == 'msvc'
  res_ext = '.res'
else
  res_ext = '.o'
endif

if ranae_compiler.get_id() == 'msvc'
  wrc_generator = generator(wrc,
  output    : [ '@BASENAME@' + res_ext ],
  arguments : [ '/fo', '@OUTPUT@', '@INPUT@' ])
else
  wrc_generator = generator(wrc,
  output    : [ '@BASENAME@' + res_ext ],
  arguments : [ '-i', '@INPUT@', '-o', '@OUTPUT@' ])
endif

ranae_version = vcs_tag(
  command: ['git', 'describe', '--dirty=+'],
  input:  'version.h.in',
  output: 'version.h')

subdir('src')