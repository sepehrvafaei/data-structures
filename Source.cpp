#include<iostream>
using namespace std;
class Heap {
private:
	int* elements;
	int heapNum;
	int heapSize;
public:
	Heap(int x=10);
	~Heap();
	bool add(int x);
	bool remove();
	void print();
};
Heap::Heap(int x) {
	heapNum = 0;
	heapSize = x;
	elements = new int[heapSize];
}
Heap::~Heap() {
	delete[] elements;
}
bool Heap::add(int x){
	if (heapNum<heapSize) {

	}
	heapNum++;
}
bool Heap::remove(){}
void Heap::print() {
	for (int i = 0; i < heapSize; i++) {
		cout << i << ' ';
	}
}
int main() {
	Heap mine(10);
	mine.add(35);
	mine.add(33);
	mine.add(42);
	mine.add(10);
	mine.add(14);
	mine.add(19);
	mine.add(27);
	mine.add(44);
	mine.add(26);
	mine.add(31);
	mine.print();
	mine.remove();
	mine.print();
	return 0;
}
