class Solution {
    public:
    int pairSum(ListNode* head){
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int ans=0;
        int i=0;
        int j=v.size()-1;
        while(i<j){
            ans=max(ans,v[i]+v[j]);
            i++;
            j--;
        }
        return ans;
    }
}