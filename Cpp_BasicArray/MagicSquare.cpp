//20191644 이연주
#include <iostream>
using namespace std;

int n, l_square[50][50], r_square[50][50];

void magic(){
	int k, l, row, col;
	for (k = 0; k < n; k++){
		for (l = 0; l < n; l++){
			l_square[k][l] = 0;
			r_square[k][l] = 0;
		}
	} // square를 0으로 초기화
	int key = 2, i = 0, j = n / 2;
	l_square[i][j] = 1; //첫 행의 중간에서 시작
	r_square[i][j] = 1;

	while(key <= n * n){//왼쪽 위방향
		if (i - 1 < 0) row = n - 1; else row = i - 1;
		if (j - 1 < 0) col = n - 1; else col = j - 1; //0, 2, 2, 1, 0, 0, 2, 1

		if (l_square[row][col]) i = (i + 1) % n; else {i = row; j = col;}
		l_square[i][j] = key++;	
	}
	
	key = 2, i = 0, j = n / 2;

	while(key <= n * n){
		if (i - 1 < 0) row = n - 1; else row = i - 1; //2, 1, 2, 1, 0, 1, 0, 2
		if (j + 1 > n - 1) col = 0 ; else col = j + 1; // 2, 0, 0, 1, 2, 2, 0, 1

		if (r_square[row][col]) i = (i + 1) % n; else {i = row; j = col;}
		r_square[i][j] = key++;
	}
}

int main(){
	cout << "Enter number of square : " << endl;
	cin >> n;
	magic();
	cout << "Magic square size is " << n << endl << "(Left)" << endl; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << l_square[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << "(Right)" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << r_square[i][j] << "  ";
		}
		cout << endl;
	}
}
