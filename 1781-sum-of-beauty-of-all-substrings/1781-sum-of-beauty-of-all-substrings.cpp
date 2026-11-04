class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
           int freq[26]={0};
            int maxfreq=0;
            for(int j=i;j<n;j++)
            {
                int index = s[j]-'a';
                freq[index]++;
                maxfreq=max(maxfreq,freq[index]);
                int minfreq=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]>0)
                    {
                        minfreq=min(minfreq,freq[k]);
                    }
                }
                ans+=maxfreq-minfreq;
            }

        }
        return ans;
        
    }
};