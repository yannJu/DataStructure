/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 5 - Heap
*Description : Heap은 Full혹은 Complete한 이진트리의 형태로써 Max/Min Heap이 있다. Max Heap은 각 노드들이 child노드보다 key값이 큰 Heap이다. 이진트리를 입력하고 그 이진트리를 Max Heap으로 나타내도록 하는 프로그램으로, struct배열에 각 노드들의 값을 담아 구현하였다. 그 후 Insert, Delete, Search, Level-test, Heap Sort까지 확인하여 Max Heap을 test하는 프로그램이다.
*Algorithm : struct배열에 먼저 입력된 초기 데이터를 담은 후, Make Heap을 통해 MaxHeap을 만든다. 먼저 Element struct에 노드의 data를 담고, Heap클래스를 통해, 이진트리를 생성한다. Insert로 배열에 추가하여 주고, Search로 배열을 for문을 통해 탐색한다. 배열의 Size 를 10으로 고정해 두었고, 크지 않은 사이즈기 때문에 단순하게 for문만으로 해결하였다. Heap클래스를 상속받은 Max Heap클래스는 Heap이 Full인지 Empty인지 확인하는 함수와 MaxHeap에 노드를 insert하는 MaxInsert, 최상위 노드를 delete 하는 Delete함수들을 가지며 그 외에도 Level의 값을 확인하는 함수와 MaxHeap을 만드는 MakeHeap이 있다. 마지막으로 오름차순으로 값을 정렬하는 Heap Sort를 통해 모든 Max Heap을 test해 볼 수 있는 프로그램을 나타낸다.
*Variables : struct Element - 노드의 data값을 담은 구조체
	   class Heap - 이진트리를 만드는 클래스로, default constructor를 통해, 동적으로 Element객체를 생성하여 이진트리를 생성하는 클래스.
	   class MaxHeap - Heap을 상속하는 클래스로 MaxHeap을 만들고, 그에 관한 Insert, Delete, 등의 역할을 하도록 하는 클래스
*********************************************************************************************************/
#include<iostream>
using namespace std;

struct Element {
	int key;
};

class Heap{
	protected:
		Element *heap;
		int n;
		int MaxSize;
	public:
		Heap(int m = 10);
		void Insert(int);
		void Search(int);
};
/*********************************************************************************************************
*function : Heap(int m)
*Description : Heap클래스 객체를 생성할때 생성되는 default constructor.
*Variables : MaxSize - 배열의 크기를 지정해 주는 변수. (생성자가 생성될때 일정한 크기가 들어오지 않으면 m = 10이므로 default는 10)
	   n - 배열의 indext를 표기하기 위한 변수
	   heap - 이진트리를 만드는 struct배열. 배열에는 노드의 data가 담겨있다.
*********************************************************************************************************/

Heap::Heap(int m){
	MaxSize = m;
	n = 0;
	heap = new Element[MaxSize+1];
}
/*********************************************************************************************************
*function : Insert(int num)
*Description : 배열의 끝에 들어오는 data를 담아준다.(Max Heap이 아니므로 순서는 상관 x)
*********************************************************************************************************/

void Heap::Insert(int num){
	heap[++n].key = num;
}
/*********************************************************************************************************
*function : Search(int sch)
*Description : 배열을 for문을 통해 돌면서 들어온 값 sch가 있는지 확인하는 함수. 없다면 NotFound를 있다면 Find Num을 출력하고 몇번째 노드인지 알려준다.
*Variables : cnt - 몇번째 노드인지 알려주기 위한 변수
*********************************************************************************************************/

