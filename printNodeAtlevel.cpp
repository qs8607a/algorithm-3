/*
编程之美 3.10 分层遍历二叉树

问题1：给定一棵二叉树，要求按分层遍历该二叉树，即从上到下按层次访问该二叉树（每一层将单独输出一行），每一层要求访问的顺序为从左到右，并将节点依次编号，
打印出分层遍历的结果

问题2：写另外一个函数，打印二叉树中某层次的节点（从左到右），其中根节点为第0层，函数原型为int PrintNodeAAtLevel(Node　*root, int level),成功返回1，失败
则返回0；
*/
#include <algorithm>
#include <iostream>

using namespace std;

class node {
public:
	int value;
	node *pLeft;
	node *pRight;
	node(int v=0):value(v),pLeft(NULL),pRight(NULL){}

};

class BinaryTree {
public:
	BinaryTree() {root = NULL; }

	void createBinaryTree(int a[], int len);
	void insert(int val);
	void insert(node *par, node *child);
	int getDepth(node *root);
	void preOrder();
	void preOrder(node *root);
	void printBinaryTree();
	void RepPrintBinaryTree();
	void RepPrintBinaryTree(node *root, int depth);
	int PrintNodeAtLevel(int level);
	int PrintNodeAtLevel(node *root,int level);
private:
	node *root;
};

void BinaryTree::createBinaryTree(int a[], int len) {
	
	for (int i=0; i<len; i++)  insert(a[i]);
}

int BinaryTree::getDepth(node *root) {
	if (root == NULL)	return 0;
	else return 1+ max(getDepth(root->pLeft), getDepth(root->pRight));
}
void BinaryTree::insert(int val) {
	node* newnode = new node(val);
	
	if(root == NULL) root = newnode;
	else insert(root, newnode);
	
}
void BinaryTree::insert(node *par, node *child) {
	node*& next = par->value > child->value ? par->pLeft : par->pRight;
		if (next == NULL) next = child;
		else insert(next, child);
}
void BinaryTree::preOrder() {
	preOrder(root);
}

void BinaryTree::preOrder(node *root) {
	cout<<root->value<<"  ";

	if (root->pLeft != NULL){	preOrder(root->pLeft);	}
	if (root->pRight != NULL){	preOrder(root->pRight);	}
}

void BinaryTree::printBinaryTree() {
	int depth = getDepth(root);

	for (int i=1; i<=depth; i++){	PrintNodeAtLevel(i);	cout<<endl;	}
}

int BinaryTree::PrintNodeAtLevel(int level) {
	return PrintNodeAtLevel(root,level);
}
int BinaryTree::PrintNodeAtLevel(node *root, int level) {
	if (level ==1 ){
		if(root != NULL )  cout<<root->value<<"  ";
		return 1;
	}else {
		//cout<<"other"<<endl;
		return PrintNodeAtLevel(root->pLeft, level-1) + PrintNodeAtLevel(root->pRight, level-1);
	}
}
void BinaryTree::RepPrintBinaryTree() {
	int depth = getDepth(root);
	RepPrintBinaryTree(root, depth);
}
void BinaryTree::RepPrintBinaryTree(node *root,int depth) {
	if (root == NULL){
		return ;
	}else{
		RepPrintBinaryTree(root->pLeft,depth-1);
		RepPrintBinaryTree(root->pRight,depth-1);
		cout<<root->value<<" ";
		return ;
	}
}
int main() {
	int a[] = {5,3,7,2,6,4,8,1,9};

	BinaryTree tree;
	tree.createBinaryTree(a, 9);
	tree.preOrder();
	cout<<endl;
	tree.PrintNodeAtLevel(4);
	cout<<endl;
	tree.printBinaryTree();
	cout<<endl;
	//tree.RepPrintBinaryTree();

	getchar();
	getchar();
	return 0;

}
