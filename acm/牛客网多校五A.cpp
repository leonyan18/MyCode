#include<bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
 
using namespace std;
typedef long long LL;
const int N = 100005;
const double EPS = 1.0e-6;
int n, k, p;
int w[N], v[N];
double tmp[N];
 
bool check(double x) {
    for (int i = 0; i < n; i++) {
        tmp[i] = v[i] - x * w[i];
    }
 
    sort(tmp, tmp + n);
 
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += tmp[n - i - 1];
    }
 
    return sum >= 0;
}
 
 
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
 
    LL x = 0, y = 0;
    scanf("%d %d", &n, &k);
 
    k = n - k;
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x += w[i];
    }
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        v[i] = p * w[i];
        y += v[i];
    }
 
    double low = 0;
    double high = 1000005;
    while (high - low > EPS) {
        double mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
 
    printf("%.8lf\n", high);
 
 
    return 0;
}
