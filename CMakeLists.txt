cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-narrowing")

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_STANDARD 90)

cmake_policy(SET CMP0048 NEW) # PROJECT_VERSION
cmake_policy(SET CMP0075 NEW) # honor ``CMAKE_REQUIRED_LIBRARIES``
project("push_swap" VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_REQUIRED_LIBRARIES "-lbsd")

include_directories(include)

file(GLOB FTLIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/libft/*.h")
file(GLOB FTLIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/libft/**/ft_*.c")

set(FTLIB_name ft)
set(FTLIB_filename libft.a)
set(FTLIB_dir ${CMAKE_CURRENT_SOURCE_DIR}/libft)
add_custom_command(OUTPUT ${FTLIB_dir}/${FTLIB_filename}
        COMMAND make -C ${FTLIB_dir})
add_custom_target(${FTLIB_filename} DEPENDS ${FTLIB_dir}/${FTLIB_filename})

add_library(${FTLIB_name} STATIC IMPORTED)
add_dependencies(${FTLIB_name} ${FTLIB_filename})
set_target_properties(${FTLIB_name} PROPERTIES
        IMPORTED_LOCATION ${FTLIB_dir}/${FTLIB_filename} # Make sure to use absolute path here
        INTERFACE_SOURCES "${FTLIB_HEADERS};${FTLIB_SOURCES}"
        INTERFACE_INCLUDE_DIRECTORIES "${FTLIB_dir}"
        INTERFACE_COMPILE_DEFINITIONS "OPTIMISTIC")

set(TARGET_NAME push_swap)
file(GLOB TARGET_HEADERS "src/*.h")
file(GLOB TARGET_SOURCES "src/*.c")

set(TARGET_CFLAGS
        -c
        -g3 -fvar-tracking -fvar-tracking-assignments
        -gdwarf-4 -gstrict-dwarf
        -L/usr/lib/debug
        -Wall -Wextra -Werror
        -fno-exceptions
        -ffunction-sections
        -fdata-sections
        -O0)
set(TARGET_LINK_FLAGS -w -lbsd -O0)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package (Threads REQUIRED)
add_executable(${TARGET_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE include src)
target_compile_options(${TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
target_link_libraries(${TARGET_NAME} bsd ${FTLIB_name} Threads::Threads)
set_target_properties(${TARGET_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CHECKER_TARGET_NAME checker)
file(GLOB TARGET_HEADERS "checker/*.h")
file(GLOB TARGET_SOURCES "checker/*.c")
add_executable(${CHECKER_TARGET_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})
target_include_directories(${CHECKER_TARGET_NAME} PRIVATE include src)
target_compile_options(${CHECKER_TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${CHECKER_TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
target_link_libraries(${CHECKER_TARGET_NAME} bsd ${FTLIB_name} Threads::Threads)
set_target_properties(${CHECKER_TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(TEST1_TARGET_NAME test1)
file(GLOB TEST1_TARGET_HEADERS "tests/*.h")
file(GLOB TEST1_TARGET_SOURCES "tests/test1.c")
add_executable(${TEST1_TARGET_NAME} ${TEST1_TARGET_HEADERS} ${TEST1_TARGET_SOURCES})
target_include_directories(${TEST1_TARGET_NAME} PRIVATE include src)
target_compile_options(${TEST1_TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${TEST1_TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
target_link_libraries(${TEST1_TARGET_NAME} bsd ${FTLIB_name} Threads::Threads)
set_target_properties(${TEST1_TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# https://youtrack.jetbrains.com/issue/CPP-22289
find_program(VALGRIND "valgrind")
set(MEMORYCHECK_COMMAND ${VALGRIND})
set(MEMORYCHECK_SUPPRESSIONS "")
set(MEMORYCHECK_COMMAND_OPTIONS
        --gen-suppressions=all
        -v
        -s
        --error-exitcode=1
        --leak-check=full
        --show-reachable=yes
        --num-callers=50
        ${MEMORYCHECK_SUPPRESSIONS}
        --errors-for-leak-kinds=definite,indirect,possible,reachable
        --trace-children=yes
#        --vgdb=no
#        --vgdb-error=0
        CACHE STRING "Options to pass to the memory checker")

include(CTest)
include(FindUnixCommands)

set(test1_command_start "ARG='2 1 3 6 5 8'")
set(test1_command "ARG='2 1 3 6 5 8'; ! $<TARGET_FILE:${TARGET_NAME}> \"\${ARG}\" | ./checker_linux $ARG | grep -v OK")
add_test(NAME test1
        COMMAND
            ${BASH} -c "${test1_command}"
        WORKING_DIRECTORY
            "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_test(NAME test2
        COMMAND
            env "ARG='sa pb pb pb sa pa pa pa'" $<TARGET_FILE:${CHECKER_TARGET_NAME}> 2 1 3 6 5 8
        WORKING_DIRECTORY
            "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_test(NAME test3
        COMMAND
            env ARG="2 1 3 6 5 8" $<TARGET_FILE:${TARGET_NAME}> 2 1 3 6 5 8
        WORKING_DIRECTORY
            "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_test(NAME memcheck_${TARGET_NAME}
        COMMAND
            "${MEMORYCHECK_COMMAND}" ${MEMORYCHECK_COMMAND_OPTIONS} $<TARGET_FILE:${TARGET_NAME}>
        CONFIGURATIONS
            DEBUG)
set_tests_properties(test1 memcheck_${TARGET_NAME}
        PROPERTIES
            TIMEOUT 500) # long for valgrind.