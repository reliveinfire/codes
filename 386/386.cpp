#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> lexicalOrder(int n){
		vector<int> res;
		helper(n, 0, res);
		return res;
        }
	void helper(int n, int curr, vector<int>& res)
	{
		if (curr <= n) {
			if (curr!=0)
				res.push_back(curr);
		}
		else
			return;
		for (int i = 0 ; i <= 9 ; i++){
			int next = curr*10+i;
			if (next != 0)
				helper(n, next, res);
		}
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	auto ret_vec = sol.lexicalOrder(13);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
