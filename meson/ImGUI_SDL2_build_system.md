```
📁 Demo
 ├─📄 meson.build 
 ├─📁 include
 ├─📁 src
 │  └─📄 demo.cpp
 ├─📁 build
 └─📁 subprojects        // ไฟล์ .wrap จะถูกสร้างหลังใช้คำสั่ง meson wrap install <...>
    ├─📁 imgui-1.89.9    // สร้างหลังจากคำสั่ง meson setup <build โฟลเดอร์>
    └─📄 imgui.wrap
```

### meson.build file
```meson
project(
    'demo',
    'c',
    'cpp',
    default_options: 'cpp_std=c++23'
)

sdl2_dep       = dependency('sdl2')
sdl2_image_dep = dependency('sdl2_image')
sdl2_ttf_dep   = dependency('sdl2_ttf')
imgui_dep      = dependency('imgui')

incdir = include_directories('include')

src = [
    'src/demo.cpp',
]

c_compiler    = meson.get_compiler('c')
cpp_compiler  = meson.get_compiler('cpp')
warning_flags = ['-Wall', '-Werror', '-Wpedantic']
warning_flags = cpp_compiler.get_supported_arguments(warning_flags)
add_project_arguments(warning_flags, language: 'cpp')

executable('demo', src, 
            include_directories: incdir,
            win_subsystem: 'console',
            dependencies: [
                sdl2_dep,
                sdl2_image_dep,
                sdl2_ttf_dep,
                imgui_dep,
            ]
)
```

### commands
```sh
$ meson setup build
$ mkdir subprojects
$ meson wrap install imgui
$ meson compile -C build
```