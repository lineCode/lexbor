cmake_minimum_required(VERSION 3.0)

project(test_lexbor_tag)

################
## Search and Includes
#########################
include_directories(".")

################
## Sources
#########################
file(GLOB_RECURSE TEST_LEXBOR_TAG_SOURCES "*.c")

################
## Create tests
#########################
EXECUTABLE_LIST("lexbor_tag_" "${TEST_LEXBOR_TAG_SOURCES}" ${TEST_UNIT_LIB_NAME} ${LEXBOR_LIB_NAME})
APPEND_TESTS("lexbor_tag_" "${TEST_LEXBOR_TAG_SOURCES}")
