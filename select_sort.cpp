//this program was written by chenshuo. 
//address:https://github.com/chenshuo/recipes/blob/master/algorithm/sel//ect.cc
// and this program use three means by STL algorithm to get the Nth bigger number
// in a sequence.
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include <assert.h>

using namespace std;

vector<int> selectBySorting(const vector<int>& input, int k1, int k2) {
	assert(0 <= k1 && k1 < input.size());
	assert(0 <= k2 && k2 < input.size());
	assert(k1 <= k2);

	vector<int> temp(input);
	sort(temp.begin(), temp.end());

	return vector<int> (temp.begin()+ k1, temp.begin()+k2+1);

}

/*
	nth_element 是STL提供的一个算法，用于找出序列中的第N大元素。 具体是通过调用nth_element(start, start+n, end)方
	可以使第n大元素处于第n位置（从0开始，其位置是下标为n的元素），并且比这个元素小的元素都排在这个元素之前，比这个元
	素大的元素都排在这个元素之后，但不能保证他们是有序的。
*/
vector<int> selectByNthElement(const vector<int> &input, int k1, int k2) {
	assert(0 <= k1 && k1 < input.size());
	assert(0 <= k2 && k2 < input.size());
	assert(k1 <= k2);

	vector<int> temp(input);
	nth_element(temp.begin(), temp.begin()+k2+1, temp.end());
	nth_element(temp.begin(), temp.begin()+k1, temp.begin()+k2+1);
  
	sort(temp.begin()+k1, temp.begin()+k2+1);
	return vector<int>(temp.begin()+k1, temp.begin()+k2+1);
}

/*
	STL算法 中的一个函数:partial_sort()
	原型：template<class RandomAccessIterator> inline
		  void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
	说明：partial_sort算法排序最小的N个元素，其中N = 中间的第一个序列。剩余的元素停滞在范围（中间， 最后一次）中为定义的顺序。
		 相当于就是说，这个是部分排序，只排序（first, middle）间的数据
*/
vector<int> selectByPartialSort(const vector<int>& input, int k1, int k2) {
		assert(0 <= k1 && k1 < input.size());
	assert(0 <= k2 && k2 < input.size());
	assert(k1 <= k2);

	vector<int> temp(input);
	nth_element(temp.begin(), temp.begin()+k1, temp.end());
	partial_sort(temp.begin()+k1, temp.begin()+k2+1, temp.end());
	return vector<int>(temp.begin()+k1, temp.begin()+k2+1);
}

void print(const vector<int>& vec) {
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ","));
	cout<<endl;
}

int main() {
	
	//istream_iterator<int> cin_it(cin);
	//istream_iterator<int> end_of_stream;
	//vector<int> input(cin_it, end_of_stream);
	vector<int> input;
	for(int i=1; i<=100; i++ ) {
		input.push_back(i);
	}
	/*
	//random_shuffle()函数原型为：
	// template<class RandomAccessIterator> inline
	// void random_shuffle(RandomAccessIterator first, RandomAccessIterator lase)
	//说明：random_shuffle()算法搅乱序列中的元素，以随机顺序，相当于c里的random(),但是比random() 更优，但是random_shuffle()因为是基于C++,
	//是STL的算法，因此不仅适用于容器，也适用于序列。因此random_shuffle()也可以用于内置数组
	*/
	random_shuffle(input.begin(), input.end());
	print(input);
	print(selectBySorting(input, 10,15));
	print(selectByNthElement(input, 10, 15));
	print(selectByPartialSort(input, 10, 15));

	getchar();
	getchar();
	return 0;
}