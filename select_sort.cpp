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
	nth_element ��STL�ṩ��һ���㷨�������ҳ������еĵ�N��Ԫ�ء� ������ͨ������nth_element(start, start+n, end)��
	����ʹ��n��Ԫ�ش��ڵ�nλ�ã���0��ʼ����λ�����±�Ϊn��Ԫ�أ������ұ����Ԫ��С��Ԫ�ض��������Ԫ��֮ǰ�������Ԫ
	�ش��Ԫ�ض��������Ԫ��֮�󣬵����ܱ�֤����������ġ�
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
	STL�㷨 �е�һ������:partial_sort()
	ԭ�ͣ�template<class RandomAccessIterator> inline
		  void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
	˵����partial_sort�㷨������С��N��Ԫ�أ�����N = �м�ĵ�һ�����С�ʣ���Ԫ��ͣ���ڷ�Χ���м䣬 ���һ�Σ���Ϊ�����˳��
		 �൱�ھ���˵������ǲ�������ֻ����first, middle���������
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
	//random_shuffle()����ԭ��Ϊ��
	// template<class RandomAccessIterator> inline
	// void random_shuffle(RandomAccessIterator first, RandomAccessIterator lase)
	//˵����random_shuffle()�㷨���������е�Ԫ�أ������˳���൱��c���random(),���Ǳ�random() ���ţ�����random_shuffle()��Ϊ�ǻ���C++,
	//��STL���㷨����˲���������������Ҳ���������С����random_shuffle()Ҳ����������������
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