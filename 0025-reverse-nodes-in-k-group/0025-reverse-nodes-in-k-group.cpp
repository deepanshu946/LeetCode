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
private:
    pair<ListNode*, ListNode*> reversek(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = curr;
        while (k--) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return make_pair(prev, curr);
    }
    bool check(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            if (count == k) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead = NULL;
        ListNode* temp = head;
        ListNode* link = NULL;
        while (temp != NULL) {
            pair<ListNode*, ListNode*> p;

            if (check(temp, k)) {
                p = reversek(temp, k);
            } else {
                break;
            }

            if (link != NULL) {
                link->next = p.first;
            }
            link = temp;

            if (newhead == NULL) {
                newhead = p.first;
            }

            temp = p.second;
        }

        if (link != NULL && temp != NULL) {
            link->next = temp;
        }

        return newhead;
    }
};