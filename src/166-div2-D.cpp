
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

typedef unsigned long long ull;
const ull B = 100000007;

int main() {
    string s, ss;
    int k;
    cin >> s >> ss;
    cin >> k;
    bool bad[26];
    REP(i, SZ(ss)){
        if(ss[i] == '0') bad[i] = true;
        else bad[i] = false;
    }

    int res = 0;
    set <ull> se;
    REP(i, SZ(s)){
        int cnt = 0;
        ull h = 0;
        for(int len = 1; len+i <= SZ(s); len++){
            if(bad[s[i+len-1]-'a']) cnt++;
            if(cnt > k) break;
            h = h*B + s[i+len-1];
            if(se.count(h)) continue;
            res++;
            se.insert(h);
        }
    }
    
    cout << res << endl;
    
    return 0;
}
