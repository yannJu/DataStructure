/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 2 - Infix-Postfix
*Description : 파일을 한줄씩 읽어들여 infix로 되어있는 식을 배열 arr에 담고 그 arr을 postfix로 변환한 후 계산하는 프로그램, Stack클래스를 구현하고 그 클래스를 이용하여 infix를 postfix로 변환한다. 그 후에 또한번 Stack클래스를 이용해 postfix된 배열을 eval하는 프로그램이다.
*Algorithm : infix를 postfox로 변환하기 위해서는 배열 arr을 한글자(char)씩 읽어들여 그 값이 연산자가 아닌 숫자가 들어오면 Stack에 Push하고, 연산자가 들어올경우 '+','-'와 '*','/'의 우선순위를 따져 Push혹은 Pop후에 Push 하도록 한다. 또한 '('가 들어올경우 그냥 Push하고 ')'들어올경우 '('가 들어올때까지 Pop해준다.
여기서 Pop한 값은 eval을 하기 위해 eval이라는 배열에 담아주도록한다.
infix가 postfix되어 eval이라는 배열에 다 담기게 되면 배열에 있는 값을 하나씩 다시 읽어들여 , 연산자가 아닌경우 다시 Stack에 Push하고 연산자인경우 이전 2개의 값을 Pop하여 변수 2개에 각각 담고, 변수 두개를 연산한 값을 다시 Stack에 Push해준다. 이과정을 반복하여 eval값을 반환하도록 한다.
*Variables : const int StackSize - Stack클래스에서 사용하는 배열 sarr, iarr의 배열크기 고정
				Class Stack - Stack을 하기 위한 클래스
				void ConPostFix - infix to postfix를 하기위한 함수
				int Operator - 연산자의 우선순위를 지정하기 위해 '+','-'는 1을, '*','/'는 2를 반환하는 함수
				void PostEval - postfix된 배열을 이용하여 계산값을 출력하는 함수
*********************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
using namespace std;

const int StackSize = 50;
class Stack{
	private:
		char sarr[StackSize]; int iarr[StackSize]; //sarr은 char값을(ConPostFix), iarr은 int값을(PostEval)사용
		int top;
	public:
		Stack() {top = -1;}
		void reset() {top = -1;}
		void PUSH(char val);
		void PUSH(int val); //인자값의 타입에 따라 다른 배열에 담기 위한 오버로딩
		char POP();
		int Pop(); //인자값의 타입에 따라 다른 배열의 값을 PUSH하기위해 다른 함수를 만듦
		void StackEmpty(){cout << "StackEmpty.\n";}
		void StackFull(){cout << "StackFull.\n";}
		char Set_Top() {return sarr[top];} //Top에 있는 값을 리턴
		int index_Top() {return top;} //Top의 인덱스 값을 리턴
		void DisplayStack();
};
void Stack::PUSH(char val){
	if (top == StackSize - 1) StackFull();
	else sarr[++top] = val;
};
void Stack::PUSH(int val){
	if (top == StackSize - 1) StackFull();
	else iarr[++top] = val;
};
char Stack::POP(){
	if (top == -1) StackEmpty();
	else return sarr[top--];
};
int Stack::Pop(){
	if (top == -1) StackEmpty();
	else return iarr[top--];
};
void Stack::DisplayStack(){
	int sp; sp = top;
	while (sp != -1){cout << (sarr[sp--] - '0') << " ";}
	cout << endl;
}; //Stack

Stack s;
void ConPostFix(char []);
int Operator(char a);
void PostEval(char eval[]);

/*********************************************************************************************************
*function : main()
*Description : main함수에서 파일을 한줄씩 읽어들여 그 식을 배열 arr에 char타입으로 담은 후 postfix로 변환하는 함수를 호출
*Variables : char arr[] - infix인 수식을 담은 배열. 파일의 한줄씩 읽어 담도록함
				ifstream - in이라는 생성자로 파일을 읽음
				getline - arr이라는 배열에 한줄씩 읽어 담도록 함
*********************************************************************************************************/

