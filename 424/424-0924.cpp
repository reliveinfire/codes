#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int characterReplacement(string s, int k){
		char mm[26] = {0};
		int j = 0;
		int ans = 0;
		for (int i = 0 ; i < s.size() ; i++){
			mm[s[i]-'A']++;
			while(true){
				int lmax = 0;
				int total = 0;
				for (int k = 0 ; k < 26 ; k++){
					total += mm[k];
					lmax = max(lmax, mm[k]);
				}
				if(lmax + k >= total){
					ans = max(ans, i-j+1);
					break;
				} else {
					mm[s[j]-'A']--;
					j++;
				}
			}
		}
		return ans;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
