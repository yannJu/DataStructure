/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 4 - DLL Exercise
*Description : DoublyLinkedList란 next노드만 연결된 SinglyLinkedList와 달리 그 이전의 노드와 그 다음의 노드 양방향과 연결된 리스트이다. 또한 이 프로그램에서는 'current'라는 노드를 이용하여 현재의 노드의 위치를 나타내고 current의 이후에 insert하거나 이전에 insert를 할 수 있으며 첫번째나 마지막 위치에 노드를 삽입할 수 있다. 그리고 현재노드를 delete하고 current노드를 변경하거나(인덱스를 통해) current노드의 data를 업데이트 할 수 있도록 한다. 마지막으로 current 혹은 List를 출력할 수 있도록 해보는 프로그램이다. Menu를 설정하여 10을 입력하기 전까지 프로그램을 반복한다.
*Algorithm : DoublyLinkedList의 다음노드를 next, 이전노드를 prev로 하고 insert한경우 그 노드를 current로 설정한다. insertafter와 insertbefore 같은경우, current가 head거나 last가 아닌경우 current의 이전이나 이후에 삽입할 노드의 next와 prev를 설정한다. head거나 last인 경우 next나 prev를 NULL로 설정해 주어야한다. 또한 insertfirst와 insertlast는 current노드가 head이거나 last인경우와 비슷하지만 current를 사용하지 않고 next와 prev를 NULL로 설정해 주었다.
insert함수는 모두 함수가 끝나기 이전에 current를 새로 삽입한 노드(temp)로 지정해주어야 한다.
delete시에, current노드가 head이거나 last인경우에는 delete후 current = head로 설정하고, 그 외에는 current노드를 그다음 nextcurrent로 지정하여주도록 하였다.
*Variables : class Node - 노드에 관한 클래스. data와 next, prev노드를 담고 있으며 default constructor를 통해 초기값을 지정해주고, List에서 friend class를 통해 접근할 수 있도록 함
	   class List - List에 대한 클래스로, head와 current 그리고 이전 current의 값을 가지는 t를 가지고 있음
*********************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	private:
		int data;
		Node *next, *prev;
		Node(int val) {data = val; next = 0; prev = 0;} //default constructor
	friend class List;
}; // Node Class

class List{
	private:
		Node *head, *current;
		int size;
	public:
		List() {head = 0; current = 0; size = 0;} //default constructor
		~List(); //소멸자
		void Insert_After(int);
		void Insert_Before(int);
		void Insert_First(int);
		void Insert_Last(int); //insert after/before, insert first/last
		void Delete_Current();
		void Locate_Current(int);
		void Update_Current(int data) {current->data = data;}
		void Display_Current();
		void Display_List();
		int Listlength() {return size;} //list의 길이 반환
		int isEmpty() {return head == 0;}
};
/*********************************************************************************************************
*function : main()
*Description : 터미널창에서 값을 입력받아 10이 입력될 때 까지 반복하고 10이 입력되면 종료하도록 한다.
*Variables : List l1 - List클래스의 생성자
	   int num - 메뉴선택을 위해 입력받는 값을 담는 변수
	   int data - insert나 update, locate등 필요한 인자값을 담기 위한 변수
*********************************************************************************************************/

int main(){
	List l1;
	int num = -1, data;

	while (num != 10){
		cout << "Command : (1) insertAfter (2)insertBefore (3)insertFirst (4)insertLast (5)deleteCurrent (6)locateCurrent (7)updateCurrent (8)displayCurrent (9)displayList (10)Quit\n";
		cin >> num;
		switch (num){
			case 1: //insertAfter를 실행후 출력
				{
					cout << "Enter a data to insert => ";
					cin >> data;
					l1.Insert_After(data);
					l1.Display_List();
					break;
				}
			case 2: //insertBefore를 실행후 출력
				{
					cout << "Enter a data to insert => ";
					cin >> data;
					l1.Insert_Before(data);
					l1.Display_List();
					break;
				}
			case 3: //insertFirst를 실행후 출력
				{
					cout << "Enter a data to insert => ";
					cin >> data;
					l1.Insert_First(data);
					l1.Display_List();
					break;
				}
			case 4: //insertLast를 실행후 출력
				{
					cout << "Enter a data to insert => ";
					cin >> data;
					l1.Insert_Last(data);
					l1.Display_List();
					break;
				}
			case 5: //Current값 delete후 출력
				{
					l1.Delete_Current();
					l1.Display_List();
					break;
				}
			case 6: //Current의 position을 변경
				{
					cout << "Enter a position to locate => ";
					cin >> data;
					l1.Locate_Current(data);
					break;
				}
			case 7: //Current data 변경 후 출력
				{
					cout << "Enter a data to update => ";
					cin >> data;
					l1.Update_Current(data);
					l1.Display_List();
					break;
				}
			case 8:
				{
					l1.Display_Current();
				}
			case 9:
				{
					l1.Display_List();
					break;
				} // 8- 9 List & Current 출력
			case 10: //List 메모리해제(delete)
				{
					l1.~List();
					break;
				}
			default: //다른 숫자가 들어왔을 경우
				{
					cout << "Number is Wrong!\n";
					break;
				}
		}
	}
}

/*********************************************************************************************************
*function : ~List()
*Description : insert시 동적할당 해준 노드들을 모두 메모리 해체해주는 소멸자 constructor.
*Variables : Node *p - head가 변경될 수 없으므로 head를 할당받는 포인터 변수. 포인터 변수가 0이 될 때 까지 반복문을 돌아 p를 delete한다.
*********************************************************************************************************/

