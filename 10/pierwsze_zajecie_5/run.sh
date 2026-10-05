#!/bin/bash

# Zatrzymuje działanie skryptu w przypadku błędu
set -e

# Jeśli jako pierwszy argument podano "debug"
if [ "$1" = "debug" ]; then
    echo "=== Budowanie i uruchamianie w trybie DEBUG (LLDB) ==="
    
    # Przechowaj pozostałe argumenty dla programu
    shift
    
    # Kompilacja projektu
    make all
    
    # Uruchomienie pod debuggerem LLDB
    lldb -- ./build/program "$@"
else
    echo "=== Budowanie i uruchamianie ==="
    
    # Kompilacja projektu
    make all
    
    # Uruchomienie programu ze wszystkimi przekazanymi argumentami
    ./build/program "$@"
fi
