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
	int findMaxConsecutiveOnes(vector<int>& nums){
		int prev;
		int ret = 0;
		int size = nums.size();
		if (size == 0)
			return 0;
		if (size == 1){
			if (nums[0] == 1)
				return 1;
			else
				return 0;
		}
		int count;
		prev = nums[0];
		if (prev == 1)
			count = 1;
		else
			count = 0;
		ret = max(ret,count);
		for (int i = 1 ; i < size ; i++){
			int target = nums[i];
			if (target && prev)
				count++;
			else if (target){
				count = 1;
			} else {
				count = 0;
			}
			prev = target;
			ret = max(ret, count);
		}
		return ret;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,1,0,1,1,1};
	genVector(da, A);
	Solution sol;
	ret = sol.findMaxConsecutiveOnes(da);
	cout << ret << "\n";

	return 0;
}
