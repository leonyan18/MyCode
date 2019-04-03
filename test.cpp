
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
		if (sum1 >= 5 && sum2 >= 5)		break;	//˫��������5��֮�󣬲���Ҫ����Ѱ�ң����Ե�6 ���г�ʱ��
		if (sum1+sum2 != s.size() && (sum1 < 5 || sum2 < 5))     //����ڳ��ֹ�ͬ���ȣ�����false�����Ե�3��6�𰸴���
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
		if (b.back() == 'n') 				//����
			people[a] = { 'm',b.substr(0,b.size() - 4) };
		else if (b.back() == 'r')			//Ů��
			people[a] = { 'f',b.substr(0, b.size() - 7) };
		else	people[a].sex = b.back();	//������
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> str >> b >> str;  //����û����
		if (people.find(a) == people.end() || people.find(b) == people.end())		printf("NA\n");
		else if (people[a].sex == people[b].sex)		printf("Whatever\n");
		else	printf("%s\n", judge(a, b) ? "Yes" : "No");
	}
	return 0;
}
