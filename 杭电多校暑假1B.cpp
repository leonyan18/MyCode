#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
struct kuo{
	int l,r;
}sk[100005];
bool cmp1(kuo a,kuo b){
	if(a.l==b.l)
		return a.r>b.r;
	return a.l<b.l;
}
bool cmp2(kuo a,kuo b){
	if(a.r==b.r)
		return a.l<b.l;
	return a.r<b.r;
}
bool cmp3(kuo a,kuo b){
    if(a.r>=a.l&&b.r>=b.l) return a.l<b.l;
    else if(a.r>=a.l) return 1;
    else if(b.r>=b.l) return 0;
    return a.r>b.r;
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
	while(t--){
		int n;
		cin>>n;
		stack<char> l;
		string s;
//		clr(sk);
		ll ans=0;
		rep(i,0,n){//��ջ��Ԥ������ 
			cin>>s;
			int len=s.length();
//			cout<<s<<endl;
			rep(j,0,len){
				if(!l.empty()&&l.top()=='('&&s[j]==')'){
					l.pop();
					ans++;
					continue;
				}
				l.push(s[j]);
			}
			sk[i].l=0;
			sk[i].r=0;
			while(!l.empty()){
				if(l.top()=='(')
					sk[i].r++;
				else
					sk[i].l++;
				l.pop();
			}
		}
		sort(sk,sk+n,cmp1);
		int temp1=0,now=0;//now�ǣ��ĸ��� temp1�ǵ�һ�ִ� 
		rep(i,1,n){
			now+=sk[i-1].r;
			if(sk[i].l>now){
				temp1+=now;
				now=0;
			}				
			else{
				now=now-sk[i].l;
				temp1+=sk[i].l;
			}
//			cout<<now<<endl;	
		}
//		cout<<"1----"<<endl;
//		rep(i,0,n){
//			cout<<sk[i].l<<" "<<sk[i].r<<endl;
//		}
		sort(sk,sk+n,cmp2);
		int temp2=0;
		now=0;
		rep(i,1,n){
			now+=sk[i-1].r;
			if(sk[i].l>now){
				temp2+=now;
				now=0;
			}				
			else{
				now=now-sk[i].l;
				temp2+=sk[i].l;
			}	
		}
//		cout<<"2----"<<endl;
//		rep(i,0,n){
//			cout<<sk[i].l<<" "<<sk[i].r<<endl;
//		}
		sort(sk,sk+n,cmp3);
		int temp3=0;
		now=0;
		rep(i,1,n){
			now+=sk[i-1].r;
			if(sk[i].l>now){
				temp3+=now;
				now=0;
			}				
			else{
				now=now-sk[i].l;
				temp3+=sk[i].l;
			}	
		}
//		cout<<"3----"<<endl;
//		rep(i,0,n){
//			cout<<sk[i].l<<" "<<sk[i].r<<endl;
//		}
//		cout<<" temp1  "<<temp1<<" temp2 "<<temp1<<" temp3 "<<temp1<<endl;
		ans+=max(max(temp1,temp2),temp3);//��������ȡ���� 
		cout<<ans*2<<endl;
	} 
}

