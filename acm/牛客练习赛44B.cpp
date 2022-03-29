#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=20000005;
unsigned int SA, SB, SC;
int mod;
unsigned int Rand(){
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}
struct Segment_tree {
    struct Node {
        int l, r;
        short sum, max, min, set_lazy, add_lazy;
    } tre[maxn *2+1];
    short arr[maxn];
    inline void push_up(int rt) {
        if(tre[rt].l == tre[rt].r) {
            return ;
        }
        tre[rt].sum = tre[rt<<1].sum + tre[rt<<1|1].sum;
        tre[rt].max = max(tre[rt<<1].max, tre[rt<<1|1].max);
        tre[rt].min = min(tre[rt<<1].min, tre[rt<<1|1].min);
    }
    inline void push_down(int rt) {
        if(tre[rt].set_lazy) { ///if set_lazy add_lazy = 0
            tre[rt<<1].set_lazy = tre[rt].set_lazy;
            tre[rt<<1].sum = (tre[rt<<1].r - tre[rt<<1].l + 1) * tre[rt].set_lazy;
            tre[rt<<1].max = tre[rt].set_lazy;
            tre[rt<<1].min = tre[rt].set_lazy;
            tre[rt<<1|1].set_lazy = tre[rt].set_lazy;
            tre[rt<<1|1].sum = (tre[rt<<1|1].r - tre[rt<<1|1].l + 1) * tre[rt].set_lazy;
            tre[rt<<1|1].max = tre[rt].set_lazy;
            tre[rt<<1|1].min = tre[rt].set_lazy;
            tre[rt].add_lazy = 0;
            tre[rt<<1].add_lazy = tre[rt<<1|1].add_lazy = 0;
            tre[rt].set_lazy = 0;
            return ;
        }
        if(tre[rt].add_lazy) {
            tre[rt<<1].add_lazy += tre[rt].add_lazy;
            tre[rt<<1].sum += (tre[rt<<1].r - tre[rt<<1].l + 1) * tre[rt].add_lazy;
            tre[rt<<1].max += tre[rt].add_lazy;
            tre[rt<<1].min += tre[rt].add_lazy;
            tre[rt<<1|1].add_lazy += tre[rt].add_lazy;
            tre[rt<<1|1].sum += (tre[rt<<1|1].r - tre[rt<<1|1].l + 1) *
                                tre[rt].add_lazy;
            tre[rt<<1|1].max += tre[rt].add_lazy;
            tre[rt<<1|1].min += tre[rt].add_lazy;
            tre[rt].add_lazy = 0;
        }
    }
    void build(int rt,int l,int r) {
        tre[rt].l = l;
        tre[rt].r = r;
        tre[rt].set_lazy = 0;
        tre[rt].add_lazy = 0;
        if(l == r) {
            tre[rt].sum = tre[rt].max = tre[rt].min = arr[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        push_up(rt);
    }
    void update1(int rt,int l,int r,long long val) { ///add
        push_down(rt);
        if(l == tre[rt].l && tre[rt].r == r) {
            tre[rt].add_lazy = val;
            tre[rt].sum += (tre[rt].r - tre[rt].l + 1) * val;
            tre[rt].max += val;
            tre[rt].min += val;
            return ;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            update1(rt<<1,l,r,val);
        } else if(l > mid) {
            update1(rt<<1|1,l,r,val);
        } else {
            update1(rt<<1,l,mid,val);
            update1(rt<<1|1,mid+1,r,val);
        }
        push_up(rt);
    }
    void update2(int rt,int l,int r,long long val) { ///set
        push_down(rt);
        if(l == tre[rt].l && tre[rt].r == r) {
            tre[rt].set_lazy = val;
            tre[rt].sum = (tre[rt].r - tre[rt].l + 1) * val;
            tre[rt].max = val;
            tre[rt].min = val;
            tre[rt].add_lazy = 0;
            return ;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            update2(rt<<1,l,r,val);
        } else if(l > mid) {
            update2(rt<<1|1,l,r,val);
        } else {
            update2(rt<<1,l,mid,val);
            update2(rt<<1|1,mid+1,r,val);
        }
        push_up(rt);
    }
    long long query1(int rt,int l,int r) { ///sum
        push_down(rt);
        if(l == tre[rt].l && tre[rt].r == r) {
            return tre[rt].sum;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            return query1(rt<<1,l,r);
        } else if(l > mid) {
            return query1(rt<<1|1,l,r);
        } else {
            return query1(rt<<1,l,mid) + query1(rt<<1|1,mid+1,r);
        }
    }
    long long query2(int rt,int l,int r) { ///max
        push_down(rt);
        if(l == tre[rt].l && tre[rt].r == r) {
            return tre[rt].max;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            return query2(rt<<1,l,r);
        } else if(l > mid) {
            return query2(rt<<1|1,l,r);
        } else {
            return max(query2(rt<<1,l,mid), query2(rt<<1|1,mid+1,r));
        }
    }
    long long query3(int rt,int l,int r) { ///min
        push_down(rt);
        if(l == tre[rt].l && tre[rt].r == r) {
            return tre[rt].min;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            return query3(rt<<1,l,r);
        } else if(l > mid) {
            return query3(rt<<1|1,l,r);
        } else {
            return min(query3(rt<<1,l,mid), query3(rt<<1|1,mid+1,r));
        }
    }
} S;
int aa[maxn];
int main() {
	#ifdef ONLINE_JUDGE
	#else
	   freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n,mod; 
	cin>>n>>mod>>SA>>SB>>SC;
	for(int i = 1;i <= n;++i)
		aa[i] = Rand() % mod + 1;
	ll ans=n*(n-1)/2;
	S.build(1,1,n);
	rep(i,1,n+1){
		S.update1(1,i,i,1);
		if(i-aa[i]-1>=1){
			ll sum=S.query1(1,1,i-aa[i]-1);
//			cout<<sum<<endl;
			ans+=sum;
			S.update2(1,1,i-aa[i],0);
			S.update1(1,i-1,i-1,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}


