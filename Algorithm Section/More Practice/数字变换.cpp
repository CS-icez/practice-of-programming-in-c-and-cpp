#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Node{
	string s;
	int o2, o3;
	bool operator<(const Node& t) const{
		if (s != t.s) return s < t.s;
		if (o2 != t.o2) return o2 < t.o2;
		return o3 < t.o3;
	}
};
int vis[100000][4][3];
int step[100000];
queue<Node> q;

int toInt(string s){
	int res = 0;
	for (int i = 0; i < 5; ++i)
		res = res*10+s[i];
	return res;
}

void bfs(){
	while (!q.empty()){
		Node pre = q.front(), cur;
		int num = toInt(pre.s), t;
		q.pop();
		
		for (int i = 0; i < 4; ++i){
			cur = pre;
			swap(cur.s[i], cur.s[i+1]);
			t = toInt(cur.s);
			if (~vis[t][cur.o2][cur.o3]) continue;
			step[t] = min(step[t], vis[t][cur.o2][cur.o3] = vis[num][pre.o2][pre.o3]+1);
			q.push(cur);
		}
		if (pre.o2 < 3){
			for (int i = 0; i < 5; ++i){
				cur = pre;
				cur.s[i] = (cur.s[i]+1)%10;
				++cur.o2;
				t = toInt(cur.s);
				if (~vis[t][cur.o2][cur.o3]) continue;
				step[t] = min(step[t], vis[t][cur.o2][cur.o3] = vis[num][pre.o2][pre.o3]+1);
				q.push(cur);
			}
		}
		if (pre.o3 < 2){
			for (int i = 0; i < 5; ++i){
				cur = pre;
				cur.s[i] = cur.s[i]*2%10;
				++cur.o3;
				t = toInt(cur.s);
				if (~vis[t][cur.o2][cur.o3]) continue;
				step[t] = min(step[t], vis[t][cur.o2][cur.o3] = vis[num][pre.o2][pre.o3]+1);
				q.push(cur);
			}
		}
	}
}

int main(){
	memset(step, 0x3f, sizeof step);
	memset(vis, -1, sizeof vis);
	string s("\1\2\3\4\5");
	vis[12345][0][0] = 0;
	step[12345] = 0;
	q.push({s, 0, 0});
	bfs();
	
	int n;
	while (cin >> n)
		cout << (step[n] == INF? -1: step[n]) << endl;
}
