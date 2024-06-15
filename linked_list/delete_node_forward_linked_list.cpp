/*

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7fmls1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        auto curr = head, prev = head;
        while(curr != nullptr){
            if(curr->val != val){
                prev = curr;
                curr = curr-> next;
            } else{
                if(prev != curr){
                    prev->next = curr->next;
                    curr->next = nullptr;
                    break;
                } else {
                    head = curr-> next;
                    curr->next = nullptr;
                    break;
                }
                
            }
        }

        return head;
    }
};