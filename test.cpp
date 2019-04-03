
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
struct Peoson {
	char sex;
	string father;
};
map<string, Peoson> people;
int judge(string a, string b) {
	set<string> s;
	int sum1=0;
	int sum2=0;
	s.clear();
	while(1){
		if(!a.empty()){
			s.insert(a);
			sum1++;
			a = people[a].father;
		}
		if(!b.empty()){
			s.insert(b);
			sum2++;
			b = people[b].father;
		}
		if (sum1 >= 5 && sum2 >= 5)		break;	//双方都超出5代之后，不需要继续寻找（测试点6 运行超时）
		if (sum1+sum2 != s.size() && (sum1 < 5 || sum2 < 5))     //五代内出现共同祖先，返回false（测试点3、6答案错误）
			return 0;
		if(b.empty()&&a.empty()){
			break;
		}
	}
	return 1;
}
int main() {
	int n, m;
	string str, a, b;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b.back() == 'n') 				//儿子
			people[a] = { 'm',b.substr(0,b.size() - 4) };
		else if (b.back() == 'r')			//女儿
			people[a] = { 'f',b.substr(0, b.size() - 7) };
		else	people[a].sex = b.back();	//其他人
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> str >> b >> str;  //姓氏没有用
		if (people.find(a) == people.end() || people.find(b) == people.end())		printf("NA\n");
		else if (people[a].sex == people[b].sex)		printf("Whatever\n");
		else	printf("%s\n", judge(a, b) ? "Yes" : "No");
	}
	return 0;
}
