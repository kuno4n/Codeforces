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

int INF = (1<<29);

    typedef pair<int, int> P;
    struct edge {int to, cap, cost, rev;};
    const int MAX_V = 7000;

    int V; // VÇÕï ìrñYÇÍÇ∏Ç…ê›íËÇ∑ÇÈÇ±Ç∆ÅBÅuç≈å„ÇÃÉmÅ[Éhî‘çÜÅ{ÇPÅvÇ≈Ç†ÇÈÇ±Ç∆Ç…íçà”ÅBsinkÇ∆ìØÇ∂êîÇ≈ÇÕÇ»Ç¢ÅBsink+1ÅB
    vector <edge> G[MAX_V]; // égÇ¢âÒÇ∑èÍçáÇÕÅAGÇ‡ñYÇÍÇ∏èâä˙âªÇ∑ÇÈÇ±Ç∆
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];
    
    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, G[to].size()});
        G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
    }
    
    int min_cost_flow(int s, int t, int f){
        int res = 0;
        fill(h, h+V, 0);
        while(f > 0){
//            priority_queue<P, vector<P>, greater<P> > que;
            deque< P > que;
            fill(dist, dist+V, INF);
            dist[s] = 0;
            que.push_back(P(0, s));
            while(SZ(que)){
                P p = que.front(); que.pop_front();
                int v = p.second;
                if(dist[v] < p.first) continue;
                REP(i, SZ(G[v])){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        if(dist[e.to] == p.first) que.push_front(P(dist[e.to], e.to));
                        else que.push_back(P(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) return -1;
            REP(v, V) h[v] += dist[v];
            int d = f;
            for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
            f -= d;
            res += d*h[t];
            for(int v = t; v != s; v = prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }



int n , m;
int table[80][80];

void init() {
}

void input() {
	cin >> n >> m;
	REP(i, n) REP(j, m) cin >> table[i][j];
}

int makenode(int x, int y){
	return x*m + y;
}

void solve() {
	V = n * m + 2;
	int S = n*m, T = n*m+1;
	REP(i, n) REP(j, m){
		if((i+j)&1) add_edge(makenode(i, j), T, 1, 0);
		else add_edge(S, makenode(i, j), 1, 0);
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	REP(i, n) REP(j, m) if(!((i+j)&1)) REP(k, 4){
		int x = i+dx[k], y = j+dy[k];
		if(x < 0 || x >= n || y < 0 || y >= m) continue;
		int from = makenode(i, j), to = makenode(x, y);
		if(table[i][j] == table[x][y]) add_edge(from, to, 1, 0);
		else add_edge(from, to, 1, 1);
	}
	cout << min_cost_flow(S, T, (n*m)/2) << endl;
	
	
//	int mask = 1<<m;
//	int crt[1<<8], nxt[1<<8];
//	REP(i, mask) crt[i] = INF;
//	crt[0] = 0;
//	REP(i, n) REP(j, m){
//		REP(k, mask) nxt[k] = INF;
//		REP(k, mask){
//			if(k&1) chmin(nxt[k>>1], crt[k]);
//			if(!(k&3) && j < m-1){
//				int add = (table[i][j] == table[i][j+1] ? 0 : 1);
//				chmin(nxt[(k>>1)|1], crt[k]+add);
//			}
//			if(!(k&1) && i < n-1){
//				int add = (table[i][j] == table[i+1][j] ? 0 : 1);
//				chmin(nxt[(k>>1)|(1<<(m-1))], crt[k]+add);
//			}
//		}
//		swap(crt, nxt);
//	} 
//	
//	cout << crt[0] << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}






