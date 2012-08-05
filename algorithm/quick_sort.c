#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * －－快速排序－－
 * 注意：对于有相等元素的情况没有考虑，需要改进
 */
int quick_partition(int v[], int low, int high) 
{
    int pivot = v[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (i < j && pivot < v[j])
            j--;
        if (i < j) {
            v[i] = v[j];
            i++;
        }

        while (i < j && pivot > v[i])
            i++;
        if (i < j) {
            v[j] = v[i];
            j--;
        }
    }
    v[i] = pivot;
    return i;
}

/*
 * －－快速排序－－
 * 快速排序的实现基于分治法，具体分为三个步骤。假设待排序的序列为L[m..n]。
 * 分解：序列L[m .. n]被划分成两个可能为空的子序列L[m .. pivot-1]和L[pivot+1 .. n]，
 * 使L[m .. pivot-1]的每个元素均小于或等于L[pivot]，同时L[pivot+1.. n]的每个元素均大于L[pivot]。
 * 其中L[pivot]称为这一趟分割中的主元（也称为枢轴、支点）。
 * 解决：通过递归调用快速排序，对子序列L[m .. pivot-1]和L[pivot+1 .. r]排序。
 * 合并：由于两个子序列是就地排序的，所以对它们的合并不需要操作，整个序列L[m .. n]已排好序。
 */
void quick_sort(int v[], int low, int high)
{
    int pivot_position;
    if (low < high) {
        pivot_position = quick_partition(v, low, high);
        quick_sort(v, low, pivot_position - 1);
        quick_sort(v, pivot_position + 1, high);
    }
}

#if 1
int main(int argc, char **argv)
{
	int value[] = {
		50, 33, 66, 72, 72, 11, 29, 45, 93, 26, 17, 49, 63,
	};
	int i = 0;

	printf("排序之前的数据:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	quick_sort(value, 0, sizeof(value)/sizeof(int) - 1);

	printf("\n排序之后的数据:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif

