inline ll Inv(ll x, ll m) {
	ll inv = gcd(x, m).x;
	inv = (inv % m + m) % m;
	return inv;
}
ll A[50000], B[50000];
// a^x=b (mod m)
ll bsgs(ll a, ll b, ll m) {
	ll s = ceil(sqrt(m));
	A[0] = 1;
	map<ll, ll> has;
	for (ll i = 1; i <= s; ++i) {
		A[i] = A[i - 1] * a % m;
		if (A[i] == b) return i;
		has[A[i]] = i;
	}
	ll invs = Inv(A[s], m);
	B[0] = b;
	for (ll i = 1; i <= s; ++i) {
		B[i] = B[i - 1] * invs % m;
		if (has.find(B[i]) != has.end())
			return has[B[i]] + s * i;
	}
	return -1;
}
ll exbsgs(ll a, ll b, ll m) {
	a %= m; b %= m;
	if (m == 1 || b == 1) return 0;
	ll g = 0, k = 0, da = 1;
	while ((g = gcd(a, m).d) > 1) {
		if (b % g != 0) return -1;
		++k;
		b /= g; m /= g;
		da = da * a / g % m;
		if (da == b) return k;
	}
	ll res = bsgs(a, b * Inv(da, m) % m, m);
	return res < 0 ? -1 : res + k;
}