inv[0] = inv[1] = 1;
for (int i = 2; i <= n; ++i)
	inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
