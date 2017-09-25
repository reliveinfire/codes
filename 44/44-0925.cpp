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
		return helper(s, p, 0, 0);
	}

	bool helper(string s, string p, int i, int j){
		if (j==p.size() - 1 && p[j]=='*')
			return true;
		while(i < s.size() && j < p.size()){
			if (s[i]==p[j] || p[j]=='?'){
				i++;
				j++;
			} else if (p[j]=='*'){
				for(int k = 0 ; i+k <=s.size() ; k++ ){
// "aa" "*", 的case 會pass, 因為會檢查到後面的i==s.size(), j == p.size();
					bool ret = helper(s,p,i+k,j+1);
					if (ret)
						return true;
				}
				break;
			} else {
				return false;
			}
		}
		if (i==s.size() && j==p.size())
			return true;
		if (i==s.size()){
			while(j<p.size()){
				if (p[j]!='*')
					return false;
				j++;
			}
			return true;
		}
		return false;
	}

};
class Solution2 {
        public:
        bool isMatch(string s, string p){
                int i = 0, j = 0;
                int pp = -1;
                int ss = -1;
                while(i < s.size()){
// 有bug, j 會超過array
                        if (s[i] == p[j]){
                                i++;
                                j++;
                        } else if (p[j]=='?'){
                                i++;
                                j++;
                        } else if (p[j]=='*'){
                                pp = j;
                                ss = i;
                                j++;
                        } else if (pp >= 0){
                                j = pp+1;
                                ss++;
                                i = ss;
                        } else
                                return false;
                }
                for (; j < p.size() ; j++){
                        if (p[j]!='*')
                                return false;
                }
                return true;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
//	string sa("aab");
//	string sb("c*a*b");
	string sa("aa");
	string sb("*");
	Solution2 sol;
	bool ret;
	ret = sol.isMatch(sa,sb);
	cout << ret << "\n";


	return 0;
}
