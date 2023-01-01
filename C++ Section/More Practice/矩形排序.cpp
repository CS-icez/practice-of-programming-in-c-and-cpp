#include <iostream>
#include <set>
using namespace std;
class Rectangle{
public:
	int s, c;
	Rectangle(int h, int w): s(h*w), c((h+w)*2){}
	friend ostream& operator<<(ostream& os, const Rectangle& t){
		return os << t.s << " " << t.c;
	}
	bool operator<(const Rectangle& b) const{
		return s == b.s? c > b.c: s > b.s;
	}
};

class Comp{
public:
	bool operator()(const Rectangle& a, const Rectangle& b) const{
		return a.c == b.c? a.s < b.s: a.c < b.c;
	}
};
int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}
