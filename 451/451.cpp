#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
bool mycompare(const pair<string,int>& a, const pair<string,int>& b)
{
	if (a.second > b.second)
		return true;
	else
		return false;
}
class Solution {
	public:
	string frequencySort(string s){
		int size = s.size();
		string result;
		if (size == 0)
			return result; 
		vector<int> counts(256,0);
		vector< pair<string,int> > table;
		for (int i = 0 ; i < size ; i++)
			counts[s[i]]++;
		for (int i = 0 ; i < 256 ; i++){
			if (counts[i]!= 0){
				stringstream ss;
				ss << (char)i;
				pair<string,int> pa(ss.str(),counts[i]);
				table.push_back(pa);
				ss.clear();
			}
		}
 		sort(table.begin(), table.end(), mycompare);

		for (int i = 0 ; i < table.size() ; i++){
			for (int j = 0 ; j < table[i].second ; j++){
				result += table[i].first;
			}
		}
		return result;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	genVector(da, A);
	string aa("tree");
	string bb("Aabb");
	string cc("cccaaa");
	Solution sol;
	cout << sol.frequencySort(aa) << endl;
	cout << sol.frequencySort(bb) << endl;
	cout << sol.frequencySort(cc) << endl;

	return 0;
}
