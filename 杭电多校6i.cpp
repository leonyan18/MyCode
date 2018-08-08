#include<bits/stdc++.h>

using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int w[MAXN];
int v[MAXN];
int par[MAXN];
int Rank[MAXN];
bool a[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        Rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x || a[x]) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    int t;
    cin >> t;
    while (t--) {
        clr(a);
        clr(w);
        clr(v);
        char s[15];
        int n;
        cin >> n;
        init(n);
        rep(i,1,n+1){
            int pos;
            cin >> pos >> s;
            if (s[0] == 'w') {
                w[i] = pos;
            } else {
                v[i] = pos;
            }
        }
        rep(i,1,n+1){
            if (w[i] != 0) {
                int temp = w[i];
                set<int> si;
                int size = 0;
                si.insert(w[i]);
                while (v[temp] != 0 && size != si.size()) {
                    size = int(si.size());
                    temp = v[temp];
                    si.insert(temp);
                }
                if (temp == i) {
                    a[w[i]] = true;
                }
            }
        }
        rep(i,1,n+1){
            if (v[i])  {
                par[i] = find(v[i]);
            }
        }
        int sum = 0;
        rep(i,1,n+1){
            sum += a[find(i)];
        }
        cout << "0 " << sum << endl;
    }
    return 0;
}
