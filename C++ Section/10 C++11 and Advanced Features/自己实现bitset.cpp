#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset 
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v ) 
			c |= (1 << bp);
		else 
			c &= ~(1 << bp);
	}
	class Inside{
	public:
		MyBitset& r;
		int pos;
		
		Inside(MyBitset& _r, size_t _pos): r(_r), pos(_pos){}
		Inside& operator=(bool val){
			r.Set(pos, val);
			return *this;
		}
		Inside& operator=(const Inside& t){
			r.Set(pos, t.r[t.pos]);
			return *this;
		}
		operator bool(){
			return r.a[pos/8]&(1<<(pos%8));
		}
	};
	
	Inside operator[](int pos){
		return Inside(*this, pos);
	}
void Print() {
		for(int i = 0;i < bitNum; ++i) 
			cout << (*this) [i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}
