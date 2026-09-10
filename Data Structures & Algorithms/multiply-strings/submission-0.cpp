class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.length();
        int n = num2.length();
        vector<int> res(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                int product = (num1[i] - '0') * (num2[j] - '0');
                
                int sum = product + res[i + j + 1];
                
                res[i + j + 1] = sum % 10;
                
                res[i + j] += sum / 10;
            }
        }
        
        string result = "";
        int start = 0;
        
        while (start < res.size() && res[start] == 0) {
            start++;
        }
        
        while (start < res.size()) {
            result.push_back(res[start] + '0'); 
            start++;
        }
        
        return result;
    }
};