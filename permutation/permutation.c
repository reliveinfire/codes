#include "stdio.h"
#include "stdlib.h"

#define MAX 128


char myString[9] = "123456789";
int used[9] = {0};
char sol[9];

void swap(int x, int y)
{
	char tmp;
	tmp = myString[x];
	myString[x] = myString[y];
	myString[y] = tmp;
	return;
}

void permutation(int start, int end, int size)
{
	int i;
	char tmp;
//	printf("start:%d, end:%d\n", start, end);
printf("MAX:%d\n", MAX);
	if (start == end) {
		for(i = 0 ; i < size ; i++)
			printf("%c", myString[i]);
		printf("\n");
	}
	for (i = start ; i <= end ; i++){
		swap(start, i);
		permutation(start + 1, end, size);
		swap(start, i);
	}
}

void enum_permutation(int n, int target)
{
	int i;
	if (n == target) {
		for(i = 0 ; i < target ; i++)	
			printf("%c", sol[i]);
		printf("\n");
		return;
	}

	for (i = 0 ; i < target ; i++) {
		if (!used[i]) {
			used[i] = 1;
			sol[n] = myString[i];
			enum_permutation(n+1, target);
			used[i] = 0;
		}
	}
}

int main(void)
{
		int i;
//		permutation(0,2,3);
		for (i = 0 ; i < 9 ; i++){
			used[i] = 0;
		}
		enum_permutation(0, 3);
		return 0;
}
