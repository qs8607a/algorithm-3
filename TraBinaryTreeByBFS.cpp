//���ù������������BFS���ķ������ж������İ���������νӣ����֮��3.10��
/*
	������ȱ�����������������������ö�����ʵ�ֵģ��Ӷ������ĵ�һ�㣨���ڵ㣩��ʼ�����϶���ס���������ͬһ���У����մ����ҵ�˳��Խڵ���һ����
	���մӸ��ڵ���Ҷ�ڵ㣬�����������������Ĵ�����ʶ������Ľڵ㣬�㷨��
	1����ʼ��һ�����У����Ѹ��ڵ�����
	2��������Ϊ�ǿ��ǣ�ѭ��ִ�в���3������5������ִ��6
	3��������ȡ��һ���ڵ㣬���ʸýڵ�
	4�����ýڵ��������Ϊ�ǿգ��򽫸ýڵ�������������
	5�����ýڵ��������Ϊ�ǿգ��򽫸ýڵ�������������
	6������
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
	cout<<"ǰ�������";
	tree.preOrder();
	cout<<endl;

	cout<<"��α�����";
	tree.BFS();
	cout<<endl;

	getchar();
	getchar();
	return 0;
}