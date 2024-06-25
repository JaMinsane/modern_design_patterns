# CMakeList.txt : CMake project for SOLID Design Principles, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget " Single Responsibility Principle.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# Add tests and install targets if needed.
target_link_libraries(CMakeTarget Boost::boost)
