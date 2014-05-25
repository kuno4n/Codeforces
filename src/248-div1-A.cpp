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



int n, m;
int a[100010];
vector <LL> b[100010];

void init() {
}

void input() {
    cin >> n >> m;
    REP(i, m) cin >> a[i];
}

void solve() {
    LL res = (1LL << 60);
    LL tmp = 0;
    REP(i, 100010) b[i].clear();
    REP(i, m){
        if(i != m-1) tmp += abs(a[i+1] - a[i]);
        if(i != 0 && a[i] != a[i-1]) b[a[i]].push_back(a[i] - a[i-1]);
        if(i != m-1 && a[i] != a[i+1]) b[a[i]].push_back(a[i] - a[i+1]);
    }
    chmin(res, tmp);
//    OUT(res);
    for(int i = 1; i <= n; i++){
        LL tmp2 = tmp;
        if(SZ(b[i]) == 0) continue;
        sort(ALL(b[i]));
//        OUT(i);
//        OUT(b[i]);
        LL minus = 0;
        LL plus = 0;
        REP(j, SZ(b[i])){
            if(b[i][j] < 0) minus++;
            else plus++;
        }
        LL cnt = 0;
        if(minus > plus) while(minus > plus){
            tmp2 -= (minus-plus) * (-b[i][minus-1] - cnt);
            cnt += (-b[i][minus-1] - cnt);
            minus--;
            plus++;
        }
        else if(plus > minus){
            reverse(ALL(b[i]));
            while(plus > minus){
                tmp2 -= (plus-minus) * (b[i][plus-1] - cnt);
                cnt += (b[i][plus-1] - cnt);
                minus++;
                plus--;
            }
        }
        chmin(res, tmp2);
    }
    
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






