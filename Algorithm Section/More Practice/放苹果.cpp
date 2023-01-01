#include <iostream>
using namespace std;

int dp[13][13];	//apple, plate

int main(){
	for (int i = 1; i <= 10; ++i)
		dp[0][i] = 1;
	
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j){
			if (j > i)
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1]+dp[i-j][j];
		}
	
	int t, m, n;
	cin >> t;
	
	while (t--){
		cin >> m >> n;
		cout << dp[m][n] << endl;
	}
}
