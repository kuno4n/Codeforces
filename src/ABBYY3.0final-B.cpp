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

    const int MAX_N = 300010;
    int bit[MAX_N], n;
    
    int sum(int i){
        int s = 0;
        while(i>0){
            s+=bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, int x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
    
    int get(int i){
		if(i == 1) return sum(i);
		return sum(i) - sum(i-1);
	}

void update(int id){
	
}




int q;
int seq[300010];
int tab[300010];


void input() {
	MSET(seq, 0); MSET(tab, 0); MSET(bit, 0);
	cin >> n;
	REP(i, n){
		int a;
		cin >> a;
		seq[i] = a;
		tab[a] = i;
	}
	cin >> q;
	
	for(int i = 1; i <= n-1; i++) if(tab[i] > tab[i+1]) add(i, 1);
}


void solve() {
	REP(__, q){
//		for(int i = 1; i < n; i++) OUT2(i, get(i));
		int p, x, y; cin >> p >> x >> y;
		if(p == 1){
			cout << sum(y-1) - sum(x-1) + 1 << endl;
		}
		else{
			int a = seq[x-1], b = seq[y-1];
			swap(seq[x-1], seq[y-1]);
			swap(tab[a], tab[b]);
			
			if(a > 1){
				int a1 = get(a-1);
				if(tab[a-1] < tab[a] && a1 == 1) add(a-1, -1);
				else if(tab[a-1] > tab[a] && a1 == 0) add(a-1, 1);
			}
			
			int a2 = get(a);
			if(tab[a] < tab[a+1] && a2 == 1) add(a, -1);
			if(tab[a] > tab[a+1] && a2 == 0) add(a, 1);
			
			int b1 = get(b-1);
			if(tab[b-1] < tab[b] && b1 == 1) add(b-1, -1);
			if(tab[b-1] > tab[b] && b1 == 0) add(b-1, 1);
			
			if(b < n){
				int b2 = get(b);
				if(tab[b] < tab[b+1] && b2 == 1) add(b, -1);
				else if(tab[b] > tab[b+1] && b2 == 0) add(b, 1);
			}
			
		}
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}






