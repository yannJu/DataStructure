/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 3 - miro
*Description : 6x6배열을 읽어들여 0으로 된 부분만 지나가 도착지점에 다다르면 종료되는 프로그램이다. 처음 미로 배열을 maze배열에 담고 위,아래,양,옆을 지나가지 못하게 하기위해 1로 채워 8x8배열로 만든다. 또한 지나갔는지 마크하기 위한 mark[8][8]배열을 만들어주는데 maze와 동일하게 가장자리를 1로 채워준다. Stack을 이용하여 시작점을 초기화하고 지나간곳의 좌표와 dir(어느방향인지 나타내는)을 struct로 저장하고 길을찾는데 이용한. 이러한 지나간 좌표와 마크된 배열을 출력하도록 하는 프로그램이다.
*Algorithm : 미로배열과, 마크하기위한 마크배열을 초기화(설정)하고 Stack이 비어있지 않으며, 아직 도착지점을 찾지 못했을 경우 이전에 지나온 좌표를 Stack에서 가져와서 그다음 지나갈 좌표가 0인지 확인하기 위해 next_row와 next_col을 이용하여 8가지 방향을 오른쪽방향으로 체크한다. 
좌표가 0이면서, 이전에 지나가지 않은(mark좌표가 0인경우)경우 해당 좌표를 mark배열에서 1로 설정하고 Stack에 구조체타입(Element)으로 PUSH해준다. 
좌표가 0인 부분이 없으면 backtracking을 통해 바로이전으로 돌아간뒤 이전에 확인하지 않은 방향부터 체크하도록 한다.
이러한 과정을 거쳐서 도착지점을 찾은경우 found를 1로 설정하고 해당 좌표를 Stack에 POP하고 mark배열에 마크해준후 반복문을 종료한다.
*Variables : const int StackSize - Stack클래스에서 사용하는 구조체 배열 stack의 배열크기 고정
	   sturuct Element - 현재 좌표와 방향을 담기위한 구조체				
	   Class Stack - Stack을 하기 위한 클래스
	   struct Offsets - 방향에 따른 그다음 좌표를 설정하기 위해 해당 vert, horiz 를 담은 구조
	   int maze[][] - 미로를 담은 배열, int mark[][] - 지나간좌표를 마크하기위한 배열
	   void MIROPATH(); - 미로의 길을 찾기 위한 함수, 도착지점에 도달할 경우 mark배열과 지나간 좌표를 출력하도록 한다.
*********************************************************************************************************/
#include <iostream>
using namespace std;

const int StackSize = 50; //StackSize 설정

struct Element{
	int row;
	int col;
	int dir;
}; //이전좌표를 저장하기 위한 구조

class Stack{
	private:
		Element stack[100];
		int top;
	public:
		Stack(){
			stack[0].row = 1; stack[0].col = 1; stack[0].dir = 0; // 시작점 설정. 좌우양옆이 1로 둘러싸인 배열이기 때문에 미로를 기준으로는 (0.0)
			top = 0;
		}		
		void reset() {top = 0;}
		void PUSH(Element position);
		Element POP() {return stack[top--];}
		bool StackFull() {return top == StackSize - 1;}
		bool StackEmpty() {return top == -1;}
		int setTop() {return top;}
		void displayStack(int val) {cout << " " << stack[val].row - 1 << "    " << stack[val].col - 1<< endl;} //PATH를 출력하기 위해 Stack출력
}; //Stack클래스
void Stack::PUSH(Element position){
	stack[++top] = position;
};

struct Offsets{
	int vert;
	int horiz;
}; //방향에 해당하는 vert와 horiz를 담을 구조체


void MIROPATH(Stack s, int final_row, int final_col);

int maze[8][8] = 
	{
	 {1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 1, 1, 1, 1, 1, 1},
	 {1, 1, 0, 1, 1, 1, 1, 1},
	 {1, 1, 0, 0, 0, 0, 1, 1},
	 {1, 1, 1, 0, 1, 1, 1, 1},
	 {1, 1, 0, 1, 0, 0, 1, 1},
	 {1, 1, 1, 1, 1, 1, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1}
	};	//1로 둘러싸인 미로이므로 8x8 이고 (1.1)~(6.6)부분이 미로에 해당
	int mark[8][8] = 
	{
	 {1, 1, 1, 1, 1, 1, 1, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 0, 0, 0, 0, 0, 0, 1},
	 {1, 1, 1, 1, 1, 1, 1, 1}
	}; //1로 둘러싸여있기 때문에 8x8로 표시하고, maze와 마찬가지로 (1.1)~(6.6) 가 해당됨

/*********************************************************************************************************
*function : main()
*Description : Stack클래스를 생성하고, 도착지점을 설정하여 준다. 그리고 길을 찾기위한 함수인 MIROPATH를 호출한다.
*Variables : Stack s - Stack클래스의 생성자
	   int final_row, int final_col - 도착지점의 좌표의 행과 열을 설정하는 변수
*********************************************************************************************************/

