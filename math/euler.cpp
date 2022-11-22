const int N = 5000000;
int prime[N], cnt = 0;
int phi[N + 10], mu[N + 10];
void Euler() {
	phi[1] = 1; mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!phi[i]) {
			prime[cnt++] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for (int j = 0; j != cnt && prime[j] * i <= N; ++j) {
			if (i % prime[j]) {
				phi[prime[j] * i] = phi[i] * phi[prime[j]];
				mu[prime[j] * i] = mu[i] * mu[prime[j]];
			} else {
				phi[prime[j] * i] = phi[i] * prime[j];
				mu[prime[j] * i] = 0;
			}
		}
	}
}