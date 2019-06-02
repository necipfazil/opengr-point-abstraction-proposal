all: test.out

test.out: test.cpp
	g++ test.cpp -std=c++11 -o test.out

run: test.out
	./test.out

clean:
	rm -f test.out