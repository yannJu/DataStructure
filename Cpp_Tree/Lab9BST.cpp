//20191644이연주

#include <iostream>
using namespace std;

class Node {
	private:
		int data;
		Node *left;
		Node *right; 
		Node(int word = 0) {data = word; left = 0; right = 0;}
	friend class Tree;
};

class Tree{
	Node *root;
	public:
		Tree() {root = 0;}
		~Tree();
		void insert(int key);
		Node *insertTree(Node*, int key);
		void del(int);
		Node *deleteBSTree(Node*, int);
		void searchTree(int);
		void searchBSTree(Node*, int key);
		void traverse();
		bool levelorder(Node*, int);
		void numofNodes();
		int leaves(Node*, int);
		int Nonleaves(Node*, int);
		void drawTree();
		void drawBSTree(Node*, int);
		Node *findMax(Node*);
		void freeBSTree(Node*);
		bool treeEmpty() {return root == 0;}
};

int main(){
	int num, wt;
	Tree t;
	do{
		cout << "1) Insert 2)Search 3)Delete 4)Traverse(level) 5)NumofNode 6)Draw 7) Quit >> ";
		cin >> num;
		cout << endl;
		
		switch (num){
			case 1:
				cout << "Enter a number to insert >> ";
				cin >> wt;
				t.insert(wt);
				cout << endl;
				break;
			case 2:
				if (!t.treeEmpty()){
					cout << "Enter a number to search >> ";
					cin >> wt;
					t.searchTree(wt);
					cout << endl;
				}
				else cout << "Tree is Empty!\n";
				break;
			case 3:
				if (!t.treeEmpty()){
					cout << "Enter a number to del >> ";
					cin >> wt;
					t.del(wt);
					cout << endl;
				}
				else cout << "Tree is Empty!\n";
				break;
			case 4:
				if (!t.treeEmpty()) t.traverse();
				else cout << "Tree is Empty!";
				cout << endl;
				break;
			case 5:
				t.numofNodes();
				break;
			case 6:
				if (!t.treeEmpty()) t.drawTree();
				else cout << "Tree is Empty!\n";
				break;
			case 7:
				t.~Tree();
				break;
		}
	}while (num != 7);
}

Tree::~Tree() {freeBSTree(root);}

void Tree::insert(int key){ //값을 추가, BST함수를 호출
	Node *ptr = root;
	insertTree(ptr, key);
}
Node *Tree::insertTree(Node* ptr, int key){ //재귀
	if (ptr == 0) { //Tree가 비어있거나, Insert할 위치에 도달하였을 때
		Node *temp = new Node(key);
		temp->left = NULL; temp->right = NULL;
		if (root == 0) root = temp;
		return temp;
	}
	else if (key < ptr->data) ptr->left = insertTree(ptr->left, key); //key값이 더 작을경우
	else if (key > ptr->data) ptr->right = insertTree(ptr->right, key); //key값이 더 클경우
}

void Tree::del(int key){ //값을 삭제, BST함수를 호출
	Node *ptr = root;
	deleteBSTree(ptr, key);
}

Node *Tree::deleteBSTree(Node *ptr, int key){ //재귀
	Node *p = NULL;
	if (ptr) {
		if (key < ptr->data){
			ptr->left = deleteBSTree(ptr->left, key);
		}
		else if (key > ptr->data){
			ptr->right = deleteBSTree(ptr->right, key);
		}
		else if ((ptr->left == 0) && (ptr->right == 0)) {//Leaf인 경우
			ptr = NULL;
		}
		else if (ptr->left == 0){ //non-Leaf && left가 없는 경우
			p = ptr; ptr = ptr->right; delete p;
		}
		else if (ptr->right == 0) { //non-Leaf && right가 없는 경우
			p = ptr; ptr = ptr->left; delete p;
		}
		else { // right and left 둘다 있는 경우 (method b : max)
			p = findMax(ptr->left); ptr->data = p->data; ptr->left = deleteBSTree(ptr->left, ptr->data);
		}
	}
	else cout << "NOT FOUND!\n";

	return ptr;
}

Node * Tree::findMax(Node*  p){ //search max
	if (p->right == 0) return p;
	else return findMax(p->right);
}

void Tree::searchTree(int key){ //search BST호출
	Node *p = root;
	searchBSTree(p, key);
}
void Tree::searchBSTree(Node *ptr, int key){
	if (ptr == 0) cout << "NOT Found!\n";
	else {
		if (key == ptr->data){
			cout << "\'" << key << "\' is Found!\n";
		}
		else if (key < ptr->data) searchBSTree(ptr->left, key);
		else if (key > ptr->data) searchBSTree(ptr->right, key);
	}
}

void Tree::traverse(){ //print level
	int level = 1;
	while(levelorder(root, level)) level++;
}

bool Tree::levelorder(Node *p, int level){ //levelorder
	bool left, right;
	if (p == 0) return false;
	else if (level == 1) {
		cout << p->data << " "; return true;
	}
	else {
		left = levelorder(p->left, level-1); right = levelorder(p->right, level-1);
		return (left||right);
	}
}

void Tree::freeBSTree(Node *p){ //노드(Tree) 초기화
	if (p != 0){
		freeBSTree(p->left);
		freeBSTree(p->right);
		delete p;
	}
}

void Tree::numofNodes(){ //node의 개수 구하는 함수
	int count = 0;
	cout << "Number of leaves: " << leaves(root, count) << " ";
	cout << "Number of Nonleaves: " << Nonleaves(root, count) << endl;
}
int Tree::leaves(Node *p, int cnt){ //node가 leave일때
	if (p) { //not empty
		if (p->left == 0 && p->right == 0) cnt++; //leaf node일때
		else{
			cnt = leaves(p->left, cnt) + leaves(p->right, cnt);
		}
	}
	else cnt = 0;
	return cnt;
}
int Tree::Nonleaves(Node *p, int cnt){ //node가 nonleave일때
	if (p) { //not empty
		if (p->left == 0 && p->right == 0) cnt = 0;
		else {
			cnt = Nonleaves(p->left, cnt) + Nonleaves(p->right, cnt) + 1;
		}
	}
	else cnt = 0;
	return cnt;
}

void Tree::drawTree() {drawBSTree(root, 1);} //재귀함수 호출(drawTree)
void Tree::drawBSTree(Node *p, int level){
	if (p != 0) {
		drawBSTree(p->right, level + 1);
		for (int i = 1; i <= level - 1; i++) cout << "     ";
		cout << p->data;
		if (p->left != 0 && p->right != 0) cout << "  <" << endl;
		else if (p->right != 0) cout << "  /" << endl;
		else if (p->left != 0) cout << "  \\" << endl;
		cout << endl;

		drawBSTree(p->left, level + 1);
	}
}
