ll a[101][101];
ll gauss() {
	ll det = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i][i] == 0) {
			int j = i + 1;
			while (j <= n && a[j][i] == 0) ++j;
			if (j > n) return 0;
			std::swap(a[i], a[j]); det = -det;
		}
		ll inv = pow(a[i][i], mod - 2);
		for (int j = i + 1; j <= n; ++j) {
			if (a[j][i] == 0) continue;
			ll k = inv * a[j][i] % mod;
			for (int p = i; p <= n; ++p)
				a[j][p] = dec(a[j][p], a[i][p] * k % mod);
		}
	}
	for (int i = 1; i <= n; ++i)
		det = det * a[i][i] % mod;
	det = (det + mod) % mod;
	return det;
}