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
	string licenseKeyFormatting(string S, int K){
		for (int i = 0 ; i < S.size() ; i++){
			if (S[i] == '-') {
				S.erase(i,1);
				i--;
			}
			if (S[i] >= 'a' && S[i] <= 'z'){
				S[i] = S[i] + 'A' - 'a';

			}
		}
		cout << S << endl;
		int size = S.size();
		int pos = size % K;
		while (pos < S.size()){
			if (pos!=0){
				S.insert(pos, string("-"));
				pos++;
			}
			pos = pos + K;
		}
		return S;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	genVector(da, A);
	string aa("2-4a0r7--4k");
	int k = 3;
	Solution sol;
	cout << sol.licenseKeyFormatting(aa,k) << "\n";

	return 0;
}
