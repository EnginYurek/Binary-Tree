// Yürek, Engin
// 040100524
// Programming Assignment 4


#include<string>
#include<iostream>
#include<fstream>
#include"BinaryTree.h"
using namespace std;


BinaryTreeClass::BinaryTreeClass(){
	root = NULL;
	nodeCounter = 0;
}//end of constructor



//insert nodes
void BinaryTreeClass::addLeaf(string Key){
	//new node creation																0							if ý add the node with nodeCounter 12,
	BT *newNode = new BT();									//				   1		   2					findlevel=4
	newNode->key = Key;										//				3    4      5     6					mostRight = 14   
	newNode->left = NULL;									//		      7  8  9 10  11 12 13 14				mostLeft=7
	newNode->right = NULL;									//													if nodeCounter is higher than (14+7)/2=10.5
															//													than temp will go to the right child of root
	BT *temp;												//													now mostRight = ceil(10.5) and leftMost =14
	BT *tempPrev; //will come 1 node after the temp
	temp = root;
	tempPrev = root;
	double a = findLevel(); 
	double mostRight=pow(2,a)-2;  //node that located at most right of level in tree or subtree
	double mostLeft=pow(2,a-1)-1; //node that located at most left of level in tree or subtree

	if (root == NULL){			//create root node
		root = newNode;
	}
	else
	{	
		while (temp!=NULL)
		{
			if (nodeCounter < (mostLeft + mostRight) / 2){   //if nodeCounter samller than middle go left else go right
				tempPrev = temp;
				temp = temp->left;
				mostRight = floor((mostLeft + mostRight) / 2);  //mostLeft is still same but mostRight is equal to most right of the subtree
			}//end of inner if 
			else
			{
				tempPrev = temp;
				temp = temp->right;
				mostLeft = ceil((mostRight + mostLeft) / 2);
			}//end of inner else
		}//end of while
		if (tempPrev->left == NULL)  //placing the newNode
			tempPrev->left = newNode;
		else
			tempPrev->right = newNode;
	}//end of very first else
		nodeCounter++;
	}//end of method addLeaf



int BinaryTreeClass::findLevel(){  //calculates the level that of the node that will be inserted
	BT*  depthCal = root;
	int leftDepthCounter =0;
	int rightDepthCounter = 0;

	while (depthCal != NULL){   //calculates the depth from left side
		leftDepthCounter++;
		depthCal = depthCal->left;
	}//end of while

	depthCal = root;
	while (depthCal != NULL){  //calculates the depth from right side
		rightDepthCounter++;
		depthCal = depthCal->right;
	}//end of while

	if (leftDepthCounter >rightDepthCounter ) //küçük olma ihtimali yok 
		return leftDepthCounter;
	else			//if depth of the leftside and right side is equal than newNode will be added to new level
		return leftDepthCounter + 1;
	
}//end of method findLevel



void BinaryTreeClass::PrintInOrder(){
	PrintInOrderPrivate(root);
}//end of method PrintInOrder


void BinaryTreeClass::PrintInOrderPrivate(BT *node){
	
	ofstream inorder;
	inorder.open("output1.txt", fstream::out | fstream::app);  //creates output file
	
	if (root != NULL){
		if (node->left != NULL){
			PrintInOrderPrivate(node->left);		
		}//end of the first inner if
		inorder << node->key << " ";		//writes to the file
		inorder.close();
		cout << node->key << " ";			//prints to the screen
		
		if (node->right != NULL){
			PrintInOrderPrivate(node->right);
		}//end of second inner if
		
	}//end of outer if
	else
	{
		cout << "the tree is empty\n";
	}//end of else
	
}//end of method PrintOrderPrivate



void BinaryTreeClass::PrintPreorder(){
	PrintPreorderPrivate(root);
}//end of method PrintPreorder


void BinaryTreeClass::PrintPreorderPrivate(BT *node){

	ofstream preorder;
	preorder.open("output2.txt", fstream::out | fstream::app);  //creates output2.txt 

	if (root != NULL){
		cout << node->key << " ";				//prints to the screen
		preorder << node->key << " ";			//writes to the file
		preorder.close();
		if (node->left != NULL){
			PrintPreorderPrivate(node->left);
		}//end of first inner if
		
		if (node->right != NULL){
			PrintPreorderPrivate(node->right);
		}//end of second inner if

	}//end of outher if
	else
	{
		cout << "the tree is empty\n";
	}//end of else
}//end of method PrintPreorderPrivate


void BinaryTreeClass::PrintPostorder(){

	PrintPostorderPrivate(root);
}//end of PrintPostorder

void BinaryTreeClass::PrintPostorderPrivate(BT *node){
	ofstream postorder;
	postorder.open("output3.txt", fstream::out | fstream::app);  //creates output3.txt file
	
	if (root != NULL){
		if (node->left != NULL){
			PrintPostorderPrivate(node->left);
		}//end of first inner if

		if (node->right != NULL){
			PrintPostorderPrivate(node->right);
		}//end of second inner if

		cout << node->key << " ";
		postorder << node->key << " ";
		postorder.close();
	}//end of outer if
	else
	{
		cout << "the tree is empty\n";
	}//end of else
}//enf of method PrintPostorderPrivate


int BinaryTreeClass::getNodeCounter(){
	return nodeCounter;
}//end of getNodeCounter
