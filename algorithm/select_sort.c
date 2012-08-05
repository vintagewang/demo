#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * ����ѡ�����򣭣�
 * ÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ�
 * ˳��������ź�������е����ֱ��ȫ�������������Ԫ�����ꡣ
 */
void select_sort(int v[], int len)
{
	int i, j, tmp, min_index;

	for(i = 0; i < len; i++) {
		min_index = i;
		for(j = i; j < len; j++) {
			if (v[j] < v[min_index]) 
				min_index = j;
		}
		tmp = v[i];
		v[i] = v[min_index];
		v[min_index] = tmp;
	}
}

#if 0
int main(int argc, char **argv)
{
	int value[] = {
		50, 33, 66, 72, 72, 11, 29, 45, 93, 26, 17, 49, 63,
	};
	int i = 0;

	printf("����֮ǰ������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	select_sort(value, sizeof(value)/sizeof(int));

	printf("\n����֮�������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif