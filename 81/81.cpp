#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool search(vector<int>& nums, int target){
		int lo = 0, hi = nums.size()-1;
		if (nums.empty())
			return false;
		while(lo <= hi){
			int mid = lo + (hi-lo)/2;
			//cout << lo <<":"<<mid <<":"<<hi<<endl;
			if (nums[mid]==target)
				return true;
			else if (nums[mid]==nums[lo] && nums[mid]==nums[hi]){
				lo++;hi--;
			} else if (nums[lo] <= nums[mid]){
				if (nums[lo]<=target && target < nums[mid])
					hi = mid - 1;
				else
					lo = mid + 1;
			} else {
				if (nums[mid]< target &&  target <= nums[hi])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
		}
		return false;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,3,1,1,1};
	Solution sol;
	int ret;
	ret = sol.search(A, 3);
	cout << ret << endl;

	return 0;
}
