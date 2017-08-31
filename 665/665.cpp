#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool checkPossibility(vector<int>& nums){
		stack<int> st;
		st.push(nums[0]);
		int modify = 0;
		for (int i = 1 ; i < nums.size() ; i++){
			if (nums[i] >= st.top())
				st.push(nums[i]);
			else {
				if (modify)
					return false;
				int top = st.top();
				st.pop();
				if (!st.empty() && nums[i]>=st.top()){
					st.push(nums[i]);
				} else if (st.empty()){
					st.push(nums[i]);
				} else {
					st.push(top);
				}
				modify = 1;
			}

		}
		return true;
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
