main: main.o ArrayStack.o List.o LinkStack.o Queue.o BinaryTreeNode.o BinaryTree.o
	g++ -o main main.o ArrayStack.o 

main.o: main.cpp
	g++ -o main.o -c main.cpp

ArrayStack.o: ArrayStack.cpp
	g++ -o ArrayStack.o -c ArrayStack.cpp
List.o: List.cpp
	g++ -o List.o -c List.cpp
LinkStack.o: LinkStack.cpp
	g++ -o LinkStack.o -c LinkStack.cpp
Queue.o: Queue.cpp
	g++ -o Queue.o -c Queue.cpp
BinaryTreeNode.o:BinaryTreeNode.cpp
	g++ -o BinaryTreeNode.o -c BinaryTreeNode.cpp
BinaryTree.o: BinaryTree.cpp
	g++ -o BinaryTree.o -c BinaryTree.cpp
clean:
	rm *.o main
