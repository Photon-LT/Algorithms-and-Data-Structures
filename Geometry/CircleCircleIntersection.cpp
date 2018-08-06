#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define oo 666666666

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

ld CircleCircleIntersection(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2)
{
    ld D = dist(x1,y1,x2,y2);
    ld PI = atan(1)*4;
    if(r1+r2 < D)return 0; //no intersection
    if(D+r1 <= r2)return PI*r1*r1; //smaller circle inside bigger one
    ld angle1 = 2.0 * acos((D * D + r1 * r1 - r2 * r2) / (2 * D * r1));
	ld angle2 = 2.0 * acos((D * D + r2 * r2 - r1 * r1) / (2 * D * r2));
	return 0.5 * (r1 * r1 * (angle1 - sin(angle1)) + r2 * r2 * (angle2 - sin(angle2)));
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ll x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if(r1 > r2){swap(x1,x2);swap(y1,y2);swap(r1,r2);}
    cout<<setprecision(13)<<fixed<<CircleCircleIntersection(x1,y1,r1,x2,y2,r2)<<"\n";
}