int main(){
	Stack s;
	int final_row = 6, final_col = 6; //도착지점 설정. 1로 둘러싸인 배열을 고려하였을때 도착지점 (5.5)를 의미함. 도착지점이 (4.4)일경우 final_row = 5, final_col = 5
	MIROPATH(s, final_row, final_col);
}

/*********************************************************************************************************
*function : MIROPATH(Stack s, int final_row, int final_col)
*Description : 인자로 받은 Stack을 이용하여 maze의 길을 찾고 지나간 길을 mark에 표시하는 함수이다. Stack이 비어있지 않으면서 도착지점이 아닌경 Element구조체의 생성자 position을 이용하여 이전 좌표를 Stack에서 가져오고 position을 통해 동서남북 약 8방향을 오른쪽 기준으로 갈수있는 길을 찾는다. 다음좌표에 해당하는 부분이 0인 경우 그 좌표를 Stack에 PUSH해주고, 다음좌표에 해당하는 좌표가 0인 부분이 없는경우 backtracking을 통해 체크해준다. 이러한 과정을 도착지점에 도달할 때 까지 반복하여 길을 찾는 알고리즘이다. 도착지점에 도착하면 found를 1로 설정하고 해당 좌표를 PUSH, mark해주면 found에 의해 그다음 반복문이 돌지않고 종료된다. 반복문이 종료되면 해당 mark배열과 PATH를 나타내는 좌표들(Stack에 저장되어 있음)을 출력한다.
*Variables : int found - 도착지점에 도달하였는지 체크하기위한 flag
	   int row, col, dir - 이전좌표의(즉 현재좌표) 행, 열, 그리고 어느방향인지 저장하기 위한 변수
	   int next_row, next_col - 그다음 가야할 좌표의 행과 열을 저장하기 위한 변수
	   Element position - 이전좌표를 POP해줄 때 저장하기위한 구조체
	   Offsets move[] - NESW등 해당하는 방향으로 다음 좌표를 설정하기 위한 vert와 horiz를 담는 구조체배열
*********************************************************************************************************/

void MIROPATH(Stack s, int final_row, int final_col){
	int found = 0; //도착지점에 도착하였는지 유무판별을 위한 변수
	int row, col, dir;
	int next_row, next_col; //이전좌표의 행,열,방향과 다음좌표의 행,열
	Element position;

	Offsets move[8];
	
	mark[1][1] = 1; //초기좌표를 마킹

	move[0].vert = -1; move[0].horiz = 0;
	move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0; move[2].horiz = 1;
	move[3].vert = 1; move[3].horiz = 1;
	move[4].vert = 1; move[4].horiz = 0;
	move[5].vert = 1; move[5].horiz = -1;
	move[6].vert = 0; move[6].horiz = -1;
	move[7].vert = -1; move[7].horiz = -1; //방향에 해당하는 좌표를 설정하기 위한 vert와 horiz 설정

	s.reset(); //Stack 초기화

	while (s.StackEmpty() == 0 && found == 0){ //Stack이 비어있거나 도착지점에 도달할 경우 종료
		position = s.POP(); //이전좌표를 POP
		row = position.row; col = position.col; dir = position.dir; //이전좌표를 각각 할당
		while (dir < 8 && found == 0){ //모든방향을 확인해 보았거나 도착지점에 도달한경우 종료
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz; //다음좌표 설정(0인지 체크하기위해)
			
			if (row == final_row && col == final_col) {//도착지점일 경우
				found = 1; //도착지점에 도착하였다는 것을 표시
				mark[row][col] = 1; //mark배열에 마킹
				position.row = row; position.col = col; position.dir = ++dir;
				s.PUSH(position); //현재 좌표를 Stack에 PUSH
			}
			else if (!maze[next_row][next_col] && !mark[next_row][next_col]){//아직 지나가지 않은 길이면서 다음좌표의 값이 0인경우
				mark[next_row][next_col] = 1; //그 좌표로 이동(마킹)
				position.row = row; position.col = col; position.dir = ++dir; 
				s.PUSH(position);
				row = next_row; col = next_col; dir = 0;
			}
			else ++dir; //
		}
	} 
	if (found){ //도착지점에 도달한 경
		cout << "The Path is\n\nrow  col\n";
		for (int i = 0; i <= s.setTop(); i++){
			s.displayStack(i);
		} //PATH출력
		cout << endl << "Marked Matrix\n";
		for (int i = 1; i < 7; i++){
			for (int j = 1; j < 7; j++){
				cout << " " << mark[i][j] << " ";
			}
			cout << endl;
		} //1로 둘러싸인 배열이므로 1부터 6까지만 반복하여 mark배열 출력
	}  
}
