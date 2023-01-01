#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;

struct C{
	string s;
	int d, c;
	bool operator<(const C& t){
		return s < t.s;
	}
} course[23];

int dp[(1<<14)+10][23];
vector<int> path[(1<<14)+10][23];
vector<int> max_path(1, 100);

int n;

int calc_t(int st){
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (st&(1<<i)) res += course[i].c;
	return res;
}


int main(){
	int T;
	cin >> T;
	
	while (T--){
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> course[i].s >> course[i].d >> course[i].c;
		
		int vic = (1<<n)-1;
			
		for (int i = 1; i <= vic; ++i){	//当前状态
			for (int j = 0; j < n; ++j){	//枚举最后一个作业
				dp[i][j] = 1e9;
				if (i&(1<<j)){
					int t = i&~(1<<j);	//上一个状态
					if (!t){
						dp[i][j] = max(0, course[j].c-course[j].d);
						path[i][j].clear();
						path[i][j].push_back(j);
					}
					else{
						path[i][j] = max_path;
						for (int k = 0; k < n; ++k)	//枚举上一个状态的最后一个作业
							if (t&(1<<k)){
								int pre_t = calc_t(t);	//上一个状态的完成时间
								int loss = max(0, pre_t+course[j].c-course[j].d)+dp[t][k];	//当前状态扣分
								
								if (loss < dp[i][j])
									dp[i][j] = loss, path[i][j] = path[t][k];
								else if (loss == dp[i][j] && path[t][k] < path[i][j]){
									dp[i][j] = loss, path[i][j] = path[t][k];
								}
							}
						path[i][j].push_back(j);	
					}

				}
				//cout << bitset<sizeof(i)*8>(i) << " ";
				//cout << setbase(10) << j << " " << dp[i][j] << endl;
			}
		}
		
		int res = 0;
		for (int i = 1; i < n; ++i)
			if (dp[vic][i] == dp[vic][res] && path[vic][i] < path[vic][res])
				res = i;
			else if (dp[vic][i] < dp[vic][res])
				res = i;
		cout << dp[vic][res] << endl;
		for (int t: path[vic][res])
			cout << course[t].s << endl;
	}
}
