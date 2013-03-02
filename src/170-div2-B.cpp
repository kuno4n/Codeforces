
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
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
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

int n;
string ss[50], res;

bool dfs(int len, string s){
//    OUT(s);
    if(SZ(s) == len){
        bool found = false;
        REP(i, n){
            if(ss[i].find(s) != string::npos){
                found = true;
                break;
            }
        }
        if(found) return false;
        else{
            res = s;
            return true;
        }
    }
    else{
        for(char c = 'a'; c <= 'z'; c++){
            string _s = s+c;
            if(dfs(len, _s)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    REP(i, n) cin >> ss[i];
    
    res = "";
    for(int d=1; ; d++){
//        OUT(d);
        if(dfs(d, "")){
            cout << res << endl;
            return 0;
        }
    }
    
    return 0;
}
