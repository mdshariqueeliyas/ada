#include<bits/stdc++.h>
using namespace std;

struct point
{
        int x,y;
        point(int a,int b)
        {
                x=a;y=b;
        }
};

bool checkOnSegment(point p,point q,point r)
{
        if(q.x>=min(p.x,r.x) && q.x<=max(p.x,r.x) && q.y>=min(p.y,r.y) && q.y<= max(p.y,r.y))
        return true;
        else
        return false;
}

int checkIntersect(point p,point q,point r)
{
        int x = (q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);

        if(x==0)
        return 0;

        if(x<0)
        return 1;
        else
        return 2;
}

int main()
{

int x,y;
bool flag = false;
cout<<"Enter p1:"<<endl;
cin>>x>>y;
point p1(x,y);

cout<<"Enter q1:"<<endl;
cin>>x>>y;
point q1(x,y);


cout<<"Enter p2:"<<endl;
cin>>x>>y;
point p2(x,y);

cout<<"Enter q2:"<<endl;
cin>>x>>y;
point q2(x,y);

int a = checkIntersect(p1,q1,p2);
int b = checkIntersect(p1,q1,q2);
int c = checkIntersect(p2,q2,p1);
int d = checkIntersect(p2,q2,q1);

if(a!=b && c!=d)
flag = true;

if(a==0 && checkOnSegment(p1,p2,q1))
flag = true;

if(b==0 && checkOnSegment(p1,q2,q1))
flag = true;

if(c==0 && checkOnSegment(p2,p1,q2))
flag = true;

if(d==0 && checkOnSegment(p2,q1,q2))
flag = true;

if(flag)
cout<<"Lines are intersecting"<<endl;
else
cout<<"Lines are not intersecting"<<endl;

return 0;
}
