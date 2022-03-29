#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=10005;
vector<ll> v[maxn];
int main() {
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k, ans = 0, x;
         scanf("%lld%lld%lld",&n,&m,&k) ;
        rep(i, 1, m + 1) {
            v[i].clear();
        }
        rep(i, 1, n + 1) {
             scanf("%d",&x);
            v[x].push_back(i);
        }
        rep(i, 1, m + 1) {
            x = v[i].size() / k;
            rep(j, 0, x) {
                if (v[i][j] <= n / 2) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

