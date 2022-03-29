#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int a[maxn];
int maxv=0;
int minv=INF;
int sta[maxn];
int lmin[maxn];
int rmin[maxn];
struct Node {
    int l, r;
    long long sum, max, min, set_lazy, add_lazy;
} tre[maxn << 2];
long long arr[maxn];
struct Segment_tree {
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
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int n;
	cin>>n;
	rep(i,1,n+1){
		cin>>a[i];
		arr[i]=arr[i-1]+a[i];
	}
	S.build(1,1,n);
	int tempmin=INF;
	int l=1,r=0;
	rep(i,1,n+1){
		while(r>=l&&a[sta[r]]>a[i]){
			rmin[sta[r]]=i;
			r--;
		}
		lmin[i]=sta[r];
		sta[++r]=i;
	}
	while(r>=l){
		rmin[sta[r]]=n+1;
		r--;
	}
	ll ans=0;
	rep(i,1,n+1){
		ll templ=arr[i-1];
		ll tempr=arr[i];
		if(i-1>0&&i-1>=lmin[i]+1){
			templ=S.query3(1,lmin[i]+1,i-1);
		}
		if(i+1<=n&&i+1<=rmin[i]-1){
			tempr=S.query2(1,i,rmin[i]-1);
		}
		ans=max(ans,(tempr-templ)*a[i]);
	}
	cout<<ans<<endl;
}



