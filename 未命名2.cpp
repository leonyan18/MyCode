//============================================================================
//Name：牛客多校第八场 1005 Magic Square 模拟
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 1e9;

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        LL a, n, b = -1, c = -1;
        scanf("%d%d",&n,&a);
        if (n == 1) {
            b = 1, c = a + 1;
        } else if (n == 2) {
            if (a % 2 != 0) {
                b = (1LL * a * a - 1) / 2, c = (1LL * a * a + 1) / 2;
            } else {
                b = 1LL * a * a / 4 - 1, c = 1LL * a * a / 4 + 1;
            }
        }

        cout << b << " " << c << endl;
    }
    return 0;
}
