#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int MAXN = 2e6 + 10;
const int MAXM = 1e8 + 10;
const ll mod = 1e9 + 7;

ll f[MAXN];

int main() {
#ifdef local
    freopen("data.txt", "r", stdin);
//    freopen("data.txt", "w", stdout);
#endif
    int cas = 1;
    int t;
    scanf("%d",&t);
    while(t--) {
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        printf("Case #%d: ",cas++);
        if(m <= k) {
            f[1] = k % (n - m + 1);
            if(f[1] == 0) f[1] = n - m + 1;
            for(ll i = 2; i <= m; i++)
                f[i] = (f[i - 1] + k - 1) % (n - m + i) + 1;
            printf("%lld\n",f[m]);
        } else {
            if(k == 1) printf("%lld\n",m);
            else {
                ll a = n - m + 1, b = 1;
                ll c = k % a, x = 0;
                if(c == 0) c = a;
                while(b + x <= m) {
                    a += x, b += x, c += k * x;
                    c %= a;
                    if(c == 0) c = a;
                    x = (a - c) / (k - 1) + 1;
                }
                c += (m - b) * k;
                c %= n;
                if(c == 0) c = n;
                printf("%lld\n",c);
            }
        }
    }
    return 0;
}
