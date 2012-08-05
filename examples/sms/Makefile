# Makefile de ejemplo para C++
# 
# Creado: jue abr 15 15:34:19 ART 2004
#
# Copyleft 2004 - Leandro Lucarella, Bajo licencia GPL [http://www.gnu.org/]
#

# CONFIGURACION
################

# Nombre del ejecutable.
target = sms_test

# Extensión de los archivos a compilar (c para C, cpp o cc o cxx para C++).
extension = cpp


# CONFIGURACION "AVANZADA"
###########################

# Opciones para el compilador C.
CFLAGS = -Wall -ansi -pedantic

# Para que explote lo mas posible
#CFLAGS += -O3 -DNDEBUG

# Para valgrind o debug
CFLAGS += -DDEBUG -ggdb

# Opciones para el compilador C++.
CXXFLAGS = $(CFLAGS) -fno-inline

# Opciones del enlazador.
LDFLAGS=-lpthread -lGL -lGLU

# Usamos ccache para acelerar la cosa...
CC=gcc
CXX=g++

# Agrego flags y libs de SDL
CFLAGS += $(shell sdl-config --cflags)
CXXFLAGS += $(shell sdl-config --cflags)
LDFLAGS += $(shell sdl-config --libs)
LDFLAGS += -lSDL_image
LDFLAGS += -lpng

# Uso enlazador de c++ si es código no C.
ifeq ($(extension), c)
enlazador = $(CC)
else
enlazador = $(CXX)
endif

# Si no especifica archivos, tomo todos.
fuentes ?= $(wildcard *.$(extension))


# REGLAS
#########

.PHONY: all clean

all: $(target)

o_files = $(patsubst %.$(extension),%.o,$(fuentes))

$(target): $(o_files)
	@if [ -z "$(o_files)" ]; \
	then \
		echo "No hay archivos de entrada, recuerde que la extensión debe ser '.$(extension)'."; \
		false; \
	fi >&2
	$(enlazador) $(LDFLAGS) $(o_files) $(LOADLIBES) $(LDLIBS) -o $(target) /usr/lib/libm.a

clean:
	@$(RM) -fv *.o $(target)

