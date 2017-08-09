#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
  	vector<vector<int>> sparseM(vector<vector<int>>& A, vector<vector<int>>& B){
		vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
		vector<vector<int>> apos(A.size());
		vector<vector<int>> bpos(B[0].size());
		int i,j;
		for (i = 0 ; i < A.size() ; i++){
			for (j = 0 ; j < A[0].size() ; j++){
				if (A[i][j]!=0){
					apos[i].push_back(j);
				}
			}
		}
		for (j = 0 ; j < B[0].size() ; j++){
			for (i = 0 ; i < B.size() ; i++){
				if (B[i][j]!=0){
					bpos[j].push_back(i);
				}
			}
		}
	
		for (i = 0 ; i < ans.size() ; i++){
			for(j = 0 ; j < ans[0].size() ; j++){
				vector<int> aa = apos[i];
				vector<int> bb = bpos[j];
				int sum = 0;
				for (int a = 0 ; a < aa.size() ; a++){
					for (int b = 0 ; b < bb.size() ; b++){
						if (aa[a]==bb[b]){
//							cout << i <<":"<<j <<"=" << A[i][aa[a]] <<"*"<<B[bb[b]][j]<<endl;
							sum += A[i][aa[a]] * B[bb[b]][j];
						}
					}
				}
				ans[i][j] = sum;
			}
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> A = {{1,0,0},
	                         {-1,0,3}
					};
	vector<vector<int>> B = {
				{7,0,9},
				{0,0,0},
				{0,0,1},
				};
	Solution sol;
	vector<vector<int>> ret_vec;
	ret_vec = sol.sparseM(A,B);

	for (vector<int> row : ret_vec){
		for (int it : row){
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
