#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
class MyFunc{
private:
	int M, N{0};
	T temp{};
	T& ret;
public:
	MyFunc(int _M, T& _ret): M(_M), ret(_ret){}
	
	void operator()(const T& t){
		temp += t;
		ret = T();
		for (int i = 0; i < M; ++i)
			ret += temp;
	}
};
int main(){
    vector<int> v1;
    vector<string> v2;
    int N, val, num_repeat,result_int=0;
    string str,result_str="";
    cin>>N;
    cin>>num_repeat;
    for(int i=0;i<N;++i){
        cin>>val;
        v1.push_back(val);
    }
    for_each(v1.begin(),v1.end(),MyFunc<int>(num_repeat,result_int));
    for(int i=0;i<N;++i){
        cin>>str;
        v2.push_back(str);
    }
    for_each(v2.begin(),v2.end(),MyFunc<string>(num_repeat,result_str));
    cout<<result_int<<endl;
    cout<<"--------------"<<endl;
    cout<<result_str<<endl;
}
