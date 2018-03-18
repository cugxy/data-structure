// Author£º		xiongw
// Date£º		2018-3-17
// filename:	main.cpp

#include <gtest\gtest.h>
#include "BinaryTree.h"
#include "BST.h"

TEST(BTNTest, HandleZeroInput)
{
	BinTreeNode<int> nodeNull;
	BinTreeNode<int> node1(1);
	BinTreeNode<int> node2(2);
	BinTreeNode<int> node3(3, &node1, &node2);
	//EXPECT_EQ(0, nodeNull.data);
	EXPECT_EQ(1, node1.data);
	EXPECT_TRUE(node1.pLeftChild == NULL);
	EXPECT_TRUE(node1.pRightChild == NULL);
	EXPECT_TRUE(node3.pLeftChild == &node1);
	EXPECT_TRUE(node3.pRightChild == &node2);
}

TEST(BINTreeTest, HandleZeroInput)
{
	BinaryTree<int> tree;
	EXPECT_TRUE(tree.IsEmpty());
	tree.Insert(1);
	EXPECT_TRUE(!tree.IsEmpty());
	tree.Insert(2);
	tree.Insert(0);
} 



int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}