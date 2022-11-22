int tri[maxn][26], fail[maxn], cnt = 0;
int insert(char *s) {
	int p = 0;
	while (*s != 0) {
		int c = *s++ - 'a';
		if (!tri[p][c]) tri[p][c] = ++cnt;
		p = tri[p][c];
	}
	return p;
}
void getFail() {
	queue<int> q;
	for (int i = 0; i != 26; ++i)
		if (tri[0][i]) {
			fail[tri[0][i]] = 0;
			q.push(tri[0][i]);
		}
	while (!q.empty()) {
		int x = q.front(); q.pop();
        // insert(fail[x], x);
		for (int i = 0; i != 26; ++i) {
			if (tri[x][i]) {
				fail[tri[x][i]] = tri[fail[x]][i];
				q.push(tri[x][i]);
			}
			else tri[x][i] = tri[fail[x]][i];
	    }
    }
}