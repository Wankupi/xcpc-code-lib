struct Node {
    int len, fa;
    int son[26];
    int& operator[](int x) { return son[x]; }
};
Node tr[];
int cnt = 1; // note that: rooted 1
inline int expand(int last, int c) {
    int p = last, ret = 0;
    if (tr[p][c]) { // omitted when single string
        int q = tr[p][c];
        if (tr[q].len == tr[p].len + 1) ret = q;
        else {
            int nq = ++cnt;
            tr[nq] = tr[q];
            tr[nq].len = tr[p].len + 1;
            tr[q].fa = nq;
            for (; p && tr[p][c] == q; p = tr[p].fa) tr[p][c] = nq;
            ret = nq;
        }
    }
    else {
        int np = ++cnt;
        tr[np].len = tr[p].len + 1;
        for (; p && tr[p][c] == 0; p = tr[p].fa) tr[p][c] = np;
        if (p == 0) tr[np].fa = 1;
        else {
            int q = tr[p][c];
            if (tr[q].len == tr[p].len + 1) tr[np].fa = q;
            else {
                int nq = ++cnt;
                tr[nq] = tr[q];
                tr[nq].len = tr[p].len + 1;
                tr[np].fa = tr[q].fa = nq;
                for (; p && tr[p][c] == q; p = tr[p].fa) tr[p][c] = nq;
            }
        }
        ret = np;
    }
    return ret;
}