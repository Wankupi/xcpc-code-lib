void kmp() {
	nxt[1] = 0;
	for (int i = 2; i <= n; ++i) {
		nxt[i] = nxt[i - 1];
		while (nxt[i] && s[i] != s[nxt[i] + 1])
			nxt[i] = nxt[nxt[i]];
		if (s[i] == s[nxt[i] + 1]) ++nxt[i];
	}
}
// exKMP
// z[i]:LCP of t[1,m] & t[i,m]
// p[i]:LCP of s[i,n] & t[1,m]
int z[], p[];
void getNxt(char *s, int n) {
	z[1] = n;
	for (int i = 2, l = 0, r = 0; i <= n; ++i) {
		if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
		while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1])
			++z[i];
		if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
	}
}
void exkmp(char *s, int n, char *t, int m) {
	getNxt(t, m);
	for (int i = 1, l = 0, r = 0; i <= n; ++i) {
		if (i <= r) p[i] = min(z[i - l + 1], r - i + 1);
		while (i + p[i] <= n && s[i + p[i]] == t[p[i] + 1]) ++p[i];
		if (i + p[i] - 1 > r) { l = i; r = i + p[i] - 1; }
	}
}