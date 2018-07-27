#include<bits/stdc++.h>
using namespace std;
#define Lson l,m,rt<<1
#define Rson m+1,r,rt<<1|1
#define pll pair<int,int>
#define mp make_pair
#define ll long long
#define INF 0x3f3f3f3f
const int maxn=1e5+5;
int n,q;
struct node
{
    int cnt,addv,minb,maxa;
} tree[maxn<<2];
int b[maxn];
void push_up(int rt)
{
    tree[rt].minb=min(tree[rt<<1].minb,tree[rt<<1|1].minb);
    tree[rt].cnt=tree[rt<<1].cnt+tree[rt<<1|1].cnt;
    tree[rt].maxa=max(tree[rt<<1].maxa,tree[rt<<1|1].maxa);
}
void push_down(int rt)
{
    if(tree[rt].addv)
    {
        int v=tree[rt].addv;
        tree[rt].addv=0;
        tree[rt<<1].maxa+=v;
        tree[rt<<1|1].maxa+=v;
        tree[rt<<1].addv+=v;
        tree[rt<<1|1].addv+=v;
    }
}
void build(int l,int r,int rt)
{
    tree[rt].addv=0;
    if(l==r)
    {
        tree[rt].cnt=tree[rt].maxa=0;
        tree[rt].minb=b[l];
        return;
    }
    int m=l+r>>1;
    build(Lson);
    build(Rson);
    push_up(rt);
}
void updata(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        tree[rt].maxa++;
        if(tree[rt].maxa<tree[rt].minb)
        {
            tree[rt].addv++;
            return;
        }
        if(l==r&&tree[rt].maxa>=tree[rt].minb)
        {
            tree[rt].cnt++;
            tree[rt].minb+=b[l];
            return;
        }
    }
    push_down(rt);
    int m=l+r>>1;
    if(L<=m)
        updata(L,R,Lson);
    if(R>m)
        updata(L,R,Rson);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return tree[rt].cnt;
    }
    int m=l+r>>1;
    push_down(rt);
    int ans=0;
    if(L<=m)
        ans+=query(L,R,Lson);
    if(R>m)
        ans+=query(L,R,Rson);
    return ans;
}
int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
    int n,x,y;
    while(~scanf("%d %d",&n,&q))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }
        build(1,n,1);
        char pp[6];
        int l,r;
        while(q--)
        {
            scanf("%s%d%d",pp,&l,&r);
            if(pp[0]=='a')
            {
                updata(l,r,1,n,1);
            }
            else
            {
                printf("%d\n",query(l,r,1,n,1));
            }
        }
    }
    for(int i=0;i<4*n;i++){
		cout<<tree[i].addv<<" "<<tree[i].maxa<<" "<<tree[i].minb<<" "<<tree[i].cnt<<endl;
	}
    return 0;
}
