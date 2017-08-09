#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define HIGH    0
#define LOW	1
class Solution {
	class Range{
		public:
		int low;
		int high;
	};
	public:
	bool find132pattern(vector<int>& nums) {
		int result = false;
		int index = LOW;
		vector<Range> pass_range;
		if (nums.size() < 2)
			return result;
		Range tmp;
		tmp.low = nums[0];
		for (int i = 1 ; i < nums.size() ; i++)
		{
			if (index == LOW) {
				if (nums[i] <= tmp.low){
					tmp.low = nums[i];
				} else {
					tmp.high = nums[i];
					index = HIGH;
				}
			}

			if (index == HIGH) {
				if (nums[i] >= tmp.high) {
					tmp.high = nums[i];
				} else {
					index == LOW;
					pass_range.push_back(tmp);
					tmp.low = nums[i];
					tmp.high = nums[i];
				}
			}
			for (int j = 0 ; j < pass_range.size() ; j++)
				if (nums[i] > pass_range[j].low &&
					nums[i] < pass_range[j].high){
					return true;	
				}

		}
		return result;
	}
};

int main()
{	
	//int test[] = {3,1,4,2};
	int test[] = {1,2,3,4};
	vector<int> data(test, test + sizeof(test)/sizeof(test[0]));
	Solution sol;
	bool ret = sol.find132pattern(data);
	if (ret)
		cout << "True\n";
	else
		cout << "False\n";
	return 0;

}
