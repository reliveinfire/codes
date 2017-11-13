#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int pivotIndex(vector<int>& nums){
		int m = nums.size();
		vector<int> left(m, 0);
		vector<int> right(m, 0);
		for (int i = 0 ; i < m ; i++){
			int pre = 0;
			if (i > 0)
				pre = left[i-1];
			left[i] = nums[i] + pre;
		}
		for (int i = m-1 ; i>=0 ; i--){
			int pre = 0;
			if (i+1<m)
				pre = right[i+1];
			right[i] = nums[i] + pre;
		}
		for (int i = 0 ; i < m ; i++){
			int ll = 0;
			int rr = 0;
			if (i>0)
				ll = left[i-1];
			if (i+1 < m) 
				rr = right[i+1];
			if (ll == rr)
				return i;
		}
		return -1;
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
