#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hello


/*����
 * �������ֲ��ң�������
 * ���ֲ����ֳ��۰���ң�����һ��Ч�ʽϸߵĲ��ҷ�����
 * [���ֲ���Ҫ��]  1.�������˳��洢�ṹ 2.���밴�ؼ��ִ�С�������С�
 * [��ȱ��]        �۰���ҷ����ŵ��ǱȽϴ����٣������ٶȿ죬ƽ�����ܺ�;
 *                 ��ȱ����Ҫ������Ϊ������Ҳ���ɾ�����ѡ�
 *                 ��ˣ��۰���ҷ��������ڲ������䶯������Ƶ���������б�
 * [�㷨˼��]      ���ȣ������м�λ�ü�¼�Ĺؼ�������ҹؼ��ֱȽϣ�
 *                 ���������ȣ�����ҳɹ������������м�λ�ü�¼����ֳ�
 *                 ǰ���������ӱ�����м�λ�ü�¼�Ĺؼ��ִ��ڲ��ҹؼ��֣�
 *                 ���һ������ǰһ�ӱ������һ�����Һ�һ�ӱ�
 *                 �ظ����Ϲ��̣�ֱ���ҵ����������ļ�¼��ʹ���ҳɹ���
 *                 ��ֱ���ӱ�����Ϊֹ����ʱ���Ҳ��ɹ���
 * [�㷨���Ӷ�]    ���������鳤��Ϊn�����㷨���Ӷ�Ϊo��log��n����
 *
 * ����ֵ��
 *		>=0		���ҵ��������±�
 *		-1		δ�ҵ�
 */
int binary_search(int v[], int len, int key)
{
	int bottom = 0;
	int top = len - 1;
	int mid = 0;
	int cnt = 0;

	while (bottom <= top) {
		cnt++;
		mid = (bottom + top) / 2;
		if (key > v[mid])
			bottom = mid + 1;
		else if (key < v[mid])
			top = mid -1;
		else {
			printf("���� %d �ζ��ֲ��ң����ҵ����� %d���±�: %d��\n", \
				cnt, v[mid], mid);
			return mid;
		}
	}

	printf("���� %d �ζ��ֲ��ң�δ�ҵ����� %d\n", cnt, key);

	return -1;
}

#if 1
int main(int argc, char **argv)
{
	int value[] = {
		11, 17, 26, 29, 33, 45, 49, 50, 63, 66, 72, 93,
	};
	int i = 0;
	int key = 0;

	printf("�����ҵ�����������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n������Ҫ���ҵ�����:");
	scanf("%d", &key);
	printf("\n");
	binary_search(value, sizeof(value)/sizeof(int), key);

	system("PAUSE");
	return 0;
}
#endif

