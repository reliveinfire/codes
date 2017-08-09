#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>

using namespace std;
static int table[256] = {0};

bool checkPass(void)
{
	for (int i = 0 ; i < 256 ; i++){
		if (table[i] > 0) {
			return false;
		}
	}
	return true;
}

int findShortest(string A, string B)
{
	int result = A.size();
	int r = B.size() - 1;
	int l = 0;

	for (int i = 0 ; i < B.size() ; i++){
		table[B[i]]++;
		table[A[i]]--;

	}	

	if (checkPass())
		return r-l+1;

	for ( r = r+1; r < A.size() ; r++){
		table[A[r]]--;
		if (checkPass()){
			while (true) {
				if ((table[A[l]]) < 0) {
					table[A[l]]++;
					l++;
				} else {
					break;
				}
			}

			if (r-l+1 < result) {
				result = r-l+1;
				cout << "l:" << l << " r:" << r << "\n";
				for (int i = l ; i <= r ; i++)
					cout << A[i];
				cout << "\n";
			}
		}
	}
	return result;
}

int main()
{
	int ret;
	string A("thisisateststring");
	string B("tist");


	cout << findShortest(A,B);
	return 0;
}
