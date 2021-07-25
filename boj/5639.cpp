#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

node *tree;


node *insert(node *tree, int data)
{
	if (tree == NULL)
	{
		tree = new node();
		tree->data = data;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (data < tree->data)
	{
		if (tree->left)
			insert(tree->left, data);
		else{
			node *newNode = new node();
			newNode -> data = data;
			newNode -> left = NULL;
			newNode -> right = NULL;
			tree->left = newNode;
		}
	}
	else if (data > tree->data)
	{
		if (tree->right)
			insert(tree->right, data);
		else{
			node *newNode = new node();
			newNode -> data = data;
			newNode -> left = NULL;
			newNode -> right = NULL;
			tree->right = newNode;
		}
	}
	return tree;
}

void postorder(node *tree)
{
	if (tree==NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout<<tree->data<<endl;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	tree = NULL;
	int data;
	while (cin>>data)
	{
		if(data == EOF) break;
		tree = insert(tree, data);
	}
	postorder(tree);
}
