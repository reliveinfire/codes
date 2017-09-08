#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix){
		vector<vector<int>> count(matrix.size(), vector<int>(matrix[0].size(),0));
		queue<pair<int,int>> qu;
		vector<pair<int,int>> res;
		cout << matrix.size() <<":" << matrix[0].size()<<endl;
		for (int i = 0 ; i < matrix.size() ; i++){
			qu.push(pair<int,int>(i,0));
		}
		for (int j = 0 ; j < matrix[0].size() ; j++){
			qu.push(pair<int,int>(0,j));
		}
		bfs(qu, count, matrix);
		for (int i = 0 ; i < matrix.size() ; i++){
			qu.push(pair<int,int>(i, matrix[0].size() - 1));
		}
		for (int j = 0 ; j < matrix[0].size() ; j++){
			qu.push(pair<int,int>(matrix.size()-1,j));
		}
		bfs(qu, count, matrix);
		for (int i = 0 ; i < matrix.size() ; i++){
			for (int j = 0 ; j < matrix[0].size() ; j++){
				if (count[i][j]==2)
					res.push_back(pair<int,int>(i,j));
			}
		}
		return res;
        }
	void bfs(queue<pair<int,int>>& qu, vector<vector<int>>& count, vector<vector<int>>& matrix){
		int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(),0));
		cout << qu.size() << endl;
		while(!qu.empty()){
			pair<int,int> cur = qu.front();
			qu.pop();
			if (visited[cur.first][cur.second])
				continue;
			visited[cur.first][cur.second] = true;
			count[cur.first][cur.second]++;
			for (int i = 0 ; i < 4 ; i++){
				int nr = cur.first + direct[i][0];
				int nc = cur.second + direct[i][1];
				if (nr >=0 && nr < matrix.size() && nc >=0 && nc < matrix[0].size() && !visited[nr][nc]){
					if (matrix[nr][nc] >= matrix[cur.first][cur.second])
						qu.push(pair<int,int>(nr,nc));
		
				}
			}
		}
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> C = {{11,3,2,4,14,6,13,18,1,4,12,2,4,1,16},{5,11,18,0,15,14,6,17,2,17,19,15,12,3,14},{10,2,5,13,11,11,13,19,11,17,14,18,14,3,11},{14,2,10,7,5,11,6,11,15,11,6,11,12,3,11},{13,1,16,15,8,2,16,10,9,9,10,14,7,15,13},{17,12,4,17,16,5,0,4,10,15,15,15,14,5,18},{9,13,18,4,14,6,7,8,5,5,6,16,13,7,2},{19,9,16,19,16,6,1,11,7,2,12,10,9,18,19},{19,5,19,10,7,18,6,10,7,12,14,8,4,11,16},{13,3,18,9,16,12,1,0,1,14,2,6,1,16,6},{14,1,12,16,7,15,9,19,14,4,16,6,11,15,7},{6,15,19,13,3,2,13,7,19,11,13,16,0,16,16},{1,5,9,7,12,9,2,18,6,12,1,8,1,10,19},{10,11,10,11,3,5,12,0,0,8,15,7,5,13,19},{8,1,17,18,3,6,8,15,0,9,8,8,12,5,18},{8,3,6,12,18,15,10,10,12,19,16,7,17,17,1},{12,13,6,4,12,18,18,9,4,9,13,11,5,3,14},{8,4,12,11,2,2,10,3,11,17,14,2,17,4,7},{8,0,14,0,13,17,11,0,16,13,15,17,4,8,3},{18,15,8,11,18,3,10,18,3,3,15,9,11,15,15}};
	Solution sol;
	int ret;
	sol.pacificAtlantic(C);
	return 0;
}
