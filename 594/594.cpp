#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int findLHS(vector<int>& nums){
		int ans = INT_MIN;
		unordered_map<int,int> cnts;
		for (int it : nums)
			cnts[it]++;
		for (auto iter = cnts.begin() ; iter!=cnts.end() ; iter++){
			int tmp = *iter;
			if (cnts.count(tmp+1)!= 0){
				ans = max(ans, cnts[tmp]+cnts[tmp+1]);
			}
			if (cnts.count(tmp-1)!=0){
				ans = max(ans, cnts[tmp]+cnts[tmp-1]);
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
