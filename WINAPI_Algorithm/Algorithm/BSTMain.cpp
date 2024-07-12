#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);

	bst.PrintTree(bst._root);

	auto searchNode = bst.Search(bst._root, 30);
	if (searchNode != nullptr)
	{
		cout << "�ش� ��尡 �ֽ��ϴ�." << endl;
		cout << searchNode->key << endl;
	}
	else
		cout << "�ش� ��尡 �����ϴ�." << endl;

	auto minNode = bst.Min(bst._root);
	cout << minNode->key << endl;

	auto maxNode = bst.Max(bst._root);
	cout << maxNode->key << endl;

	auto priviousNode = bst.Previous(bst._root);
	cout << priviousNode->key << endl;

	return 0;
}