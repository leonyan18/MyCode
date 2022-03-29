
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
const int mod=1e9+7;
ll quick(ll a,ll b,ll c){
    ll ans=1;
    a=a%c;
    while(b!=0)
    {
        if(b&1) ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return ans;
}
const int MAXN = 100010;
const int M = MAXN * 30;
int n,q,m,tot,seed;
int a[MAXN], t[MAXN];
int T[MAXN], lson[M], rson[M], c[M];
void Init_hash(){
    for(int i = 1; i <= n;i++)
        t[i] = a[i];
    sort(t+1,t+1+n);
}
int build(int l,int r){
    int root = tot++;
    c[root] = 0;
    if(l != r){
        int mid = (l+r)>>1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}
int mhash(int x){
    return lower_bound(t+1,t+1+m,x) -t;
}
int update(int root,int pos,int val){
    int newroot = tot++, tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = m;
    while(l < r){
        int mid = (l+r)>>1;
        if(pos <= mid){
            lson[newroot] = tot++; rson[newroot] = rson[root];
            newroot = lson[newroot]; root = lson[root];
            r = mid;
        }
        else{
            rson[newroot] = tot++; lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid+1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k){
    int l = 1, r = m;
    while( l < r){
        int mid = (l+r)>>1;
        if(c[lson[left_root]] -c[lson[right_root]] >= k ){
            r = mid;
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
        else{
            l = mid + 1;
            k -= c[lson[left_root]]- c[lson[right_root]];
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    return l;
}
int main()
{
    scanf("%d%d", &n,&seed);
    m=n;
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    tot = 0;
    Init_hash();
    T[n+1] = build(1,n);
    for(int i = n;i ;i--){
        int pos = mhash(a[i]);
        T[i] = update(T[i+1],pos,1);
    }
    ll sum=0;
    rep(i,1,n+1){
        rep(j,i,n+1){
            int k;
            int l=i;
            int r=j;
            if(j-i+1&1){
                int pos=query(T[l], T[r+1],j-i+1+1>>1);
//                cout<<a[pos]<<endl;
                sum+=quick(seed,(i-1)*n+r,mod)*a[pos]%mod*2;
            }
            else{
                ll num1=query(T[l], T[r+1],j-i+1>>1);
                ll num2=query(T[l], T[r+1],(j-i+1>>1)+1);
//                cout<<(a[num1]+a[num2])/2<<endl;
                sum+=quick(seed,(i-1)*n+r,mod)*((a[num1]+a[num2]))%mod;
            }
        }
    }
    sum=sum%mod;
    cout<<sum<<endl;
    return 0;
}

