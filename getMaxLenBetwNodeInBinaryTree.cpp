/*	编程之美：3.8 求二叉树中节点的最大距离
		如果我们把二叉树看成一个图，父子节点之间的连线看成是双向的，我们姑且定义“距离”为两个节点之间边的个数
		写一个程序求一棵二叉树中相距最远的两个节点之间的距离。

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//实现方法一：采用动态规划，递归求解其最大每个节点的最大距离
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
		void FindMaxLen() ;   //递归算法
		int getMaxLen() const { return nMaxLen; }
private:
	int nMaxLen;
	TreeNode *pRoot;
	void findmaxLen(TreeNode *pRoot) ; 
};

//二叉树的形成
void BinaryTree::CreateBinaryTree(int tree[], int len) {
	for(int i=0; i<len; i++)  { insert(tree[i]); }
}
//插入算法
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

//递归算法
//缺点：1、算法加入了侵入式（intrusive）的资料nMaxLeft, nMaxRight
//		2、使用的一个专门的一个变量nMaxLen,每次使用要额外初始化。
//		3、逻辑比较复杂，也有许多NULL相关的条件测试。
void BinaryTree::FindMaxLen() {
	findmaxLen(pRoot);
}
void BinaryTree::findmaxLen(TreeNode *root) {
	//遍历到叶子节点，返回
	if (root == NULL)  return;
	
	//如果左子树为空，那么该节点的左边最长距离为0
	if (root->pLeft == NULL) root->nMaxLeft = 0;
	else findmaxLen(root->pLeft);
	if (root->pRight == NULL) root->nMaxRight = 0;
	else findmaxLen(root->pRight);

	//计算左子树最长节点距离
	if (root->pLeft != NULL){
		int nTempMax = 0;
		if (root->pLeft->nMaxLeft > root->pLeft->nMaxRight)  nTempMax = root->pLeft->nMaxLeft;
		else nTempMax = root->pLeft->nMaxRight;
		
		root->nMaxLeft = nTempMax +1;
	}

	//计算右子树最长节点距离
	if (root->pRight != NULL){
		int nTempMax = 0;
		if (root->pRight->nMaxLeft > root->pRight->nMaxRight)  nTempMax = root->pRight->nMaxLeft;
		else nTempMax = root->pRight->nMaxRight;

		root->nMaxRight = nTempMax +1;
	}

	//更新最长距离
	if (root->nMaxLeft + root->nMaxRight >nMaxLen){
		nMaxLen = root->nMaxLeft + root->nMaxRight;
	}
}

//实现方法二：来自于叶劲峰先生，不需要额外空间的简明算法
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
//插入算法
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
	cout<<"两节点最长距离为:"<<maxLen<<endl;

	TREE otherTree;
	otherTree.CreateTree(a, 10);
	RESULT  result = otherTree.GetMaxDistance();
	cout<<result.nMaxDepth<<","<<result.nMaxDistance<<endl;
	
	getchar();
	getchar();
	return 0;
}