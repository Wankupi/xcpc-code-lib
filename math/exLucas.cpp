// if p is prime number
ll Lucas(ll n, ll m, ll p) {
	if (m == 0) return 1;
	return Lucas(n / p, m / p, p) * binom(n % p, m % p, p) % p;
}
// if p isn't prime number
ll p = 0, pc = 0;
ll s[1000003]; // bigger than pc
void init() {
	s[0] = 1;
	for (int i = 1; i <= pc; ++i) {
		s[i] = s[i - 1];
		if (i % p != 0) s[i] = s[i] * i % pc;
	}
}
ll fact(ll n) {
	if (n == 0 || n == 1) return 1;
	ll loop = pow(s[pc], n / pc, pc), leave = s[n % pc];
	return fact(n / p) * loop % pc * leave % pc;
}
ll g(ll n) { // how many p in [n]
	if (n < p) return 0;
	return g(n / p) + (n / p);
}
struct Equation { ll b, m; };
Equation GetBinomMod(ll n, ll m) {
	ll N = fact(n), M = inv(fact(m), pc), N_M = inv(fact(n - m), pc);
	ll pm = pow(p, g(n) - g(m) - g(n - m), pc);
	return Equation{N * M % pc * N_M % pc * pm % pc, pc};
}
Equation res;
void Combine(Equation eq) { /* refer to CRT */ }
int main() {
	ll n = 0, m = 0, mod = 0;
	scanf("%lld%lld%lld", &n, &m, &mod);
	for (ll i = 2; i * i <= mod; ++i)
		if (mod % i == 0) {
			pc = p = i;
			mod /= i;
			while (mod % i == 0) { pc *= i; mod /= i; }
			init();
			Equation e = GetBinomMod(n, m);
			Combine(e);
		}
	if (mod != 1) {
		pc = p = mod;
		init();
		Equation e = GetBinomMod(n, m);
		Combine(e);
	}
	printf("%lld", res.b);
	return 0;
}