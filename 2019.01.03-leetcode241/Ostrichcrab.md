```
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                auto result1 = diffWaysToCompute(input.substr(0,i));
                auto result2 = diffWaysToCompute(input.substr(i+1));
                for(int r1 : result1){
                    for(int r2 : result2){
                        if(c=='+') result.push_back(r1+r2);
                        else if(c=='-') result.push_back(r1-r2);
                        else result.push_back(r1*r2);
                    }
                }
            }
        }
        if(result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};
```
