int len[maxn];
int manacher(char *s, int n) {
    int ans = 0, mid = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
		len[i] = 1;
        if (i <= r) len[i] = min(len[2 * mid - i], r - i + 1);
        while (s[i - len[i]] == s[i + len[i]]) ++len[i];
        if (i + len[i] - 1 > r) { r = i + len[i] - 1; mid = i; }
        if (len[i] > ans) ans = len[i];
    }
    return ans;
}
char s[maxn], S[maxn];
// allow abba
S[0] = '/';
for (int i = 1; i <= n; ++i) { S[2 * i - 1] = '#'; S[2 * i] = s[i]; }
S[2 * n + 1] = '#';
S[2 * n + 2] = '\\';
ans = manacher(S, 2 * n + 1) - 1;
// not allow
s[0] = '/'; s[n + 1] = '\\';
ans = manacher(s, n) * 2 - 1;