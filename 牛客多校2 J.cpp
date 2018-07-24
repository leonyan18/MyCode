#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define LL long long
#define ULL unsigned LL
#define fi first
#define se second
#define pb push_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef pair<int,int> pll;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL mod =  (int)1e9+7;
const int N = 1e6 + 100;
vector<int> dp[N];
vector<pll> save[N];
int n, m;
int lowbit(int x)
{
    return x &(-x);
}
void Add(int x, int y, int c)
{
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= m; j += lowbit(j))
            dp[i][j] += c;
}
int Query(int x, int y)
{
    int cnt = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
           cnt += dp[i][j];
    return cnt;
}
struct Node{
    int x1, y1, x2, y2, k;
}A[N];
bool cmp(Node &x1, Node &x2){
    return x1.k < x2.k;
}
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int  t, v;
    int ans = 0;
    scanf("%d%d%d", &n, &m, &t);
    for(int i = 1; i <= n; i++)
        dp[i].resize(m+10);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &v);
            save[v].pb(pll(i,j));
        }
    }
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d%d%d", &A[i].x1, &A[i].y1 , &A[i].x2, &A[i].y2, &A[i].k);
        Add(A[i].x1, A[i].y1, 1);
        Add(A[i].x2+1,A[i].y2+1,1);
        Add(A[i].x1,A[i].y2+1,-1);
        Add(A[i].x2+1,A[i].y1,-1);
    }
    sort(A+1,A+1+t,cmp);
    for(int i = 1, j = 1, zz; i <= n * m; i++){
  
        while(A[j].k < i && j <= t)   j++;
        if(save[i].size() == 0) continue;
        zz = j;
        while(A[zz].k == i && zz <=t) zz++;
        for(int z = j; z < zz; ++z){
            Add(A[z].x2+1,A[z].y2+1,-1);
            Add(A[z].x1,A[z].y1,-1);
            Add(A[z].x1,A[z].y2+1,1);
            Add(A[z].x2+1,A[z].y1,1);
        }
        for(pair<int,int> it : save[i]){
            if(Query(it.fi, it.se)){
                ans++;
            }
        }
        for(int z = j; z < zz; ++z){
            Add(A[z].x2+1,A[z].y2+1,1);
            Add(A[z].x1,A[z].y1,1);
            Add(A[z].x1,A[z].y2+1,-1);
            Add(A[z].x2+1,A[z].y1,-1);
        }
        j = zz;
    }
    cout << ans << endl;
    return 0;
}



