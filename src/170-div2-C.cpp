
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

int n, m;
int usecnt[110];
int k[110][110];
bool G[110][110];
bool checked[110];

bool can(int a, int b){
    set<int> si;
    si.clear();
    REP(i, usecnt[a]) si.insert(k[a][i]);
    REP(i, usecnt[b]) si.insert(k[b][i]);
    if(SZ(si) < usecnt[a]+usecnt[b]) return true;
    else return false;
}

void rec(int v){
    if(checked[v]) return;
    checked[v] = true;
    REP(i, n) if(G[v][i] && !checked[i]) rec(i);
    return;
}

int main() {
    bool zero = true;
    cin >> n >> m;
    MSET(k, 0);
    REP(i, n){
        cin >> usecnt[i];
        if(usecnt[i] > 0) zero = false;
        REP(j, usecnt[i]){
            cin >> k[i][j];
        }
    }
    MSET(G, false);
    REP(i, n){
        for(int j=i+1; j<n; j++){
            if(can(i, j)){
                G[i][j] = true;
                G[j][i] = true;
            }
        }
    }

    MSET(checked, false);
    int cnt = 0;
    REP(i, n){
        if(!checked[i]){
            cnt++;
            rec(i);
        }
    }
    
    if(zero) cnt++;
    
    cout << cnt-1 << endl;
        
    return 0;
}
