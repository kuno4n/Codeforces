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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

const int MOD = 1000000009;

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

void add(LL &a, LL b){
    a = (a + b) % MOD;
}

void sub(LL &a, LL b){
    a = (a - b + MOD) % MOD;
}

void mul(LL &a, LL b){
    a = (a * b) % MOD;
}


LL n, m, k;

void init() {
}

void input() {
    cin >> n >> m >> k;
}

void solve() {
    LL remain = max(0LL, m - (n - n / k));
    LL res = 0;
    if(remain > 0){
        add(res, modPow(2, remain+1));
        sub(res, 2);
        mul(res, k);
    }
    add(res, (m - (remain*k) % MOD + MOD) % MOD);
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






