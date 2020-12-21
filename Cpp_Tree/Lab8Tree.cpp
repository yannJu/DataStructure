//20191644이연주

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
		void Operand(Node *node);
		void Operator(Node *node);
		void Inorder(Node *head);
		void Postorder(Node *head);
		void Preorder(Node *head);
		int Eval(Node *head); 
};

char prec[4][2] = {'*', 2, '/',2, '+', 1, '-', 1};

int main(){
	string word;
	Tree t1; //int
	Tree t2; //char
	Node *head1 = NULL, *head2 = NULL;
	
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		t1.BuildTree(word[i]);
	}

	head1 = t1.root;

	cout << "InOrder : ";
	t1.Inorder(head1);
	cout << endl;

	cout << "PostOrder : ";
	t1.Postorder(head1);
	cout << endl;

	cout << "PreOrder : ";
	t1.Preorder(head1);
	cout << endl;

	cout << "Evaluation : " << t1.Eval(head1) << endl;

	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		t2.BuildTree(word[i]);
	}

	head2 = t2.root;

	cout << "InOrder : ";
	t2.Inorder(head2);
	cout << endl;

	cout << "PostOrder : ";
	t2.Postorder(head2);
	cout << endl;

	cout << "PreOrder : ";
	t2.Preorder(head2);
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

