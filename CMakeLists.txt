cmake_minimum_required(VERSION 3.22)

if(NOT TARGET ${RamRodLog_LIBRARIES})
    project(RamRodLog
        VERSION 1.0.0
        DESCRIPTION "Ram-Rod's logger"
        LANGUAGES CXX
    )

    set(INC_DIR include/ramrod/log)
    set(SRC_DIR src/ramrod/log)

    # Header files
    set(UNIT_HPP_FILES
        ${INC_DIR}/Base.hpp
        ${INC_DIR}/Debug.hpp
        ${INC_DIR}/Endl.hpp
        ${INC_DIR}/Error.hpp
        ${INC_DIR}/File.hpp
        ${INC_DIR}/Info.hpp
        ${INC_DIR}/Logger.hpp
        ${INC_DIR}/Verbose.hpp
        ${INC_DIR}/Warning.hpp
        ${INC_DIR}/Writer.hpp
        ${INC_DIR}/WriterCerr.hpp
        ${INC_DIR}/WriterFile.hpp
        ${INC_DIR}/WriterFileCerr.hpp
        ${INC_DIR}/WriterFileCout.hpp
    )

    # Source files
    set(UNIT_CPP_FILES
        ${SRC_DIR}/Base.cpp
        ${SRC_DIR}/Debug.cpp
        ${SRC_DIR}/Endl.cpp
        ${SRC_DIR}/Error.cpp
        ${SRC_DIR}/File.cpp
        ${SRC_DIR}/Info.cpp
        ${SRC_DIR}/Logger.cpp
        ${SRC_DIR}/Verbose.cpp
        ${SRC_DIR}/Warning.cpp
        ${SRC_DIR}/Writer.cpp
        ${SRC_DIR}/WriterCerr.cpp
        ${SRC_DIR}/WriterFile.cpp
        ${SRC_DIR}/WriterFileCerr.cpp
        ${SRC_DIR}/WriterFileCout.cpp
    )

    # Private header files
    set(PRIVATE_HPP_FILES
        ${SRC_DIR}/Constants.hpp
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
        # Project files
        PUBLIC
        ${UNIT_HPP_FILES}
        PRIVATE
        ${UNIT_CPP_FILES}
        ${PRIVATE_HPP_FILES}
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

    if(BUILD_TESTING)
        add_subdirectory(tests)
    endif()
endif(NOT TARGET ${RamRodLog_LIBRARIES})
