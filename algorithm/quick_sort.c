#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * �����������򣭣�
 * ע�⣺���������Ԫ�ص����û�п��ǣ���Ҫ�Ľ�
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
 * �����������򣭣�
 * ���������ʵ�ֻ��ڷ��η��������Ϊ�������衣��������������ΪL[m..n]��
 * �ֽ⣺����L[m .. n]�����ֳ���������Ϊ�յ�������L[m .. pivot-1]��L[pivot+1 .. n]��
 * ʹL[m .. pivot-1]��ÿ��Ԫ�ؾ�С�ڻ����L[pivot]��ͬʱL[pivot+1.. n]��ÿ��Ԫ�ؾ�����L[pivot]��
 * ����L[pivot]��Ϊ��һ�˷ָ��е���Ԫ��Ҳ��Ϊ���ᡢ֧�㣩��
 * �����ͨ���ݹ���ÿ������򣬶�������L[m .. pivot-1]��L[pivot+1 .. r]����
 * �ϲ������������������Ǿ͵�����ģ����Զ����ǵĺϲ�����Ҫ��������������L[m .. n]���ź���
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

	printf("����֮ǰ������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	quick_sort(value, 0, sizeof(value)/sizeof(int) - 1);

	printf("\n����֮�������:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}
#endif

