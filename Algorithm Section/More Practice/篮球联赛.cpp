#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

char m[4][4];
char cur[4][4];

struct Node{
	int c, s;
	bool operator<(const Node& t){
		if (s != t.s) return s > t.s;
		return c < t.c;
	}
};
Node a[4];
int best;

void calc(){
	for (int i = 0; i < 4; ++i)
		a[i] = {i+1, 0};
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (cur[i][j] == 'W') ++a[i].s;
			
	sort(a, a+4);
	for (int i = 0; i < 4; ++i)
		if (a[i].c == 1){
			best = min(best, i);
			return;
		}
}

void f(int x, int y){
	if (x == 4){
		calc();
		return;
	}
	
	if (m[x][y] != '?' || x > y){
		f(x+y/3, (y+1)%4);
		return;
	}
	
	cur[x][y] = 'W', cur[y][x] = 'L';
	f(x+y/3, (y+1)%4);
	cur[x][y] = 'L', cur[y][x] = 'W';
	f(x+y/3, (y+1)%4);
}


int main(){
	int T;
	cin >> T;
	
	while (T--){
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> m[i][j];
				
		memcpy(cur, m, sizeof m);
		best = 5;
		
		f(0, 0);
		cout << (best+1) << endl;
	}
}
