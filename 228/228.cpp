#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<string> summaryRanges(vector<int>& nums){
		vector<string> ans;
		if (nums.empty())
			return {};
		string tmp;
		int left = 0, right = 0;
		for (int i = 1 ; i < nums.size() ; i++){
			cout << i << endl;
			if (nums[i]-1 != nums[i-1]){
				ans.push_back(toRange(nums, left, right));
				left = right = i;
			} else {
				right = i;
			}
		}
		ans.push_back(toRange(nums, left, right));
		return ans;
        }
	string toRange(vector<int>& nums, int left, int right){
		string ret;
		if (left == right)
			ret = to_string(nums[left]);
		else{
			ret = to_string(nums[left]);
			ret += "->";
			ret += to_string(nums[right]);
		}
		return ret;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {-2147483648,-2147483647,2147483647};
	Solution sol;
	auto ret_vec = sol.summaryRanges(B);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
