#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
	bool pick[20];
	public:
	bool canIWin(int maxChoosableInteger, int desiredTotal){
			bool ret = true;
			vector<int> data;
			if (desiredTotal <= 0)
				return true;
			for (int i = 1 ; i <= maxChoosableInteger ; i++)
				data.push_back(i);
			for (int i = 0 ; i < maxChoosableInteger ; i++)
				pick[i] = false;

			for (int i = 0 ; i < data.size() ; i++){
				if (desiredTotal > data[i]) {
					pick[i] = true;
					ret &= secondToWin(data,
							desiredTotal - data[i]);
					pick[i] = false;
				} else if (desiredTotal <= data[i]) {
					return true;
				}
			}
			return !ret;
	}

	bool secondToWin(vector<int>& nums, int desire)
	{
		bool ret = false;

		for (int i = 0 ; i < nums.size(); i++){
			if (!pick[i] && nums[i] >= desire)
				return true;
		}

		bool tmp = true;
		for (int j = 0 ; j < nums.size() ; j++){
			if (!pick[j] && desire - nums[j] > 0) {
				pick[j] = true;
				desire -= nums[j];

				for (int i = 0 ; i < nums.size() ; i++){
					if (pick[i]== false && desire - nums[i] > 0){
						pick[i] = true;
						ret = secondToWin(nums, desire - nums[i]);
						pick[i] = false;
					}
					if (ret)
						break;
				}

				desire += nums[j];
				pick[j] = false;
			}
			tmp = tmp & ret;
		}
		
		return tmp;
	}
};

int main()
{
	int ret;
	Solution sol;
	ret = sol.canIWin(18,79);

	if (ret)
		cout << "TRUE\n";
	else
		cout << "FALSE\n";

	return 0;
}
