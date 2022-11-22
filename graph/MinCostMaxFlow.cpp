int n = 0, m = 0, S = 0, T = 0;
int head[maxn], nxt[100010], to[100010], val[100010], cost[100010], cnt = 1;
bool in[maxn];
int dis[maxn], pre[maxn];
bool spfa() {
	memset(in, 0, sizeof(in));
	memset(dis, 0x3f, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	queue<int> q;
	q.push(S); in[S] = true; dis[S] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			if (val[i] && cost[i] + dis[x] < dis[to[i]]) {
				dis[to[i]] = dis[x] + cost[i];
				pre[to[i]] = i;
				if (!in[to[i]]) {
					in[to[i]] = true;
					q.push(to[i]);
				}
			}
		}
		in[x] = false;
	}
	return dis[T] != 0x3f3f3f3f;
}
inline int min(int a, int b) { return a < b ? a : b; }
int sumCost = 0, maxFlow = 0;
void getCost() {
	int flow = 0x7fffffff;
	for (int i = T; i != S; i = to[pre[i] ^ 1])
		flow = min(flow, val[pre[i]]);
	maxFlow += flow;
	for (int i = T; i != S; i = to[pre[i] ^ 1]) {
		val[pre[i]] -= flow;
		val[pre[i] ^ 1] += flow;
		sumCost += flow * cost[pre[i]];
	}
}

while (spfa()) getCost();
