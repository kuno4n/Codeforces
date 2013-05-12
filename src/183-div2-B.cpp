#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int str2int(string s){
	int res = 0;
	REP(i, SZ(s)){
		res *= 10;
		res += (s[i]-'0');
	}
	return res;
}

int sy, sm, sd, gy, gm, gd;
bool leap[2100];
int dd[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void init() {
	for(int i = 1900; i <= 2038; i++){
		if(i%4 == 0){
			if(i%100 == 0){
				if(i%400 == 0) leap[i] = true;
				else leap[i] = false;
			}
			else leap[i] = true;
		}
		else leap[i] = false;
	}
}

void input() {
	string s1, s2;
	cin >> s1 >> s2;
	sy = str2int(s1.substr(0,4));
	sm = str2int(s1.substr(5,2));
	sd = str2int(s1.substr(8,2));
	gy = str2int(s2.substr(0,4));
	gm = str2int(s2.substr(5,2));
	gd = str2int(s2.substr(8,2));
	if(sy > gy || (sy == gy && sm > gm) || (sy == gy && sm == gm && sd > gd ) ){
		swap(sy, gy);
		swap(sm, gm);
		swap(sd, gd);
	}
}

void solve() {
	int res = 0;
	while(1){
		res++;
		if(sy == gy && sm == gm && sd == gd) break;
		if(leap[sy] && sm == 2 && sd == 28) sd++;
		else{
			if(sd >= dd[sm]){
				sd = 1;
				sm++;
				if(sm == 13){
					sm = 1;
					sy++;
				}
			}
			else sd++;
		}
	}
	cout << res-1 << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






