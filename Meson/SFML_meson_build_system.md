```
📁 Demo
 ├─📄 meson.build 
 ├─📁 include
 ├─📁 src
 │  ├─📄 demo.cpp
 │  └─📄 line.cpp
 └─📁 build
```
### commands
```sh
$ meson setup build
$ meson compile -C build
```
---
## meson.build V.1 use `sfml-all`
```sh
$ pkg-config --list-all | grep sfml | awk '{print $1}'
sfml-all
sfml-audio
sfml-graphics
sfml-network
sfml-system
sfml-window
```
### meson.build file
```meson

project('demo', 'c', 'cpp',
        default_options: 'cpp_std=c++17')

sfml_dep = dependency('sfml-all')
if not sfml_dep.found()
  error('SFML not found')
endif

incdir = include_directories('include')
src_list = ['src/demo.cpp',
            'src/line.cpp']

c_compiler    = meson.get_compiler('c')
cpp_compiler  = meson.get_compiler('cpp')
warning_flags = ['-Wall', '-Werror', '-Wextra', '-Wpedantic']
warning_flags = cpp_compiler.get_supported_arguments(warning_flags)
add_project_arguments(warning_flags, language: 'cpp')

executable('demo', src_list,
            include_directories: incdir,
            win_subsystem: 'windows',
            dependencies: sfml_dep)

```
---
## meson.build V.2 use (system, window, graphics, network and audio)
### check package
```sh
$ pkg-config --list-all | grep sfml | awk '{print $1}'
sfml-all
sfml-audio
sfml-graphics
sfml-network
sfml-system
sfml-window
```
### meson.build file
```meson

project('demo', 'c', 'cpp',
        default_options: 'cpp_std=c++23')

# SFML is made of 5 modules (system, window, graphics, network and audio)
sfml_system_dep   = dependency('sfml-system')
sfml_window_dep   = dependency('sfml-window')
sfml_graphics_dep = dependency('sfml-graphics')
sfml_network_dep  = dependency('sfml-network')
sfml_audio_dep    = dependency('sfml-audio')

if not sfml_system_dep.found()
  error('sfml-system not found')
endif
if not sfml_window_dep.found()
  error('sfml-window not found')
endif
if not sfml_graphics_dep.found()
  error('sfml-graphics not found')
endif
if not sfml_network_dep.found()
  error('sfml-network not found')
endif
if not sfml_audio_dep.found()
  error('sfml-audio not found')
endif

incdir = include_directories('include')
src_list = ['src/demo.cpp',
            'src/line.cpp']

c_compiler   = meson.get_compiler('c')
cpp_compiler = meson.get_compiler('cpp')
warning_flags = ['-Wall', '-Werror', '-Wpedantic']
warning_flags = cpp_compiler.get_supported_arguments(warning_flags)
add_project_arguments(warning_flags, language: 'cpp')

executable('demo', src_list,
            include_directories: incdir,
            win_subsystem: 'windows',
            dependencies: [
                sfml_system_dep,
                sfml_window_dep,
                sfml_graphics_dep,
                sfml_network_dep,
                sfml_audio_dep])

```
### meson.build file (using array)
```meson
project('demo', 'c', 'cpp',
        default_options: 'cpp_std=c++23')

# SFML is made of 5 modules (system, window, graphics, network and audio)
sfml_dep = [dependency('sfml-system'),
            dependency('sfml-window'),
            dependency('sfml-graphics'),
            dependency('sfml-network'),
            dependency('sfml-audio')]

incdir = include_directories('include')
src_list = ['src/demo.cpp',
            'src/line.cpp']

c_compiler   = meson.get_compiler('c')
cpp_compiler = meson.get_compiler('cpp')
warning_flags = ['-Wall', '-Werror', '-Wpedantic']
warning_flags = cpp_compiler.get_supported_arguments(warning_flags)
add_project_arguments(warning_flags, language: 'cpp')

executable('demo', src_list,
            include_directories: incdir,
            win_subsystem: 'windows',
            dependencies: sfml_dep)

```