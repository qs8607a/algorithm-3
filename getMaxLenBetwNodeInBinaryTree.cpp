/*	���֮����3.8 ��������нڵ��������
		������ǰѶ���������һ��ͼ�����ӽڵ�֮������߿�����˫��ģ����ǹ��Ҷ��塰���롱Ϊ�����ڵ�֮��ߵĸ���
		дһ��������һ�ö������������Զ�������ڵ�֮��ľ��롣

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//ʵ�ַ���һ�����ö�̬�滮���ݹ���������ÿ���ڵ��������
class TreeNode {
public:
	int data;
	int nMaxLeft;
	int nMaxRight;
	TreeNode *pLeft;
	TreeNode *pRight;
	TreeNode(int d = -1):data(d),nMaxLeft(0),nMaxRight(0),pLeft(NULL),pRight(NULL) {}

};
class BinaryTree {
	public:
		BinaryTree():nMaxLen(0),pRoot(NULL) {}

		void CreateBinaryTree(int tree[], int len);
		void insert(int val);
		void FindMaxLen() ;   //�ݹ��㷨
		int getMaxLen() const { return nMaxLen; }
private:
	int nMaxLen;
	TreeNode *pRoot;
	void findmaxLen(TreeNode *pRoot) ; 
};

//���������γ�
void BinaryTree::CreateBinaryTree(int tree[], int len) {
	for(int i=0; i<len; i++)  { insert(tree[i]); }
}
//�����㷨
void BinaryTree::insert(int val) {	
	if(pRoot == NULL) {
		pRoot = new TreeNode(val);;
		return ;
	}

	TreeNode *p = pRoot;
	TreeNode *q = new TreeNode(val);

	while (p != NULL){
		if (val < p->data ){
			if(p->pLeft == NULL) { p->pLeft = q; break; }
			else  { p = p->pLeft; } 
		}else {
			if(p->pRight == NULL){   p->pRight = q; break; }
			else  { p = p->pRight; }
		}
	}
}

//�ݹ��㷨
//ȱ�㣺1���㷨����������ʽ��intrusive��������nMaxLeft, nMaxRight
//		2��ʹ�õ�һ��ר�ŵ�һ������nMaxLen,ÿ��ʹ��Ҫ�����ʼ����
//		3���߼��Ƚϸ��ӣ�Ҳ�����NULL��ص��������ԡ�
void BinaryTree::FindMaxLen() {
	findmaxLen(pRoot);
}
void BinaryTree::findmaxLen(TreeNode *root) {
	//������Ҷ�ӽڵ㣬����
	if (root == NULL)  return;
	
	//���������Ϊ�գ���ô�ýڵ����������Ϊ0
	if (root->pLeft == NULL) root->nMaxLeft = 0;
	else findmaxLen(root->pLeft);
	if (root->pRight == NULL) root->nMaxRight = 0;
	else findmaxLen(root->pRight);

	//������������ڵ����
	if (root->pLeft != NULL){
		int nTempMax = 0;
		if (root->pLeft->nMaxLeft > root->pLeft->nMaxRight)  nTempMax = root->pLeft->nMaxLeft;
		else nTempMax = root->pLeft->nMaxRight;
		
		root->nMaxLeft = nTempMax +1;
	}

	//������������ڵ����
	if (root->pRight != NULL){
		int nTempMax = 0;
		if (root->pRight->nMaxLeft > root->pRight->nMaxRight)  nTempMax = root->pRight->nMaxLeft;
		else nTempMax = root->pRight->nMaxRight;

		root->nMaxRight = nTempMax +1;
	}

	//���������
	if (root->nMaxLeft + root->nMaxRight >nMaxLen){
		nMaxLen = root->nMaxLeft + root->nMaxRight;
	}
}

//ʵ�ַ�������������Ҷ��������������Ҫ����ռ�ļ����㷨
class NODE {
public:
	NODE *pLeft;
	NODE *pRight;
	int data;
	NODE(int d = -1):pLeft(NULL),pRight(NULL),data(d) {}
};

struct RESULT {
	int nMaxDistance;
	int nMaxDepth;
};

class TREE {
public:
	TREE():pRoot(NULL) {}

	void CreateTree(int tree[], int len);
	void insert(int val);
	RESULT GetMaxDistance();
private:
	NODE *pRoot;
	RESULT getmaxdistance(NODE *root);
};

void TREE::CreateTree(int tree[], int len) {
	for(int i=0; i<len; i++)  { insert(tree[i]); }
}
//�����㷨
void TREE::insert(int val) {	
	if(pRoot == NULL) {
		pRoot = new NODE(val);;
		return ;
	}

	NODE *p = pRoot;
	NODE *q = new NODE(val);

	while (p != NULL){
		if (val < p->data ){
			if(p->pLeft == NULL) { p->pLeft = q; break; }
			else  { p = p->pLeft; } 
		}else {
			if(p->pRight == NULL){   p->pRight = q; break; }
			else  { p = p->pRight; }
		}
	}
}
RESULT TREE::GetMaxDistance(){
	RESULT result= getmaxdistance(pRoot);
	return result;
}
RESULT TREE::getmaxdistance(NODE *root){
	if (!root){
        RESULT empty = { 0, -1 };   // trick: nMaxDepth is -1 and then caller will plus 1 to balance it as zero.
        return empty;
    }

    RESULT lhs = getmaxdistance(root->pLeft);
    RESULT rhs = getmaxdistance(root->pRight);

    RESULT result;
    result.nMaxDepth = max(lhs.nMaxDepth + 1, rhs.nMaxDepth + 1);
    result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), lhs.nMaxDepth + rhs.nMaxDepth + 2);
    return result;
}
int main() {
	int a[] = {5,7,3,9,8,2,1,10,6,0};
	BinaryTree tree;
	tree.CreateBinaryTree(a, 10);
	//cout<<sizeof(a)/sizeof(int)<<endl;
	tree.FindMaxLen();
	int maxLen = tree.getMaxLen();
	cout<<"���ڵ������Ϊ:"<<maxLen<<endl;

	TREE otherTree;
	otherTree.CreateTree(a, 10);
	RESULT  result = otherTree.GetMaxDistance();
	cout<<result.nMaxDepth<<","<<result.nMaxDistance<<endl;
	
	getchar();
	getchar();
	return 0;
}