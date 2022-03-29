#include<bits/stdc++.h>
 
using namespace std;
typedef long long LL;
const int MOD = 998244353;
 
int main() {
#ifndef ONLINE_JUDGE
freopen("C://Users//yan//Desktop//in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<LL> inv(n + 5ULL), ans(n + 5ULL);
    inv[0] = inv[1] = ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    for (int i = 2; i <= n; i++)
        ans[i] = ((6 * i - 3) * ans[i - 1] % MOD - (i - 2) * ans[i - 2] % MOD + MOD) % MOD * inv[i + 1] % MOD;
    if(n == 1) cout << 1 << endl;
    else cout << ans[n - 1] * 2 % MOD << endl;
    return 0;
}
