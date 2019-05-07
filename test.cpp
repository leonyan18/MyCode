#include<bits/stdc++.h>

#define LL long long
using namespace std;
const int maxn = 1005;
LL dp[maxn][maxn], kuo[maxn], val[maxn], wei[maxn], zhi[maxn], qi[maxn];
char chuan[maxn];

int main() {
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
    LL a, k;
    while (~scanf("%lld", &a)) {
        while (a--) {
            scanf("%lld", &k);
            scanf("%s", chuan);
            LL ru = 1;
            kuo[0] = 0;
            LL ru1 = 1;
            for (LL i = 0; i < k; i++) {
                scanf("%lld", &val[i]);
                if (chuan[i] == ')') {
                    kuo[ru] = kuo[ru - 1] + val[i];
                    ru++;
                } else {
                    wei[ru1] = i;
                    zhi[ru1] = val[i];
                    qi[ru1] = ru - 1;
                    ru1++;
                }
            }
            ru1--;
            ru--;
            memset(dp, 0, sizeof(dp));
            LL jie = 0;
            for (LL i = ru1; i >= 1; i--) {
                LL zuo = ru1 - i;
                for (LL j = k - 1 - zuo; j >= wei[i]; j--) {
                    LL hou = k - 1 - j - zuo;
                    LL de = kuo[ru - hou] - kuo[qi[i]];
                    if (j == k - 1 - zuo)dp[i][j] = zhi[i] * de + dp[i + 1][j + 1];
                    else dp[i][j] = max(zhi[i] * de + dp[i + 1][j + 1], dp[i][j + 1]);
                    if (i == 1) {
                        if (dp[i][j] > jie)jie = dp[i][j];
                    }
                }
                for (LL j = wei[i] - 1; j >= wei[i - 1]; j--) {
                    dp[i][j] = dp[i][j + 1];
                    if (i == 1) {
                        if (dp[i][j] > jie)jie = dp[i][j];
                    }
                }
            }
            printf("%lld\n", jie);
        }
    }
    return 0;
}  
