cmake_minimum_required(VERSION 3.1)

if(NOT TARGET ${RamRodConsole_LIBRARIES})
  project(RamRodConsole
    VERSION 0.8.0
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
      include/ramrod/console.h
      include/ramrod/console/attention.h
      include/ramrod/console/clean.h
      include/ramrod/console/cout.h
      include/ramrod/console/endl.h
      include/ramrod/console/error.h
      include/ramrod/console/flush.h
      include/ramrod/console/format.h
      include/ramrod/console/regular.h
      include/ramrod/console/types.h
      include/ramrod/console/warning.h

      src/ramrod/console.cpp
      src/ramrod/console/attention.cpp
      src/ramrod/console/clean.cpp
      src/ramrod/console/cout.cpp
      src/ramrod/console/endl.cpp
      src/ramrod/console/error.cpp
      src/ramrod/console/flush.cpp
      src/ramrod/console/format.cpp
      src/ramrod/console/regular.cpp
      src/ramrod/console/warning.cpp
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
