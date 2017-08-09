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
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums){
		map<int,int> tt;
		vector<int> result;
		int j;
		if (nums.empty())
			return result;
		for (int i = 0 ; i < nums.size() ; i++)
			tt[nums[i]] = i;

		for (int i = 0 ; i < findNums.size() ; i++){
			map<int,int>::iterator iter = tt.find(findNums[i]);
			int pos = iter->second;
			for (j = pos + 1 ; j < nums.size() ; j++){
				if(nums[j] > findNums[i]) {
					result.push_back(nums[j]);
					break;
				}
			}
			if ( j  == nums.size())
				result.push_back(-1);
		}
		return result;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret;
	int A[] = {2,4};
	int B[] = {1,2,3,4};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.nextGreaterElement(da,db);
	for (int i = 0 ; i < ret.size() ; i++)
		cout << ret[i] << " ";
	cout << endl;

	return 0;
}
