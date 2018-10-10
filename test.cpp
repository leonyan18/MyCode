#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxn=52;
const int maxm=52;
const int maxnode=3020;
int n,m,k;
 
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[maxn],S[maxn];
    int ansd,ans[maxn];
 
    void init(int _n,int _m)
    {
        n=_n;
        m=_m;
        for(int i=0;i<=m;i++)
        {
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[m]=0,L[0]=m;
        size=m;
        for(int i=1;i<=n;i++)
            H[i]=-1;
    }
 
    void link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0)
            H[r]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
 
    void remove(int c)
    {
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }
 
    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i;
    }
 
    bool v[maxnode];
 
    int f()//¾«È·¸²¸ÇÇø¹ÀËã¼ôÖ¦
    {
        int ret=0;
        for(int c=R[0];c!=0;c=R[c])
            v[c]=true;
        for(int c=R[0];c!=0;c=R[c])
            if(v[c])
        {
            ret++;
            v[c]=false;
            for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j])
                v[Col[j]]=false;
        }
        return ret;
    }
 
    bool dance(int d)
    {
        if(d+f()>k)
            return false;
        if(d>k)
            return false;
        if(R[0]==0)
            return true;
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
            c=i;
        for(int i=D[c];i!=c;i=D[i])
        {
            remove(i);
            for(int j=R[i];j!=i;j=R[j])
                remove(j);
            if(dance(d+1)) return true;
            for(int j=L[i];j!=i;j=L[j])
                resume(j);
            resume(i);
        }
        return false;
    }
};
 
 
DLX g;
const double eps=1e-8;
 
struct point
{
    double x,y;
}city[maxm],radar[maxn];
 
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 
 
int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&m,&n,&k);
        for(int i=1;i<=m;i++)
            scanf("%lf%lf",&city[i].x,&city[i].y);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&radar[i].x,&radar[i].y);
         double l=0,r=1e5;
        while(r-l>=eps)
        {
            double mid=(l+r)/2.0;
            g.init(n,m);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(dis(radar[i],city[j])<mid-eps)
                    g.link(i,j);
            if(g.dance(0))
                r=mid-eps;
            else
                l=mid+eps;
        }
        printf("%.6lf\n",l);
    }
    return 0;
}

