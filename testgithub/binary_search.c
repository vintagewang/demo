#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hello


/*　　
 * －－二分查找－－　　
 * 二分查找又称折半查找，它是一种效率较高的查找方法。
 * [二分查找要求]  1.必须采用顺序存储结构 2.必须按关键字大小有序排列。
 * [优缺点]        折半查找法的优点是比较次数少，查找速度快，平均性能好;
 *                 其缺点是要求待查表为有序表，且插入删除困难。
 *                 因此，折半查找方法适用于不经常变动而查找频繁的有序列表。
 * [算法思想]      首先，将表中间位置记录的关键字与查找关键字比较，
 *                 如果两者相等，则查找成功；否则利用中间位置记录将表分成
 *                 前、后两个子表，如果中间位置记录的关键字大于查找关键字，
 *                 则进一步查找前一子表，否则进一步查找后一子表。
 *                 重复以上过程，直到找到满足条件的记录，使查找成功，
 *                 或直到子表不存在为止，此时查找不成功。
 * [算法复杂度]    假设其数组长度为n，其算法复杂度为o（log（n））
 *
 * 返回值：
 *		>=0		查找到的数组下标
 *		-1		未找到
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
			printf("经过 %d 次二分查找，查找到数据 %d（下标: %d）\n", \
				cnt, v[mid], mid);
			return mid;
		}
	}

	printf("经过 %d 次二分查找，未找到数据 %d\n", cnt, key);

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

	printf("待查找的线性数据列:\n");
	for(i = 0; i < sizeof(value)/sizeof(int); i++) {
		printf("%d ", value[i]);
	}

	printf("\n请输入要查找的数据:");
	scanf("%d", &key);
	printf("\n");
	binary_search(value, sizeof(value)/sizeof(int), key);

	system("PAUSE");
	return 0;
}
#endif

