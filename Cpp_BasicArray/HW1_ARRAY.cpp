/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 1 - 배열연습
*Description : 파일을 읽어들여 배열을 담고 그 배열을 transpose 하여 저장하는 프로그램과 희소행렬을 만드는 프로그램, 그 희소행렬을 전치행렬로 저장하는 프로그램
*Algorithm : 배열에 값을 저장, 텍스트파일을 읽고 저장, transpose & fast transpose 알고리즘, struct사용
*Variables : struct Matrix_value - 파일을 읽어 배열을 만들고, 그 값을 저장하는 struct
				struct Temp - 희소행렬의 각 row, column, value값을 저장하는 struct
				matrix[][] - 읽은 파일의 배열(origin matrix)가 담긴 배열
				trans_matrix[][] - matrix[][]의 전치행렬을 저장하는 struct배열
				a[] - matrix[]의 희소행렬의 struct배열
				b[], c[] - a[]의 전치행렬(일반전치, fast transpose를 이용하여 전치)을 저장하는 struct배
*********************************************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;

struct Matrix_value{
	int value;
};

struct Temp{
	int row;
	int col;
	int value;
};

Matrix_value matrix[100][100], trans_matrix[100][100];
Temp a[100], b[100], c[100];

int i, j, cnt, currentb;
void MakeMatrix();
void TransMatrix();
void RowMajor();
void TransSparseMatrix();
void Fast_Transpose(); // 19-23 : 함수에대한 선언

/*********************************************************************************************************
*function : main()
*Description : main함수에서 각 출력을 해야하는 origin matrix A와 A의 전치행렬, A의 희소행렬 a, a의 전치행렬 b, c를 구하는 함수들을 호출
*********************************************************************************************************/
int main(){
	MakeMatrix();
	TransMatrix();
	RowMajor();
	TransSparseMatrix();
	Fast_Transpose();
}

/*********************************************************************************************************
*function : MakeMatrix()
*Description : 텍스트파일을 읽고 origin matrix A를 만들고 A를 출력하는 함
*Variables : ifstream - in이라는 생성자로 파일을 읽음
				matrix[][] - origin matrix A를 위한 struct배열로, 그 행렬에 해당하는 value값 저장
*********************************************************************************************************/
void MakeMatrix(){
	ifstream in("hw1.txt"); //생성자로 파일열기
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			in >> matrix[i][j].value; //struct를 이용하여 배열의 값을 입력
		}
	}
	cout << "1) Original Matrix A" << endl;
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			cout << matrix[i][j].value << " ";
		}
		cout << endl; //origin matrix 출력
	}
	cout << endl;	
}

/*********************************************************************************************************
*function : TransMatrix()
*Description : origin matrix A의 전치행렬(열과 행이 바뀐 행렬)을 구하고 출력하는 함수
*Variables : trans_matrix[][] - origin matrix A의 전치행렬의 value값을 담는 struct배열
*********************************************************************************************************/
void TransMatrix(){
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			trans_matrix[i][j].value = matrix[j][i].value; // i,j를 바꾸어 trans_matrix를 만듦
		}
	}
	cout << "2) Transpose of Original Matrix A" << endl;
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			cout << trans_matrix[i][j].value << " ";
		}
		cout << endl;
	} // trans_matrix 출력
	cout << endl;
}

/*********************************************************************************************************
*function : RowMajor()
*Description : origin matrix A의 원소들로 희소행렬을 구하고 출력하는 함수
*Variables : cnt - value의 수를 세는 변수
				a[] - A의 희소행렬 a의 값을 저장하는 struct배열로 row, col, value의 값을 가짐 
*********************************************************************************************************/
void RowMajor(){
	cnt = 1;
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (matrix[i][j].value){
				a[cnt].row = i;
				a[cnt].col = j;
				a[cnt++].value = matrix[i][j].value; //matrix[i][j]에 값이 있다면, 그 값과 col, row값을 저장함
			}
		}
	}
	a[0].col = 6, a[0].row = 6, a[0].value = cnt - 1; //A matrix의 sparse matrix a의 col, row, value의 갯수를 0번째에 저장

	cout << "3) Sparse matrix of A - row major" << endl;
	for (i = 1; i <= a[0].value; i++){
		cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
	} // A의 sparse matrix인 a 출력
	cout << endl;
}

/*********************************************************************************************************
*function : TransSparseMatrix()
*Description : 희소행렬 a의 원소들을 이용하여 전치행렬 b를 구하고 출력하는 함수
*Variables : b[] - a의 전치행렬로 row, col, value의 값을 담음
				currentb - 현재의 위치를 나타내는 변수
*********************************************************************************************************/
void TransSparseMatrix(){
	if(a[0].value > 0) { //행렬의 값이 존재할 경우
		currentb = 1;
		for (i = 0; i < a[0].col; i++){
			for (j = 1; j <= a[0].value; j++){
				if (a[j].col == i){ //a[j]의 col을 0부터 순서대로 해야 trans(col위주)됨
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb++].value = a[j].value;
				}
			}
		}
	} 
	cout << "4) Transpose of Sparse Matrix A - column major" << endl;
	for (i = 1; i <= a[0].value; i++){
		cout << b[i].row << " " << b[i].col << " " << b[i].value << " " << endl;
	} //a의 trans b출력
	cout << endl;
}

/*********************************************************************************************************
*function : Fast_Transpose()
*Description : 희소행렬 a의 전치행렬인 c를 구하고 출력하는 함수
- > fast transpose 사용하지 않을경우 3중 for문으로 인해, 대략 col + 1 + colvalue + col + 3colvalue = 4colvalue + 2col + 1 으로 O(colvalue)로 나타날 수 있음
- > fast transpose 사용시, 단일 반복문을 여러번 사용했기 때문에 대략 col + 1 + col + value + 1 + 3value = 4value + 2col + 1 로 col과 value에 따라 시간복잡도를 구할 수 있고 O(colvalue)보다는 확연히 적은 시간복잡도가 이루어짐.
*Variables : row_terms[] - row의 값의 개수를 저장하는 배열
				starting_pos[] - 각 row의 index값을 저장하는 배열
				k, l - for문을 위한 변수
				num_cols - col의 수(전치행렬이므로 c의 row의 수)
				num_terms - value의 수 
*********************************************************************************************************/
void Fast_Transpose(){ //fast_transpose
	int row_terms[100], starting_pos[100];
	int k, l, num_cols = a[0].col, num_terms = a[0].value; 

	c[0].row = num_cols, c[0].col = a[0].row, c[0].value = num_terms;

	if (num_terms > 0){
		for (k = 0; k < num_cols; k++) row_terms[k] = 0; //row_terms를 초기화
		for (k = 0; k <= num_terms; k++) row_terms[a[k].col]++; //row_terms에 col의 값의 갯수를 구해 입력
	}
	starting_pos[0] = 1; //col에 해당하는 시작점을 정해주는 배열
	for (k = 1; k < num_cols; k++){
		starting_pos[k] = starting_pos[k - 1] + row_terms[k - 1]; //각 col의 시작점을 담아줌
	}
	for (k = 1; k <= num_terms; k++){
		l = starting_pos[a[k].col]++;
		c[l].row = a[k].col; c[l].col = a[k].row; //starting point로 trans
		c[l].value = a[k].value;
	}
	cout << "5) Fast transpose of Sparse matrix A" << endl;
	for (i = 1; i <= a[0].value; i++){
		cout << c[i].row << " " << c[i].col << " " << c[i].value << " " << endl;
	} //fast_trans를 이용한 a의 trans배열 c 출력
}
