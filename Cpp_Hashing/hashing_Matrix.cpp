#include <iostream>
using namespace std;

const int MaxSize = 7;
struct hashtable{
	int key;
	int empty;	
};

class Htable{
	private:
		hashtable htable[MaxSize];
	public:
		Htable(){for (int i = 0; i < MaxSize; i++) htable[i].empty = 1;}	
		int hash(int);
		int findIdx(int, int&);
		int insertkey(int);
		int searchkey(int);
		int deletekey(int);
		void printtable();
};

int main(){
	Htable h;
	char ch;
	int key;

	do{
		cout << "Enter command (i, f, d, g) :	";
		cin >> ch;
		if (ch != 'q'){
			cout << "Enter key :	";
			cin >> key;
			switch (ch){
				case 'i':
					if (h.insertkey(key) == 0) cout << "Cannot insert Key!\n"; break; 
				case 'f':
					if (h.searchkey(key) < 0) cout << "Cannot find Key!\n"; 
					cout << "Found " << key;
					break;
				case 'd':
					if (h.deletekey(key) == 0) cout << "Cannot delete Key!\n"; break;
				default:
					cout << "Wrong Command!"; break;
			}
		}
		h.printtable();
	}while (ch != 'q');
}

int Htable::hash(int key){
	return (key % MaxSize);
}

int Htable::findIdx(int key, int &idx){
	idx = hash(key);
	int oldIdx = idx;
	int ck = 0;
	
	while(ck == 0){
		if (htable[idx].empty == 1) return 1;
		if (htable[idx].empty == 0 && ck == 0){
			idx = (idx + 1) % MaxSize;
			if (idx == oldIdx){
				ck == 1;
				return 0;
			}
		}
	}
}

int Htable::insertkey(int key){
	int idx = hash(key);
	
	if (findIdx(key, idx) == 0) return 0;
	htable[idx].key = key;
	htable[idx].empty = 0;
	return 1;
}

int Htable::searchkey(int key){
	for (int i = 0; i < MaxSize; i++){
		if (key == htable[i].key) {	
			return i;
		}
	}
	return -1;
}

int Htable::deletekey(int key){
	int idx = hash(key);
	int ck = searchkey(key);

	if (searchkey(key) < 0) return 0;
	htable[ck].key = 0;
	htable[ck].empty = 1;
	return 1;	
}

void Htable::printtable(){
	cout << "( ";
	for (int i = 0; i < MaxSize; i++){
		if (htable[i].empty == 0) cout << htable[i].key;
		else cout << " ";
		if (i != MaxSize - 1) cout << ", ";
	}
	cout << " )";
}
