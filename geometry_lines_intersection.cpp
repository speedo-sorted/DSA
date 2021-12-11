#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)
 
struct P {
    llint x,y;
    void read(){
        cin>>x>>y;
    }
 
    P operator -(const P& b) const{         // p3=p1-p2
        return P{x-b.x,y-b.y};
    }
    long long cross(P& b,P& c){               // a.cross(b,c) find cross product w.r.t a of b and c
        long long x1=b.x-x;
        long long x2=c.x-x;
        long long y1=b.y-y;
        long long y2=c.y-y;
        return (x1*y2-x2*y1);
    }
 
};

// see if A lies on BC -> cross product should be 0 and a.x lie b/w b,c.x and a.y lie b/w b,c.y
bool point_on_line(P& a ,P& b ,P& c){   
    if(!a.cross(b,c) && (a.x>=min(c.x,b.x) && a.y>=min(c.y,b.y) && a.x<=max(c.x,b.x) && a.y<=max(c.y,b.y)))
        return 1;
    
    return 0;
}

// used inside intersect function -> it tells if c or d b/w AB or a or b bw CD
bool line_on_line(P& a,P& b,P& c,P& d)      // if lines are collinear then check if they have point in common
{
    for(int i=0;i<2;i++)
    {
        if((c.x>=min(a.x,b.x) && c.y>=min(a.y,b.y) && c.x<=max(a.x,b.x) && c.y<=max(a.y,b.y)) || (d.x>=min(a.x,b.x) && d.y>=min(a.y,b.y) && d.x<=max(a.x,b.x) && d.y<=max(a.y,b.y)) )
            return 1;

        swap(d,b);
        swap(a,c);
    }

    return 0;
}

bool intersect(P& a,P& b,P& c,P& d)  
{
    if((a.cross(b,c)>0 && a.cross(b,d)>0) || (a.cross(b,c)<0 && a.cross(b,d)<0))
            return 0;
    else if((c.cross(d,a)>0 && c.cross(d,b)>0) || (c.cross(d,a)<0 && c.cross(d,b)<0))
        return 0;
    else if(!a.cross(b,c) && !a.cross(b,d))
    {
        if(line_on_line(a,b,c,d))
            return 1;
         
        return 0;
    }
    return 1;
}

void point_in_polygon(){            // check if m points lie inside/outside/on n vertices of polygon
    int n,m;
    cin>>n>>m;
    P poly[n];
    for(int i=0;i<n;i++)
        poly[i].read();

    for(int i=0;i<m;i++)
    {
        P point;
        point.read();
        int c=0;
        // checking by imaginary point
        
        for(int i=0;i<n;i++)
        {   
            P a1=poly[i],a2=poly[(i+1)%n];
            if(point_on_line(point,a1,a2))
            {
                c=-1;
                break;
            }
            if((a1.x<=point.x && a2.x<=point.x) || (a1.x>point.x && a2.x>point.x))
                continue;
            P left,right;
            if(a1.x<a2.x)
                left=a1,right=a2;
            else 
                left=a2,right=a1;

            if(point.cross(left,right)<0)               // checking if AB lies above point else it will not intersect (point,imaginaryRef{point,x+1,INFINITY})
                c++;
            
        }
        if(c<0)
            cout<<"BOUNDARY\n";
        else if(c%2==0)
            cout<<"OUTSIDE\n";
        else 
            cout<<"INSIDE\n";

    }

}

void lattice_points()
{
    int n;
    cin>>n;
    P poly[n];
    for(int i=0;i<n;i++)
        poly[i].read();

    llint boundary=0,twicearea=0;
    for(int i=0;i<n;i++)
    {
        P diff=poly[i]-poly[(i+1)%n],origin{0,0};
        boundary+=__gcd(abs(diff.x),abs(diff.y));

        twicearea+=origin.cross(poly[i],poly[(i+1)%n]);


    }
    twicearea=abs(twicearea);
    cout<<(twicearea+2-boundary)/2<<' '<<boundary<<'\n';
    
}
 
int main(){
    boost
    lattice_points();

    return 0;
}