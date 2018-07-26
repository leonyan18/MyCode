#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N=101000;
struct node {
	int fg;//标记 
	int s;
	int mv;/最小值 
}nd[4*N];
int b[N],n,m,l,r;
char s[20];
 
void upd(int p) {
	nd[p].mv=min(nd[p+p].mv,nd[p+p+1].mv);
	nd[p].s=nd[p+p].s+nd[p+p+1].s;
}
void setf(int p,int f) {
	nd[p].fg+=f;
	nd[p].mv+=f;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].mv=b[l]-1;
		nd[p].s=0;
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
int query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
	}
}
void modify(int p,int l,int r,int tl,int tr) {
	if (tl>tr) return;
//	printf("modify %d %d %d %d %d %d\n",l,r,tl,tr,nd[p].mv,nd[p].s);
	if (tl==l&&tr==r) {
		if (nd[p].mv>0) {
			nd[p].mv--;
			nd[p].fg--;
		} else {
			if (tl==tr) {
				nd[p].mv=b[l]-1;
				nd[p].s++;
			} else {
				push(p);
				int md=(l+r)>>1;
				if (nd[p+p].mv==0) modify(p+p,l,md,tl,md);
					else setf(p+p,-1);
				if (nd[p+p+1].mv==0) modify(p+p+1,md+1,r,md+1,tr);
					else setf(p+p+1,-1);
				upd(p);
			}
		}
	} else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr);
		else modify(p+p,l,md,tl,md),modify(p+p+1,md+1,r,md+1,tr);
		upd(p);
	}
//	printf("ff %d %d\n",p,nd[p].s);
}
 
int main() {
	while (scanf("%d%d",&n,&m)!=EOF) {
		rep(i,1,n+1) scanf("%d",b+i);
		build(1,1,n);
		rep(i,1,m+1) {
			scanf("%s%d%d",s,&l,&r);
			if (s[0]=='a') {
				modify(1,1,n,l,r);
			} else {
				printf("%d\n",query(1,1,n,l,r));
			}
		}
	}
}
 
