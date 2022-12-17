class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        int a, b;
        for(auto& token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                if(token == "+")
                    s.push(a+b);
                else if(token == "-")
                    s.push(b-a);
                else if(token == "*")
                    s.push((long)a*b);
                else if(token == "/")
                    s.push(b/a);
            } else
                s.push(stoi(token));
        }

        return s.top();
    }
};