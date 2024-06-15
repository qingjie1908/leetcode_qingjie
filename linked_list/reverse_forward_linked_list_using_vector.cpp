/*
书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。

 

示例 1：

输入：head = [3,6,4,1]

输出：[1,4,6,3]
 

提示：

0 <= 链表长度 <= 10000

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7fpt1m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<int> reverseBookList(ListNode* head) {
        auto curr = head;
        std::vector<int> vec;
        auto iter = vec.begin();
        while(curr != nullptr){
            iter = vec.insert(iter, curr->val);
            curr = curr->next;
        }
        return vec;
    }
};