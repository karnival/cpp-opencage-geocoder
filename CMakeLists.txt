cmake_minimum_required(VERSION 3.2.0)
project (cpp_opencage_geocoder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# By default, build CPR in a more lightweight way.
option(USE_SYSTEM_CURL "" ON)
option(BUILD_CPR_TESTS "" OFF)
add_subdirectory(cpr)

add_subdirectory(geocoder)
