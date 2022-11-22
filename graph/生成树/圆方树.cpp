int const maxP = maxn << 1;
int cPoint = 0;
namespace CirSqTr {
	int w[maxP];
	void insert(int, int);
}
int dfn[maxn], low[maxn], cDfn = 0;
int stack[maxn], top = 0;
void tarjan(int x) {
	dfn[x] = low[x] = ++cDfn;
	stack[++top] = x;
	for (int i = head[x]; i; i = nxt[i]) {
		if(!dfn[to[i]]) {
			tarjan(to[i]);
			low[x] = min(low[x], low[to[i]]);
			if (low[to[i]] >= dfn[x]) {
				int y = 0, k = ++cPoint;
				do {
					y = stack[top--];
					CirSqTr::insert(k, y);
					CirSqTr::insert(y, k);
					++CirSqTr::w[k];
				} while (y != to[i]);
				CirSqTr::insert(k, x);
				CirSqTr::insert(x, k);
				++CirSqTr::w[k];
			}
		}
		else low[x] = min(low[x], dfn[to[i]]);
	}
}