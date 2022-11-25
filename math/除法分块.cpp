// floor
for (int l = 1, r = 0; l <= n; l = r + 1) {
	int v = n/ l;
	r = n / v;
}
// ceil
for (int l = 1, r = 0; l <= n; l = r + 1) {
	int v = (n + l - 1) / l;
	r = v == 1 ? n : (n + v - 2) / (v - 1) - 1;
}