#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int book[100010];

int main(){
	int n, x;
	string op;
	cin >> n;
	
	while (n--){
		cin >> op >> x;
		if (op == "add"){
			s.insert(x);
			book[x] = 1;
			cout << s.count(x) << endl;
		}
		else if (op == "del"){
			cout << s.erase(x) << endl;
		}
		else if (op == "ask"){
			cout << book[x] << " " << s.count(x) << endl;
		}
	}
}
