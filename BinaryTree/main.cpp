#include "BinaryTree.h"
#include "BTreeNode.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<int> t;
	t.insert(5);
	t.inOrder();
	cout << endl;
	t.insert(7);
	t.inOrder();
	cout << endl;
	t.insert(6);
	t.inOrder();
	cout << endl;
	t.insert(1);
	t.inOrder();
	cout << endl;
	t.insert(2);
	t.inOrder();
	cout << endl;
	t.insert(3);
	t.inOrder();
	cout << endl;
	t.insert(4);
	t.inOrder();
	cout << endl;
	t.remove(4);
	t.inOrder();
	cout << endl;
	t.postOrder();
	cout << endl;
	t.preOrder();
	cout << endl;
	cout << t.maximumKey() << t.minimumKey();
	t.print();
	cout << endl;
	t.search(5);
	t.destory();
	return 0;
}