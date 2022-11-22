void init() {
	euler();
	for (int i = 1; i <= N; ++i) {
		phi[i] += phi[i - 1];
		mu[i] += mu[i - 1];
	}
}
unordered_map<int, ll> fp, fm;
ll getPhiSum(int n) {
	if (n <= N) return phi[n];
	if (fp[n]) return fp[n];
	ll res = (long long)n * (n + 1) / 2;
	for (int l = 2, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= (r - l + 1) * getPhiSum(n / l);
	}
	return fp[n] = res;
}
ll getMuSum(int n) {
	if (n <= N) return mu[n];
	if (fm[n]) return fm[n];
	ll res = 1;
	for (int l = 2, r = 0; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= (r - l + 1) * getMuSum(n / l);
	}
	return fm[n] = res;
}