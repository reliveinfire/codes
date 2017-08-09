#include <stdio.h>

#define TEST_SIZE    3

int result[10] = {0};
int index = 0;

void combine_sum(int test[], int target, int size, int start)
{
	int i;
//	printf("target:%d\n", target);
	if (target == 0){
		for (i = 0 ; i < index ; i++)
			printf(" %d", result[i]);
		printf("\n");
		return;
	}
	if (target < 0){
		return;
	}
	for (i = start ; i < size ; i++) {
		result[index] = test[i];
		index++;
		combine_sum(test, target - test[i], size, i);
		index--;
	}

}

void main()
{	int test[] = {2,3,6,7};
	int target = 7;
	combine_sum(test, 7, 4, 0);
	return 0;
}
