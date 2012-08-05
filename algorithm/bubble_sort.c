#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*
 * －－冒泡排序－－
 * 依次比较相邻的两个数，将大数放在前面，小数放在后面。
 * 即首先比较第1个和第2个数，将大数放前，小数放后。
 * 然后比较第2个数和第 3个数，将大数放前，小数放后，
 * 如此继续，直至比较最后两个数，将大数放前，小数放后，
 * 此时第一趟结束，在最后的数必是所有数中的最小数。
 * 重复以上过程，仍从第一对数开始比较
 * （因为可能由于第2个数和第3个数的交换，使得第1个数不再大于第2个数），
 * 将大数放前，小数放后，一直比较到最小数前的一对相邻数，
 * 将大数放前，小数放后，第二趟结束，
 * 在倒数第二个数中得到一个新的最小数。如此下去，直至最终完成排序。
 */
void bubble_sort(int v[], int len)
{
	int i, j, tmp, is_swp;

	for(i = 0; i < len; i++) {
		is_swp = 0;
		for(j = 0; j < len - i - 1; j++) {
			if (v[j] < v[j+1]) {
				tmp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = tmp;
				is_swp = 1;
			}
		}
		if (!is_swp) return;
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

	bubble_sort(value, sizeof(value)/sizeof(int));

	printf("\n排序之后的数据:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif