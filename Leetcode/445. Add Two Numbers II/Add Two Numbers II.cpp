// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.
 

// Follow up: Could you solve it without reversing the input lists?

// Accepted
// 406.8K
// Submissions
// 672.4K
// Acceptance Rate
// 60.5%

//Approach-1 (Reverse the LinkedList)
class Solution {
public:
    
    ListNode* reverseLL(ListNode* head) {
        
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};


//Approach-2 (Using Stack) - What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry    = sum / 10;
            
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};