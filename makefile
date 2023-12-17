CC=g++

test:template/sulution.cpp
	$(CC) $^ -o build/tempTesta

%c:%/sulution.cpp
	$(CC) $^ -o build/$@