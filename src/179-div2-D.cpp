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

LL G_tmp[510][510];
LL G[510][510];
int x[510];
LL d[510][510];
int V;

vector < LL > res;

void init() {
    REP(i, 510) REP(j, 510) d[i][j] = 0;
    res.clear();
}

void input() {
    cin >> V;
    REP(i, V) REP(j, V) cin >> G_tmp[i][j];
    REP(i, V){
        int a; cin >> a;
        a--;
        x[i] = a;
    }
    
    REP(i, V) REP(j, V) G[i][j] = G_tmp[x[V-i-1]][x[V-j-1]];
}

void solve() {
    REP(i, V){
        REP(j, i){
            d[j][i] = G[j][i];
            d[i][j] = G[i][j];
            REP(k, i){
                if(j == k) continue;
                d[j][i] = min(d[j][i], d[j][k]+G[k][i]);
                d[i][j] = min(d[i][j], G[i][k]+d[k][j]);
            }
        }
        REP(j, i){
            REP(k, i){
                if(j == k) continue;
                d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
            }
        }
        
        LL len = 0;
        REP(j, i+1){
            REP(k, i+1){
                if(j == k) continue;
                len += d[j][k];
            }
        }
        res.PB(len);
    }
    reverse(ALL(res));
    REP(i, V) cout << res[i] << " ";
    cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






