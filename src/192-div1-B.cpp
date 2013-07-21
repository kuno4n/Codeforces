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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const int MN = 1010;
const int INF = (1<<30);

int tab[MN][MN];
int d[MN][MN];
int h, w;
int sx, sy, gx, gy;
VI ex, ey, en;

void init() {
}

void input() {
    ex.clear(); ey.clear(); en.clear();
    
    cin >> h >> w;
    REP(i, h) REP(j, w){
        char c;
        cin >> c; tab[i][j] = c;
        if(tab[i][j] == 'S') sx = i, sy = j;
        else if(tab[i][j] == 'E') gx = i, gy = j;
        else if(tab[i][j] >= '0' && tab[i][j] <= '9') ex.PB(i), ey.PB(j), en.PB(tab[i][j] - '0');
    }
}

void solve() {
    REP(i, MN) REP(j, MN) d[i][j] = INF;
    
    queue<int> qx, qy;
    qx.push(gx), qy.push(gy);
    d[gx][gy] = 0;
    while(SZ(qx)){
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        REP(i, 4){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || d[nx][ny] != INF || tab[nx][ny] == 'T') continue;
            qx.push(nx), qy.push(ny);
            d[nx][ny] = d[x][y] + 1;
        }
    }
    
//    REP(i, h){
//        REP(j, w){
//            cout << (d[i][j] == INF ? 999: d[i][j]) << " ";
//        }
//        cout << endl;
//    }
    
    int res = 0;
    REP(i, SZ(ex)) if(d[ex[i]][ey[i]] <= d[sx][sy]) res += en[i];
    cout << res << endl;
    
}

int main() {
	init();
    input();
    solve();
	return 0;
}






