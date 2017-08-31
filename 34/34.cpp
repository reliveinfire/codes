#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int lo = 0, hi = nums.size();
		while(lo<hi){
			int mid = lo + (hi-lo)/2;
			if (nums[mid] >=target)
				hi = mid;
			else
				lo = mid + 1;
		}
		if (lo==nums.size() || nums[lo]!=target)
			return {-1,-1};
		res.push_back(lo);
		lo = 0, hi = nums.size();
		while(lo < hi){
			int mid = lo + (hi-lo)/2;
			if (nums[mid] > target)
				hi = mid;
			else
				lo = mid+1;
		}
		res.push_back(--lo);
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
