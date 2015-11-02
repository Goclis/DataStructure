// 《代码之美》第三章

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
	swap(l, randint(l, n)); // 随机选择分界并交换到最左边
	m = l; // m在循环的过程中始终为比选定分界小的数中下标最大的
	for (i = l + 1; i < n; ++i) {
		if (x[i] < [l]) {
			swap(++m, i);
		}
	}
	swap(l, m);
	quicksort(l, m - 1);
	quicksort(m + 1, n);
}
