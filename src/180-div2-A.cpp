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

int n;
string S;

void init() {
}

void input() {
    cin >> n >> S;
}

void solve() {
    int s, t;
    int l = 0;
    int r = 0;
    int lcnt = 0;
    int rcnt = 0;
    
    REP(i, SZ(S)){
        if(S[i] == '.'){
            if(l != 0 && r == 0) r = i;
        }
        else if(l == 0) l = i + 1;
        if(S[i] == 'R'){
            rcnt++;
        }
        if(S[i] == 'L'){
            lcnt++;
        }
    }
    
    if(lcnt == 0){
        s = l;
        t = r+1;
    }
    else if(rcnt == 0){
        s = r;
        t = l-1;
    }
    else {
        s = l + rcnt;
        t = s;
    }
    cout << s << " " << t << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






