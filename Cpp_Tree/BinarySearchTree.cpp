//20191644이연주

//box, cow, owl, monkey, zebra 해보기
#include <iostream>
using namespace std;

class Node {
	private:
		//char data;
		int data;
		Node *left;
		Node *right; 
		//Node(char word = ' ') {data = word; left = 0; right = 0;}
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
		Node *searchBSTree(Node*, int key);
		void traverse();
		void inorderTraverse(Node*);
		void postorderTraverse(Node*);
		void preorderTraverse(Node*);
		void drawTree();
		void drawBSTree(Node*, int);
		Node *findMin(Node*);
		Node *findMax(Node*);
		void freeBSTree(Node*);
};

int main(){
	int num, wt;
	Tree t;
	do{
		cout << "1) Insert 2)Search 3)Delete 4)Traverse 5) Draw  6) Quit >> ";
		cin >> num;
		cout << endl;
		
		switch (num){
			case 1:
				cout << "Enter thing >> ";
				cin >> wt;
				t.insert(wt);
				cout << endl;
				break;
			case 2:
				cout << "Enter thing >> ";
				cin >> wt;
				t.searchTree(wt);
				cout << endl;
				break;
			case 3:
				cout << "Enter thing >> ";
				cin >> wt;
				t.del(wt);
				cout << endl;
				break;
			case 4:
				t.traverse();
				break;
			case 5:
				t.drawTree();
				break;
			case 6:
				t.~Tree();
				break;
		}
	}while (num != 6);
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
		/*else { // right and left 둘다 있는 경우 (method a : min)
			p = findMin(ptr->right); ptr->data = p->data; ptr->right = deleteBSTree(ptr->right, ptr->data);
		}*/
		else { // right and left 둘다 있는 경우 (method b : max)
			p = findMax(ptr->left); ptr->data = p->data; ptr->left = deleteBSTree(ptr->left, ptr->data);
		}
	}
	else cout << "NOT FOUND!\n";

	return ptr;
}

Node * Tree::findMin(Node* p){ //search min
	if (p->left == 0) return p;
	else return findMin(p->left);
}

Node * Tree::findMax(Node*  p){ //search max
	if (p->right == 0) return p;
	else return findMax(p->right);
}

void Tree::searchTree(int key){ //search BST호출
	Node *p = root;
	searchBSTree(p, key);
}
Node *Tree::searchBSTree(Node *ptr, int key){
	if (ptr == 0) return NULL;
	else {
		if (key == ptr->data) return ptr;
		else if (key < ptr->data) searchBSTree(ptr->left, key);
		else if (key > ptr->data) searchBSTree(ptr->right, key);
	}
	return ptr;
}

void Tree::traverse(){ //print in/post/pre
	Node *p = root;
	cout << "INORDER : ";
	inorderTraverse(p);
	cout << endl;
	cout << "POSTORDER : ";
	postorderTraverse(p);
	cout << endl;
	cout << "PREORDER : ";
	preorderTraverse(p);
	cout << endl;
}

void Tree::inorderTraverse(Node *p){ //inorder 재귀
	if (p != 0){
		inorderTraverse(p->left);
		cout << p->data << " ";
		inorderTraverse(p->right);
	}
}
void Tree::postorderTraverse(Node *p){ //postorder 재귀
	if (p != 0){
		postorderTraverse(p->left);
		postorderTraverse(p->right);
		cout << p->data << " ";
	}
}
void Tree::preorderTraverse(Node *p){ //preorder 재귀
	if (p != 0){
		cout << p->data << " ";
		preorderTraverse(p->left);
		preorderTraverse(p->right);
	}
}

void Tree::freeBSTree(Node *p){ //노드(Tree) 초기화
	if (p != 0){
		freeBSTree(p->left);
		freeBSTree(p->right);
		delete p;
	}
}

void Tree::drawTree() {drawBSTree(root, 1);} //재귀함수 호출
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
