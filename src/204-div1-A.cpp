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
double a[4010];

void init() {
}

void input() {
    cin >> n;
    REP(i, n*2) cin >> a[i];
}

void solve() {
    vector <double> b;
    REP(i, n*2){
        double c = a[i] - (int)a[i];
        if(c != 0.0) b.push_back(c);
    }
    sort(ALL(b));
    
    double res = 1000000.0;
    int m = SZ(b);
    if(m == 0) res = 0.0;
    for(int i = max(0, m-n); i <= min(m, n); i++){
        double tmp = 0.0;
        for(int j = 0; j < i; j++) tmp -= b[j];
        for(int j = m-1; j >= i; j--) tmp += 1.0-b[j];
        chmin(res, abs(tmp));
    }
    
    printf("%.3lf\n", abs(res));
}

int main() {
	init();
    input();
    solve();
	return 0;
}






