class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;

        for(int i=0; i<tokens.size(); i++) {
            int len = tokens[i].length();
            if(tokens[i][len-1] >= '0' && tokens[i][len-1] <='9') {
                stk.push(stoi(tokens[i]));
            } else {
                long long n1 = stk.top();
                stk.pop();
                long long n2 = stk.top();
                stk.pop();

                if(tokens[i] == "+") stk.push(n2 + n1);
                else if(tokens[i] == "-") stk.push(n2 - n1);
                else if(tokens[i] == "*") stk.push(n2 * n1);
                else if(tokens[i] == "/") stk.push(n2 / n1);
            }
        }

        return stk.top();
    }
};