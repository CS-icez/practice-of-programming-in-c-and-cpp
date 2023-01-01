#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <map>
using namespace std;

class Master{
public:
	queue<string> bag;
	unordered_set<string> pc;
	void capture(string poke){
		if (bag.size() == 6){
			pc.insert(bag.front());
			bag.pop();
		}
		bag.push(poke);
	}
	bool take(string poke){
		bool ret = pc.count(poke);
		if (ret){
			pc.erase(poke);
			capture(poke);
		}
		return ret;
	}
};

map<string, Master> mp;

int main(){
	int T, N;
	string op, name, poke;
	cin >> T;
	
	while (T--){
		cin >> N;
		mp.clear();
		
		while (N--){
			cin >> op >> name >> poke;
			if (op == "C")
				mp[name].capture(poke);
			else
				cout << (mp[name].take(poke)? "Success": "Failed") << endl;
		}
	}
}
