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
    ListNode* findkthnode(ListNode* temp, int k)
    {
        k--;

        while(temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while(temp != NULL)
        {
            ListNode* kthnode = findkthnode(temp, k);

            if(kthnode == NULL)
            {
                if(prevlast)
                {
                    prevlast->next = temp;
                }
                break;
            }

            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;

            ListNode* prev = NULL;
            ListNode* curr = temp;

            while(curr != NULL)
            {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if(head == temp)
            {
                head = kthnode;
            }
            else
            {
                prevlast->next = kthnode;
            }

            prevlast = temp;
            temp = nextnode;
        }

        return head;
    }
};
