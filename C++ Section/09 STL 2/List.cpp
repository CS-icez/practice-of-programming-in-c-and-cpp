#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

list<int> l[10000]; 

int main(){
	int n;
	cin >> n;
	string op;
	int id1, id2, num;
	
	while (n--){
		cin >> op;
		if (op == "new"){
			cin >> id1;
		}
		else if (op == "add"){
			cin >> id1 >> num;
			l[id1].push_back(num);
		}
		else if (op == "merge"){
			cin >> id1 >> id2;
			l[id1].merge(l[id2]);
		}
		else if (op == "unique"){
			cin >> id1;
			l[id1].sort();
			auto it = unique(l[id1].begin(), l[id1].end());
			l[id1].erase(it, l[id1].end());
		}
		else if (op == "out"){
			cin >> id1;
			l[id1].sort();
			for (auto it = l[id1].begin(); it != l[id1].end(); ++it){
				if (it != l[id1].begin()) cout << " ";
				cout << *it;
			}
			cout << endl;	
		}
	}
}
