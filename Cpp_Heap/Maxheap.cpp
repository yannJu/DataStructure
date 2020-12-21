#include<iostream>
#include <cctype>
using namespace std;

struct Element {
	int key;
};

class MaxHeap  {
	private:
		Element *heap;
		int n;
		int MaxSize;
	public:
		MaxHeap(int m = 10);
		bool HeapFull();
		bool HeapEmpty();
		void Insert(int);
		int Delete();
		void Print();
		int getLevel();
		int Search(int);
		void HeapSort();
		void swap(Element, Element, int);
		void adjust(int, int);
};

int main(){
	string word;
	MaxHeap mh;
	int num = -1;
	int key = -1;

	if (mh.HeapEmpty()) cout << "Heap is Empty!\n";
	cout << "Enter data to create Heap. : ";
	cin >> word;
	cout << endl;

	for (int i = 0; i < word.length(); i++){
		mh.Insert(word[i]-'0');
	}

	do{
		cout << "Menu (1. Insert, 2. Delete, 3. Empty-Test, 4. Full-Test, 5. Level-Test, 6. Heap Search, 7. Heap Sort, 8. Print, 9. Quit) : ";
		cin >> num;
		cout << endl;
		switch (num){
			case 1:
				cout << "Enter data to Insert : ";
				cin >> key;
				cout << endl;
				mh.Insert(key);
				break;
			case 2:
				cout << "Delete \'" << mh.Delete() << "\'\n";
				break;
			case 3:
				if (mh.HeapEmpty()) cout << "Heap is Empty!\n";
				else cout << "Not Empty.\n";
				break;
			case 4:
				if (mh.HeapFull()) cout << "Heap is Full!\n";
				else cout << "Not Full.\n";
				break;
			case 5:
				cout << "Heap Level " << mh.getLevel() << endl;
				break;
			case 6:
				cout << "Enter data to Search : ";
				cin >> key;
				cout << endl;
				cout << "Find num \'" << key << "\' is \'" << mh.Search(key) << "\' th \n";
				break;
			case 7:
				mh.HeapSort();
				mh.Print();
				break;
			case 8:
				mh.Print();
				break;
			case 9:
				break;
			default:
				cout << "Wrong num!\n";
				break;
		}
	}while (num != 9);
}

MaxHeap::MaxHeap(int m){
	MaxSize = m;
	n = 0;
	heap = new Element[MaxSize + 1]; //heap[0] not use
}

bool MaxHeap::HeapFull(){
	if (n == MaxSize) return true;
	return false;
}

bool MaxHeap::HeapEmpty(){
	if (n == 0) return true;
	return false;
}

void MaxHeap::Insert(int item){
	int i;
	if (!HeapFull()) {
		i = ++n;
		while ((i != 1) && (item > heap[i / 2].key)){
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i].key = item;
	}
	else cout << "Heap is FULL!\n";
}

int MaxHeap::Delete(){
	int parent, child;
	Element item, temp;

	if (!HeapEmpty()){
		item = heap[1];
		temp = heap[n--];
		parent = 1; child = 2;

		while (child <= n){
			if ((child < n) && (heap[child].key < heap[child + 1].key)) child++;
			if (temp.key >= heap[child].key) break;
			heap[parent] = heap[child];
			parent = child;		
			child *= 2;
		}

		heap[parent] = temp;
		return item.key;
	}
}

void MaxHeap::Print(){
	cout << "( ";
	for (int i = 1; i <= n; i++){
		cout << heap[i].key << " ";
	}
	cout << ")\n";
}

int MaxHeap::getLevel(){
	int cnt = 0; int sz = n;
	while (sz > 0){
		cnt += 1;
		sz /= 2;
	}
	return cnt;
}

int MaxHeap::Search(int sch){
	int cnt = 1;
	for (int i = 1; i <= n; i++){
		if (heap[i].key == sch) return cnt;
		cnt += 1;
	}
}
void MaxHeap::HeapSort(){
	for (int i = n/2; i > 0; i--) adjust(i, n);
	for (int i = n - 1; i > 0; i--){
		swap(heap[1], heap[i + 1], i);
		adjust(1, i);
	}
}

void MaxHeap::swap(Element h1, Element h2, int i){
	int temp = h1.key;
	heap[1] = h2; 
	heap[i + 1].key = temp;
}

void MaxHeap::adjust(int i, int n){
	int child;
	Element temp = heap[i];
	child = 2 * i;
	
	while (n >= child){
		if ((n > child) && (heap[child].key < heap[child + 1].key)) child += 1;
		if (temp.key >= heap[child].key) break;
		heap[child/2] = heap[child];
		child *= 2;
	}
	heap[child/2] = temp;
}
