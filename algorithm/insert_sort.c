#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * －－插入排序－－
 * 假定这个数组的序是排好的,然后从头往后,如果有数比当前外层元素的值大,
 * 则将这个数的位置往后挪,直到当前外层元素的值大于或等于它前面的位置为止.
 * 这具算法在排完前k个数之后,可以保证a[1…k]是局部有序的,保证了插入过程的正确性.
 * 1. 从第一个元素开始，该元素可以认为已经被排序
 * 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
 * 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
 * 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
 * 5. 将新元素插入到该位置中
 * 6. 重复步骤2
 * 如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的数目。
 * 该算法可以认为是插入排序的一个变种，称为二分查找排序。
 */
void insert_sort(int v[], int len)
{
	int i, j, next;

	for(i = 1; i < len; i++) {
		next = v[i];
		for(j = i - 1; j >= 0; j--) {
			if (v[j] > next) 
				v[j + 1] = v[j];
			else 
				break;
		}
		v[j + 1] = next;
	}
}

#if 0
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

	insert_sort(value, sizeof(value)/sizeof(int));

	printf("\n排序之后的数据:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif