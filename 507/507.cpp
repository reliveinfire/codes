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
	bool checkPerfectNumber(int num){
		vector<int> div;
		int sum = 0;
		div.push_back(1);
		if (num == 1)
			return false;
		for (int i = 2 ; i*i <= num ;i++){
			if (num%i == 0){
			     j = num/i;
			     div.push_back(i);
			     div.push_back(j);
			}
		}
		for (int i = 0 ; i < div.size() ; i++){
			sum += div[i];
		}

		if (num == sum)
			return true;
		else
			return false;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	Solution sol;
	ret = sol.checkPerfectNumber(28);
	cout << ret << "\n";

	return 0;
}
