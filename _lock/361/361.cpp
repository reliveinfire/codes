#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
       	int bombEnemy(vector<vector<char>>& grid){
		int ans = 0;
		vector<vector<int>> tb(grid.size(), vector<int>(grid[0].size(), 0));
		int direct[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
		for (int i = 0 ; i < grid.size() ; i++){
			for (int j = 0 ; j < grid[0].size() ; j++){
				if (grid[i][j] == 'E'){
					for (int k = 0 ; k < 4 ; k++){
						while (true){
							int nr = i + direct[k][0];
							int nc = j + direct[k][1];
							if (nr>= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()){
								if (grid[nr][nc]=='0'){
									tb[nr][nc]++;
									ans = max(ans, tb[nr][nc]);
								} else if (grid[nr][nc]=='W')
									break;
							} else
								break;
						}
					}
				}
			}
		}
		return ans;
        }
};

int minModify(TreeNode* node)
{
	
}

int helper(TreeNode* node, int& ans)
{
	if (node==NULL)
		return 0;
	int left = helper(left, ans);
	int right = helper(right, ans);
	if (left && right){
		int diff = abs(left-right);
		ans += diff;
		return node->val + left + right + diff;
	} else
		return node->val + left + right;
	
}
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
