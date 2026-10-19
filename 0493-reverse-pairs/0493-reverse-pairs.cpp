class Solution {
public:
    int reversePairs(vector<int>& nums ,int f,int mid,int l) {
        int an=mid-f+1;
        int bn=l-mid;
        vector<int> a(an),b(bn);
        for(int i=0;i<an;i++)
        {
            a[i]=nums[f+i];
        }
        for(int j=0;j<bn;j++)
        {
            b[j]=nums[mid+1+j];
        }
        long long count =0;
        int j=0;
        for(int i=0;i<an;i++)
        {
            while(j<bn &&
            (long long )a[i]>2LL*b[j])
            {
                j++;
            }
            count+=j;
        }
        int i=0;
        j=0;
        int k=f;
       
        while(i<an && j<bn)
        {
            if(a[i]<=b[j])
            {
                nums[k++]=a[i++];
            }
            else
            {
                nums[k++]=b[j++];
            }
        }
            while(i<an)
            {
                nums[k++]=a[i++];
            }
            while(j<bn)
            {
                nums[k++]=b[j++];
            }
            return count;
    }
        
        long long  mergesort(vector<int> & nums ,int f,int l)
        {
        
            if(f>=l)
            {
                return 0 ;
            }
            int mid=f+(l-f)/2;
            long long count =0;
            count+=mergesort(nums,f,mid);
            count+=mergesort(nums,mid+1,l);
            count+=reversePairs(nums,f,mid,l);
            return count;
        }
        int reversePairs(vector<int> & nums)
        {
            return (int)mergesort(nums,0,(int)nums.size()-1);
        }

        
    
};