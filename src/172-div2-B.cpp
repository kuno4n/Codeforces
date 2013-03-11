
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

double EPS = 1e-15;

int main() {
    LL x, y, n;
    cin >> x >> y >> n;
    LL dfmn = 1LL<<60;
    LL tmpa = 1LL;
    LL tmpb = 1LL;
    
    for(LL b=1; b<=n; b++){
        for(LL a=max(0LL, x*b/y-10); a<=x*b/y+10; a++){
            if(abs(x*b - a*y) * tmpb < dfmn * b){
                dfmn = abs(x*b - a*y);
                tmpa = a;
                tmpb = b;
            }
        }
    }
    cout << tmpa << "/" << tmpb << endl;
    
    return 0;
}
