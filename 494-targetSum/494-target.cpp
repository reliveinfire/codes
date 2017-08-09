#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
		int result;
	private:
		void calculateTarget(vector<int>& nums, int S, int start, int end)
		{
			if (start == end ) {
				//cout << "S:" << S << "\n";
				if (S - nums[start] == 0)
					result++;
				if( S + nums[start] == 0 )
					result++;
				return;
			}
			calculateTarget(nums, S + nums[start], start + 1, end);
			calculateTarget(nums, S - nums[start], start + 1, end);
			return;
		}
	public:
		 int findTargetSumWays(vector<int>& nums, int S)
		 {
		 	result = 0;

			calculateTarget(nums, S, 0, nums.size()- 1);

			return result;
		
		 }
};

int main()
{
#define TEST2
#ifdef TEST1
	int test[] =  {1,1,1,1,1};
	int target = 3;
#endif
#ifdef TEST2
	int test[] =  {1,0};
	int target = 1;
#endif
	int ret;
	vector<int> data(test, test + sizeof(test)/sizeof(test[0]));
	Solution sol;
	ret = sol.findTargetSumWays(data, target);
	cout << ret << "\n";

	return 0;
}
