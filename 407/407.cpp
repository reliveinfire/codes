#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	private:
		struct Element{
			int row;int col;int val;
			Element(int r, int c, int v){row = r;col = c;val = v;}
		};
        public:
        int trapRainWater(vector<vector<int>>& hm){
		if (hm.empty())
			return 0;
		int m = hm.size();
		int n = hm[0].size();
		vector<vector<int>> high(m, vector<int>(n, INT_MAX));
		vector<vector<int>> visit(m, vector<int>(n));
		queue<Element> qu;
		for (int i = 0 ; i < m ; i++){
			qu.push(Element(i,0, hm[i][0]));
			visit[i][0] = 1;
			qu.push(Element(i,n-1, hm[i][n-1]));
			visit[i][n-1] = 1;
		}
		for (int j = 1 ; j < n-1 ; j++ ){
			qu.push(Element(0,j, hm[0][j]));
			visit[0][j] = 1;
			qu.push(Element(m-1,j, hm[m-1][j]));
			visit[m-1][j] = 1;
		}
		int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		while(!qu.empty()){
			Element cur = qu.front();
			qu.pop();
			for (int i = 0 ; i < 4 ; i++){
				int nr = cur.row + direct[i][0];
				int nc = cur.col + direct[i][1];
				if (nr>=0 && nr < m && nc >= 0 && nc < n && !visit[nr][nc]){
					if (cur.val < high[nr][nc]){
						high[nr][nc] = cur.val;
						qu.push(Element(nr,nc, max(cur.val, hm[nr][nc])));
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				if (high[i][j]!=INT_MAX){
					//cout << i<<":"<<j<<endl;
					//cout << high[i][j] << endl;
					if (high[i][j] - hm[i][j] > 0)
						ans += high[i][j] - hm[i][j];
				}
			}
		}
		return ans;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
#if 1
	vector<vector<int>> A = { {12, 13,  1, 12},
			   	  {13,  4, 13, 12},
				  {13,  8, 10, 12},
				  {12, 13, 12, 12},
				  {13, 13, 13, 13} 
				  };
#else
	vector<vector<int>> A = { {2,3,4},
			   	  {5,6,7},
				  {8,9,10}
				  };
#endif
	int ret;
	Solution sol;
	ret = sol.trapRainWater(A);
	cout << ret << "\n";

	return 0;
}
