# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
# Do this to begin wtih so its easy to see what command flags are used.
# This can be done by removing the 'set' command and running make as 'make \VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Declare Build of mpags-cipher
add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/runCaesarCipher.cpp
    MPAGSCipher/processCommandLine.cpp
    )
    
target_include_directories(mpags-cipher
    PRIVATE MPAGSCipher
    )   

#our standard set of flags
set(CMAKE_CXX_FLATS "-Wall -Wextra -Werror -Wfatal_errors -Wshadow -pedantic")

set(CMAKE_CXX_STANDARD 11)

target_compile_features(mpags-cipher 
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )