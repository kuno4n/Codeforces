
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
int L[50010], P[50010], ind[50010];

bool cmp(int a, int b){
    LL A = L[a]*P[a]*(100-P[b]);
    LL B = L[b]*P[b]*(100-P[a]);
    return A > B;
}

int main() {
    int n;
    cin >> n;
    REP(i, n){
        int p, l;
        scanf("%d %d", &l, &p);
        L[i] = l; P[i] = p;
        ind[i] = i;
    }
    sort(ind, ind+n, cmp);
    double res = 0.0;
    double sum = 0.0;
    REP(i, n){
        res += sum*(100.0-P[ind[i]])/100;
        res += L[ind[i]];
        sum += L[ind[i]]*P[ind[i]]/100.0;
    }

    printf("%.10f\n", res);
    
    return 0;
}