List::~List() {//소멸자
	Node *p;

	while (head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}
/*********************************************************************************************************
*function : void Insert_After(int)
*Description : Current node 바로 다음에 insert하도록 하는 함수. 그 후 size의 크기를 1 증가시켜준다.
*Variables : Node *temp - insert할 새로운 노드
*********************************************************************************************************/

void List::Insert_After(int data) {//insertAfter
	Node *temp = new Node(data);

	if (head == 0) head = temp; //first insert
	else if (current->next != 0) { //middle insert
		temp->prev = current;
		temp->next = current->next;
		current->next->prev = temp;
		current->next = temp;
	}
	else { //last insert
		temp->prev = current;
		temp->next = 0;
		current->next = temp;
	}
	current = temp; size += 1; //current설정 및 size 증가
}

/*********************************************************************************************************
*function : void Insert_Before(int)
*Description : Current node 바로 이전에 insert하도록 하는 함수. 그 후 size의 크기를 1 증가시켜준다.
*Variables : Node *temp - insert 할 새로운 노드
*********************************************************************************************************/

void List::Insert_Before(int data) {//insertBefore
	Node *temp = new Node(data);

	if (head == 0) head = temp; //insert first
	else if (current == head) {//current 가 first일때
		temp->next = head;
		head->prev = temp;
		temp->prev = 0;
		head = temp;
	}
	else {//current middle
		temp->next = current;
		current->prev->next = temp;
		temp->prev = current->prev;
		current->prev = temp;
	}
	current = temp; size += 1; //current를 설정해주고 size를 1증가시킨다
}

/*********************************************************************************************************
*function : void Insert_First(int)
*Description : Current에 상관없이 list first에 insert 하는 함수
*Variables : Node *temp - insert 할 새로운 노드
*********************************************************************************************************/

void List::Insert_First(int data) {//insertFirst
	Node *temp = new Node(data);

	if (head == 0) head = temp;
	else {
		head->prev = temp;
		temp->next = head;
		temp->prev = 0;
		head = temp;
	}
	current = temp; size += 1; //current설정후 size 1 증가시킨다.
}

/*********************************************************************************************************
*function : void Insert_Last(int)
*Description : Current에 상관없이 List의 last에 insert하는 함수
*Variables : Node *temp - insert 할 새로운 노드
	   Node *p - head가 움직이지 않도록 하기 위한 포인터 변수. 반복문내에서 노드를 이동하는데 사용
*********************************************************************************************************/

void List::Insert_Last(int data) {//insertLast
	Node *temp = new Node(data);
	Node *p;
	
	if (head == 0) head = temp;
	else {
		p = head;
		while (p->next) p = p->next; //List의 last를 찾아서
		p->next = temp;
		temp->prev = p;
		temp->next = 0; //temp를 last로 설정하여준다
	}
	current = temp; size += 1; //current설정후 size를 1 증가시킨다.
}

/*********************************************************************************************************
*function : void Delete_Current()
*Description : Current node를 delete하는 함수
*Variables : Node *p - current를 변경시켜주기 위해 current를 할당받는 포인터
*********************************************************************************************************/

void List::Delete_Current() {//DeleteCurrent
	Node *p;

	if (head == 0) cout << "List Empty.\n";
	else if (current == head){ //current의 위치가 head일 경우 delete후 current를 head 로 설정
		p = head;
		head = head->next; head->prev = 0;
		delete p;
		current = head;
	}
	else if (current->next == 0){ //current의 위치가 last일 경우 delete후 current를 head로 설정
		current->prev->next = 0;
		p = current;
		delete p;
		current = head;
	}
	else { //current 가 middle일 경우 delete후 current를 current->next로 설정
		p = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->next;
		delete p;
	}
	size -= 1; // size를 1감소시킨다
}
/*********************************************************************************************************
*function : void Locate_Current(int)
*Description : Current node를 변경하기 위한 함수. 인자로 받은 num번째 노드를 current로 설정한다.
*Variables : Node *p -> num만큼 이동하기 위해 노드를 이동시키는 포인터
*********************************************************************************************************/

void List::Locate_Current(int num) {//LocateCurrent
	Node *p;

	if (head == 0) cout << "List Empty.\n";
	else if (Listlength() >= num){ //List의 길이가 num보다 크거나 같은경우 == num번째 노드가 List안에 있다
		p = head;
		while (--num) p = p->next;
		current = p;
		Display_Current();
	}
	else cout << "No such a line.\n";
}

/*********************************************************************************************************
*function : void Display_Current()
*Description : Current node를 출력하는 함수
*Variables : Node *p - current node까지 이동하기 위한 포인터 변수
	   int cnt - current node의 인덱스를 표기하기 위한 변수
*********************************************************************************************************/

void List::Display_Current() {//displayCurrent
	Node *p;
	int cnt = 1;
	
	p = head;
	while(p != current) { //p가 current일 때 까지 반복
		p = p->next;
		cnt += 1;
	}
	cout << cnt << " * " << p->data << endl;
}
/*********************************************************************************************************
*function : void Display_List()
*Description : Current node 바로 이전에 insert하도록 하는 함수. 그 후 size의 크기를 1 증가시켜준다.
*Variables : Node *p - 각 노드들을 이동하기 위한 포인터
	   int cnt - 노드들의 인덱스를 표기하기 위한 변수
*********************************************************************************************************/

void List::Display_List() {//displayList
	Node *p;
	int cnt = 1;

	if (head != 0){
		p = head;
		cout << "----- List -----\n";
		while(p){
			cout << cnt++ << " ";
			if (p == current) cout << "* ";
			else cout << ": ";
			cout << p->data << endl;
			p = p->next;
		}
	}
}
