# Programowanie — laboratoria C++

Repozytorium zawiera rozwiązania z laboratoriów z programowania w języku C++.
Każdy projekt jest niezależnym podprojektem budowanym za pomocą [CMake](https://cmake.org/).
Możesz sklonować całe repozytorium albo skopiować tylko wybrany katalog
laboratorium — każdy projekt ma własną konfigurację i może być uruchamiany
niezależnie.

## Spis treści

- [Szybki start dla osoby kopiującej repozytorium](#szybki-start-dla-osoby-kopiującej-repozytorium)
- [Struktura repozytorium](#struktura-repozytorium)
- [Wymagania](#wymagania)
- [Uruchamianie w Visual Studio](#uruchamianie-w-visual-studio)
- [Uruchamianie na macOS z terminala](#uruchamianie-na-macos-z-terminala)
- [Praca z Neovim](#praca-z-neovim)
- [Tworzenie nowego laboratorium](#tworzenie-nowego-laboratorium)
- [Przydatne polecenia Git](#przydatne-polecenia-git)

## Szybki start dla osoby kopiującej repozytorium

Najprościej sklonować repozytorium, a następnie przejść do konkretnego
laboratorium:

```bash
git clone <adres-repozytorium>
cd programowanie/10/arkusz2
```

Jeśli repozytorium zostało pobrane jako archiwum ZIP, rozpakuj je i wykonuj
polecenia od katalogu głównego projektu. Nie kopiuj katalogu `build/` ani
plików `.idea/`, `.vscode/` i `.DS_Store` — są to pliki lokalne danego
komputera. Wystarczą pliki `CMakeLists.txt`, `run.sh` oraz katalogi `src/`
i `include/` (jeśli dany projekt go posiada).

Do skopiowania pojedynczego laboratorium wybierz cały jego katalog, np.
`10/arkusz2/`, zachowując jego strukturę. Nie uruchamiaj `CMakeLists.txt`
z katalogu głównego repozytorium — konfiguracja znajduje się wewnątrz
każdego laboratorium.

## Struktura repozytorium

```text
.
├── 10/
│   ├── arkusz1/
│   ├── arkusz2/
│   ├── arkusz3/
│   └── arkusz4/
├── Templates/
│   └── cpp_lab/          # szablon nowego laboratorium
├── .gitignore
└── README.md
```

Struktura pojedynczego projektu wygląda następująco:

```text
arkusz2/
├── CMakeLists.txt        # konfiguracja projektu CMake
├── run.sh                # budowanie i uruchamianie na macOS/Linux
├── include/              # pliki nagłówkowe (.h, .hpp)
├── src/                  # pliki źródłowe (.cpp)
└── build/                # pliki wygenerowane podczas budowania (nie są wersjonowane)
```

`CMakeLists.txt` wyszukuje pliki `.cpp` i `.h/.hpp`, tworzy program wykonywalny
`program` i korzysta ze standardu C++17. Katalogi `build/`, pliki wykonywalne
oraz pliki konfiguracyjne edytorów są lokalne i nie powinny być dodawane do
repozytorium.

## Wymagania

- CMake 3.14 lub nowszy,
- kompilator C++ obsługujący C++17,
- Git,
- opcjonalnie: Visual Studio, CLion albo Neovim z `clangd`.

## Uruchamianie w Visual Studio

Visual Studio 2022 potrafi otwierać projekty CMake bez pliku `.sln`.

1. Sklonuj repozytorium lub rozpakuj pobrane archiwum.
2. Otwórz w Visual Studio katalog wybranego projektu, np. `10/arkusz2`.
3. Wybierz konfigurację `Debug` albo `Release` oraz właściwy cel `program`.
4. Visual Studio automatycznie odczyta `CMakeLists.txt` i skonfiguruje projekt.
5. Uruchom program przyciskiem **Run** lub klawiszem `F5` (debugowanie) albo
   `Ctrl+F5` (uruchomienie bez debugera).

W systemie Windows może być potrzebne zainstalowanie workloadu **Desktop
development with C++** oraz komponentu **CMake tools for Windows**. Skrypt
`run.sh` jest przeznaczony głównie dla macOS/Linux i nie jest wymagany w Visual
Studio.

## Uruchamianie na macOS z terminala

Po zainstalowaniu narzędzi Apple możesz użyć kompilatora dostarczanego przez
Xcode Command Line Tools:

```bash
xcode-select --install
brew install cmake
```

Następnie przejdź do wybranego projektu. Poniższa ścieżka jest przykładem —
zamień `10/arkusz2` na katalog laboratorium, które chcesz uruchomić:

```bash
cd 10/arkusz2
chmod +x run.sh       # tylko przy pierwszym użyciu, jeśli trzeba
./run.sh              # konfiguracja, kompilacja i uruchomienie
./run.sh argument1    # przekazanie argumentu do programu
./run.sh debug        # kompilacja i uruchomienie pod LLDB
```

Skrypt utworzy katalog `build/`, jeśli nie istnieje, a program zapisze jako
`build/program`. To samo można wykonać ręcznie:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/program
```

## Praca z Neovim

Do wygodnej pracy z C++ warto mieć zainstalowane `neovim`, `cmake` i
`clangd`:

```bash
brew install neovim cmake llvm
```

Otwórz katalog projektu, a nie pojedynczy plik:

```bash
cd 10/arkusz2
nvim .
```

Po pierwszej konfiguracji CMake plik `build/compile_commands.json` dostarcza
`clangd` informację o opcjach kompilacji, ścieżkach i standardzie języka.
Jeżeli konfiguracja Neovim wymaga pliku w katalogu głównym projektu, można
utworzyć dowiązanie:

```bash
ln -sf build/compile_commands.json compile_commands.json
```

Wtyczka LSP w Neovim powinna uruchamiać `clangd` dla plików `.cpp` i `.hpp`.
Dzięki temu dostępne są między innymi podpowiedzi, przechodzenie do definicji,
diagnostyka oraz formatowanie kodu. Po dodaniu nowych plików lub zmianie
`CMakeLists.txt` ponownie uruchom:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

## Tworzenie nowego laboratorium

Można skopiować gotowy szablon:

```bash
./Templates/cpp_lab/new-lab.sh ../Lab5
cd ../Lab5
./run.sh
```

Szablon zawiera `CMakeLists.txt`, `run.sh` i katalog `src/` z plikiem
`main.cpp`. Skrypt działa niezależnie od lokalizacji, w której sklonowano
repozytorium, i tworzy katalog docelowy, jeśli jeszcze nie istnieje.

## Przydatne polecenia Git

```bash
git status
git add 10/arkusz2
git commit -m "Opis zmian"
git push
```
