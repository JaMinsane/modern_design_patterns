# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("modern_design_patterns")

# Boost
set(BOOST_ROOT "E:/dev/cpp/libraries/boost_1_85_0")
find_package(Boost 1.85 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Include sub-projects.
add_subdirectory ("SOLID Design Principles")
