ll const mod = 998244353;
void OR(ll *f, ll *a, ll opt) {
	for (int i = 0; i < N; ++i)
		f[i] = a[i];
	for (int len = 1; len < N; len <<= 1)
		for (int i = 0; i < N; i += (len << 1))
			for (int j = 0; j < len; ++j)
				(f[i + len + j] += f[i + j] * opt) %= mod;
}

void AND(ll *f, ll *a, ll opt) {
	for (int i = 0; i < N; ++i)
		f[i] = a[i];
	for (int len = 1; len < N; len <<= 1)
		for (int i = 0; i < N; i += (len << 1))
			for (int j = 0; j < len; ++j)
				(f[i + j] += f[i + len + j] * opt) %= mod;
}

void XOR(ll *f, ll *a, ll opt) {
	for (int i = 0; i < N; ++i)
		f[i] = a[i];
	for (int len = 1; len < N; len <<= 1)
		for (int i = 0; i < N; i += (len << 1))
			for (int j = 0; j < len; ++j) {
				f[i + j] = (f[i + j] + f[i + len + j]) % mod;
				f[i + len + j] = (f[i + j] - 2 * f[i + len + j]) % mod;
				f[i + j] = f[i + j] * opt % mod;
				f[i + len + j] = f[i + len + j] * opt % mod;
			}
}
OR/AND(.., .., +1)
OR/AND(.., .., -1)
XOR(.., .., +1)
XOR(.., .., 499122177)