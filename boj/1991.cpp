#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct node{
	int left;
	int right;
};

struct node tree[30];
int N;
void preorder(int n)
{
	//if (N < n || tree[n].left == '.' || tree[n].right == '.')
	//	return;
	printf("%c",'A' + n);
	if(tree[n].left != -19)
		preorder(tree[n].left);
	if(tree[n].right != -19)
		preorder(tree[n].right);
}

void inorder(int n)
{
	if(tree[n].left != -19)
		inorder(tree[n].left);
	printf("%c", 'A' + n);
	if(tree[n].right != -19)
		inorder(tree[n].right);

}

void postorder(int n)
{
	if(tree[n].left != -19)
		postorder(tree[n].left);
	if(tree[n].right != -19)
		postorder(tree[n].right);
	printf("%c", 'A'+ n);
}
int main() {

	cin>>N;
	char l, r, value;
	for(int i=0; i<N; i++)
	{
		cin >>l >> r >> value;
			tree[l - 'A'].left = r - 'A';
			tree[l - 'A'].right = value - 'A';
	}
	preorder(0);
	cout<<endl;
	inorder(0);
	cout<<endl;
	postorder(0);
}
