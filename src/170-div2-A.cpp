
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
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
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
int n, d[100], s, t;


int main() {
    cin >> n;
    REP(i, n) cin >> d[i];
    cin >> s >> t;
    s--; t--;
    
    int s1 = 0;
    int s2 = 0;
    for(int a=s; a!=t; a = (a+1)%n) s1 += d[a];
    for(int a=t; a!=s; a = (a+1)%n) s2 += d[a];
    cout << min(s1, s2) << endl;
    
    return 0;
}
