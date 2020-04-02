cmake_minimum_required(VERSION 3.2)

project(boost_dll_example)

SET(USE_CONAN TRUE)

# Automatic get boost with conan package manager
# https://docs.conan.io/en/latest/introduction.html
if(USE_CONAN)
    include(cmake/conan_get_dependencies.cmake)
    
    conan_get_dependencies(
        ${PROJECT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.71.0 COMPONENTS filesystem system)
include_directories(${Boost_INCLUDE_DIRS})

# Without this, the shared library will not work on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

SET(LIB_NAME shared_lib)
add_library(${LIB_NAME} SHARED)

target_sources(${LIB_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shared_lib.cpp
)

target_link_libraries(${LIB_NAME} ${Boost_LIBRARIES})

set_target_properties(${LIB_NAME}
PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
)

# path, where compiled dll and lib files will be copy
install(TARGETS ${LIB_NAME}
  LIBRARY DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
  ARCHIVE DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
  RUNTIME DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
)

SET(APP_NAME loader)
add_executable(${APP_NAME})

target_sources(${APP_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/loader.cpp
)

target_link_libraries(${APP_NAME} ${Boost_LIBRARIES})
