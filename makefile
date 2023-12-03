CC=g++

%c:%/code.cpp
	$(CC) $^ -o build/$@