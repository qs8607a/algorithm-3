//���֮����3.9 �ؽ�������
/*
	����һ�ö�����������ÿ���ڵ㶼��Ψһ���ַ�����ʾ������ṹ���£�
	struct NODE {
	NODE *pLeft;
	NODE *pRight;
	char chValue;
	};
	�����Ѿ�����ǰ���������������Ľ����ϣ��ͨ��һ���㷨�ؽ������
	���������Ķ������£�
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

 //��һ���ݹ�ʵ�֣��Լ�ʵ�֣�
void Rebulid(char *pPreOrder, char* pInOrder, int nTreeLen, NODE** pRoot) {
		
		if (nTreeLen == 0)
			return ;
		
		*pRoot = new NODE(pPreOrder[0]);
		cout<<setw(5)<<(*pRoot)->chValue;
		//Ѱ��������
		int nLeft = 0;
		for (int j =0; j< nTreeLen; j++ ){ 
			if (pPreOrder[j] == pInOrder[0]){
				break;
			}else nLeft++;
		}
	
		//cout<<nLeft<<endl;
		Rebulid(pPreOrder + 1 ,pInOrder, nLeft, &(*pRoot)->pLeft);
		
		//Ѱ��������
		Rebulid(pPreOrder+nLeft+1, pInOrder+nLeft+1, nTreeLen- nLeft - 1,&(*pRoot)->pRight); 

}

int main() {
	char pPreOrder[] = "abdcef";
	char pInOrder[] = "dbaecf";
	
	NODE *root = NULL;

	 //�ؽ�������
	Rebulid(pPreOrder, pInOrder,strlen(pPreOrder)+1 ,&root);
	cout<<endl;
	//cout<<root->chValue<<endl;
	//�������
	postOrder(root);

	getchar();
	getchar();

	return 0;

	
}