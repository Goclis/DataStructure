/**
 * 区别主要在于while内部。
 *
 * 第一种使用三个分支实现找到了就返回，不继续往后的循环。
 *
 * 第二种会把while都执行完（while条件避免了死循环），但内部只使用了两个分支，并在最后加入
 * 一个判断来确定是否找到，主要思想在于认为log2(N)的算法没必要为了节省最后的几个循环而加入
 * 复杂的内部计算（分支）。
 */

// 按照原先的思路实现的二分查找
int binary_sort_1(int *arr, int arr_size, int key)
{
	int low = 0;
	int high = arr_size - 1;
	int mid, mid_val;

	while (low <= high) {
		mid = (low + high) / 2;
		mid_val = arr[mid];

		if (mid_val == key) {
			return mid;	
		} else if (mid_val > key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}


// 《代码之美》第四章看到的二分查找
int binary_sort_2(int *arr, int arr_size, int key)
{
	int low = -1;
	int high = arr_size;
	int mid;

	while (high - low > 1) {
		mid = (high + low) / 2;

		if (arr[mid] > key) {
			high = mid;
		} else {
			low = mid;
		}
	}

	if (-1 == low || arr[low] != key)
		return -1;

	return low;
}
