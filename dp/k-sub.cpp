inline int nextS(int S) {
	int x = S & -S, y = S + x;
	return ((S & ~y) / x >> 1) | y;
}