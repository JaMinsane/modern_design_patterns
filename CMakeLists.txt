# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
include(FetchContent)
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

# GoogleTest
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/34ad51b3dc4f922d8ab622491dd44fc2c39afee9.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include sub-projects.
add_subdirectory ("SOLID Design Principles")
add_subdirectory ("Creational Design Patterns")
add_subdirectory ("Structural Design Patterns")
add_subdirectory ("Pruebas")

