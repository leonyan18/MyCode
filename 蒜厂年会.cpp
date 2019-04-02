#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;
int a[N];
LL pre[N];
int main() {
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
       scanf("%d", &a[i]);
       a[n + i] = a[i];
   }
   for (int i = 1; i <= 2 * n; i++) {
       pre[i] = pre[i - 1] + a[i];
   }
   deque<int> q;
   q.push_back(0);
   LL ans = a[1];
   int l=0;
	int r=0;
   for (int i = 1; i <= 2 * n; i++) {
       if (!q.empty() && q.front() < i - n) {
           q.pop_front();
       }
       if(ans<pre[i] - pre[q.front()]){
       	printf("%d %d %lld\n", l,r,ans);
       	r=i;
       	l=q.front();
	   }
       ans = max(ans, pre[i] - pre[q.front()]);
       while (!q.empty() && pre[q.back()] >= pre[i]) {
           q.pop_back();
       }
       q.push_back(i);
   }
    printf("%d %d\n", l,r);
   printf("%lld\n", ans);
   return 0;
}
