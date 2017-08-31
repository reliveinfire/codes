#include "../helpers.cpp"

class Solution {
        public:
        int jump(vector<int>& nums){
                int ans = 0;
                int ma = 0, next = 0;
                if (nums.size() == 1)
                        return 0;
                for (int i = 0 ; i < nums.size() ; i++){
                        if (nums[i]+i > ma){
                                ma = nums[i] + i;

                        }
                       if (i == next){
                                   next = ma;
                                   ans++;
                        }
                        if (next >= nums.size() - 1)
                                break;
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
