#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
class Solution {
	public:
	int findCircleNum(vector< vector<int> >& M){
		int size = M.size();
		int circle = 0;
		bool *visited = new bool[size];
		queue<int> qu;
		for (int i = 0 ; i < size ; i++)
			visited[i] = false;

		for (int i = 0 ; i < size ; i++){
			if (!visited[i]){
				qu.push(i);
				while(!qu.empty()){
						int index = qu.front();
						qu.pop();
						visited[index]= true;
						for(int j = 0 ; j < size ; j++){
							if (M[index][j] && !visited[j]) {
								qu.push(j);
							}
					}
				}
				circle++;
			}
		}
		return circle;
	}
};

int main()
{
	int ret;
	int test[3][3] =  {
			{1,1,0},
			{1,1,1},
			{0,1,1}
				};
	vector< vector<int> > matrix;
	vector<int> row;
	for (int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			row.push_back(test[i][j]);
		 }
		matrix.push_back(row);
		row.clear();
	}
	Solution sol;
	cout << sol.findCircleNum(matrix) << "\n";

	return 0;
}
