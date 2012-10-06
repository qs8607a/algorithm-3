//��תһ�������Ķ����Ʊ�ʾ


#include <iostream>

using namespace std;



//�ⷨһ
const int MAXN = 32;

unsigned int BitRev1(unsigned int input) {

	unsigned int ret, i;

	for (ret = i = 0; i<MAXN; i++, input = input>>1){
		ret = (ret <<1) | (input & 1);
	}
}

//�ⷨ��
/* 
	��һ�д���Ϊ��żλ�໥�������ڶ�������λΪһ����Ԫ����ż��Ԫ���н�����
	����������λΪһ��Ԫ����ż��Ԫ���н������������԰�λΪһ����Ԫ����ż��Ԫ���н�����
	���һ����ʮ��λΪһ����Ԫ����ż��Ԫ���н�����
	���ˣ�32��ת��ɣ��㷨������
*/

unsigned int bit_reverse(unsigned int n)
{
	n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xaaaaaaaa);
	n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xcccccccc);
	n = ((n >> 4) & 0x0f0f0f0f) | ((n << 4) & 0xf0f0f0f0);
	n = ((n >> 8) & 0x00ff00ff) | ((n << 8) & 0xff00ff00);
	n = ((n >> 16) & 0x0000ffff) | ((n << 16) & 0xffff0000);

	return n;
}


//�ⷨ�� ���ڽⷨ��������һ���Ż�

unsigned int rev(unsigned x) 
{ 
	x = (x & 0x55555555) << 1 | (x >> 1) & 0x55555555 ; 
	x = (x & 0x33333333) << 2 | (x >> 2) & 0x33333333 ; 
	x = (x & 0x0f0f0f0f) << 4 | (x >> 4) & 0x0f0f0f0f ; 
	x = (x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24) ; 
	return x ; 
}