class Solution {
public:
    int countstudent(vector<int> &arr,int pages)
    {
        int student=1;
        long long  studentpage=0;
        for(int i=0;i<arr.size();i++)
        {
            if(studentpage+arr[i]<=pages)
            {
                studentpage+=arr[i];
            }
            else
            {
                student++;
                studentpage=arr[i];
            }
        }
        return student;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(k>n)
        {
            return -1;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int student=countstudent(nums,mid);
            if(student>k)
            {
                low=mid+1;

            }
            else
            {
                high=mid-1;

            }
        }
        return low;
        
    }
};