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

set <LL> s;
int n;

void init() {
}

void input() {
    s.clear();
    cin >> n;
    REP(i, n){
        LL a;
        cin >> a;
        while(1){
            set<LL>::iterator it = s.find(a);
            if(it == s.end()){
                s.insert(a);
                break;
            }
            s.erase(it);
            a++;
        }
    }
//    OUT(s);
}

void solve() {
    LL res = 0;
    LL ptr = 0;
    FIT(it, s){
        res += (*it) - ptr;
        ptr = (*it)+1;
    }
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






