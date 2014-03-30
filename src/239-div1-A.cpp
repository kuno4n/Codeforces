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

double EPS = 1e-10;

double add(double a, double b){
    if(abs(a+b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y){
    }
    P operator + (P p){
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p){
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d){
        return P(x*d, y*d);
    }
    double dot(P p){ // 内積
        return add(x*p.x, y*p.y);
    }
    double det(P p){ // 外積
        return add(x*p.y, -y*p.x);
    }
};


long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}



int memo[2010][2010];
vector < pair <int, int> > A, B;

void init() {
    MSET(memo, 0);
    REP(i, 2010) REP(j, 2010){
        memo[i][j] = i*i + j*j;
    }
}

int a, b;

void input() {
    cin >> a >> b;
}


void solve() {
    A.clear();
    B.clear();
    FOR(i, 1, 2010) FOR(j, 1, 2010){
        if(memo[i][j] == a*a) A.push_back(make_pair(i, j));
        if(memo[i][j] == b*b) B.push_back(make_pair(i, j));
    }
    
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {1,-1,1,-1};
    REP(i, SZ(A)) REP(j, SZ(B)){
        int x1 = A[i].first;
        int y1 = A[i].second;
        REP(k, 4){
            int x2 = B[j].first * dx[k];
            int y2 = B[j].second * dy[k];
            if(P(x1, y1).det(P(x2, y2)) == 0) continue;
            if(x1 == x2 || y1 == y2) continue;
            if(x1*x1 + y1*y1 + x2*x2 + y2*y2 != (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) continue;
            cout << "YES" << endl;
            cout << "0 0" << endl;
            cout << x1 << " " << y1 << endl;
            cout << x2 << " " << y2 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






