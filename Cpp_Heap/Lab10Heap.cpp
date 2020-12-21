#include<iostream>
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
		MaxHeap(int m = 8);
		bool HeapFull();
		bool HeapEmpty();
		void Insert(int);
		int Delete();
		void Print();
		int getLevel();
		void Search(int);
};

int main(){
	string word;
	MaxHeap mh;
	int num = -1;
	int key = -1;

	cout << "Enter data to create Heap. : ";
	cin >> word;
	cout << endl;

	for (int i = 0; i < word.length(); i++){
		mh.Insert(word[i]-'0');
	}

	do{
		cout << "Menu (1. Insert, 2. Delete, 3. Empty-Test, 4. Full-Test, 5. Level-Test, 6. Heap Search, 7. Print, 8. Quit) : ";
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
				mh.Search(key);
				break;
			case 7:
				mh.Print();
				break;
			case 8:
				break;
			default:
				cout << "Wrong num!\n";
				break;
		}
	}while (num != 8);
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

void MaxHeap::Search(int sch){
	int cnt = 1;
	for (int i = 1; i <= n; i++){
		if (heap[i].key == sch) {
			cout << "Find num \'" << sch << "\' is found. \'" << cnt << "\' th \n";
			return ;
		}
		cnt += 1;
	}
	cout << "Not Found.\n";
}
