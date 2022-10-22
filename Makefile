CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

EXECUTABLE_NAME = PnixEngine

build: clean *.cpp *.hpp
	mkdir debug
	g++ $(CFLAGS) -o debug/$(EXECUTABLE_NAME) *.cpp $(LDFLAGS)

run: build
	./debug/$(EXECUTABLE_NAME)

.PHONY: test clean

test: build
	./$(EXECUTABLE_NAME)

clean:
	rm -rf debug

shader-compile:
	./compile.sh
