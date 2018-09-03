#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <map>
#define PI acos(-1.0)
#define mod 1e9+7
#define inf 0x3f3f3f3f
using namespace std;


int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
    int t,n,m;
//    scanf("%d",&t);
    t=100;
    n=0;
    while(t--)
    {

//        scanf("%d",&n);
		n++;
        if(n==0)printf("0\n");
        else if(n==1)printf("4\n");
        else if(n==2)printf("4\n");
        else
        {
            m=sqrt(n/2);
            //当正好是正方形的时候
            printf("%d ",n);
            if(m*m*2==n)printf("%d\n",m*4);
            else if(m*(m+1)*2==n)printf("%d\n",m*4+2);
            else if(n>m*m*2&&n<(m+1)*m*2)
            {
                if(n<=m*m*2+m-1)printf("%d\n",m*4+1);
                else printf("%d\n",m*4+2);
            }
            else if(n>m*(m+1)*2)
            {
                if(n<=m*(m+1)*2+m)printf("%d\n",m*4+3);
                else printf("%d\n",m*4+4);
            }
        }
    }
    return 0;
}
