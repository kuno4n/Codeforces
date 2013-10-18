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


LL n, m;
string s1, s2;

bool chk[1000010];
LL cnt[1000010][26];

void init() {
}

void input() {
    cin >> n >> m;
    cin >> s1 >> s2;
}

void solve() {
    if(SZ(s1) < SZ(s2)) swap(n, m), swap(s1, s2);
    MSET(chk, false), MSET(cnt, 0);
    
    LL a = SZ(s1), b = SZ(s2);
    REP(i, b){
        if(chk[i]) continue;
        LL tab[26]; MSET(tab, 0);
        LL j = i;
        int c = 0;
        do{
            tab[s1[j]-'a']++;
            j = (j+b)% a;
            c++;
        }while(j != i);
        REP(k, 26) tab[k] *= m/c;
        j = i;
        do{
            chk[j] = true;
            REP(k, 26) cnt[j][k] = tab[k];
            j = (j+a)% b;
        }while(j != i);
    }
    LL res = a*n;
    REP(i, b) res -= cnt[i][s2[i]-'a'];
    cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






