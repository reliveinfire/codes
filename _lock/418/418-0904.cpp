#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
/* 沒有驗證過 T_T */
class Solution {
        public:
        int wordsTyping(vector<string>& sent, int rows, int cols){
		int ans = 0;
		int row = 0, col = 0;
		int idx = 0, all = 0;
		for (string s : sent)
			all += 1 + s.size();
		while(row < rows){
			while(col < cols){
				if (idx == 0 && cols - col >= all-1){
					int cnt = (cols-col+1)/all;
					col += cnt * all;
					ans += cnt * sent.size();
				} else if (cols - col > sent[idx].size()){
					col += sent[idx++].size() + 1;
					ans++;
				} else
					break;
			}
			col = 0;
			row++;
		}
		return ans/sents.size();
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
