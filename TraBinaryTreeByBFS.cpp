//采用广度优先搜索（BFS）的方法进行二叉树的按层遍历（衔接：编程之美3.10）
/*
	广度优先遍历二叉树（层序遍历）是用队列来实现的，从二叉树的第一层（根节点）开始，自上而下住层遍历；在同一层中，按照从左到右的顺序对节点逐一访问
	按照从根节点至叶节点，从左子树至右子树的次序访问二叉树的节点，算法：
	1、初始化一个队列，并把根节点入列
	2、当队列为非空是，循环执行步骤3到步骤5，否则执行6
	3、出队列取得一个节点，访问该节点
	4、若该节点的左子树为非空，则将该节点的左子树入队列
	5、若该节点的右子树为非空，则将该节点的右子树入队列
	6、结束
*/

#include <iomanip>
#include <iostream>
#include <deque>

using namespace std;

class node {
public:
	int data;
	node *pLeft;
	node *pRight;
	node(int d = 0):data(d),pLeft(NULL),pRight(NULL){}
};
 class BinaryTree {
 public:
	 BinaryTree():root(NULL){}

	 void createBinaryTree(int a[], int len) ;
	 void insert(node *newnode, node *root);
	 void insert(int val);

	 void preOrder();
	 void preOrder(node *root);

	 void BFS();
 private:
	 node *root;
 };

void BinaryTree::createBinaryTree(int a[], int len) {
	for (int i=0; i<len; i++)   insert(a[i]);  
}

void BinaryTree::insert(int val) {
	node *newnode = new node(val); 

	if (root == NULL) root= newnode;
	else insert(newnode, root);
}

void BinaryTree::insert(node *newnode, node *root) {
	node*& next = (newnode->data < root->data)?root->pLeft:root->pRight;
	
	if(next == NULL) next = newnode;
	else insert(newnode, next);
}

void BinaryTree::preOrder() {
	preOrder(root);
}

void BinaryTree::preOrder(node *root) {
	
	cout<<setw(4)<<root->data ;
	if (root->pLeft != NULL) preOrder(root->pLeft);
	
	 if(root->pRight != NULL) preOrder(root->pRight);
}

void	BinaryTree::BFS() {

	deque<node*> Queue;
	Queue.push_back(root);
	while (!Queue.empty()) {
		node *p = Queue.front();
		cout<<setw(4)<<p->data;
		Queue.pop_front();
		if(p->pLeft != NULL) Queue.push_back(p->pLeft);
		if (p->pRight != NULL) Queue.push_back(p->pRight);
	}
}

int main() {
	int a[] = {6,9,4,7,3,5,1,2};

	BinaryTree tree;
	tree.createBinaryTree(a, 8);
	cout<<"前序遍历：";
	tree.preOrder();
	cout<<endl;

	cout<<"层次遍历：";
	tree.BFS();
	cout<<endl;

	getchar();
	getchar();
	return 0;
}