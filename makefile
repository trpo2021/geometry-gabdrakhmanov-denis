CFLAGS := -Wall -Wextra -Werror -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/geometry

SOURCES := $(wildcard src/geometry/*.cpp)
LIBSOURCES := $(wildcard src/libgeometry/*.cpp)

LIBOBJ := $(patsubst src/libgeometry/%.cpp, obj/src/libgeometry/%.o, $(LIBSOURCES))
LIB := obj/src/libgeometry/libgeometry.a

OBJ := $(patsubst src/geometry/%.cpp, obj/src/geometry/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(LIB) $(OBJ)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) -I src/libgeometry

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/libgeometry/%.o: src/libgeometry/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/libgeometry

obj/src/geometry/%.o: src/geometry/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c  $< -o $@ -I src/libgeometry

run: $(TARGET)
	./bin/geometry


clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	rm -rf bin/geometry

.PHONY: clean run all