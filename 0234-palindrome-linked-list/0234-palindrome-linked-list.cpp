/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans1;
        vector<int>ans2;
        while(temp!=nullptr && head!=nullptr){
            ans1.push_back(temp->val);
            ans2.push_back(head->val);
            temp=temp->next;
            head=head->next;
        }
        reverse(ans1.begin(),ans1.end());
        if(ans1==ans2){
            return true;
        }
        return false;
    }
};