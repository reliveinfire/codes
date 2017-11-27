#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
		if (image[sr][sc]==newColor)
			return image;
		int m = image.size();
		int n = image[0].size();
		int color = image[sr][sc];
		image[sr][sc] = newColor;
		queue<pair<int,int>> qu;
		qu.push(make_pair(sr,sc));
		int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		while(!qu.empty()){
			int cr = qu.front().first;
			int cc = qu.front().second;
			qu.pop();
			for (int i = 0 ; i < 4 ; i++){
				int nr = cr + direct[i][0];
				int nc = cc + direct[i][1];
				if ( nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc]==color){
					image[nr][nc] = newColor;
					qu.push(make_pair(nr,nc));
				}
			}
		}
		return image;
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
