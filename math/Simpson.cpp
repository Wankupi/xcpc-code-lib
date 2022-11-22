const double eps = 0.00000001;
double f(double);
inline double Simpson(double L, double R) {
	double mid = L + (R - L) / 2;
	return (f(L) + f(R) + 4 * f(mid)) / 6 * (R - L);
}
double calc(double l, double r, double ans) {
	double mid = (l + r) / 2.0;
	double lRes = Simpson(l, mid), rRes = Simpson(mid, r);
	if (abs(lRes + rRes - ans) < eps) return lRes + rRes;
	return calc(l, mid, lRes) + calc(mid, r, rRes);
}