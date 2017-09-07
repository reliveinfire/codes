#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string solveEquation(string sent){
		int invert = 0;
		int xv = 0, cv = 0, num = 0;
		string op("+");
		for (int i = 0 ; i < sent.size() ; i++){
			if (sent[i]>= '0' && sent[i] <='9'){
				num = num* 10 + sent[i] - '0';
			} else if (sent[i] == 'x'){
				if (i== 0 || sent[i-1]=='+' || sent[i-1]=='-' || sent[i-1]=='=')
					num = 1;
				if ((!invert && op == "+") || (invert && op=="-"))
					xv += num;
				else 
					xv -= num;	
				num = 0;
			} else {
				if ((!invert && op == "+") || (invert && op=="-"))
					cv += num;
				else 
					cv -= num;	
				num = 0;
				if (sent[i] == '='){
					invert = 1;
					op = "+";
				}
				else if (sent[i] == '+')
					op = "+";
				else if (sent[i] == '-')
					op = "-";
			}
			if (i == sent.size() - 1 && sent[i]!='x'){
				if ((!invert && op == "+") || (invert && op=="-"))
					cv += num;
				else 
					cv -= num;	

			}
		}
		cout << xv <<":" << cv << endl;
		if (xv == 0 && cv == 0)
			return "Infinite solutions";
		else if (xv==0)
			return "No solution";
		else if (cv==0)
			return "x=0";
		else {
			string ans("x=");
			string ret = to_string(-cv/xv);
			return ans + ret;
		}
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	string ret;
	//ret = sol.solveEquation("x+5-3+x=6+x-2");
	ret = sol.solveEquation("0x=0");
	cout << ret << "\n";


	return 0;
}
