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

string s;

void init() {
}

void input() {
	cin >> s;
}

void solve() {
	LL res = 1;
	int use = 10;
	bool used[10]; REP(i, 10) used[i] = false;
	
	int zero = 0;
	
	if(s[0] == '?') res *= 9;
	if('A' <= s[0] && s[0] <= 'J') res *= 9, use--, used[s[0]-'A'] = true; 
	
	FOR(i, 1, SZ(s)){
		if(s[i] == '?') zero++;
		if('A' <= s[i] && s[i] <= 'J'){
			if(!used[s[i]-'A']){
				res *= use--;
				used[s[i]-'A'] = true;
			}
		} 
	}
	cout << res;
	REP(i, zero) cout << '0';
	cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






