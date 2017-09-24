#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> findPerm(string sign){
		vector<int> res;
		int cur = 1;
		int dcnt = 0;
		for (int i = 0 ; i < sign.size() ; i++){
			if (sign[i]=='D'){
				dcnt++;
				cur++;
			} else if (sign[i]=='I'){
				for (int j = 0 ; j < dcnt ; j++){
					res.push_back(cur--);
				}
				res.push_back(cur);
				cur = cur + dcnt + 1;
				dcnt = 0;
			}
		}
		for (int j = 0 ; j < dcnt ; j++)
			res.push_back(cur--);
		res.push_back(cur);
		return res;
        }
#if 0
	vector<int> findPerm2(string sign){
		vector<int> res;
		int cur = 1;
		for (int i = 0 ; i < sign.size() ; i++){
			if (sign[i]=='D'){
				int j = i;
				int cnt = 1;
				while(j <sign.size() && sign[j]=='D'){
					j++;
					cnt++;
				}
				if (res.empty())
					res.push_back(cur+cnt);
				for (k = 0; k <)	
			}
		}
	}
#endif
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	auto ret_vec = sol.findPerm("DDIIDD");
	//auto ret_vec = sol.findPerm("IDDDI");
	//auto ret_vec = sol.findPerm("IDDIDDDI");
	//auto ret_vec = sol.findPerm("DIII");

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
