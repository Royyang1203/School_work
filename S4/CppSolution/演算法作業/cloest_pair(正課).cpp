#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace  std;
struct point
{
	double x;
	double y;
};
vector<point> v;
bool cmp_x(point a,point b){return a.x<b.x;}
bool cmp_y(point a,point b){return a.y<b.y;}
double dis(point a,point b){return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}

double combine(int low,int mid,int high,double min_left,double min_right)
{
	vector<point>v2;
    double d = min(min_left,min_right);
    double line = (v[mid+1].x + v[mid].x)/2;//line:左集合與右集合的中間線x座標

	for(int i=mid+1;v[i].x<line+d && i<=high;i++)
		v2.push_back(v[i]);
	for(int j=mid;v[j].x>line-d && j>=low;j--)
        v2.push_back(v[j]);

	sort(v2.begin(),v2.end(),cmp_y);
  
	for(unsigned int i=0;i<v2.size();i++)
        for(unsigned int j=1;j<=7 && (i+j)<v2.size();j++)
            d = min(d,dis(v2[i],v2[i+j]));
    return d;
}

double divide(int l,int r)
{
	if(l>=r) return 10000;///剩一個點的時候

	int mid =(l+r)/2;
	double lmin = divide(l,mid);
	double rmin = divide(mid+1,r);
  
	return combine(l,mid,r,lmin,rmin);
}
int main()
{
	int number;
	double temp;
	double a,b;
	while(cin>>number )
	{
		if(number==0)
			break;
		for(int i=0;i<number;i++)
		{
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),cmp_x);
		cout<<divide(0,number-1);
		v.clear();
	}
	
}