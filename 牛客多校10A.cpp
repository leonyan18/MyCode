#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
const int mod= 998244353;
ll presum[maxn];
ll a[maxn];
ll qkm(ll base, ll mi){
    ll ans = 1;
    while(mi) {
        if(mi & 1) ans = ans * base % mod;
        base = base * base % mod;
        mi >>= 1;
    }
    return ans;
}
int main(){
    //本地测试
    #ifdef ONLINE_JUDGE
    #else
//    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);//取消同步
    std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    int t;
    scanf("%d", &t);
    while(t--){
        ll n,m;
        scanf("%lld %lld", &n,&m);
        ll sum=0;
        ll temp=qkm(2,n*m);
        presum[0]=0;
        a[0]=0;
        rep(i,1,n+1){
            cin>>a[i];
            sum+=a[i];
            sum%=mod;
            presum[i]=sum;
        }
        rep(i,0,m){
            ll op,l,r;
            scanf("%lld%lld%lld", &op,&l,&r);
            if(op==1){
                continue;
            }
            else{
                ll ans=presum[r]-presum[l-1]+mod;
                ans%=mod;
                ans=ans*temp%mod;
                cout<<ans<<endl;
            }
        }
    }
}
