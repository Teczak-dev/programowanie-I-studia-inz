#!/bin/bash

# Zatrzymuje działanie skryptu w przypadku błędu
set -e

# Nazwa pliku wykonywalnego
TARGET="./build/program"

# Jeśli jako pierwszy argument podano "debug"
if [ "$1" = "debug" ]; then
    echo "=== Budowanie i uruchamianie w trybie DEBUG (LLDB) ==="
    
    # Przechowaj pozostałe argumenty dla programu
    shift
    
    # Kompilacja projektu
    make all
    
    # Pod lldb nie możemy użyć potoku '| iconv', ponieważ popsułoby to sterowanie debuggerem.
    # Aby lldb działał poprawnie w Ghostty, musimy uruchomić sam program z poziomu lldb 
    # (znaki pod lldb mogą mieć krzaczki, ale sam debugger będzie działał stabilnie).
    lldb -- $TARGET "$@"
else
    echo "=== Budowanie i uruchamianie ==="
    
    # Kompilacja projektu
    make all
    
    # Uruchomienie programu z konwersją CP852 -> UTF-8 dla Ghostty
    $TARGET "$@" | iconv -f CP852 -t UTF-8
fi

