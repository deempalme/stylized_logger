cmake_minimum_required(VERSION 3.1)

if(NOT TARGET ${RamRodConsole_LIBRARIES})
  project(RamRodConsole
    VERSION 0.7.0
    DESCRIPTION "Ram-Rod console printer"
    LANGUAGES CXX
  )

  set(${PROJECT_NAME}_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
    CACHE INTERNAL ""
  )
  set(${PROJECT_NAME}_LIBRARIES
    ${PROJECT_NAME}
    CACHE INTERNAL ""
  )

  add_library(${PROJECT_NAME})

  target_sources(${PROJECT_NAME}
    PRIVATE
      include/ramrod/console/printer.h
      include/ramrod/console/types.h
      src/ramrod/console/printer.cpp
  )

  target_include_directories(${PROJECT_NAME} BEFORE PRIVATE include)

  set_target_properties(${PROJECT_NAME}
    PROPERTIES
      CXX_STANDARD          11
      CXX_STANDARD_REQUIRED TRUE
      CXX_EXTENSIONS        FALSE
  )

  target_compile_options(${PROJECT_NAME}
    PRIVATE
      -Wall
      -Wextra
      -Wundef
      -pedantic
      -Wconversion
      -Wcast-align
      -Wfloat-equal
      -Wpointer-arith
      -Wsign-conversion
      -Wunreachable-code
      -Wunused-function
      -Wignored-qualifiers
  )

  target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
endif(NOT TARGET ${RamRodConsole_LIBRARIES})
