// 1e9+7,1e9+9,23333333333333333,1e18+9
ll const mod = 999999797, base = 157;
ll hash[maxn];
ll mi[maxn];
void preHash(char *s, int n) {
	mi[0] = 1;
	for (int i = 1; i <= n; ++i) {
		mi[i] = mi[i - 1] * base % mod;
		hash[i] = (hash[i - 1] * base + str[i] - 'a') % mod;
	}
}
inline ll getHash(int l, int r) {
	return ((hash[r] - hash[l - 1] * mi[r - l + 1] % mod) % mod + mod) % mod;
}