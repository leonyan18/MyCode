#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define clr(x) memset(x,0,sizeof(x))
const int INF=0x3f3f3f3f;
const int maxn=100005;
string son="sson";
string dau="sdottir";
string a[maxn];
map<string,bool> sex;
map<string,bool>  pos;
map<string,string> mtx;
map<string,bool> orgin;
set<string> s;
int main(){
	//本地测试
	#ifdef ONLINE_JUDGE
	#else
    freopen("C://Users//yan//Desktop//in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	getchar();
	rep(i,0,n){
		string temp1,temp2;
		cin>>temp1;
		a[i].append(temp1);
		a[i].append(" ");
		cin>>temp2;
		a[i].append(temp2);
		int len=a[i].length();
		if(len>4&&a[i].compare(len-4,len,son)==0){
			a[i].erase(len-4,len);
			mtx[temp1]=temp2.substr(0,temp2.length()-4);
			sex[a[i]]=1;
		}else if(len>7&&a[i].compare(len-7,len,dau)==0){
			a[i].erase(len-7,len);
			mtx[temp1]=temp2.substr(0,temp2.length()-7);
			sex[a[i]]=0;
		}else{
			mtx[temp1]=temp2;
			orgin[temp2]=1;
			if(temp2[temp2.length()-1]=='f'){
				sex[a[i]]=0;
			}else{
				sex[a[i]]=1;
			}
		}
		pos[a[i]]=1;
//		cout<< mtx[temp1]<<endl; 
//		cout<<a[i]<<" "<<sex[a[i]]<<" "<<pos[a[i]]<<endl;
	}
	int q;
	cin>>q;
	cout<<orgin["orgin"]<<endl;
	while(q--){
		string p1,p2;
		string temp;
		cin>>temp;
		p1.append(temp);
		p1.append(" ");
		cin>>temp;
		p1.append(temp);
		cin>>temp;
		p2.append(temp);
		p2.append(" ");
		cin>>temp;
		p2.append(temp);
		if(pos[p1]&&pos[p2]){
			if(sex[p1]!=sex[p2]){
				s.clear();
				string name1,name2;
				int pos=p1.find(" ");
				name1=p1.substr(0,pos);
				pos=p2.find(" ");
				name2=p2.substr(0,pos);
				int sum1=0;
				int sum2=0;
				bool flag=0;
				while(1){
//					cout<<name1<<"==="<<name2<<endl;
					if(orgin[name1]==0){
						s.insert(name1);
						name1=mtx[name1];
						sum1++;
					}
					if(orgin[name2]==0){
						s.insert(name2);
						name2=mtx[name2];
						sum2++;
					}
					if(sum1>=5&&sum2>=5){//都过了5代 
						flag=1;
						break;
					}
					if(sum1+sum2!=s.size()&& (sum1 < 5 || sum2 < 5)){//有重复元素 
						flag=0;
						break;
					}
					if(orgin[name1]==1&&orgin[name2]==1){//如果都到了祖先说明应该结束了 
						flag=1;
						break;
					}
				}
				if(flag){
					cout<<"Yes"<<endl;
				}else{
					cout<<"No"<<endl;
				}
			}else{
				cout<<"Whatever"<<endl;
			}
		}else{
			cout<<"NA"<<endl;
		}
	}
}
