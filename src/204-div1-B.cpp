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

int n;
int a[3010];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> a[i];
}

void solve() {
    int dif = 0;
    REP(i, n-1) for(int j = i+1; j < n; j++) if(a[i] > a[j]) dif++;
    if(dif == 0) cout << 0 << endl;
    else if(dif == 1) cout << 1 << endl;
    else{
        int prv2 = 0;
        int prv1 = 1;
        int now = 0;
        for(int i = 2; i <= dif; i++){
            now = prv2 + 4;
            prv2 = prv1;
            prv1 = now;
        }
        cout << prv1 << endl;
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






