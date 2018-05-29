#include "BinaryTree.h"
#include "BST.h"
#include "AVL.h"

void test_BinaryTree() 
{
	BinaryTree<int>* pBT = new BinaryTree<int>();
	pBT->Insert(1);
	pBT->Insert(2);
	pBT->Insert(3);
	pBT->Insert(4);
	pBT->Insert(5);
	pBT->Insert(6);
	pBT->Insert(7);
	pBT->Insert(8);
	pBT->Insert(9);
	pBT->Insert(10);
	delete pBT;
}

void test_BST() 
{
	BST<int>* pBST = new BST<int>();
	pBST->Insert(1);
	delete pBST;
}

int main()
{
	test_BinaryTree();

	return 0;
}