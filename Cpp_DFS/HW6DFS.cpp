/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 6 - DFS
*Description : DFS는 깊이우선탐색을 의미하며, 그래프 연산방법중 하나이다. 텍스트파일을 읽어들여, 그래프를 만들 인접 리스트로 DFS를 표현하는데, Node타입의 배열 graph에 각 vertex노드를 담고, 인접한 노드들을 링크로 연결하도록한다. 인접한 리스트로 그래프를 표현한 후에는, 방문여부에 따라 방문하지 않은 Node배열의 원소노드를 재귀적으로 탐색하도록한다. 따라서 DFS후, 결과를 출력하는 프로그램이다.
*Algorithm : 테스트 케이스의 노드가 최대 8개이므로, 방문배열과 Node타입의 graph배열의 크기를 8로 const형태로 지정하여 준다. 노드클래스를 만들어 주는데, 데이터 값을 담는 변수 data와 링크를 내부에 생성해주고, 클래스 생성시 들어오는 인자값을 data로 지정하고 link는 NULL값으로 초기화 하는 클래스를 만들어준다. 이 노드를 이용하여 dfs할 수 있는 그래프인 Tree 클래스를 이용해 dfs해 주도록한다. dfs는 초기값 노드0을 입력받도록 하는데 '0'노드를 방문표시 한 후에, 출력하고 '0'노드와 인접해있는 노드를 링크를 통해 탐색하고, 그 노드가 방문되지 않은 노드이면 dfs함수를 다시 호출해 인접한 링크를 인자로 전달하는 재귀함수를 통해 dfs하도록 한다. 그후 모두 방문하였거나, 연결된 노드가 없을 경우 dfs를 마친다.
*Variables : const int ArrSize - 방문 배열의 크기 지정
	   const int GraphSize - 그래프 노드를 담는 배열의 크기 지정
	   class Node - 노드 클래스
	   class Tree - 그래프를 만드는 tree클래스
*********************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int ArrSize = 8;
const int GraphSize = 8;

class Node{
private:
	int data;
	Node *link;
	Node(int num) {data = num; link = NULL;}
friend class Tree;
};

class Tree{
private:
	Node *graph[GraphSize];
	bool visit[ArrSize];
public:
	Tree();
	void build(int p, int c);
	void dfs(int v);
	void print_graph();
};
/*********************************************************************************************************
*function : Tree()
*Description : Tree클래스 객체가 생성될 때 호출되는 default 생성자. 방문배열을 초기화 해주고 graph배열을 초기화 해준다.
*********************************************************************************************************/

Tree::Tree(){
	for (int i = 0; i < ArrSize; i++){
		visit[i] = false;
	}
	for (int i = 0; i < GraphSize; i++){
		graph[i] = NULL;
	}
}/*********************************************************************************************************
*function : build(int p, int c)
*Description : 연결된 노드(p와 c)들이 인자로 들어오면, 부모노드 p노드에 c를 연결해주도록 하는 tree를 생성하고 인접한 리스트로 만들도록 하는 함수. 들어온 노드들이 graph에 없는경우 새로운 노드를 만들어 graph배열에 담고, p를 부모노드로 하여, p노드 끝에 c노드를 연결함으로써, 인접리스트를 생성한다.
*Variables : Node *temp_P - 부모노드 p를 담는 위치가 비어있을 때 부모노드를 만드는 노드
	   Node *temp_C - 자식노드 c를 담는 위치가 비어있을 때 자식노드를 만드는 노드
	   Node *P - 부모노드가 변경되지 않도록 할당하는 포인터변수
	   Node *C - 부모노드의 끝에 링크하기 위해 생성하는 노드
*********************************************************************************************************/

void Tree::build(int p, int c){
	if (graph[p] == NULL){
		Node *tmp_P = new Node(p);
		graph[p] = tmp_P;
	}
	if (graph[c] == NULL){
		Node *tmp_C = new Node(c);
		graph[c] = tmp_C;
	}

	Node *P = graph[p];
	Node *C = new Node(c);
	while (P->link != NULL) P = P->link;
	P->link = C;
}
/*********************************************************************************************************
*function : dfs(int v)
*Description : DFS를 하기 위한 함수. 들어오는 인자 v는 그래프의 초기 root인 0을 의미한다. 그래프의 root가 들어오면, 그 루트의 방문여부를 true로 설정하고, 출력한 후, root노드를 계속 link하여 null값이 나올때 까지 반복하고, 인접한 노드가 방문되지 않은 노드이면 다시 dfs를 호출하여 위의 과정을 반복한다.
*Variables : Node *w - 그래프를 탐색하기위한 포인터 변수
*********************************************************************************************************/

void Tree::dfs(int v){
	Node *w;
	visit[v] = true;
	cout << "V" << v;
	for (w = graph[v]; w != NULL; w = w->link){
		if (!visit[w->data]) {
			cout << " -> ";
			dfs(w->data);
		}
	}
}
/*********************************************************************************************************
*function : print_graph()
*Description : graph를 전체 출력하는 함수. 인접한 리스트로 표현되어있기 때문에, graph배열을 돌면서 각 노드가 link되어있는 노드들도 모두 출력하도록 한다. 만약 graph 원소가 비어있으면 출력하지 않는다.
*Variables : Node *w - 그래프를 탐색하기 위한 포인터 변수
*********************************************************************************************************/

void Tree::print_graph(){
	Node *w;
	for (int i = 0; i < GraphSize; i++){
		if (graph[i] != NULL){
			cout << "Graph[" << i << "]   ->  ";
			for (w = graph[i]->link; w != NULL; w = w->link){
				cout << w->data << " ";
			}
			cout << endl;
		}
	}
}
/*********************************************************************************************************
*function : main()
*Description : 그래프를 생성하고 dfs를 테스트하기위한 main 함수. 텍스트 파일을 읽어들여 그 값을 통해 그래프 생성 후 인접리스트로 표현한 값을 화면에 출력하고 dfs한 후 출력하도록 한다.
*Variables : Tree t1, t2 - 테스트 하기 위한 그래프 객체.(테스트하기 위해 각 노드의 값과 간선의 개수를 미리 지정함)
	   ifstream in - "hw6.txt"파일을 읽어들이기 위한 ifstream객체
	   int num1, num2 - num1은 부모노드를, num2는 자식노드를 입력받아 그래프를 생성하도록 한다.
*********************************************************************************************************/

int main(){
	Tree t1, t2;
	ifstream in("hw6.txt");
	int num1, num2;

	for (int i = 0; i < 20; i++){
		in >> num1 >> num2; //파일을 읽어들여 그 값을 num1, num2에 할당
		t1.build(num1, num2);
	}
	cout << "Graph Data #1: \n";
	t1.print_graph();
	cout << "\nOutput : \n";
	t1.dfs(0);
	cout << endl;
	for (int i = 0; i < 16; i++){
		in >> num1 >> num2;
		t2.build(num1, num2);
	}
	cout << "Graph Data #2: \n";
	t2.print_graph();
	cout << "\nOutput : \n";
	t2.dfs(0);
	cout << endl;
}
