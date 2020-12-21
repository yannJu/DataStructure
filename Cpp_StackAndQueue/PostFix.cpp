#include <iostream>
#include <fstream>
using namespace std;

const int StackSize = 50;
class Stack{
	private:
		char sarr[StackSize]; int top;
	public:
		Stack() {top = -1;}
		void PUSH(char val);
		char POP();
		void StackEmpty(){cout << "StackEmpty.\n";}
		void StackFull(){cout << "StackFull.\n";}
		char Set_Top() {return sarr[top];}
		int index_Top() {return top;}
		void DisplayStack();
};
void Stack::PUSH(char val){
	if (top == StackSize - 1) StackFull();
	else sarr[++top] = val;
};
char Stack::POP(){
	if (top == -1) StackEmpty();
	else return sarr[top--];
};
void Stack::DisplayStack(){
	int sp; sp = top;
	while (sp != -1){cout << sarr[sp--] << " ";}
	cout << endl;
}; //Stack

Stack s;
char arr[100];
int i = 0;
void ConPostFix(char [], int i);
int Operator(char a);

int main(){
	ifstream in("hw2.txt");
	while (!in.eof()){
		in >> arr[i++];
	}
	ConPostFix(arr, i);
	cout << endl;
}

void ConPostFix(char arr[], int i){
	char token;
	for (int j = 0; j < i; j++){
		token = arr[j];
		switch(token){
			case '(':
				s.PUSH(token);
				break;
			case ')':
				while (s.Set_Top() != '('){
					cout << s.POP();
				}
				s.POP();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (Operator(token) > Operator(s.Set_Top())) s.PUSH(token);
				else {
					cout << s.POP();
					s.PUSH(token);
				}
				break;
			default:
				cout << token;
		}
	}
	while (s.index_Top() >= 0){
		cout << s.POP();
	}
}

int Operator(char a){
	int weight = -1;
	switch(a){
		case '+':
		case '-':
			weight = 1;
			break;
		case '*':
		case '/':
			weight = 2;
			break;
	}
	return weight;
}
