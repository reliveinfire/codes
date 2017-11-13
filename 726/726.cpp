#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string countOfAtoms(string formula){
		string res;
		auto tmp = helper(formula, 0, formula.size()-1);
		for(auto iter = tmp.begin() ; iter != tmp.end() ; iter++){
			if (iter->second>1)
				res += iter->first + to_string(iter->second);
			else
				res += iter->first;
		}
		return res;
        }
	map<string,int> helper(string formula, int left, int right){
		int idx = left;
		map<string,int> res;
		while(idx<=right){
			if (formula[idx]>='A' && formula[idx]<='Z'){
				string atom;
				atom += formula[idx++];
				while(idx<=right && formula[idx]>='a' && formula[idx]<='z'){
					atom += formula[idx++];
				}
				int count = 0;
				while(idx<=right && formula[idx]>='0' && formula[idx]<='9'){
					count = count*10 + formula[idx++]-'0';
				}
				if (count==0)
					res[atom]++;
				else
					res[atom] += count;
			} else if (formula[idx]=='('){
				int lp = 1;
				int start = idx;
				int end;
				while(lp > 0){
					idx++;
					if (formula[idx]=='(')
						lp++;
					else if (formula[idx]==')')
						lp--;
				}
				end = idx++;
				auto tmp = helper(formula, start+1, end-1);
				int count = 0;
				while(idx<=right && formula[idx]>='0' && formula[idx]<='9'){
					count = count*10 + formula[idx++]-'0';
				}
				if (count==0){
					count = 1;
				}
				for (auto iter = tmp.begin() ; iter != tmp.end() ; iter++){
					res[iter->first] += count * iter->second;
				}
			}
		}
		return res;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	//auto ret_vec = sol.countOfAtoms("Mg(OH)2");
	auto ret_vec = sol.countOfAtoms("K4(ON(SO3)2)2");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i];
	cout <<endl;

	return 0;
}
