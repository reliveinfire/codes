#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int search(vector<int>& nums, int target){
		int lo = 0, hi = nums.size()-1;
		if (nums.empty())
			return -1;
		while(lo <= hi){
			int mid = lo + (hi-lo)/2;
			//cout << lo <<":"<<mid <<":"<<hi<<endl;
			if (nums[mid]==target)
				return mid;
			else if (nums[lo] <= nums[mid]){
				if (nums[lo]<=target && target < nums[mid])
					hi = mid - 1;
				else
					lo = mid + 1;
			} else if (nums[hi] > nums[mid]){
				if (nums[mid]< target &&  target <= nums[hi])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
		}
		return -1;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {3,1};
	Solution sol;
	int ret;
	ret = sol.search(A, 3);
	cout << ret << endl;

	return 0;
}
