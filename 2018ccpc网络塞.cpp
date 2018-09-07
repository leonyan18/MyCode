#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mod 1000000007
#define lowbit(x) (x&(-x))
#define mem(a,b) memset(a,b,sizeof(a))
#define FRER() freopen("in.txt","r",stdin);
#define FREW() freopen("out.txt","w",stdout);
 
using namespace std;
 
typedef pair<int,int> pii;
const int maxn = 200000 + 7 , inf = 0x3f3f3f3f ;
 
int nxt[maxn],to[maxn],head[maxn];
ll cap[maxn],d[maxn],siz[maxn];
int n,nEdge;
void addEdge(int u,int v,ll c){
    nxt[nEdge]=head[u],to[nEdge]=v,cap[nEdge]=c,head[u]=nEdge++;
}
 
void dp(int u,int fa){
    d[u] = 0 , siz[u] = 1;
    for(int e = head[u];~e;e=nxt[e]){
        int v = to[e];
        if(v==fa) continue;
        dp(v,u);
    }
    for(int e = head[u];~e;e=nxt[e]){
        int v = to[e];
        if(v==fa) continue;
        siz[u]+=siz[v];
        d[u]=(d[u]+d[v])%mod;
        d[u]=(d[u]+cap[e]*siz[v]%mod*(n-siz[v])%mod)%mod;
    }
}
 
int main(){
    //FRER();
    //FREW();
    int u,v;
    ll c;
    while(~scanf("%d",&n)){
        mem(head,-1);
        nEdge = 0;
        for(int i=0;i<n-1;i++){
            scanf("%d%d%lld",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
        }
        dp(1,0);
        ll f = 1;
        for(ll i = 1 ; i <= n-1 ;i++)
            f = f * i % mod;
        ll ans = d[1] * f %mod;
        ans = ans * 2 %mod;
        printf("%lld\n",ans);
    }
    return 0;
}

