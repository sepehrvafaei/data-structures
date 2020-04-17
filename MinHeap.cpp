#include<iostream>
using namespace std;

template <class T>
class MinHeap{
private:
	T* heapArr;
	int size;
	int capacity;
public:
	MinHeap(int n =20);
	~MinHeap();
	void MinHeapify(int);
	int parentIndex(int i) { return (i - 1) / 2; }
	int leftIndex(int i) { return (2 * i + 1); }
	int rightIndex(int i) { return (2 * i + 2); }
	void add(T key);
	T removeMin();
	void print();
	void swap(T*,T*);
};
template <class T>
MinHeap<T>::MinHeap(int n)
{
	heapArr = new T[n];
	size = 0;
	capacity = n;
}
template <class T>
MinHeap<T>::~MinHeap()
{
	delete[] heapArr;
}
template <class T>
void MinHeap<T>::MinHeapify(int i) {
		int l = leftIndex(i);
		int r = rightIndex(i);
		int smallest = i;
		if (l < size && heapArr[l] < heapArr[i])
			smallest = l;
		if (r < size && heapArr[r] < heapArr[smallest])
			smallest = r;
		if (smallest != i)
		{
			swap(&heapArr[i], &heapArr[smallest]);
			MinHeapify(smallest);
		}
	}
template <class T>
void MinHeap<T>::add(T key)
{
	if (size < capacity)
	{
		heapArr[size] = key;
		int currentIndex = size;
		while (currentIndex > 0)
		{
			int parentIndex = (currentIndex - 1) / 2;
			if (heapArr[currentIndex] < heapArr[parentIndex])
				swap(&heapArr[currentIndex],& heapArr[parentIndex]);
			else
				break;
			currentIndex = parentIndex;
		}
		size++;
	}
	else
	{
		cout << "The Heap is Full." << endl;
	}
}
template <class T>
T MinHeap<T>::removeMin()
{
	T removedElement = heapArr[0];
	heapArr[0] = heapArr[size - 1];
	size--;

	int currentIndex = 0;
	while (currentIndex < size)
	{
		int leftChildIndex = 2 * currentIndex + 1;
		int rightChildIndex = 2 * currentIndex + 2;

		if (leftChildIndex >= size)
			break;
		int minChildIndex = leftChildIndex;
		if (rightChildIndex < size)
		{
			if (heapArr[minChildIndex] >heapArr[rightChildIndex])
				minChildIndex = rightChildIndex;
		}

		if (heapArr[currentIndex] > heapArr[minChildIndex])
		{
			swap(&heapArr[currentIndex], &heapArr[minChildIndex]);
			currentIndex = minChildIndex;
		}
		else
			break;
	}

	return removedElement;
}
template <class T>
void MinHeap<T>::swap(T *x, T *y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

template <class T>
void MinHeap<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Heap element " << i << " = " << heapArr[i] << endl;
	}
}
int main() {
	MinHeap<int> h(11);
	h.add(3);
	h.add(2);
	h.add(15);
	h.add(5);
	h.add(4);
	h.add(45);
	h.print();
	cout << "element at index "<<h.removeMin()<<" removed." << endl;
	h.print();
	cin.get();
	return 0;
}