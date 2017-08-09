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
	vector<int> findDisappearedNumbers(vector<int>& nums){
		vector<int> result;
		if (nums.empty())
			return result;
		int pos;
		for (int i = 0 ; i < nums.size() ; i++){
			if (nums[i] < 0)
			 	pos = -nums[i] -1;
			else
				pos = nums[i] - 1;
			if (nums[pos] > 0 )
				nums[pos] = -nums[pos];
		}
		for (int i = 0 ; i < nums.size() ; i++){
			if (nums[i] > 0)
				result.push_back(i+1);
		}
		return result;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret;
	int A[] = {4,3,2,7,8,2,3,1};
	genVector(da, A);
	Solution sol;
	ret = sol.findDisappearedNumbers(da);
	for (int i = 0 ; i < ret.size() ; i++){
		cout << ret[i] <<" ";
	}
	cout << endl;

	return 0;
}
