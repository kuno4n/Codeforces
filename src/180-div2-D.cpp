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

int n, m, k;
int a[100010], b[100010];

void init() {
}

void input() {
    REP(i, 100010){
        a[i] = 0;
        b[i] = 0;
    }
    cin >> n >> m >> k;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];
    sort(a, a+n, greater<int>());
    sort(b, b+m, greater<int>());
}

void solve() {
    int acnt, bcnt;
    acnt = 0; bcnt = 0;
    
    int ptra, ptrb;
    ptra = 0; ptrb = 0;
    while(ptra != n || ptrb != m){
        if(ptrb == m || a[ptra] > b[ptrb]){
            acnt++;
            ptra++;
        }
        else if(ptra == n || a[ptra] < b[ptrb]){
            bcnt++;
            ptrb++;
        }
        else if(a[ptra] == b[ptrb]){
            ptra++;
            ptrb++;
        }
        
        if(acnt > bcnt){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






