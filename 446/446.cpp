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
    int numberOfArithmeticSlices(vector<int>& A) {
    	if (A.size() < 3)
		return 0;
    	vector< map<long,pair<int,int>>> dp(A.size()); //diff to length,count
	int ans = 0;
	for (int i = 1 ; i < A.size(); i++){
		for(int j = 0 ; j < i ; j++){
			long diff = (long)A[i] - (long)A[j];
			pair<int,int> tmp, pre;
			cout << j <<"," << i << endl;
			if (dp[j].find(diff)!=dp[j].end()){
					cout << "AAA\n";
				if (dp[i].find(diff)!=dp[i].end()){
					cout<< "NOT EMPTY  "<< dp[i][diff].first;
					cout<< "  "<< dp[i][diff].second << endl;
					cout<< "NOT EMPTY  "<< dp[j][diff].first;
					cout<< "  "<< dp[j][diff].second << endl;
				}
				//if (dp[i].find(diff)!=dp[i].end() && dp[i][diff].first == (dp[j][diff].first+1)){
				if (dp[i].find(diff)!=dp[i].end()){
					cout << "A 11111111111111\n";
					pre.second = dp[i][diff].second;
					pre.second++;
				}
				else{
					cout << "A 222222222222222\n";
					pre.second = dp[j][diff].second;
				}
				pre.first = dp[j][diff].first+1;
				cout << pre.first << endl;
				dp[i][diff] = pre;
			} else{
					cout << "BBB\n";
				tmp.first = 2;
				if (dp[i].find(diff)!=dp[i].end())
					tmp.second = dp[i][diff].second+1;
				else
					tmp.second = 1;
				dp[i][diff] = tmp;
				
			}
		}
	}
	for (int i = 0 ; i < A.size() ; i++){
		for (map<long,pair<int,int>>::iterator iter = dp[i].begin();
			iter != dp[i].end() ; iter++)
		{
			int len = iter->second.first - 2;
			if (len >0){
				ans = ans+ (len * iter->second.second);
			}
		}
	}
#if 1
	for (int i = 0 ; i < A.size() ; i++){
		cout << i << " ===\n";
		for (map<long,pair<int,int>>::iterator iter = dp[i].begin();
			iter != dp[i].end() ; iter++){
		cout << " diff:"  << iter->first;
		cout << " len:"  << iter->second.first;
		cout << " count:"  << iter->second.second <<endl;
		}
	}
	
#endif
	return ans;
        
    }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {2,4,6,8,10};
	genVector(da, A);
	
	int B[] = {2,2,3,4};
	genVector(db, B);
	
	int C[] = {-2147483648, 0, -2147483648};
	genVector(dc, C);
	
	int D[] = {1,1,1,1};
	genVector(dd, D);
	Solution sol;
//	cout << sol.numberOfArithmeticSlices(da) << endl;
//	cout << sol.numberOfArithmeticSlices(db) << endl;
	cout << sol.numberOfArithmeticSlices(dd) << endl;

	return 0;
}
