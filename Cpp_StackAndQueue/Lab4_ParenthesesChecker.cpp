#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int StackSize = 100;
string arr[100];
int i = 0;
int validity;

class Stack{
	private:
		char sarr[StackSize]; int top;
	public:
		Stack() {top = -1;}
		void reset() {top = -1;}
		void PUSH(char val){sarr[++top] = val;}
		char POP() {return sarr[top--];}
		bool StackEmpty(){return top == -1;}
		bool StackFull(){return top == StackSize - 1;}
		void DisplayStack();
};
void Stack::DisplayStack(){
	int sp; sp = top;
	while (sp != -1){cout << sarr[sp--] << " ";}
	cout << endl;
}; //Stack

int Check(char []);
bool Match(char tmp, char s);
int mimatched, balanced, unbalanced;

Stack s;

int main(){
	ifstream in("Lab4.txt");
	char buffer[80]; //string line;
	while(in.getline(buffer, 80)){
		cout << i + 1 << ". " << buffer << endl;
		i += 1;
		validity = Check(buffer);
		switch(validity){
			case 0:
				mimatched += 1;
				break;
			case 1:
				cout << "The Expression is Valid.\n"; balanced += 1;
				break;
			case 2:
				unbalanced += 1;
				break;
		}
		cout << endl;
	}
	cout << "Total : valid : " << balanced << " Unbalanced : " << unbalanced << " Mismatched : " << mimatched << endl;
}

int Check(char exp[]){
	char temp;
	s.reset();
	for (int j = 0; j < strlen(exp); j++){
		if (exp[j] == '(' || exp[j] == '{' || exp[j] == '[') s.PUSH(exp[j]);
		if (exp[j] == ')' || exp[j] == '}' || exp[j] == ']') {
			if (s.StackEmpty()) {
				cout << "The Expression has unbalanced parentheses.\n";
				return 2;
			}
			else {
				temp = s.POP();
				if (!Match(temp, exp[j])) {
					cout << "Mismatched " << temp << " and " << exp[j] << endl;
					return 0;
				}
			}
		}
	}
	if (s.StackEmpty()) return 1;
	else cout << "The Expression has unbalanced parentheses.\n"; return 2;
}

bool Match(char tmp, char s){
	if ((tmp == '(' && s == ')') || (tmp == '{' && s == '}') || (tmp == '[' && s == ']')) return true;
	else return false;
}
