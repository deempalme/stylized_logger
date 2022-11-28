cmake_minimum_required(VERSION 3.1)

if(NOT TARGET ${RamRodLog_LIBRARIES})
  project(RamRodLog
    VERSION 0.8.0
    DESCRIPTION "Ram-Rod's log printer"
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

  add_library(${PROJECT_NAME} STATIC)

  target_sources(${PROJECT_NAME}
    PRIVATE
      include/ramrod/log.h
      include/ramrod/log_attention.h
      include/ramrod/log_base.h
      include/ramrod/log_error.h
      include/ramrod/log_format.h
      include/ramrod/log_good.h
      include/ramrod/log_ostream.h
      include/ramrod/log_perror.h
      include/ramrod/log_types.h
      include/ramrod/log_warning.h

      src/ramrod/log.cpp
      src/ramrod/log_attention.cpp
      src/ramrod/log_base.cpp
      src/ramrod/log_error.cpp
      src/ramrod/log_format.cpp
      src/ramrod/log_good.cpp
      src/ramrod/log_ostream.cpp
      src/ramrod/log_perror.cpp
      src/ramrod/log_warning.cpp
  )

  target_include_directories(${PROJECT_NAME} BEFORE PUBLIC include)

  set_target_properties(${PROJECT_NAME}
    PROPERTIES
      CXX_STANDARD          17
      CXX_STANDARD_REQUIRED TRUE
      CXX_EXTENSIONS        FALSE
  )

  target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

endif(NOT TARGET ${RamRodLog_LIBRARIES})
