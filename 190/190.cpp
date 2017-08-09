#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

typedef unsigned int uint32_t;

using namespace std;
class Solution {
	public:
	uint32_t reverseBits(uint32_t n){
		int bit;
		int ans = 0;
		int i, j;
		for(i = 31,j = 0 ; i>=0 ; i--, j++){
			bit = (n >> i) & 0x1;
			ans = ans | (bit << j);
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.reverseBits(43261596);
	cout << ret << "\n";

	return 0;
}
