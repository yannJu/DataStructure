#include<iostream>
#include <cctype>
using namespace std;

class Node {
	private:
		//char data;
		int data;
		Node *left;
		Node *right; 
		//Node(char word = ' ') {data = word; left = 0; right = 0;}
		Node(int word = 0) {data = word; left = 0; right = 0;}
	friend class Tree;
};

class Tree{
	public:
		Node *root;
		Tree() {root = 0;}
		void insert(int key);
		Node *insertTree(Node*, int key);
		void traverse();
		bool levelorder(Node *p, int level);
};
void Tree::insert(int key){ //값을 추가, BST함수를 호출
	Node *ptr = root;
	insertTree(ptr, key);
}
// Build Binary Tree

struct Element {
	int key;
};
class MinHeap  {
	private:
		Element *heap;
		int n;
		int MinSize;
	public:
		MinHeap(int m = 7);
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

Node * insertTree(Node* ptr, int key);
void inorderTraverse(Node *p);

int main(){
	string word;
	Tree t;
	MinHeap mh;
	int cnt = 1;
	int num = -1;
	int key = -1;

	cout << "Enter data to create Heap. : ";
	cin >> word;

	for (int i = 0; i < word.length(); i++){
		t.insert(word[i]-'0');
		mh.Insert(word[i]-'0');
	}
	t.traverse();
	cout << endl;
	
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
/**********BT에관련한 함수 (insert, inorder)*********/

Node *Tree::insertTree(Node* ptr, int key){ //재귀
	if (ptr == 0) { //Tree가 비어있거나, Insert할 위치에 도달하였을 때
		Node *temp = new Node(key);
		temp->left = NULL; temp->right = NULL;
		if (root == 0) root = temp;
		return temp;
	}
	else if (key < ptr->data) ptr->left = insertTree(ptr->left, key); //key값이 더 작을경우
	else if (key > ptr->data) ptr->right = insertTree(ptr->right, key); //key값이 더 클경우
}
void Tree::traverse(){ //print level
	int level = 1;
	while(levelorder(root, level)) level++;
}

bool Tree::levelorder(Node *p, int level){ //levelorder
	bool left, right;
	if (p == 0) return false;
	else if (level == 1) {
		cout << p->data << " "; return true;
	}
	else {
		left = levelorder(p->left, level-1); right = levelorder(p->right, level-1);
		return (left||right);
	}
}

/********* MinHeap Fuc *************/
MinHeap::MinHeap(int m){
	MinSize = m;
	n = 0;
	heap = new Element[MinSize + 1]; //heap[0] not use
}

bool MinHeap::HeapFull(){
	if (n == MinSize) return true;
	return false;
}

bool MinHeap::HeapEmpty(){
	if (n == 0) return true;
	return false;
}

void MinHeap::Insert(int item){
	int i;
	if (!HeapFull()) {
		i = ++n;
		while ((i != 1) && (item < heap[i / 2].key)){
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i].key = item;
	}
	else cout << "Heap is FULL!\n";
}

int MinHeap::Delete(){
	int parent, child;
	Element item, temp;

	if (!HeapEmpty()){
		item = heap[1];
		temp = heap[n--];
		parent = 1; child = 2;

		while (child <= n){
			if ((child < n) && (heap[child].key > heap[child + 1].key)) child++;
			if (temp.key <= heap[child].key) break;
			heap[parent] = heap[child];
			parent = child;		
			child *= 2;
		}

		heap[parent] = temp;
		return item.key;
	}
}

void MinHeap::Print(){
	cout << "( ";
	for (int i = 1; i <= n; i++){
		cout << heap[i].key << " ";
	}
	cout << ")\n";
}

int MinHeap::getLevel(){
	int cnt = 0; int sz = n;
	while (sz > 0){
		cnt += 1;
		sz /= 2;
	}
	return cnt;
}

int MinHeap::Search(int sch){
	int cnt = 1;
	for (int i = 1; i <= n; i++){
		if (heap[i].key == sch) return cnt;
		cnt += 1;
	}
}
void MinHeap::HeapSort(){
	for (int i = n/2; i > 0; i--) adjust(i, n);
	for (int i = n - 1; i > 0; i--){
		swap(heap[1], heap[i + 1], i);
		adjust(1, i);
	}
}

void MinHeap::swap(Element h1, Element h2, int i){
	int temp = h1.key;
	heap[1] = h2; 
	heap[i + 1].key = temp;
}

void MinHeap::adjust(int i, int n){
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
