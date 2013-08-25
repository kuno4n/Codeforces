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

int n, a_pcnt;
LL a[10];
int pcnt[10];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> a[i];
}

int rec(int cur, vector<LL> &tree, int rootcnt, int total_pcnt){
    if(cur == n) return total_pcnt + n - a_pcnt + (rootcnt != 1);
    
    int best = (1<<29);
    REP(i, SZ(tree)) if(tree[i] % a[cur] == 0){
        tree.push_back(a[cur]);
        tree[i] /= a[cur];
        chmin(best, rec(cur+1, tree, rootcnt+(i==0), total_pcnt + (i==0 ? pcnt[cur] : 0)));
        tree.pop_back();
        tree[i] *= a[cur];
    }
    return best;
}



void solve() {
    sort(a, a+n, greater<LL>());
    REP(i, n){
        LL x = a[i];
        for(LL j = 2; j*j <= x; j++){
            while(x%j == 0){
                pcnt[i]++;
                x /= j;
            }
        }
        if(x != 1) pcnt[i]++;
        if(pcnt[i] == 1) a_pcnt++;
    }
    vector <LL> tree;
    tree.push_back(0LL);
    cout << rec(0, tree, 0, 0) << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






