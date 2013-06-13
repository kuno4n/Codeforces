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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int n;
int a[1000000];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) scanf("%d", &a[i]);
}

void solve() {
    int res = 0;
    int p[n];
    REP(i, n) p[i] = i;
    do{
        bool OK = true;
        REP(i, n){
            int j = i;
            int cnt = 0;
            do{
                if(a[j] == 1) cnt++;
                j = p[j];
            }while(j != i);
            if(cnt > 2) OK = false;
        }
        if(OK) res++;
    }while(next_permutation(p, p+n));
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






