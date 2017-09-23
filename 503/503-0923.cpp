#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	public:
		vector<int> nextGreaterElements(vector<int>& nums){
			vector<int> res(nums.size(), -1);
			stack<int> st;
			if (nums.empty())
				return {};
			for (int i = 0 ; i < 2*nums.size() ; i++){
				int idx = i % nums.size();
				while(!st.empty()){
					int tp = st.top();
					if (nums[idx]> nums[tp]){
						res[tp] = nums[idx];
						st.pop();
					} else
						break;
				}
				st.push(idx);
			}
			return res;
		}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	Solution sol;
	auto ret_vec = sol.nextGreaterElements(A);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
