//ALDS1_5_C Recursion / Divide and Conquer - Koch Curve
#include <cstdio>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
    Point(){}
    Point(int x1, int y1){
        x = x1;
        y = y1;
    }
    void print()
    {
        printf("%.8f %.8f\n",x,y);
    }

};

void koch(int n,Point p1, Point p2)
{
    if(n==0)
    {
        return;
    }

    Point s,t,u;
    double unit = M_PI / 180.0;
    s.x = (2*p1.x + p2.x)/3.0;
    s.y = (2*p1.y + p2.y)/3.0;
    t.x = (p1.x + 2*p2.x)/3.0;
    t.y = (p1.y + 2*p2.y)/3.0;
    u.x = (t.x-s.x)*cos(60.0*unit) - (t.y-s.y)*sin(60.0*unit) + s.x;
    u.y = (t.x-s.x)*sin(60.0*unit) + (t.y-s.y)*cos(60.0*unit) + s.y;

    koch(n-1,p1,s);
    s.print();
    koch(n-1,s,u);
    u.print();
    koch(n-1,u,t);
    t.print();
    koch(n-1,t,p2);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    Point p1(0,0),p2(100,0);
    p1.print();
    koch(n,p1,p2);
    p2.print();
    return 0;
}