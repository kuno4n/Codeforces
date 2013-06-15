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

//map<LL, LL> m;
int gr[33] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14,13,1};
LL n;

void init() {
}

void input() {
    cin >> n;
}

//LL cal(LL msk){
//    if(msk == 0) return 0;
//    if(m[msk] != 0) return m[msk];
//    set<LL> s;
//    REP(i, 35) if(msk&(1LL<<i)){
//        LL msk2 = msk;
//        for(int j = i; j < 35; j += (i+1)) if(msk2&(1LL<<j)) msk2 -= (1LL<<j);
//        s.insert(cal(msk2));
//    }
//    
//    LL res = 0;
//    while(s.count(res)) res++;
//    return m[msk] = res;
//}

void solve() {
//    for(LL i = 0; i < 35; i++){
//        OUT(i);
//        OUT(cal((1LL<<i)-1));
//    }
    int g = 1;
    set<LL> chked;
    for(int i = 2; i <= sqrt(n); i++){
        if(chked.count(i)) continue;
        int cnt = 0;
        for(LL j = i; j <= n; j*=i ){
            cnt++;
            chked.insert(j);
        }
        g ^= gr[cnt];
    }
    g ^= ((n - SZ(chked) - 1) & 1);
    if(g) cout << "Vasya" << endl;
    else cout << "Petya" << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






