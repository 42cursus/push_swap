# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 22:25:33 by abelov            #+#    #+#              #
#    Updated: 2024/06/09 22:25:34 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0048 NEW) # PROJECT_VERSION

project(push_swap
        VERSION 0.1.0
        HOMEPAGE_URL "https://github.com/42cursus/push_swap"
        LANGUAGES C)
set(CMAKE_C_STANDARD 99)

set(PARENT_PROJECT_NAME "${PROJECT_NAME}")

# **************************************************************************** #

set(FT_LIB_NAME ft)
set(FT_LIB_FILENAME libft.a)
set(FT_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/ft")

file(GLOB_RECURSE FT_LIB_HEADERS "${FT_LIB_DIR}/*.h")
file(GLOB_RECURSE FT_LIB_SOURCES "${FT_LIB_DIR}/*.c")

add_custom_target(${FT_LIB_NAME}_target ALL
        COMMAND make -C ${FT_LIB_DIR}
        BYPRODUCTS "${FT_LIB_DIR}/${FT_LIB_FILENAME}"
        SOURCES "${FT_LIB_HEADERS};${FT_LIB_SOURCES}"
        COMMENT "Building FT_LIB")

add_library(${FT_LIB_NAME} STATIC IMPORTED)
add_dependencies(${FT_LIB_NAME} "${FT_LIB_NAME}_target")
set_target_properties(${FT_LIB_NAME} PROPERTIES
        IMPORTED_LOCATION ${FT_LIB_DIR}/${FT_LIB_FILENAME} # Make sure to use absolute path here
        INTERFACE_COMPILE_DEFINITIONS ""
        INTERFACE_LINK_OPTIONS ""
        INTERFACE_SOURCES "${FT_LIB_HEADERS}"
        INTERFACE_INCLUDE_DIRECTORIES "${FT_LIB_DIR};${FT_LIB_DIR}/include")

# **************************************************************************** #

set(PSWP_LIB_NAME psort)
set(PSWP_LIB_FILENAME libpsort.a)
set(PSWP_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/psort")

file(GLOB_RECURSE PSWP_LIB_HEADERS "${PSWP_LIB_DIR}/*.h")
list(FILTER PSWP_LIB_HEADERS EXCLUDE REGEX "${PSWP_LIB_DIR}/test/*" )
file(GLOB_RECURSE PSWP_LIB_SOURCES "${PSWP_LIB_DIR}/*.c")
list(FILTER PSWP_LIB_SOURCES EXCLUDE REGEX "${PSWP_LIB_DIR}/test/*")

add_custom_target(${PSWP_LIB_NAME}_target ALL
        COMMAND make -C ${PSWP_LIB_DIR}
        BYPRODUCTS "${PSWP_LIB_DIR}/${PSWP_LIB_FILENAME}"
        SOURCES "${PSWP_LIB_HEADERS};${PSWP_LIB_SOURCES}"
        COMMENT "Building PSWP_LIB")

add_library(${PSWP_LIB_NAME} STATIC IMPORTED)
add_dependencies(${PSWP_LIB_NAME} "${PSWP_LIB_NAME}_target")
set_target_properties(${PSWP_LIB_NAME} PROPERTIES
        IMPORTED_LOCATION "${PSWP_LIB_DIR}/${PSWP_LIB_FILENAME}" # Make sure to use absolute path here
        INTERFACE_COMPILE_DEFINITIONS ""
        INTERFACE_SOURCES  "${PSWP_LIB_HEADERS};${PSWP_LIB_SOURCES}"
        INTERFACE_INCLUDE_DIRECTORIES "${PSWP_LIB_DIR};${PROJECT_SOURCE_DIR}/include;${PSWP_LIB_DIR}/include")

add_custom_target(fclean ALL)
add_custom_command(TARGET fclean POST_BUILD
        COMMAND make -C ${FT_LIB_DIR} fclean
        COMMAND make -C ${PSWP_LIB_DIR} fclean)

# **************************************************************************** #

set(TARGET_NAME "${PROJECT_NAME}_exe")
set(TARGET_LIBRARIES ${FT_LIB_NAME} ${PSWP_LIB_NAME})

file(GLOB_RECURSE TARGET_HEADERS "${PROJECT_SOURCE_DIR}/src/push_swap/*.h")
file(GLOB_RECURSE TARGET_SOURCES "${PROJECT_SOURCE_DIR}/src/push_swap/*.c")

add_executable(${TARGET_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})
set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "push_swap")
target_compile_options(${TARGET_NAME} PRIVATE
        -Wno-error=parentheses
        -fno-omit-frame-pointer
        #        -fsanitize=address
        #        -fsanitize=leak
)
target_include_directories(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${TARGET_NAME} "${TARGET_LIBRARIES}")

# **************************************************************************** #

set(TARGET_NAME "checker_exe")
set(TARGET_LIBRARIES ${FT_LIB_NAME} ${PSWP_LIB_NAME})

file(GLOB_RECURSE TARGET_HEADERS "${PROJECT_SOURCE_DIR}/src/checker/*.h")
file(GLOB_RECURSE TARGET_SOURCES "${PROJECT_SOURCE_DIR}/src/checker/*.c")

add_executable(${TARGET_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})
set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "checker")
target_compile_options(${TARGET_NAME} PRIVATE
        -Wno-error=parentheses
        -fno-omit-frame-pointer
        #        -fsanitize=address
        #        -fsanitize=leak
)
target_include_directories(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(${TARGET_NAME} "${TARGET_LIBRARIES}")