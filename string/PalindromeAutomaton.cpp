char s[];
int fa[N], len[N], son[N][27], cnt = 1, last = 0;
void init() { fa[0] = 1; len[1] = -1; cnt = 1; }
void pushR(int r) {
	int p = last, c = s[r] - 'a';
	while (s[r - len[p] - 1] != s[r]) p = fa[p];
	if (!son[p][c]) {
		int np = ++cnt; len[np] = len[p] + 2;
		int k = fa[p];
		while (s[r - len[k] - 1] != s[r]) k = fa[k];
		fa[np] = son[k][c];
		son[p][c] = np;
	}
	last = son[p][c];
	// for Bidirectional PAM, the next line is necessary
	// if (len[lastR] == r - l + 1) lastL = lastR;
}