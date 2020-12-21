#include <iostream>
using namespace std;

int starta = 0, startb, startd, finisha  = 0, finishb, finishd, tmp;

void polyadd();
void subtract();
void attach(int coef, int expon);
int compare(int a, int b);

struct Terms{
	int expon;
	int coef;
};

struct Terms t[50];

int main(){
	int c, e, as;
	cout << "(1)Addition/ (2)Subtraction? type 1 or 2" << endl;
	cin >> as;
	while(1){
		cin >> c >> e;
		t[finisha].expon = e;
		t[finisha++].coef = c;
		if (e == 0) break;
	}
	finisha--;
	startb = finishb = finisha + 1;
	while(1){
		cin >> c >> e;
		t[finishb].expon = e;
		t[finishb++].coef = c;
		if (e == 0) break;
	}
	finishb--;
	startd = finishd = finishb + 1;
	switch (as){
		case 1: polyadd(); break;
		case 2: subtract(); break;
	}
	for(; startd <= finishd; startd++){
		if (t[startd].coef == 0) continue;
		cout << t[startd].coef << " " << t[startd].expon << " ";
	}
	cout << endl;
}

void polyadd(){
	while (starta <= finisha && startb <= finishb){
		switch (compare(t[starta].expon, t[startb].expon)){
			case -1:
				attach(t[startb].coef, t[startb].expon);
				startb++; break;
			case 0:
				tmp = t[starta].coef + t[startb].coef;
				if(tmp){
					attach(tmp, t[starta].expon);
				}
				starta++; startb++; break;
			case 1:
				attach(t[starta].coef, t[starta].expon);
				starta++; break;
		}
	}

	for(; starta <= finisha; starta++){
		attach(t[starta].coef, t[startb].expon);
	}
	for(; startb <= finishb; startb++){
		attach(t[startb].coef, t[startb].expon);
	}
	
	finishd -= 1;
}

void subtract(){
	while (starta <= finisha && startb <= finishb){
		switch (compare(t[starta].expon, t[startb].expon)){
			case -1:
				attach(t[startb].coef, t[startb].expon);
				startb++; break;
			case 0:
				tmp = t[starta].coef - t[startb].coef;
				attach(tmp, t[starta].expon);
				starta++; startb++; break;
			case 1:
				attach(t[starta].coef, t[starta].expon);
				starta++; break;
		}
	}

	for(; starta <= finisha; starta++){
		attach(t[starta].coef, t[starta].expon);
	}	
	for(; startb <= finishb; startb++){
		attach(t[startb].coef, t[startb].expon);
	}	

	finishd -= 1;
}
void attach(int coef, int expon){
	if (finishd >= 50){
		cout << "Too Many Elements..\n";
	}
	else{
		t[finishd].coef = coef;
		t[finishd++].expon = expon;
	}
}

int compare(int a, int b){
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}
