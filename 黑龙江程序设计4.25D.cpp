#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
struct node{  
    int l,r;//区间[l,r]  
    int add;//区间的延时标记  
    int sum;//区间和  
    int mx; //区间最大值  
    int mn; //区间最小值  
}tree[maxn<<2];//一定要开到4倍多的空间  
  
void pushup(int index){  
    tree[index].sum = tree[index<<1].sum+tree[index<<1|1].sum;  
    tree[index].mx = max(tree[index<<1].mx,tree[index<<1|1].mx);  
    tree[index].mn = min(tree[index<<1].mn,tree[index<<1|1].mn);  
}  
void pushdown(int index){  
    if(tree[index].add){  
        tree[index<<1].sum += (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add;  
        tree[index<<1|1].sum +=(tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add;  
        tree[index<<1].mx += tree[index].add;  
        tree[index<<1|1].mx += tree[index].add;  
        tree[index<<1].mn += tree[index].add;  
        tree[index<<1|1].mn += tree[index].add;  
        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;  
  
    }  
}  
void build(int l,int r,int index){
    tree[index].l = l;  
    tree[index].r = r;  
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){
        tree[index].mn = tree[index].mx = tree[index].sum;  
        return ;  
    }  
    int mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}  
void updata(int l,int r,int index,int val){  
    if(l <= tree[index].l && r >= tree[index].r){  
        tree[index].sum += (tree[index].r-tree[index].l+1)*val;  
        tree[index].mn += val;  
        tree[index].mx += val;  
        tree[index].add += val;//延时标记  
  
        return ;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,index<<1,val);  
    }  
    if(r > mid){  
        updata(l,r,index<<1|1,val);  
    }  
    pushup(index);  
}  
int query(int l,int r,int index){  
    if(l <= tree[index].l && r >= tree[index].r){  
        //return tree[index].sum;  
        return tree[index].mx;  
        //return tree[index].mn;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    int ans = 0;  
    int Max = 0;  
    int Min = INF;  
    if(l <= mid){  
        ans += query(l,r,index<<1);  
        Max = max(query(l,r,index<<1),Max);  
        Min = min(query(l,r,index<<1),Min);  
    }  
    if(r > mid){  
        ans += query(l,r,index<<1|1);  
        Max = max(query(l,r,index<<1|1),Max);  
        Min = min(query(l,r,index<<1|1),Min);  
    }  
    //return ans;  
    return Max;  
    //return Min;  
}  
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
	build(1,1e5+5,1);
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		updata(x+1,y,1,1);
	}
	cout<<query(1,1e5+5,1)<<endl;
}
