#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
int ans[100005];
int pre[100005];
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
	while(t--){
		int n,m;
		clr(ans);
		cin>>n>>m;
		rep(i,1,n+1) pre[i]=i;//��ʼ����ߵĶ˵� 
		rep(i,0,m){
			int l,r;
			cin>>l>>r;
			pre[r]=min(pre[r],l); 
		}
		per(i,1,n){
			pre[i]=min(pre[i],pre[i+1]);//���Ÿ�����ߵĶ˵� 
		}
		set<int> v;
		v.clear();
		int pos=1;//�±� 
		rep(i,1,n){
			v.insert(i);//��ʼ��set��������� 
		}
		rep(i,1,n+1){
			while(pos<pre[i]){//posС����ߵ�����˵��ǰ�������Ҫ�ӻ�set�� 
				v.insert(ans[pos]);
				pos++;
			}
			ans[i]=*v.begin();//����set����С�� 
			v.erase(ans[i]);//��ȥ����� 
		}
		rep(i,1,n+1){
			cout<<ans[i];
			if(i!=n){
				cout<<" ";
			} 
		}
		cout<<endl;
	} 
}




