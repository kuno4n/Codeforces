
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
    int n;
    int x[1010], y[1010];
    int xcnt[1010], ycnt[1010];
    REP(i, 1005) x[i] = y[i] = 0;
    cin >> n;
    REP(i, n-1){
        int xx, yy;
        cin >> xx >> yy;
        x[i] = xx;
        y[i] = yy;
    }

    int res = 0;
    vector < VI > vi;
    vi.clear();
    
    for(int now=n; now>=2; now--){
        REP(i, 1005) xcnt[i] = ycnt[i] = 0;
        REP(i, n-1) {
            if(x[i] <= now) ycnt[y[i]]++;
            if(y[i] <= now) xcnt[x[i]]++;
        }
        if(ycnt[now] > 0){
            int target = -1;
            for(int j=1; j<now; j++) if(ycnt[j] == 0) target = j;
            if(target==-1) break;
            res++;
            REP(j, n-1) if(y[j] == now) y[j] = target;
            VI tmp;
            tmp.PB(2);
            tmp.PB(target);
            tmp.PB(now);
            vi.PB(tmp);
        }
        if(xcnt[now] == 0){
            int target = -1;
            for(int j=1; j<now; j++) if(xcnt[j] > 0) target = j;
            if(target==-1) break;
            res++;
            REP(j, n-1) if(x[j] == target) x[j] = now;
            VI tmp;
            tmp.PB(1);
            tmp.PB(target);
            tmp.PB(now);
            vi.PB(tmp);
        }
    }

    
    cout << res << endl;
    REP(i, res){
        cout << vi[i][0] << " " << vi[i][1] << " " << vi[i][2] << endl;
    }
    
    return 0;
}
