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

LL k;

bool g[1010][1010];
int d;

int G[1010][1010];

void init() {
}

void input() {
    cin >> k;
}

void solve() {
    MSET(g, false);
    
//    g[0][2] = g[2][0] = g[0][3] = g[3][0] = true;
//    int u = 3;
//    for(int i = 1; i <= 3; i++){
//        g[u+1][u-1] = g[u-1][u+1] =
//        g[u+1][u] = g[u][u+1] =
//        g[u+2][u-1] = g[u-1][u+2] =
//        g[u+2][u] = g[u][u+2] = true;
//        u += 2;
//    }
//    
//    int mp[40];
//    for(int i = 0; i <= 3; i++){
//        u++;
//        g[2*(i+1)][u] = g[u][2*(i+1)] = true;
//        for(int j = i+2; j <= 4; j++){
//            u++;
//            g[u-1][u] = g[u][u-1] = true;
//        }
//        mp[i] = u;
//    }
//    
//    for(int i = 0; i <= 3; i++){
//        if((1LL<<i) & k) g[1][mp[i]] = g[mp[i]][1] = true;
//    }
//    
//    cout << u+1 << endl;
//    REP(i, u+1){
//        REP(j, u+1){
//            if(g[i][j]) cout << 'Y';
//            else cout << 'N';
//        }
//        cout << endl;
//    }
    
    g[0][2] = g[2][0] = g[0][3] = g[3][0] = true;
    int u = 3;
    for(int i = 1; i <= 31; i++){
        g[u+1][u-1] = g[u-1][u+1] =
        g[u+1][u] = g[u][u+1] =
        g[u+2][u-1] = g[u-1][u+2] =
        g[u+2][u] = g[u][u+2] = true;
        u += 2;
    }
    
    int mp[40];
    for(int i = 0; i <= 31; i++){
        u++;
        g[2*(i+1)][u] = g[u][2*(i+1)] = true;
        for(int j = i+2; j <= 32; j++){
            u++;
            g[u-1][u] = g[u][u-1] = true;
        }
        mp[i] = u;
    }
    
    for(int i = 0; i <= 31; i++){
        if((1LL<<i) & k) g[1][mp[i]] = g[mp[i]][1] = true;
    }
    
    cout << u+1 << endl;
    REP(i, u+1){
        REP(j, u+1){
            if(g[i][j]) cout << 'Y';
            else cout << 'N';
        }
        cout << endl;
    }
    
    
//    bool vis[u];
//    MSET(vis, false);
//    int a[u];
//    MSET(a, 0);
//    a[0] = 1;
//    queue<int> q;
//    q.push(0);
//    while(SZ(q)){
//        int n = q.front();
//        q.pop();
//        REP(i, u) if(g[n][i]){
//            if(!vis[i]) q.push(i);
//            vis[i] = true;
//            a[i] += a[n];
//        }
//    }
//    OUT(a[1]);
    
}

int main() {
	init();
    input();
    solve();
	return 0;
}






