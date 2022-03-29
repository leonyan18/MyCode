#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <map>
 
using namespace std;
long long time;
const char aimStr[] = {
	11, 12, 13, 14, 15, 16, 17, 1,
	21, 22, 23, 24, 25, 26, 27, 1,
	31, 32, 33, 34, 35, 36, 37, 1,
	41, 42, 43, 44, 45, 46, 47, 1, 0
};
struct Node {
	char str[36];
	int steps;
};
char buf[36];
 
void Move(Node &now, int val) {
	for(int i = 0; ; ++i)
		if(now.str[i] == val) {
			now.str[i] = 1;
			return;
		}
}
 
int BFS() {
	queue<Node> Q;
	Node tmp, now;
	strcpy(now.str, buf);
	now.steps = 0;
	Q.push(now);
 
	map<string, int> mp;
	int mpid = 1, i, j;
	mp[buf] = mpid++;
//	if(mp[aimStr] == mp[buf]) return 0;
//	mp[aimStr] = mpid++;
 
	while(!Q.empty()) {
		now = Q.front(); Q.pop();
		for(i = 0; i < 32; ++i) {
			if(now.str[i] == 1 && now.str[i-1] != 1 
				&& now.str[i-1] % 10 != 7) {
				tmp = now;
				Move(tmp, tmp.str[i-1] + 1);
				tmp.str[i] = tmp.str[i-1] + 1;
				++tmp.steps;
//				if(mp[tmp.str] == mp[aimStr]) return tmp.steps;
				if(mp[tmp.str] == 0) {
					mp[tmp.str] = mpid++;
					Q.push(tmp);
					time++;
				}
			}
		}
	}
 
	return -1;
}
 
int main() {
	 freopen("C://Users//11835//Desktop//in.txt","r",stdin);
	int n, i, j, k, tmp;
	scanf("%d", &n);
	while(n--) {
		time=0;
		for(i = k = 0; i < 4; ++i) {
			buf[k++] = (i + 1) * 10 + 1;
			for(j = 1; j < 8; ++j) {
				scanf("%d", &tmp);
				buf[k] = tmp;
				if(buf[k] % 10 == 1) 
					buf[k] = 1;
				++k;
			}
		}
		printf("%d\n", BFS());
		printf("%lld\n", time);
	}
	return 0;
}

