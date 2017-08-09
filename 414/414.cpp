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
	int thirdMax(vector<int>& nums){
		vector<int> tmax;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return nums[0] > nums[1] ? nums[0] : nums[1];

		tmax.push_back(nums[0]);
		for (int i = 1 ; i < nums.size() ; i++){
			bool inside = false;
			int target = nums[i];
			for (int j = 0 ; j < tmax.size() ; j++){
				if (target == tmax[j]){
					inside = true;
					break;
				}
			}
			if (inside)
				continue;
			if (tmax.size() < 3)
				tmax.push_back(target);
			else {
				if ( tmax.back() < target){
					tmax.pop_back();
					tmax.push_back(target);
				}
			}
			sort(tmax.begin(), tmax.end(), greater<int>() );
		}
		if (tmax.size()>=3)
			return tmax.back();
		else
			return tmax.front();
	}
};

#define genVector(data, array) vector<int> data(array, array + sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	int A[] = {1,1,2};
	genVector(da, A);
	Solution sol;
	ret = sol.thirdMax(da);
	cout << ret << "\n";

	return 0;
}
