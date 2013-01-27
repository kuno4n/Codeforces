
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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    int dp[100010] = {0};
    REP(i, n){
        int a, aa;
        cin >> a;
        aa = a;
        int mx = 0;
        for(int i=2; i*i<=a; i++){
            if(a%i) continue;
            mx = max(mx, dp[i]);
            while(a%i==0) a/=i;
        }
        mx = max(mx, dp[a]);
        for(int i=2; i*i<=aa; i++){
            if(aa%i) continue;
            while(aa%i==0) aa/=i;
            dp[i] = mx+1;
        }
        if(aa!=1) dp[aa] = mx+1;
        
    }
    dp[1] = 1;
    int res = 0;
    REP(i, 100010) res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}
