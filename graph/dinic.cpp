int cur[maxn], dep[maxn];
int q[maxn];
bool bfs() {
	memset(dep, 0, sizeof dep);
	memcpy(cur, head, sizeof cur);
	dep[S] = 1;
	int ql = 1, qr = 1;
	q[1] = S;
	while (ql <= qr) {
		int x = q[ql++];
		for (int i = head[x]; i; i = nxt[i]) {
			if (dep[to[i]] == 0 && val[i] > 0) {
				dep[to[i]] = dep[x] + 1;
				q[++qr] = to[i];
			}
		}
	}
	return dep[T] > 0;
}
int dinic(int x, int flow) {
	if (x == T) return flow;
	int use = 0;
	for (int i = cur[x]; i && use < flow; i = nxt[i]) {
		cur[x] = i;
		if (dep[to[i]] == dep[x] + 1 && val[i] > 0) {
			int k = dinic(to[i], min(flow - use, val[i]));
			use += k;
			val[i] -= k;
			val[i ^ 1] += k;
		}
	}
	if (use < flow) dep[x] = 0;
	return use;
}

while (bfs()) Flow += dinic(S, inf);