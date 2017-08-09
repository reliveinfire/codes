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
	vector<int> constructRectangle(int area){

		int x=1;
		vector<int> ret;
		while((x)*(x) < area){
			x++;
		}
		int y;
		for ( ; x <= area ; x++){
			if (area % x == 0){
				y = area / x;			
				break;
			}
		}
		ret.push_back(x);
		ret.push_back(y);
		return ret;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret= sol.constructRectangle(1);
	cout << ret[0] << "," << ret[1];
	return 0;
}
