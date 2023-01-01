#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
private:
	int h, w;
	int* p;
	int cnt{0};
public:
	IntegralImage(int _h, int _w): h(_h+1), w(_w+1){
		p = new int[h*w]{};
	}
	void operator()(int* t){
		++cnt;
		for (int i = 0; i < w-1; ++i)
			p[cnt*w+i+1] = p[(cnt-1)*w+i+1]+p[cnt*w+i]-p[(cnt-1)*w+i]+t[i];
		
		if (cnt == h-1)
			for (int i = 0; i < h-1; ++i)
				for (int j = 0; j < w-1; ++j)
					p[i*w+j] = p[(i+1)*w+j+1];
	}
	int* operator[](int pos){
		return p+pos*w;
	}
};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
    for(int j=0;j<W;++j)
        cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }
   
}
