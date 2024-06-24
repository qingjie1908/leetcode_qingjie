/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

 

示例 1：



输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：



输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：



输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。
 

注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

 

相关标签

C++



作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/7fw58c/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

#include <unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto curr = head;
        Node* newhead = new Node(0);
        auto newcurr = newhead;

        std::unordered_map<Node*, Node*> list_map = {{head, newhead}}; //key type Node* does not have strict weak order rule

        while(curr != nullptr){ //first copy next order part
            newcurr->val = curr->val;
            if(curr->next != nullptr){
                newcurr->next = new Node ((*(curr->next)).val);
            } else { newcurr->next = nullptr;}
            
            curr = curr->next;
            newcurr = newcurr->next;

            list_map.insert({curr, newcurr}); 

        }

        //now map store Node* 
        //{{old_1, new_1}, {old_2, new_2}, {old_3, new_3}};
        //if old_1->random is old_3;
        //then new_1->random should be new_3, which is accessed from unordered_map list_map[old_3], where old_3 is the key

        //sweep again for random
        curr = head;
        newcurr = newhead;
        while(curr != nullptr){

            if (curr->random != nullptr){
                auto key_oldrandom = curr->random;
                newcurr->random = list_map[key_oldrandom];
            } else {
                newcurr->random = nullptr;
            }

            curr = curr->next;
            newcurr = newcurr->next;

        }

        return newhead;
    }
};