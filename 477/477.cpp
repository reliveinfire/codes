#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int totalHammingDistance(vector<int>& nums){
		int size = nums.size();
		int one;
		int zero;
		int ret = 0;
		for (int i = 31 ; i >= 0 ; i--){
			one = zero = 0;
			for (int j = 0 ; j < size ; j++){
				int tmp = (nums[j] >> i) & 0x1;
				if(tmp)
					one++;
				else
					zero++;
			}
			ret += one * zero;
		}
		return ret;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {4,14,2};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.totalHammingDistance(da);
	cout << ret << "\n";

	return 0;
}
