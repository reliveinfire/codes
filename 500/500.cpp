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
	vector<string> findWords(vector<string>& words){
		vector<string> result;
		string row1("qwertyuiopQWERTYUIOP");
		string row2("asdfghjklASDFGHJKL");
		string row3("zxcvbnmZXCVBNM");

		vector< map<string,int> > vv;
		map<string, int> mm;

		for (int i = 0 ; i < row1.size(); i++){
			mm[row1.substr(i,1)] = 1;
		}
		vv.push_back(mm);
		mm.clear();
		for (int i = 0 ; i < row2.size(); i++){
			mm[row2.substr(i,1)] = 1;
		}
		vv.push_back(mm);
		mm.clear();
		for (int i = 0 ; i < row3.size(); i++){
			mm[row3.substr(i,1)] = 1;
		}
		vv.push_back(mm);
		mm.clear();

		for (int i = 0 ; i < words.size() ; i++){
			string tmp = words[i];
			int first = 0;
			bool same = true;
			for (int j = 0 ; j < vv.size() ; j++){
				mm = vv[j];
				if (mm.find(tmp.substr(0,1))!=mm.end()){
					first = j;
					break;
				}
			}
			cout << first << endl;
			for (int k = 0 ; k < tmp.size() ; k++){
				mm= vv[first];
				if (mm.find(tmp.substr(k,1)) == mm.end()){
					same = false;
					break;
				}
			}

			if (same)
				result.push_back(tmp);
		}
		return result;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("Hello");
	string sb("Alaska");
	string sc("Dad");
	string sd("Peace");
	vector<string> ss;
	ss.push_back(sa);
	ss.push_back(sb);
	ss.push_back(sc);
	ss.push_back(sd);
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret_vec = sol.findWords(ss);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
