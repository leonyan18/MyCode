#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
#define mod 1000000007
ll a[105],f[105];//f是2的几次幂 a是i+1第一次出现之前的个数 
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	ll T;
    scanf("%lld",&T);
    a[0]=f[0]=1;
    for(ll i=1;i<=62;i++)a[i]=a[i-1]*2+1,f[i]=f[i-1]*2;
    ll inv=(mod+1)/2;
    while(T--)
    {
        ll pos=0,n,m,ans=0;
        scanf("%lld",&n);
        m=n;
        for(ll i=62;i>=0;i--)
            if(m-a[i]>=0)
                m-=a[i],pos=pos+(1ll<<i);//最靠近的位置如果那个数重复次数没有结束则pos取开始之前的位置 
        pos+=(m>0);
        ll now=pos-1,num=0;
        for(ll i=1;f[i-1]<=now;i++)//等差数列求和 
        {//e是最后一个出现位置 step是第几个项  s是第一项 
            ll s=f[i-1],step=(now-s)/f[i]+1,e=(step-1)*f[i]+s; 
            ll haha=(s+e)%mod*(step%mod)%mod*inv%mod;//sn等差数列的和 inv取逆元 
            ans=(ans+haha*i%mod)%mod;//i重复次数
            num+=step*i;//num是记录的个数
        }
//        cout<<"pos  "<<pos<<endl; 
        ans=(ans+1+(n-num-1)%mod*(pos%mod)%mod)%mod;//(n-num-1)缺少的个数 因为多了个1 
        printf("%lld\n",ans);
    }
}




