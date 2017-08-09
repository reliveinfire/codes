#include <stdio.h>

void ninetable(int i, int j)
{
	printf("%d*%d=%d\n", i, j, i*j);
	if (i==9 && j==9)
		return;
	if (j==9) {
		i++;
		j=0;
	}
	ninetable(i, j+1);
}

int main()
{
	ninetable(1,1);
	return 0;
}
