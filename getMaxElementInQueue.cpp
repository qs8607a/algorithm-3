//假设有这样一个拥有3个操作的队列：
//	1、EnQueue():讲V加入队列中
//	2、DeQueue():使队列中的队首元素删除并返回此元素
//	3、MaxElement():返回队列中的最大值
//	请设计一种数据结构，让MaxElement操作的时间复杂度尽可能地低



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//常规方法：以数组作为队列的底层数据结构
class Queue {
public :
	Queue(){head = tail = 0;}
	int enQueue(int element) {
		int result = 1;
		if(tail - head < 100 ) {
			queue[tail] = element;
			++tail;
		}
		else {
			result = 0;
		}

		return result;
	}
	void DeQueue() {
		++head;
	}

	int MaxElement() {
		int element = 0;
		for(int i=head; i<tail; i++) {
			if(element < queue[i]) element = queue[i];
		}

		return element;
	}

private:
	int head;
	int queue[100];
	int tail;
};

const int MAXN = 100;
//以最大堆来维护队列中的元素
class heap {
public:
	heap() { currentNum = 0;}
	void FilterDown(int i){
		int current= i;
		int child = 2*i+1;
		int temp = queue[current];
		while(child < currentNum) {
			if (child+1 < currentNum && queue[child] < queue[child+1]){
				child += 1;
			}

			if ( queue[current] > queue[child]) break;
			else {
				queue[current] = queue[child];
				current = child;
				child = child*2 +1;
			}
		}

		queue[current] = temp;
	}

	int MaxElement() {return queue[0];}
	void insert(int v) {
		queue[currentNum] = v;
		++currentNum;
		FilterDown(0);
	}
	void DeElement(int v) {
		for (int i=0; i<currentNum; i++)
		{
			if(v == queue[i]  ){
				if(i == currentNum - 1) { currentNum--; break;}
				else {
					queue[i] = queue[currentNum -1];
					--currentNum;
					FilterDown(0);
				}
			}
		}
	}

	int CurrentNum() {return currentNum;}
private:
	int queue[MAXN];
	int currentNum;
};

class  queueHeap {
public:
	queueHeap() { head = 0; }
	int EnQueue(int element) {
		int n = node.CurrentNum();
		queue[n] = element;
		node.insert(element);
		return 1;
	}

	void DeQueue() {
		int temp = queue[head++];
		node.DeElement(temp);
	}

	int MaxElement() { return node.MaxElement();}
	
private:
	heap node;
	int head;
	int queue[100];
};


//用堆栈来实现队列

class stack {
public:
	stack() {
		stackTop = -1;
		maxStackItemIndex = -1;
	}

	void push(int x) {
		++stackTop;
		if (stackTop >= MAXN){
			cout<<"超出栈范围了！！"<<endl;
		}else {
			stackItem[stackTop] = x;
			if ( x >Max()){
				
				linkNextMaxItem[stackTop] = maxStackItemIndex;
				maxStackItemIndex = stackTop;
			}else linkNextMaxItem[stackTop] = -2;
		}
	}
	int Pop() {
		int ret = -1;
		if (stackTop <0 ){
			cout<<"没有元素了!!"<<endl;
		}else {
			ret = stackItem[stackTop];
			if (stackTop == maxStackItemIndex){
				maxStackItemIndex = linkNextMaxItem[stackTop];
			}
			stackTop--;
		}
		
		return ret;
	}
	int Max() {
		if(maxStackItemIndex >= 0) return stackItem[maxStackItemIndex];
		else return -1;
	}

	bool empty() { return (stackTop <0)?true:false; }
private:
	int stackItem[MAXN];
	int stackTop;
	int linkNextMaxItem[MAXN];
	int maxStackItemIndex;
};
class SQueue {
public:
	int MaxValue(int x, int y) {
		return (x>y)?x:y;
	}

	int MaxElement() {
		return MaxValue(stackA.Max(), stackB.Max());
	}
	
	void EnQueue(int value) {
		stackB.push(value);
	}

	int DeQueue() {
		if (stackA.empty()){
			while(!stackB.empty()) {
				stackA.push(stackB.Pop());
			}
		}

		return stackA.Pop();
	}
private:
	stack stackA;
	stack stackB;
};

int main() {
	//以数组实现的
	Queue queue;
	cout<<" 请输入队列中的值：";
	int value ;
	while (cin>>value)
	{
		queue.enQueue(value);
	}

	int maxNum = queue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;

	queue.DeQueue();
	maxNum = queue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;

	//以最大堆来实现的
	getchar();
	cin.clear();
	queueHeap hqueue;
	int element;
	cout<<" 请输入队列中的值：";
	while(cin>>element) {
		hqueue.EnQueue(element);
	}

	maxNum = hqueue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;

	 hqueue.DeQueue();
	maxNum = hqueue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;

	//以堆栈来实现
	getchar();
	cin.clear();
	SQueue squeue;
	int val;
	cout<<" 请输入队列中的值：";
	while(cin>>val) {
		squeue.EnQueue(val);
	}

	maxNum = squeue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;

	int delElement = squeue.DeQueue();
	cout<<"删除元素："<<delElement<<endl;
	maxNum = squeue.MaxElement();
	cout<<"最大值："<<maxNum<<endl;
	getchar();
	getchar();

	return 0;
}