// CRT, ans = x
// x mod mi = ai
M[0] = 1;
for (int i = 1; i <= n; ++i) M[0] *= m[i];
ll x = 0;
for (int i = 1; i <= n; ++i) {
	M[i] = M[0] / m[i];
	ll inv = (exgcd(M[i], m[i]).x + m[i]) % m[i];
	x = (x + a[i] * M[i] % M[0] * inv % M[0]) % M[0];
}
// exCRT, ans = b1
inline ll muti(ll a, ll b, ll mod) {...}
ll b1 = 0, a1 = 0;
void combine(ll b2, ll a2) {
	Result r = exgcd(a1, a2); a2 /= r.d;
	r.x = (r.x % a2 + a2) % a2;
	ll m = a1 * a2;
	//ll x = ((r.x * (b2 - b1) / r.d) * a1 + b1) % m;
	// the second parameter of muti must be non negetive
	ll x = (muti(muti((b2 - b1) / r.d, r.x, m), a1, m) + b1) % m;
	a1 = m; b1 = (x % a1 + a1) % a1;
}