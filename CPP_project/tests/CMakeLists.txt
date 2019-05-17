set(MODULE_NAME PikiFams)

include_directories("${CMAKE_SOURCE_DIR}/tests")
include_directories("${CMAKE_SOURCE_DIR}/src")

set(TEST_SOURCE
    combineTheBestStep_Tests.cpp
	Test_hd.h
	Tests_PikiFamsGameBot.cpp
	tests.cpp
    )

add_executable(${MODULE_NAME}_tests ${TEST_SOURCE})
target_link_libraries(${MODULE_NAME}_tests 
	PIKIFAMS_LIB 
	gtest 
	gmock_main)


add_test(NAME ${MODULE_NAME}_tests COMMAND ${MODULE_NAME}_tests)
