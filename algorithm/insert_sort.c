#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * �����������򣭣�
 * �ٶ��������������źõ�,Ȼ���ͷ����,��������ȵ�ǰ���Ԫ�ص�ֵ��,
 * ���������λ������Ų,ֱ����ǰ���Ԫ�ص�ֵ���ڻ������ǰ���λ��Ϊֹ.
 * ����㷨������ǰk����֮��,���Ա�֤a[1��k]�Ǿֲ������,��֤�˲�����̵���ȷ��.
 * 1. �ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
 * 2. ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
 * 3. �����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ��
 * 4. �ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
 * 5. ����Ԫ�ز��뵽��λ����
 * 6. �ظ�����2
 * ����Ƚϲ����Ĵ��۱Ƚ���������Ļ������Բ��ö��ֲ��ҷ������ٱȽϲ�������Ŀ��
 * ���㷨������Ϊ�ǲ��������һ�����֣���Ϊ���ֲ�������
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

	printf("����֮ǰ������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	insert_sort(value, sizeof(value)/sizeof(int));

	printf("\n����֮�������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif