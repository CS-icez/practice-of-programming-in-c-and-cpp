#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12;
int h, w;
long long dp[N+1][1<<N];	//pre i-1 filled, i end up as j
bool avi[1<<N];
vector<int> avi2[1<<N];

void init_avi(){
	memset(avi, 0, sizeof avi);
	for (int i = 0, cnt; i < (1<<w); ++i){
		avi[i] = 1;
		cnt = 0;
		for (int j = 0; j < w; ++j)
			if (i&1<<j){
				if (cnt&1) break;
				cnt = 0;
			}
			else ++cnt;
		if (cnt&1) avi[i] = 0;
	}
}

void init_avi2(){
	for (auto& t: avi2)	//×¢ÒâÒª¼Ó&
		t.clear();
	
	for (int i = 0; i < (1<<w); ++i)
		for (int j = 0; j < (1<<w); ++j)
			if (!(i&j) && avi[i|j])
				avi2[i].push_back(j);
}

signed main(){
	while (cin >> h >> w, h){
		init_avi();
		init_avi2();
		
		memset(dp, 0, sizeof dp);
		dp[1][0] = 1;
		
		for (int i = 2; i <= h+1; ++i)	//deal with line i
			for (int j = 0; j < (1<<w); ++j)	//line i end up as j
				for (int k: avi2[j])	//line i-1 end up as k
					dp[i][j] += dp[i-1][k];
				
		cout << dp[h+1][0] << endl;
	}
}
