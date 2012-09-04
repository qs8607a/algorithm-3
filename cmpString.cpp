//编程之美 ：3.3
//计算字符串的相似度

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minValue(int num1, int num2, int num3) {
	return max(max(num1,num2), num3);
}

//原书代码
int calculateStringDistance(string strA, int pABegin, int pAEnd, string strB, int pBBegin, int pBEnd) {
	if(pABegin >pAEnd) {
		if(pBBegin >pBEnd)  return 0;
		else return pBEnd - pBBegin + 1;
	}

	if(pBBegin >pBEnd) {
		if(pABegin >pAEnd) return 0;
		else return pAEnd - pABegin + 1; 
	}

	if(strA[pABegin] == strB[pBBegin]) {
		return calculateStringDistance(strA, pABegin+1, pAEnd, strB, pBBegin+1, pBEnd);
	}else {
		int t1 = calculateStringDistance(strA, pABegin+1, pAEnd, strB, pBBegin+2, pBEnd);
		int t2 = calculateStringDistance(strA, pABegin+2, pAEnd, strB, pBBegin+1, pBEnd);
		int t3 = calculateStringDistance(strA, pABegin+2, pAEnd, strB, pBBegin+2, pBEnd);
		return minValue(t1, t2, t3) +1;
	}
}


//动态规划方法
int calculateStringDistance(string strA,string strB) {
	int lenA = strA.size() ;
	int	lenB = strB.size() ;

	int d[100][100] = {0};
	for(int i=0; i<lenA; i++)   d[i][0] = i;
	for(int j=0; j<lenB; j++)   d[0][j] = j;

	for(int i=1; i<=lenA; i++) {
		for(int j=1; j<=lenB; j++) {
			if(strA[i-1] == strB[j-1]) {
				d[i][j] = d[i-1][j-1];
			}else {
				int edIns = d[i][j-1] + 1;
				int edDel = d[i-1][j] + 1;
				int edRep = d[i-1][j-1] + 1;

				d[i][j] = minValue(edIns, edDel, edRep);
			}
		}
	}

	return d[lenA][lenB];


}
int main() {
	string str1 = "abcdefg";
	string str2 = "abcdef";

	int result1 = calculateStringDistance(str1, 0, str1.size()-1, str2, 0, str2.size()-1);
	cout<<result1<<endl;

	int result2 =calculateStringDistance(str1, str2);
	cout<<result2<<endl;

	getchar();
	getchar();
	return 0;
}