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

#define MOD 1000000007

long long _pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

const int MAX_N = 1000;
int nCr[MAX_N+1][MAX_N+1];

void make(){
    for(int i=1; i<=MAX_N; i++){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        for(int j=1; j<i; j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }
}



int n, m, on[1010];
LL totaloff, off[1010], offptr;

void init() {
    make();
}

void input() {
    cin >> n >> m;
    REP(i, m) cin >> on[i];
    sort(on, on+m);
}

void solve() {
    totaloff = n - m;
    offptr = m + 1;
    REP(i, m){
        if(i == 0) off[i] = on[i] - 1;
        else off[i] = on[i] - on[i-1] - 1;
    }
    off[m] = n - on[m-1];
    
    LL res = 1;
    REP(i, offptr) if(off[i] != 0){
        res = (res * nCr[totaloff][off[i]]) % MOD;
        totaloff -= off[i];
        if(i != 0 && i != offptr-1) res = (res * _pow(2, off[i]-1)) % MOD;
    }

    cout << res << endl;
    return;
}

int main() {
	init();
    input();
    solve();
	return 0;
}
