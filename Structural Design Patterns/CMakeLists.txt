# CMakeList.txt : CMake project for SOLID Design Principles, include source and define
# project specific logic here.
#

file(GLOB CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp")
file(GLOB INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/*/includes")

foreach(CPP_FILE ${CPP_FILES})
    get_filename_component(EXEC_NAME ${CPP_FILE} NAME_WE)
    string(REPLACE " " "_" EXEC_NAME ${EXEC_NAME})
    add_executable(${EXEC_NAME} ${CPP_FILE})

    # Set C++ standard to C++20 if CMake version is greater than 3.12
    if (CMAKE_VERSION VERSION_GREATER 3.12)
        set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 20)
    endif()

    target_include_directories(${EXEC_NAME} PRIVATE ${INCLUDE_DIRS})

    if (${EXEC_NAME} MATCHES "_test$")
		target_link_libraries(${EXEC_NAME} gtest gtest_main)
        add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
	else()
		target_link_libraries(${EXEC_NAME} Boost::boost)
    endif()
endforeach()
