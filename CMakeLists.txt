cmake_minimum_required(VERSION 3.12.0)
project(is_even_project VERSION 0.1.0)


include(CTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(is_even_library_test
      ${CMAKE_SOURCE_DIR}/tests/is_even_test.cpp
      )
add_test(is_even_library_test is_even_library_test COMMAND is_even_library_test)
target_include_directories(is_even_library_test PRIVATE ${CMAKE_SOURCE_DIR}/src)


find_package(doctest CONFIG REQUIRED)
target_link_libraries(is_even_library_test PRIVATE doctest::doctest)


set(dkasses_compile_options_msvc
    /MP /permissive- /W4 /w14640 /w14242 /w14254 /w14263 /w14265 /w14287 
    /we4289 /w14296 /w14311 /w14545 /w14546 /w14547 /w14549 /w14555 /w14619 
    /w14640 /w14826 /w14905 /w14906 /w14928
    )
set(dkasses_compile_options_else
    -Wall -Wextra -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast
    -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion
    -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond
    -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast
    -Wdouble-promotion -Wformat=2
    )


if(MSVC)
  target_compile_options(is_even_library_test PRIVATE ${dkasses_compile_options_msvc})
else()
  target_compile_options(is_even_library_test PRIVATE ${dkasses_compile_options_else})
endif()
