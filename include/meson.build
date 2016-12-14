epoxy_headers = [
  'epoxy/egl.h',
  'epoxy/gl.h',
  'epoxy/glx.h',
  'epoxy/wgl.h',
]

epoxy_gen_headers = [ join_paths(meson.build_root(), 'include/epoxy/gl_generated.h') ]

if build_egl
  epoxy_gen_headers += [ join_paths(meson.build_root(), 'include/epoxy/egl_generated.h') ]
endif

if build_glx
  epoxy_gen_headers += [ join_paths(meson.build_root(), 'include/epoxy/glx_generated.h') ]
endif

if build_wgl
  epoxy_gen_headers += [ join_paths(meson.build_root(), 'include/epoxy/wgl_generated.h') ]
endif

install_headers(epoxy_headers + epoxy_gen_headers, subdir: 'epoxy')
