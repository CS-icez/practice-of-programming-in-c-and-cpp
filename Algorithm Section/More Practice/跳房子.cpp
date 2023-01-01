#include <bits/stdc++.h>
using namespace std;

struct Node{
	int x;
	string str;
};
int n, m;
queue<Node> q;
set<int> s;

void bfs(){
	Node pre, cur;
	while (!q.empty()){
		pre = q.front();
		q.pop();
		
		cur = pre;
		cur.x *= 3, cur.str += "H";
		if (!s.count(cur.x)){
			s.insert(cur.x);
			q.push(cur);
			if (cur.x == m) return;
		}
		
		cur = pre;
		cur.x /= 2, cur.str += "O";
		if (!s.count(cur.x)){
			s.insert(cur.x);
			q.push(cur);
			if (cur.x == m) return;
		}
	}
}

int main(){
	while (cin >> n >> m, n){
		q = queue<Node>();
		s.clear();
		
		q.push({n, ""});
		s.insert(n);
		bfs();
		cout << q.back().str.size() << endl;
		cout << q.back().str << endl;
	}
}
