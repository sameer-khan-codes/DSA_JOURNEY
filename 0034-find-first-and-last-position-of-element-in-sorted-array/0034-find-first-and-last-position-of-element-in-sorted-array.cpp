class Solution {
public:
int firstoccurrence(vector<int> &nums,int  target)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
        {
        first=mid;
            high=mid-1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return first;
    

}
int lastoccurrence(vector<int> & nums,int target)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
        {
         last=mid;
         low=mid+1;

        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return last;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstoccurrence(nums,target);
        int last =lastoccurrence(nums,target);
        if(first==-1)
        {
            return {-1,-1};
        }
        return { first ,last};
    }
};