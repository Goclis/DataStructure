// 看了《代码之美》第三章，忍不住要实现一下

int x[10];

int randint(int l, int r)
{
	return l + rand() % (r - l + 1);
}

void swap(int i, int j)
{
	int tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void quicksort(int l, int n)
{
	if (l >= n) return;

	int i, m;
	swap(l, randint(l, n));
	m = l;
	for (i = 1; i < n; ++i) {
		if (x[i] < [l]) {
			swap(++m, i);
		}
	}
	swap(l, m);
	quicksort(l, m - 1);
	quicksort(m + 1, n);
}
