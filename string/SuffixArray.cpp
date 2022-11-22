char s[];
int n = 0, M = 0;
int sa[], A[], B[], t[], height[];
int *rank = A, *tp = B;
inline void Qsort() {
	for (int i = 0; i <= M; ++i) t[i] = 0;
	for (int i = 1; i <= n; ++i) ++t[rank[i]];
	for (int i = 1; i <= M; ++i) t[i] += t[i - 1];
	for (int i = n; i; --i) sa[t[rank[tp[i]]]--] = tp[i];
}
void SuffixSort() {
	M = 256;
	for (int i = 1; i <= n; ++i) rank[i] = s[i], tp[i] = i;
	Qsort();
	for (int len = 1, p = 0; p < n && len < n; M = p, len <<= 1) {
		p = 0;
		for (int i = 1; i <= len; ++i) tp[++p] = n - len + i;
		for (int i = 1; i <= n; ++i) if (sa[i] > len) tp[++p] = sa[i] - len;
		Qsort();
		tp[sa[1]] = p = 1;
		for (int i = 2; i <= n; ++i) tp[sa[i]] = (rank[sa[i - 1]] == rank[sa[i]] && rank[sa[i - 1] + len] == rank[sa[i] + len] ? p : ++p);
		std::swap(rank, tp);
	}
}
void getHeight() {
	for (int i = 1, k = 0; i <= n; ++i) {
		if (rank[i] == 1) { k = height[1] = 0; continue; }
		if (k) --k;
		int j = sa[rank[i] - 1];
		while (i + k <= n && s[i + k] == s[j + k]) ++k;
		height[rank[i]] = k;
	}
}