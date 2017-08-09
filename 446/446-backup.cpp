#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Status
{	
	public:
		int cout;
		int length;
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	if (A.size() < 3)
		return 0;
    	vector< map<long,int> > dp(A.size()); //diff,length
	vector< map<int,int>>   lens(A.size());//length, count
	int ans = 0;
	for (int i = 1 ; i < A.size(); i++){
		for(int j = 0 ; j < i ; j++){
			long diff = (long)A[i] - (long)A[j];
			if (dp[j].find(diff)!=dp[j].end()){
				dp[i][diff] = dp[j][diff]+1;
			} else{
				dp[i][diff] = 2;
			}
			int len = dp[i][diff];
			if (i==3)
				cout << " dif:" << diff;
				cout << " len:" << len <<endl;
			if (lens[i].find(len) != lens[i].end()){
				if (i==3)
					cout << "here\n";
				lens[i][len]++;
			} else {
				if (lens[j][len-1]){
					lens[i][len] = lens[j][len-1];
				} else {
						lens[i][len]=1;
				};
			}
		}
	}
	for (int i = 0 ; i < A.size() ; i++){
		for (map<long,int>::iterator iter = dp[i].begin();
			iter != dp[i].end() ; iter++)
		{
			int nums = lens[i][iter->second];
			int len = iter->second - 2;
			cout << i <<" diff:" <<iter->first<< " len:" << len+2 <<" count:"<<nums<<endl;
			if (len >0){
				ans = ans+ (nums * len);
			}
		}
	}
	for (int i = 0 ; i < A.size() ; i++)
		cout <<" " << dp[i][1];
	cout << endl;
	
	for (int i = 0 ; i < A.size() ; i++)
		cout <<" " << lens[i][1];
	cout << endl;
	
	for (int i = 0 ; i < A.size() ; i++)
		cout <<" " << dp[i][2];
	cout << endl;
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
	
	int D[] = {1,2,3,4,5,6};
	genVector(dd, D);
	Solution sol;
	cout << sol.numberOfArithmeticSlices(dd) << endl;
//	cout << sol.numberOfArithmeticSlices(db) << endl;
//	cout << sol.numberOfArithmeticSlices(dc) << endl;

	return 0;
}
