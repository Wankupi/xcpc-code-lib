int dfn[20001], low[20001], num = 0;
int root = 0;
bool cut[20001];
void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	int flag = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = to[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				++flag;
				if (x != root||flag > 1 )
					cut[x] = true;
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}
for (int i = 1; i <= n; ++i) if (!dfn[i]) {
	root = i; tarjan(i);
}
int ans = 0;
for (int i = 1; i <= n; ++i) if (cut[i])++ans;
