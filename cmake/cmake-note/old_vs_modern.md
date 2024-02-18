```
## Note
Variable : CMAKE_RUNTIME_OUTPUT_DIRECTORY
Property : RUNTIME_OUTPUT_DIRECTORY
```

```cmake
# Old (Global Property)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
```
```cmake
#### Modern (Target Property) เซ็ตได้แค่ 1 property แต่เซ็ตได้หลาย target

set_property(
	TARGET 
		target_1
		target_2
		target_3
	PROPERTY 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)
```
```cmake
#### Modern (Target Property) เซ็ตได้หลาย property และหลาย  target
set_target_properties(
	target_1
	target_2
	target_3
	PROPERTIES 
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
) 
```
```cmake
# Modern

target_link_options()
target_link_libraries()
target_compile_options()
target_compile_features()
target_link_directories()
target_precompile_headers()
target_compile_definitions()
target_include_directories()
target_sources()
```