#include <iostream>
using namespace std;

struct ArrayTemp{
	int row;
	int col;
	int value;
};
ArrayTemp a[100], b[100];

int currentb, i, j, n;
void transmatrix();
void fast_transpose();

int main(){

	cin >> a[0].row >> a[0].col >> a[0].value;
	for(i = 1; i < a[0].value + 1; i++){
		cin >> a[i].row >> a[i].col >> a[i].value;
	}
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	cin >> n;
	switch (n){
		case 1:
			transmatrix();
			break;
		case 2:
			fast_transpose();
			break;
	}
}

void transmatrix(){
	if(a[0].value > 0) {//0이 아닌 행렬
		currentb = 1;
		for (i = 0; i < a[0].col; i++){
			for (j = 1; j <= a[0].value; j++){
				if (a[j].col == i){
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb++].value = a[j].value;
				}
			}
		}
	}

	for (i = 0; i <= a[0].value; i++){
		cout << b[i].row << " " << b[i].col << " " << b[i].value << " " << endl;
	}
}

void fast_transpose(){
	int row_terms[100], starting_pos[100];
	int k, l, num_cols = a[0].col, num_terms = a[0].value;

	b[0].row = num_cols, b[0].col = a[0].row, b[0].value = num_terms;

	if (num_terms > 0){
		for (k = 0; k < num_cols; k++) row_terms[k] = 0;
		for (k = 0; k <= num_terms; k++) row_terms[a[k].col]++;
	}
	starting_pos[0] = 1;
	for (k = 1; k < num_cols; k++){
		starting_pos[k] = starting_pos[k - 1] + row_terms[k - 1];
	}
	for (k = 1; k <= num_terms; k++){
		l = starting_pos[a[k].col]++;
		b[l].row = a[k].col; b[l].col = a[k].row;
		b[l].value = a[k].value;
	}
	for (i = 0; i <= a[0].value; i++){
		cout << b[i].row << " " << b[i].col << " " << b[i].value << " " << endl;
	}
}
