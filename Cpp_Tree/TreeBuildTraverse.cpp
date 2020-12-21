#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Node {
	private:
		char data;
		Node *left;
		Node *right; 
		int prio;
		Node(char word) {data = word; left = 0; right = 0; prio = 4;}
	friend class Tree;
};

class Tree{
	public:
		Node *root;
		Tree() {root = 0;}
		//~Tree();
		void BuildTree(char);
		void BuildTree(int);
		void Operand(Node *node);
		void Operator(Node *node);
		void Inorder(Node *head);
		void Postorder(Node *head);
		void Preorder(Node *head);
		int Eval(Node *head);
		void DrawTree(Node *head, int level);
		void Express(Node *head);
};

char prec[4][2] = {'*', 2, '/',2, '+', 1, '-', 1};

int main(){
	string word;
	Tree t1;
	Node *head = NULL;
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		t1.BuildTree(word[i]);
	}

	head = t1.root;

	cout << "InOrder : ";
	t1.Inorder(head);
	cout << endl;

	cout << "PostOrder : ";
	t1.Postorder(head);
	cout << endl;

	cout << "PreOrder : ";
	t1.Preorder(head);
	cout << endl;

	cout << "Evaluation : " << t1.Eval(head) << endl;

	cout << "Tree : " << endl;
	t1.DrawTree(head, 1);
	cout << endl;

	cout << "Express : ";
	t1.Express(head);
	cout << endl;
}

//Tree함수

void Tree::BuildTree(char data){
	Node *newnode = new Node(data);
	for (int i = 0; i < 4; i++){
		if (newnode->data == prec[i][0]) {
			newnode->prio = prec[i][1];
			Operator(newnode);
			return;
		}
	}
	Operand(newnode);
} //노드생성후 Tree생성->연산자인지 아닌지 구분

void Tree::Operand(Node *node){
	Node* p;
	if (root == 0) {
		root = node;
	}
	else {
		p = root;
		while (p->right != 0) p = p->right;
		p->right = node;
	}
} //피연산자일 경우

void Tree::Operator(Node *node){
	if (root->prio >= node->prio) {
		node->left = root;
		root = node;
	}
	else {
		node->left = root->right;
		root->right = node;
	}
} //연산자인경우

void Tree::Inorder(Node *head){
	if (head){
		Inorder(head->left);
		cout << head->data << " ";
		Inorder(head->right);
	}
} //순차적

void Tree::Postorder(Node *head){
	if (head){
		Postorder(head->left);
		Postorder(head->right);
		cout << head->data << " ";
	}
} //후위

void Tree::Preorder(Node *head){
	if (head){
		cout << head->data << " ";
		Preorder(head->left);
		Preorder(head->right);
	}
} //전위

int Tree::Eval(Node *head){
	int value;
	int left, right;
	
	if (head != 0){
		if (isdigit(head->data) != 0) value = head->data-'0';
		else {
			left = Eval(head->left);
			right = Eval(head->right);
			switch (head->data){
				case '+': 
					value = left + right;
					break;
				case '-': 
					value = left - right;
					break;
				case '*': 
					value = left * right;
					break;
				case '/': 
					value = left / right;
					break;
			};
		}
	}
	return value;
} //Eval

void Tree::DrawTree(Node *head, int level){
	if (head != 0) {
		DrawTree(head->right, level + 1);
		for (int i = 1; i <= level - 1; i++) cout << "     ";
		cout << head->data;
		if (head->left != 0 && head->right != 0) cout << "  <" << endl;
		else if (head->right != 0) cout << "  /" << endl;
		else if (head->left != 0) cout << "  \\" << endl;
		cout << endl;

		DrawTree(head->left, level + 1);
	}
} //DrawTree

void Tree::Express(Node *head){
	if (head != 0){
		if(head->left != 0) cout << "(";
		Express(head->left);
		cout << head->data;
		Express(head->right);
		if (head->right != 0) cout << ")";
	}
} //Expression
