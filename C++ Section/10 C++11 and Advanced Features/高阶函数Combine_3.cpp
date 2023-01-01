#include <iostream>
using namespace std;
template <class T, class U, class V>
auto combine(T t, U u){
	return [=](V v)->V{return t(t(v)+u(v));};
}
int main()
{
    auto Square = [] (double a) { return a * a; };
    auto Inc = [] (double a) { return a + 1; };
    cout << combine<decltype(Square),decltype(Inc),int>(Square,Inc)(3) << endl;
    cout << combine<decltype(Inc),decltype(Square),double>(Inc,Square)(2.5) << endl;

    return 0;
}
