#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=1000005;
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
    freopen("C://Users//yan//Desktop//Rinne Loves Study2.txt","w+",stdout);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	long long m,n,t,i=1,j,c;
    scanf("%lld %lld %lld",&n,&m,&t);
    long long move;
    long long b;
    long long a[100003]={0},d[100003]={0};
   for(c=0;c<t;c++)
   {
        scanf("%lld %lld",&move,&b);
        if(move==1){
            a[b-1]++;
        }
        else if(move==2){
            d[b-1]++;
        }
   }
   long long int q;
   scanf("%lld",&q);
    for(i=0;i<q;i++){
    	long long int x,y;
    	scanf("%lld %lld",&x,&y);
        printf("%lld\n",a[x-1]+d[y-1]);
    }
    return 0;
}



