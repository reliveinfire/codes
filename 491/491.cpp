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
	vector< vector<int> > result;
	public:
	vector<vector<int> > findSubsequences(vector<int>& nums){
		vector<int> tmp;
		result.clear();
		tmp.clear();
		helper(nums, 0, tmp);
		return result;
	}

	void helper(vector<int>& nums, int start, vector<int>& tmp){
		if (tmp.size() >= 2){
			result.push_back(tmp);
		}
		if (start == nums.size())
			return;
		vector<int> local;
		bool visited;

		for (int i = start ; i < nums.size() ; i++){
			int target = nums[i];
			visited = false;
			for (int j = 0 ; j < local.size() ; j++){
				if(target == local[j]){
					visited = true;
					break;
				}
			}
			if (visited)
				continue;
			local.push_back(target);
			if (tmp.empty() || tmp.back() <= target ) {
				tmp.push_back(target);
				helper(nums, i+1, tmp);
				tmp.pop_back();
			}
		}
		return;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector< vector<int> > ret;
	vector<int> ret_vec;
	int A[] = {4,6,7,7};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.findSubsequences(da);
	for (int i = 0 ; i < ret.size(); i++){
		vector<int> tmp = ret[i];
		for (int j = 0 ; j < tmp.size() ; j++)
			cout<< tmp[j];
		cout << endl;
	}

	return 0;
}
