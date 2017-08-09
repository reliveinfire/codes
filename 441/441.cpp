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
	int arrangeCoins(int n){
		int prev = 1;
		int i = 2;
		long curr;
		long tmp = n;
		
		if (n==0)
			return 0;
		while (true) {
			if (i > 2*tmp/i - 1 )
				return i-1;
			i++;
		}
	}
};

int main()
{
	int ret;
	Solution sol;
	cout << sol.arrangeCoins(5) << "\n";
	cout << sol.arrangeCoins(8) << "\n";
	cout << sol.arrangeCoins(1804289383) << "\n";

	return 0;
}
