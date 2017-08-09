#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>

using namespace std;
class Solution {
	public:
	string str[10];
	int table[26];
	int result[10];
	int isDone;
	string answer;
	string originalDigits(string s){
		int maxDigit = s.size() / 3;
		answer.clear();
		str[0] = string("zero");
		str[1] = string("one");
		str[2] = string("two");
		str[3] = string("three");
		str[4] = string("four");
		str[5] = string("five");
		str[6] = string("six");
		str[7] = string("seven");
		str[8] = string("eight");
		str[9] = string("nine");
		isDone = 0;
		for (int i = 0 ; i < 26 ; i++) {
			table[i] = 0;
		}
		
		for (int i = 0 ; i < 10 ; i++) {
			result[i] = 0;
		}

		for (int i = 0 ; i < 10 ; i++){
			for (int j = 0 ; j < str[i].size() ; j++)
				table[str[i][j] - 'a']++;
		}
		for (int i = 0 ; i < 26 ; i++)
			cout << " " << table[i];
		cout << "\n";

		
		for (int i = 0 ; i < s.size() ; i++)
			table[s[i] - 'a']++;
		
		// for z (zero, 0)
		int count = table['z' - 'a'];
		for (int i = 0 ; i < count ; i++){
			result[0]++;
			removeString(str[0]);
		}
		
		// for x (six,6)
		count = table['x' - 'a'];
		for (int i = 0 ; i < count ; i++){
			result[6]++;
			removeString(str[6]);
		}
		
		// for w (two,2)
		count = table['w' - 'a'];
		for (int i = 0 ; i < count ; i++){
			result[2]++;
			removeString(str[2]);
		}
		
		// for g (eight, 8)
		count = table['g' - 'a'];
		for (int i = 0 ; i < count ; i++){
			result[8]++;
			removeString(str[8]);
		}
		
		// for u (eight, 4)
		count = table['u' - 'a'];
		for (int i = 0 ; i < count ; i++){
			result[4]++;
			removeString(str[4]);
		}
		helper(s);
		return answer;
	}

	void removeString(string tmp){
		for(int i = 0 ; i < tmp.size() ; i++){
			table[tmp[i] - 'a']--;
		}
	}

	void helper(string s) {
		if (isDone)
			return;

		if (checkAllzero()) {
			isDone = 1;
			for (int i = 0 ; i < 10 ; i++){
				for(int j = 0 ; j < result[i] ; j++){
					stringstream ss;
					ss << i;
					answer += ss.str();
				}
			}
			return;
		}

		if (checkFail()){
			return;	
		}
		for (int i = 0 ; i < 10; i++){
			if (i==0 || i == 2 || i ==4 ||
			    i==6 || i == 8)
			    	continue;
			for (int j = 0 ; j < str[i].size();j++){
				table[str[i][j] - 'a']--;
			}
//			cout << "pick:" << i << "\n";
			result[i]++;
			helper(s);
//			cout << "put:" << i  << "\n";
			for (int j = 0 ; j < str[i].size();j++){
				table[str[i][j] - 'a']++;
			}
			result[i]--;
		}
		return;
	}

	bool checkAllzero(){
		for (int i = 0 ; i < 26 ; i++){
			if (table[i]!=0)
				return false;
		}
		return true;
	}

	bool checkFail(){
		for (int i = 0 ; i < 26 ; i++){
			if (table[i] < 0)
				return true;
		}
		return false;
	}
};

int main()
{
	int ret;
	int test[] = {1,2,3};
	string A("eenrozo"); //01
	string B("fviefuro"); //45
	string C("owoztneoer"); //012
	string D("nnei"); //9
	string E("zerozero"); //00

	Solution sol;
	cout << sol.originalDigits(A) << "\n";
	cout << sol.originalDigits(B) << "\n";
	cout << sol.originalDigits(C) << "\n";
	cout << sol.originalDigits(D) << "\n";
	cout << sol.originalDigits(E) << "\n";

	return 0;
}
