#include <iostream>
using namespace std;

int cost1[6][6] = {
{999, 20, 15, 999, 999, 999},
{999, 999, 999, 999, 10, 30},
{999, 4, 999, 999, 999, 10},
{999, 999, 999, 999, 999, 999},
{999, 999, 999, 15, 999, 999},
{999, 999, 999, 4, 10, 999}
};

int cost2[6][6] = {
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
	Graph g1, g2;
	
	cout << "	";
	for (int i = 0; i < 6; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 6; i++){
		cout << i << "	";
		for (int j = 0; j < 6; j++){
			cout << cost1[i][j] <<"	";
		}
		cout << endl;
	}
	g1.initCostMatrix();
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (i != j) g1.insertCostMatrix(i, j, cost1[i][j]);
		}
	}
	g1.Shortestpath(0, 6);
	cout << endl;

	cout << "	";
	for (int i = 0; i < 6; i++) cout << i << "	";
	cout << endl;

	for (int i =0 ; i < 6; i++){
		cout << i << "	";
		for (int j = 0; j < 6; j++){
			cout << cost2[i][j] <<"	";
		}
		cout << endl;
	}
	g2.initCostMatrix();
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (i != j) g2.insertCostMatrix(i, j, cost2[i][j]);
		}
	}
	g2.Shortestpath(0, 6);
	cout << endl;
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
	print_Distance(n, 0);
	cout << endl;

	for (i = 0; i < n - 1; i++){
		u = choose(distance, n, check);
		check[u] = 1;

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
	int i, min = 1000; //min = max_value 로 초기화
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
	if (s == 0) cout << "\nStart from Vertex " << s << " : ";
	else cout << "\nSelected Node : " << s << ",	";
	cout << "Distance->	";
	for (int i = 0; i < n; i++) cout << distance[i] << " ";
}
