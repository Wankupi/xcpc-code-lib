inline bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
int st[maxn]; // stack
void CreateVirtualTree() {
	std::sort(s + 1, s + t + 1, cmp);
	root = st[top = 1] = s[1];
	for (int i = 2; i <= t; ++i) {
		int lca = lca(st[top], s[i]);
		while (top > 1 && dfn[lca] <= dfn[st[top - 1]]) {
			insertV(st[top - 1], st[top], dis(st[top - 1], st[top]));
			--top;
		}
		if (st[top] != lca) {
			insertV(lca, st[top], dis(lca, st[top]));
			st[top] = lca;
			if (top == 1) root = lca;
		}
		st[++top] = s[i];
	}
	while (--top > 0)
		insertV(st[top], st[top + 1], dis(st[top], st[top + 1]));
}