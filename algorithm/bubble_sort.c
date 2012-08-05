#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*
 * ����ð�����򣭣�
 * ���αȽ����ڵ�������������������ǰ�棬С�����ں��档
 * �����ȱȽϵ�1���͵�2��������������ǰ��С���ź�
 * Ȼ��Ƚϵ�2�����͵� 3��������������ǰ��С���ź�
 * ��˼�����ֱ���Ƚ��������������������ǰ��С���ź�
 * ��ʱ��һ�˽������������������������е���С����
 * �ظ����Ϲ��̣��Դӵ�һ������ʼ�Ƚ�
 * ����Ϊ�������ڵ�2�����͵�3�����Ľ�����ʹ�õ�1�������ٴ��ڵ�2��������
 * ��������ǰ��С���ź�һֱ�Ƚϵ���С��ǰ��һ����������
 * ��������ǰ��С���ź󣬵ڶ��˽�����
 * �ڵ����ڶ������еõ�һ���µ���С���������ȥ��ֱ�������������
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

	printf("����֮ǰ������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	bubble_sort(value, sizeof(value)/sizeof(int));

	printf("\n����֮�������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif