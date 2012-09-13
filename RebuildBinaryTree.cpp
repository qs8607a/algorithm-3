//编程之美：3.9 重建二叉树
/*
	给定一棵二叉树，假设每个节点都用唯一的字符来表示，具体结构如下：
	struct NODE {
	NODE *pLeft;
	NODE *pRight;
	char chValue;
	};
	假设已经有了前序遍历和中序遍历的结果，希望通过一个算法重建这棵树
	给定函数的定义如下：
	void Rebulid(char *pPreOrder, char* pInOrder, int nTreeLen, NODE** pRoot) {}

*/
#include <iostream>
#include <iomanip>
#include <string>

#include <stdlib.h>

using namespace std;

struct NODE {
	NODE *pLeft;
	NODE *pRight;
	char chValue;
	NODE(char c):chValue(c){pLeft = pRight = NULL; };
};


void postOrder(NODE *pRoot) {
//	cout<<setw(5)<<pRoot->chValue;
	if (pRoot->pLeft != NULL){
		postOrder(pRoot->pLeft);
	}

	if (pRoot->pRight != NULL)	{
		postOrder(pRoot->pRight);
	}
	cout<<setw(5)<<pRoot->chValue;
}

 //法一：递归实现（自己实现）
void Rebulid(char *pPreOrder, char* pInOrder, int nTreeLen, NODE** pRoot) {
		
		if (nTreeLen == 0)
			return ;
		
		*pRoot = new NODE(pPreOrder[0]);
		cout<<setw(5)<<(*pRoot)->chValue;
		//寻找左子树
		int nLeft = 0;
		for (int j =0; j< nTreeLen; j++ ){ 
			if (pPreOrder[j] == pInOrder[0]){
				break;
			}else nLeft++;
		}
	
		//cout<<nLeft<<endl;
		Rebulid(pPreOrder + 1 ,pInOrder, nLeft, &(*pRoot)->pLeft);
		
		//寻找右子树
		Rebulid(pPreOrder+nLeft+1, pInOrder+nLeft+1, nTreeLen- nLeft - 1,&(*pRoot)->pRight); 

}

int main() {
	char pPreOrder[] = "abdcef";
	char pInOrder[] = "dbaecf";
	
	NODE *root = NULL;

	 //重建二叉树
	Rebulid(pPreOrder, pInOrder,strlen(pPreOrder)+1 ,&root);
	cout<<endl;
	//cout<<root->chValue<<endl;
	//后序遍历
	postOrder(root);

	getchar();
	getchar();

	return 0;

	
}