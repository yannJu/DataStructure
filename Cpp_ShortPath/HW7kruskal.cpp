/*********************************************************************************************************
*Name : 이연주
*Student ID : 20191644
*Program ID : HW 7 - Kruskal's MST
*Description : MST는 최소비용신장트리를 의미하며 계산방법에는 Kruskal, prim, sollin등이 있고 Greedy method를 사용한다.
특히 Kruskal알고리즘은, 한번에 한 간선씩 최소비용을 구축하고 오름차순으로 비용순으로 간선을 정렬하고 cycle이 되지 않으면서 간선이 총 정점 - 1인 경우 까지 반복하여 MST를 이루도록 한다. 이 프로그램은 텍스트파일을 읽어 노드의 정점과 cost를 할당해주고 인접리스트로 트리를 받아온 후 cost가 작은 순으로 sort배열에 담아, 그 배열을 kruskal알고리즘으로 MST를 구현한 후 출력하는 프로그램이다.
*Algorithm : 텍스트파일에서 두개의 정점과 비용을 받아 Node로 만든 후 , 연결되는 정점끼리 link를 하여 인접리스트를 구현한다.
먼저 노드클래스를 구현하여 무방향그래프지만, 시작정점과 종료정점으로 두어 연결된 정점들을 저장하고, 비용을 저장한다. 그다음 sort할 때 방문한 노드인지 체크하기 위해 val변수 또한 만들어 주어 구현하였다. 이러한 노드들을 사용하여 인접리스트를 탐색하는데 cost가 작은 순으로 cost_G배열에 담으면 Node들을 원소로 갖는 배열이 생성된다. 그 배열의 간선의 갯수가 정점의 수보다 하나 작을때 까지만 반복하여, cycle이 되지 않는 노드들을 간선으로 연결하여 트리를 생성한다.
*Variables : const int MAX_ARY - 정점의 갯수를 담는 배열
	   const int MAX_EDGE - 간선의 갯수를 담는 배열
	   char check[] - 노드의 이름을 저장해 놓은 배열, 프로그램에서는 계속 배열의 idx를 나타내기 위해 idx사용이 헷갈리지 않게 하기 위해 사용
	   class Node - 노드 클래스
	   class Tree - 그래프를 만들고 kruskal알고리즘을 사용하는 tree클래스
*********************************************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ARY = 6;
const int MAX_EDGE = 10;
char check[MAX_ARY] = {'A', 'B', 'C', 'D', 'E', 'F'};

class Node{
	private:
		char begin;
		char end;
		int cost;
		Node *link;
		int val;
		Node(char c, char e, int num) {begin = c; end = e; cost = num; link = NULL; val = 0;}
	friend class Tree;
};

class Tree{
	private:
		Node *graph[MAX_ARY];
		Node *sort_G[MAX_EDGE];
		int visit[MAX_ARY];
		int parent[MAX_ARY];
	public:
		Tree(){ //Tree클래스가 실행되면 graph와 parent배열을 초기화 시켜준다.
			for (int i =0; i < MAX_ARY; i++){
				graph[i] = 0;
				parent[i] = -1; //parent원소가 음수인 경우 정점의 개수를 의미, 양수인 경우 루트의 idx표현, 따라서 초기값은 정점이 1개인 경우이므로 -1
			}
		}
		void insert(char, int, char);
		int sort(int);
		void print();
		int find_set(char); //루트 찾기
		void union_set(char, char); //집합으로 합치기
		void kruskal(); 
};
/*********************************************************************************************************
*function : main()
*Description : 'hw7.txt'파일을 읽어들여, 정점들과 비용을 인접리스트로 표현하도록 트리에 추가해주고, tree의 메소드인 sort를 이용하여 비용이 작은순으로 정렬한 후 Kruskal알고리즘을 실행하여 MST를 구현하는 프로그램을 호출하고 각각 출력하는 main함수이다.
*Variables : Tree t1 - Tree class의 객체
	   char p, q - 노드를 저장하는 변수
	   int r - 비용을 저장하는 변수
*********************************************************************************************************/

