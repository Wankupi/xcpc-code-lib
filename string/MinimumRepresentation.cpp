// indexed form 1
int k = 0, i = 0, j = 1;
while (k < n && i < n && j < n) {
	if (s[(i + k) % n + 1] == s[(j + k) % n + 1]) k++;
	else {
		s[(i + k) % n + 1] > s[(j + k) % n + 1] ? i = i + k + 1 : j = j + k + 1;
		if (i == j) i++;
		k = 0;
	}
}
i = min(i, j) + 1;