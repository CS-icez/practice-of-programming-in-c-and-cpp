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

int a[5][5], r_max[5], c_min[5];

int main(){
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> a[i][j];
			
	for (int i = 0; i < 5; ++i)
		for (int j = 1; j < 5; ++j)
			if (a[i][j] > a[i][r_max[i]]) r_max[i] = j;
			
	for (int j = 0; j < 5; ++j)
		for (int i = 1; i < 5; ++i)
			if (a[i][j] < a[c_min[j]][j]) c_min[j] = i;
			
	for (int i = 0; i < 5; ++i)
		if (c_min[r_max[i]] == i){
			printf("%d %d %d", i+1, r_max[i]+1, a[i][r_max[i]]);
			return 0;
		}
	puts("not found");
}