int main(){
	ifstream in("hw7.txt");
	Tree t1;
	char p, q;
	int r;
	
	cout << "<<INPUT DATA>> \n";
	for (int i = 0; i < 10; i++){
		in >> p >> r >> q;
		t1.insert(p, r, q); //노드의 정점과 비용을 tree에 추가하여준다
	}
	cout << endl;
	cout << "<<SORTED DATA>> \n";
	t1.sort(0);
	t1.print();
	cout << endl;
	cout << "<<KRUSKAL's MST>> \n";
	t1.kruskal();
}
/*********************************************************************************************************
*function : insert(char b, int c, char e)
*Description : 정점 두개와 비용을 인자로 받아, 각 정점의 인덱스를 구하고, 무방향이므로 첫번째 정점이 빈 tree라면 그 정점을 루트로 하고 그렇지 않다면, 첫번째 정점을 링크하여 새로운 노드를 만든 후 graph 노드배열에 담도록 한다. 노드에는 첫번째 정점과 그에 이어져 있는 정점, 그리고 비용을 저장한다. 각 노드들을 링크함을 통해 인접리스트를 생성한다.
*Variables : int begin_idx - 첫번째 정점의 이름(A, B...)를 저장하는 변수
	   int end_idx - 두번째 정점(첫번째 정점과 이어져있는 정점)의 이름을 저장하는 변수
	   Node *tmp_B - 첫번째 정점을 노드로 만들어 저장하는 노드포인터
	   Node *P - 첫번째 정점이 연결되어있는 집합을 담은 배열의 원소의 포인터를 저장
	   Node *C - P에 첫번째 정점을 링크하기 위해 할당하는 노드포인터
*********************************************************************************************************/

void Tree::insert(char b, int c, char e){
	int begin_idx, end_idx;

	for (int i =0; i < MAX_ARY; i++){
		if (check[i] == b) begin_idx = i;
		if (check[i] == e) end_idx = i;		
	} //begin, end 인덱스
	
	if (graph[begin_idx] == NULL){
		Node *tmp_B = new Node(check[begin_idx], check[end_idx], c);
		graph[begin_idx] = tmp_B;
	}
	else{
		Node *P = graph[begin_idx];
		Node *C = new Node(check[begin_idx], check[end_idx], c);
		while (P->link != NULL) {P = P->link;}
		P->link = C;
	}
	cout << check[begin_idx] << " " << c << " " << check[end_idx] << ", ";
}
/*********************************************************************************************************
*function : sort(int c)
*Description : 인접리스트인 graph배열을 cost가 작은 순으로 sort_G배열에 담는다. 먼저 모든 인접리스트를 다 검사하는데, 방문을 하지 않았으면서 mincost보다 작은 경우 그 노드를 가장 작은 노드(r)로 지정하고, r노드를 방문을 체크한 후, sort_G배열에 차례차례 담는다. 이 과정을 간선의 갯수만큼 하도록한다.
*Variables : Node *p - 정점이 변하지 않도록 할당해 놓는 변수
	   Node *r - mincost를 가지는 노드를 저장하는 변수
	   int mincost - 정점의 노드의 비용이 mincost보다 작으면 mincost에 할당하도록 저장하기 위한 변수
	   int costCnt - 배열의 인덱스를 지정하기 위한 변수
*********************************************************************************************************/

int Tree::sort(int c){
	Node *p;
	Node *r;
	int mincost = 999;
	int costCnt = c;

	if (costCnt == MAX_EDGE) return costCnt;

	for (int i =0; i < MAX_ARY; i++){
		p = graph[i];
		while(p != NULL){
			if (p->val == 0 && mincost > p->cost) {
				mincost = p->cost;
				r = p;
			}
			p = p->link;
		}
	}
	r->val = 1; sort_G[costCnt++] = r;
	costCnt = sort(costCnt);
}
/*********************************************************************************************************
*function : print()
*Description : Sorting된 인접리스트를 담은 배열을 출력하기 위한 함수.
*********************************************************************************************************/
void Tree::print(){
	for (int i =0; i < MAX_EDGE; i++){
		cout << sort_G[i]->begin << " " << sort_G[i]->cost << " " << sort_G[i]->end << ", ";
	}
	cout << endl;
}
/*********************************************************************************************************
*function : find_set(char n)
*Description : 노드의 루트노드의 인덱스를 찾기 위한 함수. 들어온 정점의 인덱스를 찾은 후, 각 정점의 부모노드 혹은 연결된 정점의 개수를 나타내는 parent배열을 탐색하는데, 원소가 양수인 경우 부모노드의 인덱스를 의미하며, 음수인경우 루트노드로써 루트노드의 집합속 원소개수를 의미한다. 따라서 parent[node_idx]가 양수인경우는 루트가 아니므로 그 구간동안 계속 부모노드를 타고올라가서, 루트에 도달하였을때의 인덱스를 반환하여 자신의 루트노드를 찾는다.
*Variables : int node_idx - 자신의 인덱스를 저장하는 변수
*********************************************************************************************************/

