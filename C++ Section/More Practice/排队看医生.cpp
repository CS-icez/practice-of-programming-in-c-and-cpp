#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient{
	inline static int n{0};
	int id, prior;
	bool operator<(const Patient& t) const{
		return prior == t.prior? id > t.id: prior < t.prior;
	}
};

class Doctor{
public:
	priority_queue<Patient> q;
	void in(int b){
		q.push({++Patient::n, b});
	}
	void out(){
		if (q.empty()) cout << "EMPTY" << endl;
		else{
			cout << q.top().id << endl;
			q.pop();
		}
	}
};

int main(){
	int T, n, a, b;
	string op;
	cin >> T;
	
	while (T--){
		Doctor d[4];
		Patient::n = 0;
		cin >> n;
		while (n--){
			cin >> op;
			if (op == "IN"){
				cin >> a >> b;
				d[a].in(b);
			}
			else{
				cin >> a;
				d[a].out();
			}
		}
	}
}
