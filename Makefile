all: ./tmp/main.cpp ./build/logger.o
	g++ ./tmp/main.cpp ./build/logger.o -o ./tmp/sim

./build/logger.o: ./src/logger.cpp ./src/logger.hpp
	g++ -c ./src/logger.cpp -o ./build/logger.o