int Tree::find_set(char n){
	int node_idx;

	for (int i = 0; i < MAX_ARY; i++) {
		if (check[i] == n) node_idx = i;
	}

	while(parent[node_idx] >= 0){
		node_idx = parent[node_idx];
	}
	return node_idx;
}
/*********************************************************************************************************
*function : union_set(char node_a, char node_b)
*Description : 들어온 두 정점을 집합으로 합치는 함수이다. 먼저 노드가 변하지 않도록 tmp라는 변수를 만들어주고 각 노드의 인덱스를 구하여준다. 만약 두 각 인덱스에 해당하는 parent배열의 원소가 양수이면 루트가 아닌것을 의미하고, 음수이면 루트를 의미하므로, 두 원소가 루트인 경우 node_a(첫번째 정점)을 루트로 지정하여, 두번째 정점의 원소에는 첫번째 정점의 인덱스를 저장하여주고, node_a에 node_b의 원소를 더해줌으로써 (-1) 정점의 개수를 늘리도록한다. 그리고 만약 둘중 한 노드만 루트이고 다른 노드는 루트가 아닌 경우에는, 루트노드를 다른 노드의 집합에 더해주도록 한다. 루트노드가 아닌 노드의 부모노드에 루트노드의 원소를 더해주어 정점의 갯수를 늘려준다. 마지막으로 둘다 루트가 아닌경우에는 두 노드를 합친 후 다른 노드에 이어주도록 한다. 예를들어 node_a의 부모노드의 인덱스를 따로 tmp에 저장해주고, node_a의 루트를 node_b의 루트로 지정한 후, node_a의 부모노드에 node_b의 부모노드 인덱스를 할당해 줌으로써 부모노드를 통일한다.
*Variables : Node *temp_P - 부모노드 p를 담는 위치가 비어있을 때 부모노드를 만드는 노드
	   Node *temp_C - 자식노드 c를 담는 위치가 비어있을 때 자식노드를 만드는 노드
	   Node *P - 부모노드가 변경되지 않도록 할당하는 포인터변수
	   Node *C - 부모노드의 끝에 링크하기 위해 생성하는 노드
*********************************************************************************************************/

void Tree::union_set(char node_a, char node_b){
	int tmp;
	int a_idx, b_idx;

	for (int i = 0; i < MAX_ARY; i++) {
		if (check[i] == node_a) a_idx = i;
		if (check[i] == node_b) b_idx = i;
	}

	if (parent[a_idx] < 0 && parent[b_idx] < 0) {//둘다 root{
		if (parent[a_idx] <= parent[b_idx]){
			tmp = parent[b_idx];
			parent[b_idx] = a_idx;
			parent[a_idx] += tmp; 
		}
		else {
			tmp = parent[a_idx];
			parent[a_idx] = b_idx;
			parent[b_idx] += tmp; 
		}
	}
	else if (parent[a_idx] < 0 && parent[b_idx] >= 0){
		tmp = parent[a_idx];
		parent[a_idx] = parent[b_idx];
		parent[parent[b_idx]] += tmp;
	}
	else if (parent[a_idx] >= 0 && parent[b_idx] < 0){
		tmp = parent[b_idx];
		parent[b_idx] = parent[a_idx];
		parent[parent[a_idx]] += tmp;
	}
	else{
		tmp = parent[a_idx];
		parent[a_idx] = parent[b_idx];
		parent[tmp] = parent[b_idx];
	}
}
/*********************************************************************************************************
*function : kruskal()
*Description : Kruskal알고리즘을 사용하여 MST를 만드는 함수. 먼저 비용을 0으로, edge의 번호를 의미하는 cnt를 1로 초기화한다. 그리고 간선의 갯수가 정점 - 1일 때 까지 반복하는데, 만약 각 정점의 부모노드가 같은 경우는 cycle형태를 의미하므로, 간선으로 채택하지 않고 , 부모노드가 다른경우, 비용을 cost에 더해주고, 각 정점을 집합으로 합쳐주도록한다.
그리고 간선의 갯수가 정점 - 1 이 되었을 경우 반복문을 종료하고 비용을 출력한다.
*Variables : int cost - 비용을 합산하기위한 변수
	   int cnt - 간선의 갯수를 나타내기 위한 변수
*********************************************************************************************************/

void Tree::kruskal(){
	int cost = 0;
	int cnt = 1;

	for (int i =0; i < MAX_EDGE; i++){
		if (cnt == MAX_ARY) break;
		if (find_set(sort_G[i]->begin) != find_set(sort_G[i]->end)){
			cost += sort_G[i]->cost;
			cout << cnt;
			cout << ") Edge" << cnt++ << " :	" << sort_G[i]->begin << " " << sort_G[i]->cost << " " << sort_G[i]->end << endl;
			union_set(sort_G[i]->begin, sort_G[i]->end);
		}
	}
	cout << endl << "Total Cost : 	" << cost << endl;
}
