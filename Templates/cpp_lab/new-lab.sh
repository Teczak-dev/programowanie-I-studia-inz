#!/bin/bash

# Zatrzymuje skrypt w razie wystąpienia błędu
set -e

# Sprawdzenie czy podano ścieżkę do nowego projektu jako argument
if [ -z "$1" ]; then
    echo "Błąd: Nie podano ścieżki docelowej!"
    echo "Użycie: $0 <ścieżka_do_nowego_projektu>"
    echo "Przykład: $0 ~/Dane/Programowanie/studiaInzSem1/programowanie/Lab3"
    exit 1
fi

TARGET_DIR="$1"
TEMPLATE_DIR="/Users/mikolajsobczak/Dane/Programowanie/studiaInzSem1/programowanie/Templates/cpp_lab"

echo "=== Tworzenie nowego projektu laboratorium ==="
echo "Kopiowanie szablonu z: $TEMPLATE_DIR"
echo "Do katalogu docelowego: $TARGET_DIR"

# Utworzenie katalogu docelowego, jeśli jeszcze nie istnieje
mkdir -p "$TARGET_DIR"

# Kopiowanie plików szablonu
cp "$TEMPLATE_DIR/CMakeLists.txt" "$TARGET_DIR/"
cp "$TEMPLATE_DIR/run.sh" "$TARGET_DIR/"
cp -r "$TEMPLATE_DIR/src" "$TARGET_DIR/"

# Nadanie praw wykonywalności dla skryptu run.sh w nowym projekcie
chmod +x "$TARGET_DIR/run.sh"

echo "=== Sukces! Projekt został przygotowany. ==="
echo "Przejdź do katalogu: cd \"$TARGET_DIR\""
