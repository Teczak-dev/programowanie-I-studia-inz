cmake_minimum_required(VERSION 3.14)
project(ProjektLaboratorium CXX)

# Standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dodanie katalogu z plikami nagłówkowymi
include_directories(. include src)

# Pobranie plików .cpp oraz .hpp z automatycznym odświeżaniem w razie dodania nowych
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.h" "*.hpp")

# Filtrowanie: wykluczenie plików wygenerowanych w katalogu build/
set(SOURCES "")
foreach(source_file ${ALL_SOURCES})
    if(NOT source_file MATCHES "${CMAKE_BINARY_DIR}")
        list(APPEND SOURCES ${source_file})
    endif()
endforeach()

# Utworzenie pliku wykonywalnego
add_executable(program ${SOURCES} ${HEADERS})

# Zapis pliku wykonywalnego w katalogu build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
