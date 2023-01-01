#include <set>
#include <iostream>
#include <string>
using namespace std;

class myComp{
public:
    using pii = pair<int, int>;
	#define x first
	#define y second
	bool operator()(const pii& a, const pii& b) const{
		if (a.x == -1 || b.x == -1) return a.y > b.y;
		if (a.y == -1 || b.y == -1) return a.x < b.x;
		return a < b;
	}
	#undef x
	#undef y
};

int main() {
	string cmd;
	set<pair<int, int>, myComp> S;
	while (cin >> cmd) {
		if (cmd == "A") {
			int x, y;
			cin >> x >> y;
			S.insert(make_pair(x, y));
		} else if (cmd == "Qx") {
			int x;
			cin >> x;
			cout << S.lower_bound(make_pair(x, -1))->second << endl;
		} else if (cmd == "Qy") {
			int y;
			cin >> y;
			cout << S.lower_bound(make_pair(-1, y))->first << endl;
		} else {
			int x, y;
			cin >> x >> y;
			S.erase(make_pair(x, y));
		}
	}
	return 0;
}