void Heap::Search(int sch){
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

class MaxHeap : public Heap {
	public:
		bool HeapFull();
		bool HeapEmpty();
		void MakeHeap();
		void MaxInsert(int);
		int Delete();
		void Print();
		int getLevel();
		void HeapSort();
		void swap(Element, Element, int);
		void adjust(int, int);
};
/*********************************************************************************************************
*function : main
*Description : MaxHeap클래스 객체를 생성하고, 이진트리를 생성한다. 그리고 프로그램을 돌려 MaxHeap을 테스트 하는 함수.
*Variables : Max Heap mh - MaxHeap 객체
	   num - 초기데이터를 입력받기 위한 변수, 그 이후에는 메뉴를 선택하는 변수로 재사용
	   key - Insert나, Search등을 할 때 값을 입력하기 위한 변수
*********************************************************************************************************/

int main(){
	MaxHeap mh;
	int num = -1;
	int key = -1;

	cout << "Enter data to create Heap. (10) : ";
	for (int i = 0; i < 10; i++){
		cin >> num;
		mh.Insert(num);
	}

	do{
		cout << "Menu (1. Insert, 2. Delete, 3. Search 4. Level-Test, 5. Heap Sort, 6. Make Heap, 7. Print, 8. Quit) : ";
		cin >> num;
		cout << endl;
		switch (num){
			case 1:
				cout << "Enter data to Insert : ";
				cin >> key;
				mh.Insert(key);
				break;
			case 2:
				cout << "Delete \'" << mh.Delete() << "\'\n";
				break;
			case 3:
				cout << "Enter data to Search : ";
				cin >> key;
				mh.Search(key);
				break;
			case 4:
				cout << "Heap Level " << mh.getLevel() << endl;
				break;
			case 5:
				mh.HeapSort();
				cout << "Sort 결과 :    ";
				mh.Print();
				break;
			case 6:
				mh.MakeHeap();
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
/*********************************************************************************************************
*function : HeapFull()
*Description : Heap이 꽉 채워져 있는지 확인하기 위한 함수로, 맨 마지막 노드의 index 즉 n이 MaxSize일 경우 true를 반환한다.
*********************************************************************************************************/

bool MaxHeap::HeapFull(){
	if (n == MaxSize) return true;
	return false;
}
/*********************************************************************************************************
*function : HeapEmpty()
*Description : Heap이 비어있는지 확인하기 위한 함수로, n이 0이면 Heap이 비어있는 경우이므로 true를 반환한다.
*********************************************************************************************************/

bool MaxHeap::HeapEmpty(){
	if (n == 0) return true;
	return false;
}
/*********************************************************************************************************
*function : MakeHeap()
*Description : 현재의 Heap이 MaxHeap이 아닌 그냥 이진트리로 되어있는 경우 MaxHeap으로 변경하도록 하는 함수이다. 맨 마지막 index인 n의 부모부터 확인하면서, i가 최상위 노드가 될 때 까지 반복하고, adjust함수를 호출한다.
*********************************************************************************************************/

void MaxHeap::MakeHeap(){
	for (int i = n/2; i > 0; i--){
		adjust(i, n);
	}
}
/*********************************************************************************************************
*function : MaxInsert(int item)
*Description : MaxHeap인 Heap이 Full이 아닌경우, Insert하도록 하는 함수. 빈 Heap이 아니면서, 들어온 값이 부모의 data보다 큰 경우 반복문을 시행하는데, 부모의 data보다 크면 자리를 바꾸어야 하므로, 들어온 data가 들어갈 자리가 i라면, i번째에 부모의 data값을 할당하고, i의 index를 원래의 부모의 index로 만들고, 부모가 자신의 data보다 큰경우까지 반복한다. 반복문을 나오고 i에 들어올 data인 item을 할당하여 준다. 만약 Heap이 Full이라면 경고문을 출력하고 함수를 끝낸다.
*Variables : i - 들어오는 data가 위치할 index를 나타낼 변수.
*********************************************************************************************************/

void MaxHeap::MaxInsert(int item){
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
/*********************************************************************************************************
*function : Delete()
*Description : MaxHeap의 최상위 노드, 즉 가장큰 data를 가진 노드를 delete하는 함수이다. delete후에는 다시 MaxHeap을 정리하도록 한다. 지울 노드를 item변수에 담고, 가장 마지막 노드를 temp변수에 담는다. 그 후 노드의 맨 처음부터 반복해 나가기 시작하는데, 마지막 노드를 확인할 때 까지 반복문을 돌리는데, child가 마지막 노드가 아니고, 자신의 형제노드보다 작으면 child를 +1해준다. 그 후에 마지막 노드와 data를 비교하여, 작거나 같으면 종료한다. 그렇지 않으면, 부모자리에 child를 할당하고, index를 확인하기 위한 parent변수에는 child를, child는 그 아래 child노드의 index를 받으며 반복문을 돈다.
*Variables : parent, child - parent, child의 index를 나타내기 위한 변수
	   Element item, temp - heap의 맨 첫번째 최상위 노드와 마지막인 최하위 노드를 각각 담는 구조체 변수
*********************************************************************************************************/

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
/*********************************************************************************************************
*function : Print()
*Description : 배열을 for문을 통해 읽으면서 각 노드의 data를 출력하는 함수.
*********************************************************************************************************/

void MaxHeap::Print(){
	cout << "Heap :     ( ";
	for (int i = 1; i <= n; i++){
		cout << heap[i].key << " ";
	}
	cout << ")\n";
}
/*********************************************************************************************************
*function : getLevel()
*Description : 전체 Heap의 레벨을 확인하기 위한 함수로, 마지막 노드를 2로 나누면서 레벨을 확인한다.
*Variables : cnt - 레벨을 확인하기 위한 변수.
	   sz - 전체 Heap의 크기를 나타내기 위한 변수
*********************************************************************************************************/

int MaxHeap::getLevel(){
	int cnt = 0; int sz = n;
	while (sz > 0){
		cnt += 1;
		sz /= 2;
	}
	return cnt;
}
/*********************************************************************************************************
*function : HeapSort()
*Description : 오름차순으로 Heap을 정렬하는 함수. 먼저 마지막 노드부터 최 상위 노드까지, 반복문을 돌면서 maxheap으로 만든 후에, 다시 마지막 노드부터 처음노드까지 반복하며, 맨 마지막노드(가장 값이 작은 노드)와 첫번째 노드(가장 값이 큰 노드)의 자리를 바꾼 후 maxheap으로 정리하는것을 반복한다.
*********************************************************************************************************/

void MaxHeap::HeapSort(){
	for (int i = n/2; i > 0; i--) adjust(i, n);
	for (int i = n - 1; i > 0; i--){
		swap(heap[1], heap[i + 1], i);
		adjust(1, i);
		Print();
	}
}
/*********************************************************************************************************
*function : swap(Element h1, Element h2, int i)
*Description : 들어오는 Element인자들의 값을 서로 바꿔주고 i번째 자리에 할당는 함수.
*Variables : temp - 값을 바꾸기 위해, data를 담아놓는 변수
*********************************************************************************************************/

void MaxHeap::swap(Element h1, Element h2, int i){
	int temp = h1.key;
	heap[1] = h2; 
	heap[i + 1].key = temp;
}
/*********************************************************************************************************
*function : adjust(int i, int n)
*Description : n번째 노드까지 maxheap으로 정렬하도록 하는 함수. i는 parent의 index로 child의 data가 자신의 형제의 data보다 작으면 child +1을 해주고, child가 부모의 노드의 data보다 큰경우 부모와 child를 바꾸도록 반복한다.
*Variables : child - child의 index를 담기 위한 변수
	   Element temp - 노드를 바꾸기 위해 담아놓는 변수
*********************************************************************************************************/

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
