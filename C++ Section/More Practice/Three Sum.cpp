#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

multiset<int> s;
int a[5000 + 5];

int main() {
	int n, T, k;
	scanf("%d", &T);
	while (T--) {
		s.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d", a + i);
			s.insert(a[i]);
		}
		bool flag = false;
		scanf("%d", &k);
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				int target = k - a[i] - a[j], min_count = 1;
				switch(s.count(target)){
					case 0: break;
					case 1:
						if (target != a[i] && target != a[j])
							flag = true;
						break;
					case 2:
						if (target == a[i] && target == a[j]) break;
						flag = true;
						break;
					default:
						flag = true;
						break;
				}
				if (flag) break;
}
			if (flag) break;
		}
		puts(flag? "Yes": "No");
	}
}
