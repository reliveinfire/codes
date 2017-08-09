#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
		map<int,int> ab;
		int count = 0;

		for (int i = 0 ; i < A.size() ; i++){
			for(int j = 0 ; j < B.size() ; j++){
				int target = A[i] + B[j];
				int tmp;
				map<int,int>::iterator index;
				index = ab.find(target);
				if (index != ab.end()){
					tmp = index->second;
					ab.erase(index);
					tmp++;
					ab[target] = tmp;
				} else {				
					ab[target] = 1;
				}
			}
		}
		
		for (int i = 0 ; i < C.size() ; i++){
			for(int j = 0 ; j < D.size() ; j++){
				int target = 0 - (C[i] + D[j]);
				map<int,int>::iterator iter;
				iter = ab.find(target);
				if ( iter != ab.end())
					count+= iter->second;
			}
		}

		return count;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	int A[] = {-1,-1};
	int B[] = {-1, 1};
	int C[] = {-1, 1};
	int D[] = { 1,-1};
	genVector(da,A);
	genVector(db,B);
	genVector(dc,C);
	genVector(dd,D);
	Solution sol;
	ret = sol.fourSumCount(da,db,dc,dd);
	cout << ret << "\n";

	return 0;
}
