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
    getline(cin, s);
}

void solve() {
    bool in = false;
    REP(i, SZ(s)){
        if(in){
            if(s[i] == '"'){
                cout << '>' << endl;
                in = false;
            }
            else cout << s[i];
        }
        else{
            if(s[i] == ' ') continue;
            else if(s[i] == '"'){
                cout << '<';
                in = true;
            }
            else{
                if(i == 0 || s[i-1] == ' ') cout << '<';
                cout << s[i];
                if(i == SZ(s)-1 || s[i+1] == ' ') cout << '>' << endl;
            }
        }
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