int main(){
	char arr[100];
	ifstream in("hw2.txt");
	while (in.getline(arr, 100)){
		cout << "1) Enter data (infix form) : " << arr << endl;
		ConPostFix(arr);
		cout << endl;
	}
}

/*********************************************************************************************************
*function : ConPostFix(char arr[])
*Description : 인자로 받은 arr배열을 Stack을 이용하여 Postfix로 변환해 eval배열에 담음. 각 배열을 token으로 읽어들여 token이 연산자가 아니면 바로 eval에 담고, 연산자라면 Operator라는 함수를 호출하여, 우선순위를 판단하고 Push혹은 Pop하여 eval배열을 채운뒤 postfix된 배열을 출력하고 PostEval함수를 호출하여 계산값을 출력하도록함
*Variables : char eval[] - infix 수식을 postfix하여 담을 배열
				char token - arr배열을 한글자씩 읽어들이기 위해 담을 변수
				int i - eval의 index 카운터
				PostEval(char []) - postfix배열을 이용하여 eval하는 함수
*********************************************************************************************************/

void ConPostFix(char arr[]){
	char eval[100];
	char token;
	int i = 0; //eval index 초기화
	s.reset(); //Stack의 배열들을 모두 초기화 하도록 
	cout << "2) Conversion (postfix form) : ";
	for (int j = 0; j < strlen(arr); j++){
		token = arr[j];
		switch(token){
			case '(':
				s.PUSH(token);
				break;
			case ')':
				while (s.Set_Top() != '('){//Stack의 Top이 '('일때까지 순
					eval[i++] = s.POP();
				}
				s.POP();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (Operator(token) > Operator(s.Set_Top())) s.PUSH(token); //Operator함수를 통해 token의 우선순위 판단
				else {
					eval[i++] = s.POP();
					s.PUSH(token);
				}
				break;
			default:
				eval[i++] = token;
		}
	}
	while (s.index_Top() >= 0){ //Top의 index값이 초기값이 될 때 까지
		eval[i++] = s.POP();
	}
	for (int j = 0; j < i; j++){
		cout << eval[j] << " "; //postfix 출력
	}
	cout << endl;
	PostEval(eval); //eval하기위해 PostEval호출
}

/*********************************************************************************************************
*function : Opertaor(char a)
*Description : 인자값에 따라 값을 반환하는 함수. '+','-'는 1을 '*','/'는 2를 반환하도록 함
*Variables : int weight - 인자값에 따라 해당값을 담아주는 변
*********************************************************************************************************/

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

/*********************************************************************************************************
*function : PostEval(char [])
*Description : 인자로 받은 postfix배열 eval을 한글자씩 token으로 읽어들여, 들어온값이 숫자이면 Stack에 Push하고 , 연산자라면 이전 2개의 값을 Pop하여 각각 변수에 담아 연산하고 Push하도록 함. 마지막엔 eval된 값을 출력함
*Variables : int op1, op2 - 연산을 하기위해 push된 이전의 두개의 값을 담는 변수
				char token - eval배열의 값을 한글자씩 읽기위해 담는 변수
				isdigit() - 들어온 값이 변환하였을때 int로 변환 가능하면 0이아닌 수를 반환하여, 숫자인지 판별하기 위한 함수
*********************************************************************************************************/

void PostEval(char eval[]){
	s.reset();
	int op1, op2;
	char token;
	
	for (int j = 0; j < strlen(eval); j++){
		token = eval[j];
		switch (token){
			case '+':
				op2 = s.Pop();
				op1 = s.Pop();
				s.PUSH(op1 + op2);
				break;
			case '-':
				op2 = s.Pop();
				op1 = s.Pop();
				s.PUSH(op1 - op2);
				break;
			case '*':
				op2 = s.Pop();
				op1 = s.Pop();
				s.PUSH(op1 * op2);
				break;
			case '/':
				op2 = s.Pop();
				op1 = s.Pop();
				s.PUSH(op1 / op2);
				break;
			default:
				if (isdigit(token)) s.PUSH(token - '0'); //숫자가 들어오면 그 값을 int로 하여 Stack의 int형 배열 iarr에 Push
				break;
		}
	}
	cout << "3) Result : " << s.Pop() << endl;
}
