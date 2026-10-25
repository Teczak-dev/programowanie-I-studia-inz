#!/bin/bash

# Zatrzymuje działanie skryptu w przypadku błędu
set -e

BUILD_DIR="build"

# Jeśli katalog build nie istnieje LUB nie ma w nim pliku CMakeCache.txt, skonfiguruj CMake
if [ ! -d "$BUILD_DIR" ] || [ ! -f "$BUILD_DIR/CMakeCache.txt" ]; then
    echo "=== Konfiguracja CMake ==="
    cmake -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Debug
fi

# Jeśli jako pierwszy argument podano "debug"
if [ "$1" = "debug" ]; then
    echo "=== Budowanie i uruchamianie w trybie DEBUG (LLDB) ==="
    shift
    
    # Kompilacja projektu
    cmake --build $BUILD_DIR
    
    # Uruchomienie pod debuggerem LLDB
    lldb -- ./$BUILD_DIR/program "$@"
else
    echo "=== Budowanie i uruchamianie ==="
    
    # Kompilacja projektu
    cmake --build $BUILD_DIR
    
    # Uruchomienie programu ze wszystkimi przekazanymi argumentami
    ./$BUILD_DIR/program "$@"
fi
