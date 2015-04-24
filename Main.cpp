// Yürek, Engin
// 040100524
// Programming Assignment 4


#include<iostream>
#include<string>
#include<fstream>
#include"BinaryTree.h"

using namespace std;

int main(){

	int print;
	string letter;
	BinaryTreeClass tree;
	ifstream infile;	// creates the input file object
	infile.open("example-input.txt");	//opens our input file


	cout<< "input text: ";
	while (infile.good()) // To get all the lines until the end
	{
		getline(infile, letter);
		tree.addLeaf(letter);
		cout<<letter << " ";
	}

	cout << "\n\nPress 1 to print inorder\n      2 to print preorder \n      3 to print postorder.\n";
	cin >> print;

	switch (print){
	case 1: 
		cout << "\n\nPrint Inorder: " << endl;
		tree.PrintInOrder();
		break;
	case 2:
		cout << "\n\nPrint Preorder: " << endl;
		tree.PrintPreorder();
		break;
	case 3:
		cout << "\n\nPrint Postorder " << endl;
		tree.PrintPostorder();
		cout << endl;
		break;
	default:
		cout << "\nYou pressed wrong number.\n";
			break;
	}
	

	getchar();
	getchar();
	return 0;
}