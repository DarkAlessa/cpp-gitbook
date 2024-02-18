Example
```meson
project('demo', 
		'c',
		'cpp',
        default_options: [
          'cpp_std=c++23',
          'warning_level=3',
          'werror=true'])

gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')
if not gtkmm_dep.found()
  error('gtkmm-4.0 not found')
endif

incdir = include_directories('include')
src = ['src/app.cpp',
	   'src/demo.cpp']

executable('demo', src, 
           include_directories: incdir,
           win_subsystem: 'console',
           dependencies: gtkmm_dep)
```

```text

win_subsystem: 'console' # จะโชว์ console
win_subsystem: 'windows' # จะไม่โชว์ console

```