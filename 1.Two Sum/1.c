#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
	int *r = (int *)malloc(sizeof(int) * 2);
	int *seat = (int *)malloc(sizeof(int) * numsSize);
	int change = 0, i = 0, j, tmp;
	for (i = 0; i < numsSize; i++) {
		seat[i] = i;
	}

	do {
		change = 0;
		for (i = 1; i < numsSize; i++) {
			if(nums[i] < nums[i-1]) {
				tmp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = tmp;
				tmp = seat[i];
				seat[i] = seat[i-1];
				seat[i-1] = tmp;
				change++; 
			}
		}
	} while(change > 0);

	for (i =0, j = numsSize -1; i < j;) {
		if (nums[i] + nums[j] == target) {
			r[0] = seat[i];
			r[1] = seat[j];
			break;
		} else if (nums[i] + nums[j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return  r;
}


int main() {
	int a[] = {3, 2, 4};
	int *b = twoSum(a, 3, 6);

	return 0;
}
