.PHONY: clean

OPTIONS = -O3 -Wall

s: s.cpp
	g++ s.cpp -o s $(OPTIONS)

clean:
	rm s