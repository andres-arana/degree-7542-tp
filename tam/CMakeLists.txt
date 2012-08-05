# El nombre del proyecto es "TAM".
# CMake genera automaticamente una variable llamada TAM_SOURCE_DIR que puede 
# llamarse usando ${TAM_SOURCE_DIR} con la ruta del codigo.
# Lo mismo con ${TAM_BINARY_DIR} para binarios
project (TAM)

# Version requerida
cmake_minimum_required (VERSION 2.6)

# Flags de compilacion
add_definitions(
	-Wall 
	-Wnon-virtual-dtor 
	-pedantic 
	-pedantic-errors 
	-O3 
	-DNDEBUG 
	-std=c++98 
	-DTLOG)

# Le decimos donde poner los binarios de librerias y ejecutables.
# CMake admite instrucciones partidas en varias lineas.
SET (LIBRARY_OUTPUT_PATH ${TAM_BINARY_DIR}/bin 
	CACHE PATH "Directory for Libraries")
SET (EXECUTABLE_OUTPUT_PATH ${TAM_BINARY_DIR}/bin 
	CACHE PATH "Directory for Executables")

# Buscamos a Gtkmm.
# Ahora las variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES 
# contienen lo que necesitamos.
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
pkg_check_modules(CAIROMM cairomm-1.0)
pkg_check_modules(LIBGLADEMM libglademm-2.4)
pkg_check_modules(SIGCMM sigc++-2.0)

# Nos aseguramos que el compilador encuentra los archivos de include
# pertenecientes a la libreria common y a las de Gtkmm.
include_directories (
	${TAM_SOURCE_DIR}/src/common 
	${TAM_SOURCE_DIR}/src/game
	${TAM_SOURCE_DIR}/src/ui
	${GTKMM_INCLUDE_DIRS}
	${CAIROMM_INCLUDE_DIRS}
	${LIBGLADEMM_INCLUDE_DIRS}
	${SIGCMM_INCLUDE_DIRS}
)

# Nos aseguramos que el linker encuentra las librerias.
link_directories (
	${TAM_BINARY_DIR}/src/common
	${TAM_BINARY_DIR}/src/game
	${GTKMM_LIBRARY_DIRS}
	${CAIROMM_LIBRARY_DIRS}
	${LIBGLADEMM_LIBRARY_DIRS}
	$[SIGCMM_LIBRARY_DIRS}
)

# Decimos a CMake que haga recursion a los siguientes directorios
# en orden de aparicion.
add_subdirectory (src/common)
add_subdirectory (src/game)
add_subdirectory (src/server)  
add_subdirectory (src/client)
add_subdirectory (src/editor)
add_subdirectory (src/ui)
