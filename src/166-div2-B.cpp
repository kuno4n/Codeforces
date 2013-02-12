
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

const int INF = (1<<30)-1;
int prime[20000];

int sieve(int n){
    int p = 0;
    bool is_prime[n+1]; 
    for(int i=0; i<=n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
        }
    }
    return p;
}

int main() {
    int n, m;
    cin >> n >> m;
    int tab[n][m];
    REP(i, n){
        REP(j, m){
            cin >> tab[i][j];
        }
    }
    REP(i, 20000) prime[i] = INF;
    sieve(200000);
    
    
    int res = INF;
    REP(x, n){
        int tmp = 0;
        REP(y, m){
            tmp += prime[lower_bound(prime, prime+20000, tab[x][y]) - prime] - tab[x][y];
        }
        res = min(res, tmp);
    }
    REP(y, m){
        int tmp = 0;
        REP(x, n){
            tmp += prime[lower_bound(prime, prime+20000, tab[x][y]) - prime] - tab[x][y];
        }
        res = min(res, tmp);
    }
    
    cout << res << endl;
    return 0;
}
