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


const int MAX_N = 100010;
int par[MAX_N];  //親
int _rank[MAX_N]; //木の深さ
int cnt[MAX_N];

// n要素で初期化
void init(int n){
    REP(i, n){
        par[i] = i;
        _rank[i] = 0;
        cnt[i] = 1;
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    int cx = cnt[find(x)];
    int cy = cnt[find(y)];
    if(_rank[x] < _rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
    cnt[find(x)] = cx + cy;
}
//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}


LL n, m;
LL a[100010], x[100010], y[100010];
tuple<LL, LL, LL> t[100010];

void init() {
}

void input() {
    cin >> n >> m;
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> x[i] >> y[i];
    REP(i, m) x[i]--, y[i]--;
}

void solve() {
    init(n);
    double res = 0.0;
    REP(i, m) t[i] = make_tuple(min(a[x[i]], a[y[i]]), x[i], y[i]);
    sort(t, t+m);
    reverse(t, t+m);
    
    REP(i, m){
        tuple<LL, LL, LL> T = t[i];
        LL A = get<0>(T);
        int X = get<1>(T);
        int Y = get<2>(T);
        if(same(X, Y)) continue;
        LL cx = cnt[find(X)];
        LL cy = cnt[find(Y)];
        res += cx * cy * A;
        unite(X, Y);
    }
    printf("%.10lf\n", res*2/(n*(n-1)));
}

int main() {
	init();
    input();
    solve();
	return 0;
}






