all: compile run

compile:
	g++ -I ./include/ -o ./lib/IntNode.o -c ./src/IntNode.cpp
	g++ -I ./include/ -o ./lib/IntAVLTree.o -c ./src/IntAVLTree.cpp
	g++ -I ./include/ -o ./lib/ExtNode.o -c ./src/ExtNode.cpp
	g++ -I ./include/ -o ./lib/ExtAVLTree.o -c ./src/ExtAVLTree.cpp
	g++ -I ./include/ -o ./bin/program ./lib/IntNode.o ./lib/IntAVLTree.o ./lib/ExtNode.o ./lib/ExtAVLTree.o ./src/program.cpp
run:
	./bin/program