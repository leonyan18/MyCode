#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
int edge[maxn][10][2];
int el[maxn];
int num[maxn];
int vis[maxn];
int a[maxn];
int b[maxn];
int topos[maxn];
int tt=0;
struct Segment_tree {
    struct Node {
        int l, r;
        long long sum, max, min, set_lazy, add_lazy;
    } tre[maxn << 2];
    long long arr[maxn];
    inline void push_up(int rt) {
        if(tre[rt].l == tre[rt].r) {
            return ;
        }
        tre[rt].sum = tre[rt<<1].sum + tre[rt<<1|1].sum;
        tre[rt].max = max(tre[rt<<1].max, tre[rt<<1|1].max);
        tre[rt].min = min(tre[rt<<1].min, tre[rt<<1|1].min);
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
    long long query1(int rt,int l,int r,int k) { ///sum
    	cout<<"´Î”µ"<<++tt<<endl;
        if(l == tre[rt].l && tre[rt].r == r) {
        	if(tre[rt].max<=k)
            	return r-l+1;
            if(tre[rt].min>k)
            	return 0;
        }
        int mid = (tre[rt].l + tre[rt].r) >> 1;
        if(r <= mid) {
            return query1(rt<<1,l,r,k);
        } else if(l > mid) {
            return query1(rt<<1|1,l,r,k);
        } else {
            return query1(rt<<1,l,mid,k) + query1(rt<<1|1,mid+1,r,k);
        }
    }
} S;
int main(){
	//±¾µØ²âÊÔ
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int x,y,len;
		scanf("%d%d%d",&x,&y,&len);
		num[x]++;
		num[y]++;
		edge[x][el[x]][0]=y;
		edge[y][el[y]][0]=x;
		edge[x][el[x]++][1]=len;
		edge[y][el[y]++][1]=len;
	}
	int start=0;
	int end=0;
	rep(i,1,n+1){
		if(num[i]==1&&start==0){
			start=i;
		}
		if(num[i]==1&&start!=0){
			end=i;
		}
	}
	int pos=start;
	vis[pos]=1;
	int now=0;
	a[now++]=pos;
	while(pos!=end){
		rep(i,0,el[pos]){
			int next=edge[pos][i][0];
			if(vis[next]==0){
				pos=next;
				vis[pos]=1;
				a[now++]=pos;
				break; 
			}
		}
	}
	rep(i,0,n){
		topos[a[i]]=i;
		if(i!=0){
			rep(j,0,el[a[i]]){
				if(edge[a[i]][j][0]==a[i-1]){
					S.arr[i]=edge[a[i]][j][1];
				}
			}
		}
	}
	S.build(1,1,n-1);
	rep(i,0,m){
		int tempx,tempy,tempk;
		scanf("%d%d%d",&tempx,&tempy,&tempk);
		int x=min(topos[tempx],topos[tempy]);
		int y=max(topos[tempx],topos[tempy]);
		printf("%d\n",S.query1(1,x+1,y,tempk));
	}
}
