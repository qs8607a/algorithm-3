//这是讨论的是KMP字符匹配算法;
//kmp字符串模式匹配：一种在一个字符串中定位另一个串的高效算法。简单匹配算法的时间复杂度为O（m*n）;kmp匹配算法,其时间复杂度为;o(m+n);

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

//简单匹配算法， 将主串S中某个位置i起始的子串和模式串T相比较。即从j=0起比较S[i+j]与T[j]，若相等，则在主串S中存在以i为起始位置匹配成功的可能性，继续往后
//比较（j逐步增1），直至与T串中最后一个字符相等为止，否则改从S串的下一个字符起重新开始进行下一轮的匹配，即将串T向后滑动一位，即i增1，而j退回至0，重新开始
//新一轮的匹配
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

//KMP匹配算法的核心是：利用已经得到的部分匹配信息来进行后面的匹配过程。
void get_nextval(const char *T, int next[]) {
	//求模式串T的next函数值并存入数组next
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

	cout<<" 显示得到的模式匹配值："<<endl;
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
	cout<<"匹配？："<<result<<endl;
	getchar();
	getchar();

	return 0;
}