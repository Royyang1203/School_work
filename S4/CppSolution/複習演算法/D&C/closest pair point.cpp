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

vector<point> combine(int low,int mid,int high,vector<point> lmin,vector<point> rmin)
{
	vector<point>v2,temp;
	double min_left = dis(lmin[0],lmin[1]);
	double min_right = dis(rmin[0],rmin[1]);	

    double d = min(min_left,min_right);
    double line = (v[mid+1].x + v[mid].x)/2;//line:左集合與右集合的中間線x座標

	for(int i=mid+1;v[i].x<line+d && i<=high;i++)
		v2.push_back(v[i]);
	for(int j=mid;v[j].x>line-d && j>=low;j--)
        v2.push_back(v[j]);

	sort(v2.begin(),v2.end(),cmp_y);
	/*cout<<"////////////////////\n";
	for(unsigned int i=0;i<v2.size();i++)
		cout<<v2[i].x<<" "<<v2[i].y<<endl;
	cout<<"////////////////////\n";*/
	for(unsigned int i=0;i<v2.size();i++)
        for(unsigned int j=1;j<=7 && (i+j)<v2.size();j++)
		{
			if(dis(v2[i],v2[i+j])<d)
			{
				d = dis(v2[i],v2[i+j]);
				temp.clear();
				temp.push_back(v2[i]);
				temp.push_back(v2[i+j]);
			}
		}
    return temp;
}
vector<point> three_point(int n)
{
	vector<point> temp;
	float min = 1000000;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dis(v[i], v[j]) < min)
			{
				min = dis(v[i], v[j]);
				temp.push_back(v[i]);
				temp.push_back(v[j]);
			}
                
        }
    }
    return temp;
}
vector<point> divide(int l,int r)
{
	if((r-l+1)<=3)
		return three_point(r-l+1);
	
	int mid =(l+r)/2;
	vector<point> lmin = divide(l,mid);
	vector<point> rmin = divide(mid+1,r);

	return combine(l,mid,r,lmin,rmin);
}
int main()
{
	int number;
	vector<point>temp;
	double a,b,r;
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
		temp=divide(0,number-1);
		cout<<temp[0].x<<" "<<temp[0].y<<endl;
		cout<<temp[1].x<<" "<<temp[1].y<<endl;

		r = dis(temp[0],temp[1]);

		if(r<10000)
			printf("%.4f\n",r);
		else cout<<"INFINITY\n";
		v.clear();
	}
}
