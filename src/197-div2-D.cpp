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

LL a[1<<18];

void init() {
}

void upd(int depth, int head, int node, LL num){
    int cur = head + node;
    a[cur] = num;
    if(depth == n) return;
    
    LL num2 = (node & 1) ? a[cur-1] : a[cur+1];
    LL nxt = (depth & 1) ? (num ^ num2) : (num | num2);
    upd(depth+1, head+(1<<(n-depth)), (node>>1), nxt);
}

void input() {
    cin >> n >> m;
    REP(i, (1<<n)) cin >> a[i];
    
    int head = 0;
    for(int i = 0; i < n-1; i++){
        head += (1<<(n-i));
        for(int j = 0; j < (1<<(n-i)); j += 2){
            int cur = (head - (1<<(n-i))) + j;
            a[head + (j>>1)] = (i & 1) ? (a[cur] ^ a[cur+1]) : (a[cur] | a[cur+1]);
        }
    }
}

void solve() {
    REP(_, m){
        LL p , b;
        cin >> p >> b;
        p--;
        upd(0, 0, p, b);
        cout << a[(1<<(n+1))-2] << endl;
    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}






