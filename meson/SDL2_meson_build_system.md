## แบบมี Native package
```
📁 Demo
 ├─📄 meson.build 
 ├─📁 include
 ├─📁 src
 │  └─📄 verlet.cpp
 └─📁 build
```
### meson.build file
```meson

project('demo', 'c', 'cpp',
        default_options: 'cpp_std=c++23')

sdl2_dep 	   = dependency('sdl2')
sdl2_image_dep = dependency('sdl2_image')
sdl2_ttf_dep   = dependency('sdl2_ttf')

incdir = include_directories('include')
src = 'src/verlet.cpp'  # for multiple file src = ['src1.cpp', 'src2.cpp']

c_compiler    = meson.get_compiler('c')
cpp_compiler  = meson.get_compiler('cpp')
warning_flags = ['-Wall', '-Werror', '-Wextra', '-Wpedantic']
warning_flags = cpp_compiler.get_supported_arguments(warning_flags)
add_project_arguments(warning_flags, language: 'cpp')

executable('demo', src, 
		include_directories: incdir,
		win_subsystem: 'windows',
		dependencies: [sdl2_dep, sdl2_image_dep, sdl2_ttf_dep])

```
### commands
```sh
$ meson setup build
$ meson compile -C build
```
---
## แบบไม่มี  Native package (WrapDB)
บางแพลตฟอร์มไม่มีระบบบ `native package` ในกรณีเหล่านี้เป็นเรื่องปกติที่จะรวมไลบรารีบุคคลที่สามทั้งหมดใน `source tree` โดยการสร้างโฟลเดอร์ `subprojects` จากนั้นใช้คำสั่ง `meson wrap install <package>`
```
📁 Demo
 ├─📄 meson.build 
 ├─📁 include
 ├─📁 src
 │  └─📄 verlet.cpp
 ├─📁 build
 └─📁 subprojects     // ไฟล์ .wrap จะถูกสร้างหลังใช้คำสั่ง meson wrap install <...>
    ├─📄 sdl2.wrap
    ├─📄 sdl2_image.wrap
    ├─📄 sdl2_ttf.wrap
    ├─📄 sdl2_mixer.wrap
    └─📄 sdl2_net.wrap
```
### commands
```sh
$ meson setup build
$ mkdir subprojects
$ meson wrap install sdl2
$ meson wrap install sdl2_image
$ meson wrap install sdl2_ttf
$ meson wrap install sdl2_net
$ meson wrap install sdl2_mixer
$ meson compile -C build
```