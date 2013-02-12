
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

int main() {
    int n, k;
    cin >> n >>k;
    if(n < k*3){
        cout << -1 << endl;
        return 0;
    }
    int i=1;
    for(; i<=2*k; i++){
        printf("%d ", (i-1)/2+1);
    }
    int tmp = i%k;
    for(; i<=n; i++){
        printf("%d", (i-tmp)%k+1);
        if(i<n) printf(" ");
    }
    cout << endl;
    return 0;
}
