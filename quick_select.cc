#include <stdio.h>


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 三数中值
int median3(int arr[], int low, int high) {
	int mid = (low + high) / 2;

	// 构造low<=mid<=high
	if (arr[low] > arr[mid])
		swap(&arr[low], &arr[mid]);
	if (arr[low] > arr[high])
		swap(&arr[low], &arr[high]);
	if (arr[mid] > arr[high])
		swap(&arr[mid], &arr[high]);
	
	// 将中数放在high
	swap(&arr[mid], &arr[high]);

	return arr[high]; //pivot
}

int partion(int arr[], int low, int high) {
	int i = low - 1;
	int j = low;
	int x = arr[high];

	for(; j<high; j++) {
		if (arr[j] <= x)
			swap(&arr[++i], &arr[j]);
		
	}
	swap(&arr[i+1], &arr[high]);

	return i+1;
}

int quick_select(int arr[], int low, int high, int k) {
	printf("{%d ~ %d} ", low, high);
	
	if (low > high)
		return -1;
	
	median3(arr, low, high);

	int pos = partion(arr, low, high);

	printf("pos : %d\n", pos);

	if (pos == k-1)
		return arr[pos];
	else if (pos > k-1)
		return quick_select(arr, low, pos-1, k);
	else
		return quick_select(arr, pos+1, high, k);
	
}

int main(int argc, char *argv[])
{
	int test[] = {5, 4, 8, 1, 6, 3, 2, 7};
	int len = sizeof(test)/sizeof(int);

	//测试获取第3小的数
	int ret = quick_select(test, 0, len-1, 3);
	printf("%d \n", ret);

	int test2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	len = sizeof(test2)/sizeof(int);
	ret = quick_select(test2, 0, len-1, 4);
	printf("%d \n", ret);
	
    return 0;
}