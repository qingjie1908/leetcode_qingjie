/*
给定一个头节点为 head 的单链表用于记录一系列核心肌群训练编号，请将该系列训练编号 倒序 记录于链表并返回。

 

示例 1：

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
 

示例 2：

输入：head = [1,2]
输出：[2,1]
 

示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/

 

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7fadz7/
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
    ListNode* trainningPlan(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        auto curr = head->next;
        auto prev = head;
        prev->next = nullptr;

        while(curr != nullptr){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};