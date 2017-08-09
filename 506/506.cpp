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
	vector<string> findRelativeRanks(vector<int>& nums){
		vector<int> rank(nums.begin(), nums.end());
		sort(rank.begin(), rank.end(), greater<int>());
		vector<string> result;
		cout << nums.size() << endl;
		for (int i = 0 ; i < nums.size() ; i++){
			int target = nums[i];
			int j = bs(rank, 0, nums.size() - 1, target);
			cout << "target:" << target;
			cout << " j:" << j  << endl;
			if (j == 0){
				result.push_back("Gold Medal");
			} else if (j==1) {
				result.push_back("Silver Medal");
			} else if (j==2) {
				result.push_back("Bronze Medal");
			} else {
				stringstream ss;
				ss << (j+1);
				result.push_back(ss.str());
			}
		}
		return result;
	}
	int bs(vector<int>& ref, int l, int r, int target)
	{
		int m;
		while (l<=r){
			m = (l+r)/2;
			if (ref[m]==target)
				return m;
			else if (ref[m] > target)
				l = m+1;
			else
				r = m-1;
		}
		return l;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> ret;
	int A[] = {3,4,5,2,1};
	genVector(da, A);
	Solution sol;
	ret = sol.findRelativeRanks(da);
	for (int i = 0 ; i < ret.size() ; i++){
		cout << " " << ret[i];
	}
	cout << endl;

	return 0;
}
