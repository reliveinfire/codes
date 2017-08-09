#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <limits>

using namespace std;

class Solution {
	private:
		long result;
		void getMoves(vector<int>& nums, int element){
			long count = 0;
			long diff;
			for (int i = 0 ; i < nums.size() ; i++){
				diff = nums[i] > element ? nums[i] - element:
							element - nums[i];
				count = count + diff;
			}
			
			result = min(result, count);
			return;
		}
	public:
		int minMoves2(vector<int>& nums){
			map<int, int> checked;
			result = LONG_MAX;
			for (int i = 0 ; i < nums.size() ; i++) {
				if (checked.find(nums[i]) == checked.end()) 
				{
					getMoves(nums, nums[i]);
					checked[nums[i]] =  1;
				}
			}

			return (int)result;
		}
};

int main()
{
	int test[] = {-6,7,8};
	int ret;
	vector<int> data(test, test + sizeof(test)/sizeof(test[0]));
	Solution sol;
	ret = sol.minMoves2(data);
	cout << ret;

	return 0;
}
