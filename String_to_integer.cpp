class Solution {
public:
	int myAtoi(string str) {
		int len = str.length();
		if (len == 0) {
			return 0;
		}
		long int ans = 0;
		bool valid = false;
		int sign = 1;
		int idx = 0;
		while (idx < len && str[idx] == ' ') {
			++idx;
		}
		if (idx < len && str[idx] == '-') {
			sign = -1;
			++idx;
		}
		else if (idx < len && str[idx] == '+') {
			sign = 1;
			++idx;
		}
		while (idx < len && str[idx] >= '0' && str[idx] <= '9') {
			valid = true;
			ans = ans * 10 + str[idx] - '0';
			if(sign * ans > INT_MAX){
			    return INT_MAX;
			}else if(sign * ans < INT_MIN){
			    return INT_MIN;
			}
			++idx;
		}
		if (valid) {
			return static_cast<int>(sign * ans);
		}
		return 0;
	}
};