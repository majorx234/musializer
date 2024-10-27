cmake_minimum_required(VERSION 3.16)
project(musializer)

find_package(raylib)
find_package(PkgConfig)
pkg_search_module(FFTW3 REQUIRED fftw3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
find_library(MATH_LIBRARY m REQUIRED)

set(MUSIALIZER_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/musializer.c
  )

set(PLUGIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.c
  )

set(SPECTRUM_PLUGIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/spectrum_plugin.c
  )

set(SINE_WAVE_COMPARE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sine_wave_compare.c
  )


add_library(plugin SHARED)
target_sources(plugin
 PRIVATE
  ${PLUGIN_SOURCES}
)
target_include_directories(plugin
 PRIVATE
  ${raylib_INCLUDE_DIRS}
  ${FFTW3_INCLUDE_DIRS}
)
target_link_libraries(plugin
  ${raylib_LIBRARIES}
)

add_library(spectrum_plugin SHARED)
target_sources(spectrum_plugin
 PRIVATE
  ${SPECTRUM_PLUGIN_SOURCES}
)
target_include_directories(spectrum_plugin
 PRIVATE
  ${raylib_INCLUDE_DIRS}
  ${FFTW3_INCLUDE_DIRS}
)
target_link_libraries(spectrum_plugin
  ${raylib_LIBRARIES}
)

add_executable(musializer)
target_sources(musializer
 PRIVATE
  ${MUSIALIZER_SOURCES}
)
target_include_directories(musializer
 PRIVATE
  ${raylib_INCLUDE_DIRS}
)
target_link_libraries(musializer
  ${raylib_LIBRARIES}
)

add_executable(sine_wave_compare)
target_sources(sine_wave_compare
 PRIVATE
  ${SINE_WAVE_COMPARE_SOURCES}
)
target_include_directories(sine_wave_compare
 PRIVATE
  ${raylib_INCLUDE_DIRS}
)
target_link_libraries(sine_wave_compare
 PUBLIC
  ${MATH_LIBRARY}
  ${raylib_LIBRARIES}
)
