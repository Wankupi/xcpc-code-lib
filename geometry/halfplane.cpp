/**
 * @param n the number of lines
 * @param p result
 * @returns the number of points
 */
int halfplane(int n, Line *a, Point *p) {
	std::sort(a + 1, a + n + 1);
	static Line q[maxn];
	int ql = 1, qr = 1;
	q[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		while (ql < qr && a[i].onRight(p[qr]))
			--qr;
		while (ql < qr && a[i].onRight(p[ql + 1]))
			++ql;
		q[++qr] = a[i];
		if (std::abs(cross(q[qr].v, q[qr - 1].v)) <= eps) {
			if (q[qr].onRight(q[qr - 1].p) && dot(q[qr].v, q[qr - 1].v) <= -eps) {
				return 0;
			}
			--qr;
			if (q[qr].onLeft(a[i].p)) q[qr] = a[i];
		}
		if (ql < qr)
			p[qr] = intersect(q[qr - 1], q[qr]);
	}
	while (ql < qr && q[ql].onRight(p[qr]))
		--qr;
	if (qr - ql <= 1) return 0;
	p[ql] = intersect(q[ql], q[qr]);
	if (ql != 1) {
		for (int i = 1; i <= qr - ql + 1; ++i)
			p[i] = p[ql + i - 1];
	}
	return qr - ql + 1;
}
