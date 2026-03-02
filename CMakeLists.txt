cmake_minimum_required(VERSION 3.15)

if(NOT TARGET ${RamRodLog_LIBRARIES})
    project(RamRodLog
        VERSION 0.9.0
        DESCRIPTION "Ram-Rod's logger"
        LANGUAGES CXX
    )

    set(INC_DIR include/ramrod/log)
    set(SRC_DIR src/ramrod/log)

    # Header files
    set(UNIT_HPP_FILES
        ${INC_DIR}/Base.hpp
        ${INC_DIR}/Debug.hpp
        ${INC_DIR}/Error.hpp
        ${INC_DIR}/Info.hpp
        ${INC_DIR}/Logger.hpp
        ${INC_DIR}/Output.hpp
        ${INC_DIR}/OutputFile.hpp
        ${INC_DIR}/Verbose.hpp
        ${INC_DIR}/Warning.hpp
    )

    # Source files
    set(UNIT_CPP_FILES
        ${SRC_DIR}/Base.cpp
        ${SRC_DIR}/Debug.cpp
        ${SRC_DIR}/Error.cpp
        ${SRC_DIR}/Info.cpp
        ${SRC_DIR}/Logger.cpp
        ${SRC_DIR}/Output.cpp
        ${SRC_DIR}/OutputFile.cpp
        ${SRC_DIR}/Verbose.cpp
        ${SRC_DIR}/Warning.cpp
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
        # Project files
        ${UNIT_CPP_FILES}
        ${UNIT_HPP_FILES}
    )

    target_include_directories(${PROJECT_NAME}
        BEFORE PUBLIC
        include
    )

    set_target_properties(${PROJECT_NAME}
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS FALSE
    )

    target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
endif(NOT TARGET ${RamRodLog_LIBRARIES})
