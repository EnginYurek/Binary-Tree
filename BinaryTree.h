// Y�rek, Engin
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
	int nodeCounter; //eklenecek olan d���m�n ka��nc� d���m oldu�unu say�yor
	
	int findLevel();	//eklenecek olan d���m�n hangi levele eklenece�ini buluyor
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

