int n = 0, m = 0;
int head[maxn], nxt[maxm], to[maxm], cnt = 0;
ll val[maxm], dis[maxn], Ep[maxn];
inline void insert(int u, int e, ll v) { nxt[++cnt] = head[u]; head[u] = cnt; to[cnt] = e; val[cnt] = v; }
bool inQ[maxn], confirmed[maxn];
int times[maxn];
bool spfa() {
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
	queue<int> q;
	q.push(0); inQ[0] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		inQ[x] = false;
		for (int i = head[x]; i; i = nxt[i])
			if (dis[x] + val[i] < dis[to[i]]) {
				dis[to[i]] = dis[x] + val[i];
				if (++times[to[i]] > 2 * n) return false;
				if (!inQ[to[i]]) {
					q.push(to[i]);
					inQ[to[i]] = true;
				}
			}
	}
	return true;
}
struct Point { int id; ll d; };
bool operator<(const Point &lhs, const Point &rhs) { return lhs.d > rhs.d; }
inline int min(int a, int b) { return a < b ? a : b; }
void dij(int S) {
	memset(dis, 0x3f, sizeof(dis));
	memset(confirmed, 0, sizeof(confirmed));
	dis[S] = 0;
	priority_queue<Point> q;
	q.push({ S,0 });
	while (!q.empty()) {
		int x = q.top().id; q.pop();
		if (confirmed[x]) continue;
		confirmed[x] = true;
		for (int i = head[x]; i; i = nxt[i])
			if (!confirmed[to[i]]) {
				if (dis[x] + val[i] - Ep[to[i]] + Ep[x] < dis[to[i]]) {
					dis[to[i]] = dis[x] + val[i] - Ep[to[i]] + Ep[x];
					q.push({ to[i],dis[to[i]]});
				}
			}
	}

}

// after read in and insert edges
for (int i = 1; i <= n; ++i) insert(0, i, 0);
if (!spfa()) { printf("-1\n"); return 0; }
for (int i = 1; i <= n; ++i) Ep[i] = dis[i];
// forall x \in [n], run
dij(x);
// then dis(x, i) =
dis[i] + Ep[i] - Ep[x];
