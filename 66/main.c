#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int* carry_result;
	int carry = 0, carry_one = 1;
	carry_result = malloc(digitsSize + 1);
	memset(carry_result, 0, (digitsSize + 1) * sizeof(int));
	carry_result[0] = 1;

	*returnSize = digitsSize;

	while (digitsSize != 0) {
		digitsSize--;
		if (digits[digitsSize] == 9) {
			carry = 1;
			digits[digitsSize] = 0;
		} else {
			carry = 0;
			digits[digitsSize]++;
		}
		if (!carry)
			return digits;
	}

	/*means all 9 */
	if (carry){
		*returnSize = *returnSize + 1;
		return carry_result;
	}

	return digits;
}

int mytest[] = {9,9,9,9,9,9,8,8,8,3,3,9};
int main(void)
{
	int rs;
	int i;
	int *result;
	result = plusOne(mytest, sizeof(mytest)/sizeof(int), &rs);
#if 1
	printf("size:%d\n", rs);
	for( i = 0 ; i < rs ; i++){
		printf("%d",  result[i]);
	}
#endif
	printf("\n");
	return 0;
}
