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

bool tab[110][110];
int n;

void init() {
}

void input() {
    cin >> n;
    REP(i, n) REP(j, n){
        char c;
        cin >> c;
        if(c == 'E') tab[i][j] = true;
        else tab[i][j] = false;
    }
}

void solve() {
    vector<pair<int, int> > res;
    res.clear();
    
    REP(i, n){
        bool NG = true;
        REP(j, n) NG &= tab[i][j];
        if(NG) break;
        REP(j, n){
            if(!tab[i][j]){
                res.push_back(make_pair(i+1, j+1));
                break;
            }
        }
    }
    if(SZ(res) == n){
        REP(i, n) cout << res[i].first << " " << res[i].second << endl;
        return;
    }
    
    res.clear();
    REP(j, n){
        bool NG = true;
        REP(i, n) NG &= tab[i][j];
        if(NG) break;
        REP(i, n){
            if(!tab[i][j]){
                res.push_back(make_pair(i+1, j+1));
                break;
            }
        }
    }
    if(SZ(res) == n){
        REP(i, n) cout << res[i].first << " " << res[i].second << endl;
        return;
    }
    cout << -1 << endl;
    return;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






