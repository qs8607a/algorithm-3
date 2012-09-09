//����������һ��ӵ��3�������Ķ��У�
//	1��EnQueue():��V���������
//	2��DeQueue():ʹ�����еĶ���Ԫ��ɾ�������ش�Ԫ��
//	3��MaxElement():���ض����е����ֵ
//	�����һ�����ݽṹ����MaxElement������ʱ�临�ӶȾ����ܵص�



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//���淽������������Ϊ���еĵײ����ݽṹ
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
//��������ά�������е�Ԫ��
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


//�ö�ջ��ʵ�ֶ���

class stack {
public:
	stack() {
		stackTop = -1;
		maxStackItemIndex = -1;
	}

	void push(int x) {
		++stackTop;
		if (stackTop >= MAXN){
			cout<<"����ջ��Χ�ˣ���"<<endl;
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
			cout<<"û��Ԫ����!!"<<endl;
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
	//������ʵ�ֵ�
	Queue queue;
	cout<<" ����������е�ֵ��";
	int value ;
	while (cin>>value)
	{
		queue.enQueue(value);
	}

	int maxNum = queue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;

	queue.DeQueue();
	maxNum = queue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;

	//��������ʵ�ֵ�
	getchar();
	cin.clear();
	queueHeap hqueue;
	int element;
	cout<<" ����������е�ֵ��";
	while(cin>>element) {
		hqueue.EnQueue(element);
	}

	maxNum = hqueue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;

	 hqueue.DeQueue();
	maxNum = hqueue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;

	//�Զ�ջ��ʵ��
	getchar();
	cin.clear();
	SQueue squeue;
	int val;
	cout<<" ����������е�ֵ��";
	while(cin>>val) {
		squeue.EnQueue(val);
	}

	maxNum = squeue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;

	int delElement = squeue.DeQueue();
	cout<<"ɾ��Ԫ�أ�"<<delElement<<endl;
	maxNum = squeue.MaxElement();
	cout<<"���ֵ��"<<maxNum<<endl;
	getchar();
	getchar();

	return 0;
}