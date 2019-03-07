cmake_minimum_required(VERSION 2.6)
project(mallocator)
add_executable(mallocator mallocator.c cmdline.c)

# gengetopt for command line parsing
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmdline.c" AND NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmdline.h")
    message("** Command line parser source files not found. Creating gengetopt rules ...")

    # Check if gengetopt is installed
    find_program(GENGETOPT gengetopt)
    if (NOT GENGETOPT)
        message(FATAL_ERROR "Unable to find gengetopt")
    endif (NOT GENGETOPT)

    add_custom_command (
        OUTPUT		${CMAKE_CURRENT_SOURCE_DIR}/cmdline.c ${CMAKE_CURRENT_SOURCE_DIR}/cmdline.h
        COMMAND		gengetopt -i ${CMAKE_CURRENT_SOURCE_DIR}/mallocator.ggo --output-dir ${CMAKE_CURRENT_SOURCE_DIR} --unamed-opts=VALUES
        DEPENDS 	${CMAKE_CURRENT_SOURCE_DIR}/mallocator.ggo
        COMMENT		"Generating getopt parser code (cmdline.*) ..."
        VERBATIM
        )
endif (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmdline.c" AND NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/cmdline.h")

