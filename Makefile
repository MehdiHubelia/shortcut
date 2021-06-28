.PHONY: clean

OPTIONS = -O3 -std=c++17

s: s.h s.cpp
	g++ s.cpp -o s $(OPTIONS)

clean:
	rm s