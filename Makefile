.PHONY: clean

OPTIONS = -O3 -Wall

s: s.h s.cpp
	g++ s.cpp -o s $(OPTIONS)

clean:
	rm s