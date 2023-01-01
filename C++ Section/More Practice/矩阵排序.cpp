#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mat{
	int h,w;
public:
	Mat(int height,int width):h(height),w(width)
	{
		++num;
		id = num;
		size = h*w;
	}
	int a[5][5], id, sum{0}, size;
	inline static int num{0};
	
	bool operator<(const Mat& t){
		return size == t.size? id > t.id: size < t.size;
	}
	
	friend istream& operator>>(istream& is, Mat& m){
		for (int i = 0; i < m.h; ++i)
			for (int j = 0; j < m.w; ++j){
				is >> m.a[i][j];
				m.sum += m.a[i][j];
			}
		return is;
	}
	
	friend ostream& operator<<(ostream& os, Mat& m){
		for (int i = 0; i < m.h; ++i)
			for (int j = 0; j < m.w; ++j)
				os << m.a[i][j] << " \n"[j==m.w-1];
		return os;
	}
};

bool comparator_1(const Mat& a, const Mat& b){
	return a.sum == b.sum? a.id > b.id : a.sum < b.sum;
}

class comparator_2{
public:
	bool operator()(const Mat& a, const Mat& b){
		return a.id < b.id;
	}
};
int main()
{
	vector<Mat> m;
	m.push_back(Mat(2,2));
	m.push_back(Mat(3,4));
	m.push_back(Mat(2,2));
	cin >> m[0] >> m[1] >> m[2];
	sort(m.begin(),m.end());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_1);
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_2());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	return 0;
}
