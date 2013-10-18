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

int n , m;
int l[300010], r[300010], x[300010];
set <pair <int, int> > s;
vector < pair <int, int> > beg[300010], en[300010];

void init() {
    s.clear();
    REP(i, 300010) beg[i].clear(), en[i].clear();
}

void input() {
    cin >> n >> m;
    REP(i, m){
        int l, r, x;
        cin >> l >> r >> x;
        if(l == x) beg[l+1].push_back(make_pair(i, x)), en[r].push_back(make_pair(i, x));
        else if(r == x) beg[l].push_back(make_pair(i, x)), en[r-1].push_back(make_pair(i, x));
        else{
            beg[l].push_back(make_pair(i, x));
            en[x-1].push_back(make_pair(i, x));
            beg[x+1].push_back(make_pair(i, x));
            en[r].push_back(make_pair(i, x));
        }
    }
}

void solve() {
    for(int i = 1; i <= n; i++){
        REP(j, SZ(beg[i])) s.insert(beg[i][j]);
        if(SZ(s) == 0) cout << 0;
        else cout << (*(s.begin())).second;
        if(i == n) cout << endl;
        else cout << " ";
        REP(j, SZ(en[i])) s.erase(s.find(en[i][j]));
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






