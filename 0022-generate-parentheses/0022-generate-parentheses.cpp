class Solution {
public:
    void solve(vector<string>& ans,string s,int n ,int open,int close)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return ;
        }
        if(open<n)
        {
            s.push_back('(');
            solve(ans,s,n,open+1,close);
            s.pop_back();

        }
        if(close<open)
        {
            s.push_back(')');
            solve(ans,s,n,open,close+1);
            s.pop_back();
        }
        return ;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(ans,s,n,0,0);
        return  ans;
        
    }
};