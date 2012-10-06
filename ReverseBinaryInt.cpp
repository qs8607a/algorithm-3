//逆转一个整数的二进制表示


#include <iostream>

using namespace std;



//解法一
const int MAXN = 32;

unsigned int BitRev1(unsigned int input) {

	unsigned int ret, i;

	for (ret = i = 0; i<MAXN; i++, input = input>>1){
		ret = (ret <<1) | (input & 1);
	}
}

//解法二
/* 
	第一行代码为奇偶位相互交换；第二行以两位为一个单元，奇偶单元进行交换；
	第三行以四位为一单元，奇偶单元进行交换；第四行以八位为一个单元，奇偶单元进行交换；
	最后一行以十六位为一个单元，奇偶单元进行交换。
	至此，32反转完成，算法结束。
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


//解法三 基于解法二，做了一定优化

unsigned int rev(unsigned x) 
{ 
	x = (x & 0x55555555) << 1 | (x >> 1) & 0x55555555 ; 
	x = (x & 0x33333333) << 2 | (x >> 2) & 0x33333333 ; 
	x = (x & 0x0f0f0f0f) << 4 | (x >> 4) & 0x0f0f0f0f ; 
	x = (x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24) ; 
	return x ; 
}