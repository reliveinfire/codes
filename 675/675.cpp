#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int cutOffTree(vector<vector<int>>& forest){
		vector<int> target;
		int res = 0;
		for (int i = 0 ; i < forest.size() ; i++){
			for (int j = 0 ; j < forest[0].size() ; j++){
				if (forest[i][j]>1)
					target.push_back(forest[i][j]);
			}
		}
		sort(target.begin(), target.end());
		int idx = 0;
		int row = 0, col = 0;
		if (forest[0][0]==target[idx])
			idx++;
		while (true){
			pair<int,int> ret = bfs(forest, target[idx], row, col, res);
			if (ret.first<0)
				return -1;
			row = ret.first;
			col = ret.second;
			idx++;
			if (idx==target.size())
				break;
		}
		return res;
        }
	pair<int,int> bfs(vector<vector<int>>& forest, int target, int sr, int sc, int& res){
		vector<vector<int>> dist(forest.size(), vector<int>(forest[0].size(), INT_MAX));
		queue<pair<int,int>> qu;
		qu.push(pair<int,int>(sr,sc));
		dist[sr][sc] = 0;
		int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		while(!qu.empty()){
			pair<int,int> cur = qu.front();
			qu.pop();
			int cr = cur.first;
			int cc = cur.second;
			for (int i = 0 ; i < 4 ; i++){
				int nr = cr + direct[i][0];
				int nc = cc + direct[i][1];
				if (nr >= 0 && nr < forest.size() && nc >= 0 && nc < forest[0].size() && forest[nr][nc]>0){
					if (dist[cr][cc]+1 < dist[nr][nc]){
						dist[nr][nc] = dist[cr][cc] + 1;
						qu.push(pair<int,int>(nr,nc));
						if (forest[nr][nc]==target){
							res += dist[nr][nc];
							return pair<int,int>(nr,nc);
						}
					}
				}
			}
				
		}
		return pair<int,int>(-1,-1);
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> A = { {2,3,4},
			 	  {0,0,5},
				  {6,7,8} };
	Solution sol;
	int ret;
	ret = sol.cutOffTree(A);
	cout << ret << "\n";
	return 0;
}
