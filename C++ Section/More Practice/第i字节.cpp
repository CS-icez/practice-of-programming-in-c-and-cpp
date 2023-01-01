#include <iostream>
using namespace std;
int getByte(int x, int i){
    return
(unsigned)x>>i*8<<24>>24  // 我偷懒了, 这个表达式依赖于int是32位的
;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x, i;
        cin >> x >> i;
        cout << getByte(x, i) << endl;
    }
    return 0;
}
