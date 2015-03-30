#include <stdio.h> 

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int hoare_partion(int arr[], int low, int high) {
	int i = low;
	int j = high;

	int x = arr[low];

	while (i < j) {
		while (arr[j] > x)
			j--;
		while (arr[i] < x)
			i++;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	//printf("i: %d, j: %d\n", i, j);
	return i;
}

void quick_sort(int arr[], int low, int high) {
	if (low >= high)
		return;
	int mid = hoare_partion(arr, low, high);
	quick_sort(arr, low, mid-1);
	quick_sort(arr, mid+1, high);
}

int main(int argc, char *argv[])
{
	// 测试partion
	int test[] = {5, 4, 8, 1, 6, 3, 2, 7};
	int len = sizeof(test)/sizeof(int);
	int mid = hoare_partion(test, 0, len-1);
	printf("mid: %d\n", mid);
	for (int i=0; i<len; i++)
		printf("%d ", test[i]);
	
	// 测试排序
	int test2[] = {5, 4, 8, 1, 6, 3, 2, 7};
	len = sizeof(test2)/sizeof(int);
	quick_sort(test2, 0, len-1);
	printf("\n");
	for (int i=0; i<len; i++)
		printf("%d ", test2[i]);
	
    return 0;
}


