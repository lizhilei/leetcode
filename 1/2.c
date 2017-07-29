#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int val;
	int pos;
} Node;

static int compare(const void * val1,const void * val2) {
	return ((const Node *)val1)->val - ((const Node *) val2)->val;
}

int* twoSum(int* nums, int numsSize, int target) {
    Node *nodes = (Node *)malloc(sizeof(Node) * numsSize);
	int i, j;
	for (i = 0;i < numsSize; i++) {
		nodes[i].val = nums[i];
		nodes[i].pos = i;
	}

    qsort(nodes, numsSize, sizeof(Node), compare);
	int *ret = malloc(2 * sizeof(int));
    ret[0] = ret[1] = -1;
	int tmp = 0;
	for (i =0, j = numsSize -1; i < j;) {
		tmp = nodes[i].val + nodes[j].val;
		if (tmp == target) {
			ret[0] = nodes[i].pos;
			ret[1] = nodes[j].pos;
			break;
		} else if (tmp > target) {
			j--;
		} else {
			i++;
		}
	}
	return  ret;
}


int main() {
	int a[] = {3, 2, 4};
	int *b = twoSum(a, 3, 6);

	return 0;
}
