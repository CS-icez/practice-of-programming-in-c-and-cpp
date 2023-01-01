#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1011;
char a[N], b[N];
int dp[N][N];

int main(){
	int n;
	cin >> n;
	
	while (n--){
		scanf("%s%s", a+1, b+1);
		
		int l1 = strlen(a+1), l2 = strlen(b+1);
		
		for (int i = 1; i <= l1; ++i)
			dp[i][0] = i;
		for (int j = 1; j <= l2; ++j)
			dp[0][j] = j;
		
		
		for (int i = 1; i < l1+1; ++i)
			for (int j = 1; j < l2+1; ++j){
				dp[i][j] = min(dp[i][j-1], dp[i-1][j])+1;
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);

				if (a[i] == b[j]) 
					dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
			}
		cout << dp[l1][l2] << endl;
	}
		
}
