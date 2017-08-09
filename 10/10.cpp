#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	bool isMatch(string s, string p){
		vector< vector<int> > dp(s.size(), vector<int>(p.size));
		
		return helper(s,p, s.size()-1, p.size()-1);
	}

	bool helper(string s, string p, int m, int n)
	{
		//cout << m << ":" << n << endl;
		if (m < 0 && n < 0)
			return true;
		if (m<0){
			while(n>0){
				if (p[n]=='*'){
					n = n-2;
				} else 
					return false;	
			}
			if (n<0)
				return true;
			else
				return false;
		}

		if (n < 0){
			if (m>0)
				return false;
		}
		
		if (s[m] == p[n])
			return helper(s,p,m-1,n-1);
		else {
			if (p[n]=='*'){
				n--;
				if (s[m] == p[n]){
					// the .* may be empty!
					return helper(s,p,m-1,n+1) || helper(s,p,m-1,n-1) || helper(s,p,m,n-1);
				} else if (p[n] == '.'){
					// the .* may be empty!
					return helper(s,p,m-1,n+1) || helper(s,p,m-1,n-1) || helper(s,p,m,n-1);
				} else {
					return helper(s,p,m,n-1);
				}
			
			} else if (p[n] == '.'){
				return helper(s,p,m-1,n-1);
			} else 
				return false;
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
//	string sa("abbbaccbcc");
//	string sb("b*a*a.*");
//	string sa("ba");
//	string sb("..b*a*");
	string sa("baabbbaccbcc");
	string sb("..b*a*a.*");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	bool ret;
	ret = sol.isMatch(sa,sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
