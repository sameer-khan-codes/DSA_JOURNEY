class Solution {
public:
    void findcombination(int idx,int k,int target,vector<vector<int>> &ans,vector<int> &ds)
    {
    if(k==0)
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return ;
    }
    for(int i=idx;i<=9;i++)
    {
        if(i>target)
        {
            break;
        }
        ds.push_back(i);
        findcombination(i+1,k-1,target-i,ans,ds);
        ds.pop_back();
    }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(1,k,n,ans,ds);
        return ans;
        
    }
};