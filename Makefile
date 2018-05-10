#Basic variables:

CC = gcc
CFLAGS = -Wextra -Wall
LDFLAGS = -lm -lrt
# List of sources:
SOURCES = main.c
OBJECTS = $(SOURCES:.cpp=.o)

# Name of executable target:
EXECUTABLE = Rami_2048

#CFLAGS += `pkg-config --cflags mrpt-base`
LDFLAGS += `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0`


all: $(SOURCES) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm $(OBJECTS) $(EXECUTABLE)
