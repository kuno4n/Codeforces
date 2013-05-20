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
int n;
bool can[5010];
int mem[5010];


int grundy(int a){
    if(a < 0) return 0;
    if(mem[a] != -1) return mem[a];
    
    set<int> s;
    for(int i = 1; i <= a; i++) s.insert(grundy(i-2) ^ grundy(a-i-1));
    
    int res = 0;
    while(s.count(res)) res++;
    return mem[a] = res;
}

int calnim(VI a){
    int res = 0;
    REP(i, SZ(a)) res ^= mem[a[i]];
    return res;
}


void init() {
    REP(i, 5010) mem[i] = -1;
    REP(i, 5000) grundy(i);
//    REP(i, 10) OUT(mem[i]);
}

void input() {
    cin >> s;
    n = SZ(s);
    REP(i, 5010) can[i] = false;
    for(int i = 1; i <= n-2; i++) if(s[i-1] == s[i+1]) can[i] = true;
    
}

void solve() {
    VI a;
    int tmp = 0;
    REP(j, 5010){
        if(can[j]) tmp++;
        else{
            if(tmp != 0) a.push_back(tmp);
            tmp = 0;
        }
    }
    if(calnim(a) == 0) cout << "Second" << endl;
    else{
        cout << "First" << endl;
        REP(i, 5010) if(can[i]){
            bool b1 = can[i-1];
            bool b2 = can[i];
            bool b3 = can[i+1];
            can[i-1] = false;
            can[i] = false;
            can[i+1] = false;
            VI aa;
            int _tmp = 0;
            REP(j, 5010){
                if(can[j]) _tmp++;
                else{
                    if(_tmp != 0) aa.push_back(_tmp);
                    _tmp = 0;
                }
            }
            if(calnim(aa) == 0){
                cout << i+1 << endl;
                return;
            }
            can[i-1] = b1;
            can[i] = b2;
            can[i+1] = b3;
        }
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






