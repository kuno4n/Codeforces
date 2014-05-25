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


int n, m, q;
int a[1010][1010];

int up[1010][1010], down[1010][1010];
int le[1010][1010], ri[1010][1010];


void init() {
}

void input() {
    cin >> n >> m >> q;
    MSET(a, 0);
    REP(i, n) REP(j, m) cin >> a[i+1][j+1];
    n += 2;
    m += 2;
}


void dump(){
    cout << "board" << endl;
    REP(i, n){
        REP(j, m) cout << a[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "up" << endl;
    REP(i, n){
        REP(j, m) cout << up[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "down" << endl;
    REP(i, n){
        REP(j, m) cout << down[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "left" << endl;
    REP(i, n){
        REP(j, m) cout << le[i][j];
        cout << endl;
    }
    cout << endl;
    cout << "right" << endl;
    REP(i, n){
        REP(j, m) cout << ri[i][j];
        cout << endl;
    }
    cout << endl;
}


void upd(int i, int j, int op){
    up[i][j] = 0;
    down[i][j] = 0;
    le[i][j] = 0;
    ri[i][j] = 0;
    
    int x, y, cnt;
    if(op == 0){
        x = i+1, y = j, cnt = 1;
        while(x < n && a[x][y]) up[x][y] = cnt++, x++;
    }
    if(op == 1){
        x = i-1, y = j, cnt = 1;
        while(x >= 0 && a[x][y]) down[x][y] = cnt++, x--;
    }
    if(op == 2){
        x = i, y = j+1, cnt = 1;
        while(y < m && a[x][y]) le[x][y] = cnt++, y++;
    }
    if(op == 3){
        x = i, y = j-1, cnt = 1;
        while(y >= 0 && a[x][y]) ri[x][y] = cnt++, y--;
    }
}

void solve() {
    MSET(up, 0);
    MSET(down, 0);
    MSET(le, 0);
    MSET(ri, 0);
    REP(i, n) REP(j, m) if(a[i][j] == 0){
        upd(i, j, 0);
        upd(i, j, 1);
        upd(i, j, 2);
        upd(i, j, 3);
    }
    
    REP(_, q){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            a[x][y] = !a[x][y];
            if(a[x][y] == 0){
                upd(x, y, 0);
                upd(x, y, 1);
                upd(x, y, 2);
                upd(x, y, 3);
            }
            else{
                int i, j;
                
                i = x, j = y;
                while(a[i][y] == 1) i--;
                upd(i, y, 0);
                i = x, j = y;
                while(a[i][y] == 1) i++;
                upd(i, y, 1);
                i = x, j = y;
                while(a[x][j] == 1) j--;
                upd(x, j, 2);
                i = x, j = y;
                while(a[x][j] == 1) j++;
                upd(x, j, 3);
            }
//dump();
        }
        else{
            int res = 0;
            int u, d, l, r;
            
            l = 1010, r = 1010;
            for(int i = x; i < n; i++){
                if(a[i][y] == 0) break;
                chmin(l, le[i][y]);
                chmin(r, ri[i][y]);
                chmax(res, (abs(i-x)+1)*(l+r-1));
            }
            l = 1010, r = 1010;
            for(int i = x; i >= 0; i--){
                if(a[i][y] == 0) break;
                chmin(l, le[i][y]);
                chmin(r, ri[i][y]);
                chmax(res, (abs(i-x)+1)*(l+r-1));
            }
            u = 1010, d  = 1010;
            for(int j = y; j < m; j++){
                if(a[x][j] == 0) break;
                chmin(u, up[x][j]);
                chmin(d, down[x][j]);
                chmax(res, (abs(j-y)+1)*(u+d-1));
            }
            u = 1010, d  = 1010;
            for(int j = y; j >= 0; j--){
                if(a[x][j] == 0) break;
                chmin(u, up[x][j]);
                chmin(d, down[x][j]);
                chmax(res, (abs(j-y)+1)*(u+d-1));
            }
            
            cout << res << endl;
        }
    }

    
}

int main() {
	init();
    input();
    solve();
	return 0;
}






