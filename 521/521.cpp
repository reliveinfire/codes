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
	int findLUSlength(string a, string b){
		if (a.size() > b.size())
			return a.size();
		if (a.size() < b.size())
			return b.size();
		for (int i = 0 ; i < a.size() ; i++){
			if (a[i]!=b[i])
				return a.size();
		}
		
		return -1;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("horbxeemlgqpqbujbdagizcfairalg");
	string sb("iwvtgyojrfhyzgyzeikqagpfjoaeen");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret = sol.findLUSlength(sa,sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
