#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int N = 111;
const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};
int r, c, k;
int bar[N][N];
int tim[N][N][13];
struct{
	int x, y, st;
} q[N*N*10];
int head, tail;

int main(){
	int T;
	cin >> T;
	
	while (T--){
		head = 0, tail = 0;
		memset(tim, -1, sizeof tim);
		memset(bar, 0, sizeof bar);	//Note here
		
		cin >> r >> c >> k;
		
		char ch;
		int xs, ys, xe, ye;
		
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j){
				cin >> ch;
				switch (ch){
					case '.': break;
					case '#': bar[i][j] = 1; break;
					case 'S': xs = i, ys = j; break;
					case 'E': xe = i, ye = j; break;
				}
			}
			
		q[tail++] = {xs, ys, 0};
		tim[xs][ys][0] = 0;
		
		int x1, y1, cur_t, idx, flag = 0;
		while (head < tail && !flag){
			auto t = q[head++];
			for (int i = 0; i < 4; ++i){
				x1 = t.x+dx[i], y1 = t.y+dy[i], cur_t = tim[t.x][t.y][t.st]+1, idx = cur_t%k;

				if (x1 < 1 || y1 < 1 || x1 > r || y1 > c)
					continue;
				if (idx && bar[x1][y1]) continue;
				if (~tim[x1][y1][idx]) continue;	
				
				tim[x1][y1][idx] = cur_t;
				q[tail++] = {x1, y1, idx};
				
				if (x1 == xe && y1 == ye){
					flag = 1;
					cout << cur_t << endl;
				}
			}
		}
		
		if (!flag) cout << "Oop!" << endl;
	}
}
