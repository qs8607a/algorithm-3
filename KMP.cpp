//�������۵���KMP�ַ�ƥ���㷨;
//kmp�ַ���ģʽƥ�䣺һ����һ���ַ����ж�λ��һ�����ĸ�Ч�㷨����ƥ���㷨��ʱ�临�Ӷ�ΪO��m*n��;kmpƥ���㷨,��ʱ�临�Ӷ�Ϊ;o(m+n);

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//��ƥ���㷨�� ������S��ĳ��λ��i��ʼ���Ӵ���ģʽ��T��Ƚϡ�����j=0��Ƚ�S[i+j]��T[j]������ȣ���������S�д�����iΪ��ʼλ��ƥ��ɹ��Ŀ����ԣ���������
//�Ƚϣ�j����1����ֱ����T�������һ���ַ����Ϊֹ������Ĵ�S������һ���ַ������¿�ʼ������һ�ֵ�ƥ�䣬������T��󻬶�һλ����i��1����j�˻���0�����¿�ʼ
//��һ�ֵ�ƥ��
int index_BF(char S[], char T[], int pos) {
	int i = pos, j = 0;
	
	while(S[i+j] != '\0' && T[j] != '\0') {
		if(S[i+j] == T[j]) j++;
		else { i++; j = 0; }
	}

	if(T[j] == '\0') {
		return i;
	}else 
		return -1;
}

//KMPƥ���㷨�ĺ����ǣ������Ѿ��õ��Ĳ���ƥ����Ϣ�����к����ƥ����̡�
void get_nextval(const char *T, int next[]) {
	//��ģʽ��T��next����ֵ����������next
	int j = 0, k = -1;
	next[0] = -1;

	while(T[j] != '\0') {
		if(k == -1 || T[j] == T[k]) {
			++j; ++k;
			if(T[j] != T[k]) next[j] = k;
			else next[j] = next[k];
		}
		else k = next[k];
	}

	cout<<" ��ʾ�õ���ģʽƥ��ֵ��"<<endl;
	copy(next, next+strlen(T), ostream_iterator<int>(cout, ","));
	cout<<endl;
}

int KMP(const char *text, const char* pattern) {
	if(!text || !pattern || pattern[0] == '\0'|| text[0] == '\0') 
		return -1;
	int len = strlen(pattern) + 1;
	int *next = new int[len];

	get_nextval(pattern, next);

	int index=0, i=0, j=0;

	while(text[i] != '\0' && pattern[j] != '\0') {
		if(text[i] == pattern[j]) { ++i; ++j; }
		else {
			index += j-next[j];
			if(next[j] != -1) j = next[j];
			else {  j = 0; ++i;}
		}
	}

	delete[] next;
	
	if(pattern[j] == '\0') return index;
	else return -1;
}

int main() {
	char *text = "abaabcababdbba";
	char *pattern = "ababd";

	int result = KMP(text,pattern);
	cout<<"ƥ�䣿��"<<result<<endl;
	getchar();
	getchar();

	return 0;
}