#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int minPatches(vector<int>& nums, int n){
		int ans = 0, idx = 0;
		// 要考慮到overflow!!!
		long curmax = 0;
		while(curmax < n){
			if (idx < nums.size()){
				if (curmax+1 >= nums[idx]){
					curmax += nums[idx];
					idx++;
				} else {
					curmax += curmax +1;
					ans++;
				}
			} else {
				curmax += curmax + 1;
				ans++;
			}
		}
		return ans;
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
