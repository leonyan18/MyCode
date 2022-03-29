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
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);//取消同步
	std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		stack<char> l;
		string s;
//		clr(sk);
		ll ans=0;
		rep(i,0,n){//用栈来预处理（） 
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
		int temp1=0,now=0;//now是（的个数 temp1是第一种答案 
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
		ans+=max(max(temp1,temp2),temp3);//三种排序取最优 
		cout<<ans*2<<endl;
	} 
}

