#include <iostream>
using namespace std;

int cost1[7][7] = {
{100, 2, 4, 5, 100, 100, 100},
{100, 100, 100, 2, 7, 100, 100},
{100, 100, 100, 1, 100, 4, 100},
{100, 2, 1, 100, 4, 3, 100},
{100, 7, 100, 4, 100, 1, 5},
{100, 100, 4, 3, 1, 100, 7},
{100, 100, 100, 100, 7, 5, 100}
};

int cost2[8][8] = {
{0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{300, 0, 10000, 10000, 10000, 10000, 10000, 10000},
{1000, 800, 0, 10000, 10000, 10000, 10000, 10000},
{10000, 10000, 1200, 0, 10000, 10000, 10000, 10000},
{10000, 10000, 10000, 1500, 0, 250, 10000, 10000},
{10000, 10000, 10000, 1000, 10000, 0, 900, 1400},
{10000, 10000, 10000, 10000, 10000, 10000, 0, 1000},
{1700, 10000, 10000, 10000, 10000, 10000, 10000, 0}
};

int cost3[6][6] = {
{100, 20, 15, 100, 100, 100},
{100, 100, 100, 100, 10, 30},
{100, 4, 100, 100, 100, 10},
{100, 100, 100, 100, 100, 100},
{100, 100, 100, 15, 100, 100},
{100, 100, 100, 4, 10, 100}
};

int cost4[6][6] = {
{999, 50, 10, 999, 45, 999},
{999, 999, 15, 999, 10, 999},
{20, 999, 999, 15, 999, 999},
{999, 20, 999, 999, 35, 999},
{999, 999, 999, 30, 999, 999},
{999, 999, 999, 3, 999, 999}
};


class Graph{
	private:
		int check[10];
		int distance[10];
		int cost[10][10];
	public:
		void initCostMatrix();
		void insertCostMatrix(int , int, int);
		void Shortestpath(int, int);
		int choose(int[], int, int[]);
		void print_Distance(int, int);
};

int main(){
	Graph g1, g2, g3, g4;
	
	cout << "	";
	for (int i = 0; i < 7; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 7; i++){
		cout << i << "	";
		for (int j = 0; j < 7; j++){
			cout << cost1[i][j] <<"	";
		}
		cout << endl;
	}
	g1.initCostMatrix();
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (i != j) g1.insertCostMatrix(i, j, cost1[i][j]);
		}
	}
	g1.Shortestpath(0, 7);
	cout << endl;

	cout << "	";
	for (int i = 0; i < 8; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 8; i++){
		cout << i << "	";
		for (int j = 0; j < 8; j++){
			cout << cost2[i][j] <<"	";
		}
		cout << endl;
	}
	g2.initCostMatrix();
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (i != j) g2.insertCostMatrix(i, j, cost2[i][j]);
		}
	}
	g2.Shortestpath(4, 8);
	cout << endl;

	cout << "	";
	for (int i = 0; i < 6; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 6; i++){
		cout << i << "	";
		for (int j = 0; j < 6; j++){
			cout << cost3[i][j] <<"	";
		}
		cout << endl;
	}
	g3.initCostMatrix();
	for (int i = 0; i < 6; i++){
		for (int j = 0; j <6; j++){
			if (i != j) g3.insertCostMatrix(i, j, cost3[i][j]);
		}
	}
	cout << endl;
	g3.Shortestpath(0, 6);

	cout << "	";
	for (int i = 0; i < 6; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 6; i++){
		cout << i << "	";
		for (int j = 0; j < 6; j++){
			cout << cost4[i][j] <<"	";
		}
		cout << endl;
	}
	g4.initCostMatrix();
	for (int i = 0; i < 6; i++){
		for (int j = 0; j <6; j++){
			if (i != j) g4.insertCostMatrix(i, j, cost4[i][j]);
		}
	}
	cout << endl;
	g4.Shortestpath(0, 6);
}

void Graph::initCostMatrix(){
	int i, j;
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (i == j) cost[i][j]  = 0;
			else cost[i][j] = 999;
		}
	}
}

void Graph::insertCostMatrix(int i, int j, int c){
	cost[i][j] = c;
}

void Graph::Shortestpath(int v, int n){
	int i, u, w;

	for (i = 0; i < n; i++){
		check[i] = 0;
		distance[i] = cost[v][i];
	}
	check[v] = 1; distance[v] = 0;

	for (i = 0; i < n - 1; i++){
		u = choose(distance, n, check);
		check[u] = 1;
		cout << "Distance ->	";
	 	print_Distance(n, u);
		cout << endl;
	
		for (w = 0; w < n; w++){
			if (check[w] == 0){
				if (distance[u] + cost[u][w] < distance[w]) distance[w] = distance[u] + cost[u][w];
			}
		}
	}
}

int Graph::choose(int d[], int l, int f[]){
	int i, min = 10000; //min = max_value 로 초기화
	int result = 0;
	
	for (i = 0; i < l; i++){
		if (d[i] < min && f[i] == 0) {
			min = d[i];
			result = i;
		}
	}
	return result;
}

void Graph::print_Distance(int n, int s){
	for (int i = 0; i < n; i++) cout << distance[i] << " ";
	cout << "	(Selected Node : " << s << ")" << endl;
}
