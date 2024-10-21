cmake_minimum_required(VERSION 3.16)
project(musializer)

find_package(raylib)
find_package(PkgConfig)
pkg_search_module(FFTW3 REQUIRED fftw3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(MUSIALIZER_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/musializer.c
  )

set(PLUGIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.c
  )

add_library(plugin SHARED)
target_sources(plugin
 PRIVATE
  ${PLUGIN_SOURCES}
)
target_include_directories(plugin
 PRIVATE
  ${raylib_INCLUDE_DIRS}
)
target_link_libraries(plugin
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
