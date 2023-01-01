#include <iostream>
#include <utility>
#include <vector>
using namespace std;

using pii = pair<int, int>;

const int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
int maze[8][8];
vector<pii> route, best(100);
int vis[8][8];

void dfs(int x, int y){
	if (x == 5 && y == 5){
		if (route.size() < best.size())
			best = route;
		return;
	}
	
	for (int i = 0; i < 4; ++i){
		int x1 = x+dx[i], y1 = y+dy[i];
		if (x1 < 1 || y1 < 1 || x1 > 5 || y1 > 5)
			continue;
		if (vis[x1][y1] || maze[x1][y1])
			continue;
		route.push_back({x1, y1});
		vis[x1][y1] = 1;
		dfs(x1, y1);
		route.pop_back();
		vis[x1][y1] = 0;
	}
}


int main(){
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= 5; ++j)
			cin >> maze[i][j];
	
	route.push_back({1, 1});
	vis[1][1] = 1;		
	dfs(1, 1);
	for (auto t: best)
		printf("(%d, %d)\n", t.first-1, t.second-1);
}
