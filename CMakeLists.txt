# Konfiguration des Buildsystems CMake
#-------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.14)
# Name des Projekts
project(Zettel07)

# Optionen
#-------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prüfe ob Heapspeicher gefunden wird,
# der nicht freigegeben wurde
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Füge selbsgeschriebene Includes hinzu
include_directories(Headerdatei)
# Füge externe Includes hinzu
#include_directories(external)
include_directories(/usr/include/python3.10)
include_directories(-lpython3.10)

# Baue Programme
#-------------------------------------------#
add_executable(BA main/Bachelorarbeit.cpp Funktionsdatei/Bachelorarbeit.cpp)

