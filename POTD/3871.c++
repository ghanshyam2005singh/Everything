class solution{
    public:
    long long countCommas(long long){
        long long ans=0;
        long long start=1000;
        long long count=1;
        while(start<=n){
            long long count=min(n-start+1, start*1000-start);
            ans+=count*commas;
            if(start>n/1000) break;
            start*=1000;
            commas++;
        }
        return ans;
    }
}