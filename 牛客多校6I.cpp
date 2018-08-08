#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int mod=998244353;
//(0)����
const int MAXN=200010;
struct node{
	int l,r;
	int id;
	bool operator<(const node &A)const{
		if(l==A.l) return r<A.r;
		return l<A.l;
	}
};
node a[MAXN];
int ans[MAXN<<2];
int b[MAXN];
int p[MAXN];
int n,m;
int res,num;
//a[]Ϊԭ������Ϣ��ans[]ģ���߶���ά�������Ҷ˵� b[]Ϊ�ڼ��α��ƻ� p[]l���������з�����ֲ��� 
//(1)���½����Ϣ
void PushUp(int rt)
{
    ans[rt]=max(ans[rt<<1],ans[rt<<1|1]);
}
//(2)����
void Build(int l,int r,int rt)
{
	ans[rt]=0;
    if (l==r)
    {
        ans[rt]=a[l].r;
        return;
    }
    int mid=(l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}
//(5)�������
void Update(int L,int R,int x,int index,int l,int r,int rt)
{
	if(ans[rt]<x) return;//���x�������Ҷ˵��ұ�return 
	if(L>R || l>r) return; 
    if (l==r)
    {
    	ans[rt]=-INF;//�õ���Ҷ˵���Ϊ����С 
        b[a[l].id]=index;//��¼�ڼ��α��ƻ� 
        num++;//�������� 
        res=res*a[l].id%mod;//�۳� 
        return;
    }
    int mid=(l+r)>>1;
    if (L<=mid) Update(L,R,x,index,l,mid,rt<<1);
    if (R>mid) Update(L,R,x,index,mid+1,r,rt<<1|1);
    PushUp(rt);
}
int main(){
	//���ز���
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//ȡ��ͬ��
	std::cin.tie(0);//���cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
	int t;
	cin>>t;
	rep(ca,1,t+1) {
		clr(b);
		clr(ans);
		clr(p);
		clr(a);
		printf("Case #%d:\n",ca);
		cin>>n>>m;
		rep(i,1,n+1){
			cin>>a[i].l>>a[i].r;
			a[i].id=i;
			p[i]=a[i].l;
		}
		sort(a+1,a+n+1);
		sort(p+1,p+n+1);
		Build(1,n,1);
		rep(i,1,m+1){
			int x;
			cin>>x;
			x^=res;
			int pos=upper_bound(p+1,p+n+1,x)-p-1;//�ҳ�lС�ڵ���x������ 
			res=1;num=0;//��ʼ��res��num 
			Update(1,pos,x,i,1,n,1);//���� 
			printf("%d\n",num);
			if(num==0) res=0;
		}
		rep(i,1,n+1) printf("%d%c",b[i],i==n?'\n':' ');
	}
}


