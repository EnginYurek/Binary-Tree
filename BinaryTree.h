// Yürek, Engin
// 040100524
// Programming Assignment 4


#include<string>
#include<iostream>
using namespace std;

//tree struct
struct binaryTree{

	string key;
	struct binaryTree *right;
	struct binaryTree *left;
};//end of struct binaaryTree

typedef struct binaryTree BT;

class BinaryTreeClass{

private:
	BT *root;
	int nodeCounter; //eklenecek olan düðümün kaçýncý düðüm olduðunu sayýyor
	
	int findLevel();	//eklenecek olan düðümün hangi levele ekleneceðini buluyor
	int getNodeCounter();
	
	void PrintInOrderPrivate(BT *node);
	void PrintPreorderPrivate(BT *node);
	void PrintPostorderPrivate(BT *node);

public:
	
	BinaryTreeClass();
	void addLeaf(string Data); 

	void PrintInOrder();
	void PrintPreorder();
	void PrintPostorder();

};//end of class BinaryTreeClass

