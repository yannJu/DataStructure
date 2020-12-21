#include <iostream>
#include <fstream>
using namespace std;

struct Student {
	char name;
	int ID;
	string major;
	char grade;
	Student *next;
}; //노드 struct

class List{
	private:
		Student *head;

	public:
		List() {head = 0;}
		~List();
		void Insert(Student data);
		void Selecttraverse(char grade);
		void SelectMajor(string major);
		bool isEmpty();
		void traverseList();
};//LinkedList Class

void List::Insert(Student data){
	Student *temp = new Student();
	temp->name = data.name;
	temp->ID = data.ID;
	temp->major = data.major;
	temp->grade = data.grade;

	Student *p, *q;

	if (head == 0) head = temp;
	else if (temp->name < head->name) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->name < temp->name)){
			q = p;
			p = p->next;
		}
		if (p != 0){
			temp->next = p; q->next = temp;
		}
		else{
			q->next = temp;
		}
	}
}//Insert

bool List::isEmpty(){
	if (head == 0) {
		cout << "List is Empty.\n";
		return true;
	}
	else return false;
}//IsEmpty

void List::traverseList(){
	Student *p;
	
	if (!isEmpty()){
		p = head;
		cout << "name    ID    Major   Grade\n";
		while(p){
			cout << "  " <<  p->name << "     " << p->ID << "     " << p->major << "      " << p->grade << endl;
			p = p->next;
		}
		cout << endl;
	}
	else cout << "List is empty!\n";
}//traverse = 모든 list의 값 출력

void List::Selecttraverse(char grade){
	Student *p;

	if(!isEmpty()){
		p = head;
		cout << "name    ID    Major   Grade\n";
		while(p){
			if (p->grade == grade){
				cout << "  " <<  p->name << "     " << p->ID << "     " << p->major << "      " << p->grade << endl;
			}
			p = p->next;
		}
		cout << endl;
	}
}

void List::SelectMajor(string major){
	Student *p;
	
	if(!isEmpty()){
		p = head;
		cout << "name    ID    Major   Grade\n";
		while(p){
			if (p->major == major){
				cout << "  " <<  p->name << "     " << p->ID << "     " << p->major << "      " << p->grade << endl;
			}
			p = p->next;
		}
		cout << endl;
	}
}

List::~List(){
	Student *p;
	while(head != 0){
		p = head;
		head = head->next;
		delete p;
	}
}//~List = 리스트 초기화

int main(){
	ifstream in("data1.txt");
	ifstream in2("data2.txt");
	
	Student stu;
	List l1, l2;
	char name, grade;
	int ID;
	string major;

	for (int i = 0; i < 7; i++){
		in >> stu.name >> stu.ID >> stu.major >> stu.grade;
		l1.Insert(stu); l2.Insert(stu);
	}
	l1.traverseList();
	l1.Selecttraverse('A');
	
	for (int i = 0; i < 3; i++){
		in2 >> stu.name >> stu.ID >> stu.major >> stu.grade;
		l2.Insert(stu);
	}
	l2.SelectMajor("CS");
	l1.~List();
}
