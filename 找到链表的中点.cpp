
//链表内找中点
//如果是 1 2 3 4 5 6     3 和 4都可以是中点 但是取第二个为中点
// 如果是 1 2 3 4 5     取三为中点
//这里的算法是快慢指针  快指针一次走两步 慢指针一次走一步
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr)//循环结束条件 fast如果已经走到了尾部 或者已经是nullptr 则结束不管
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}
//单指针解法 计算出链表长度 然后再单只真遍历
//如果是 1 2 3 4 5 6     3 和 4都可以是中点 但是取第二个为中点
// 如果是 1 2 3 4 5     取三为中点
ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
        ++n;
        cur = cur->next;
    }//得到链表长度 n
    int k = 0; //k从0出发
    cur = head;//cur从head出发  这说明循环结束的时候 指向的是第 k+1个节点
               //1 2 3 4 5 n = 5/2 = 2 k 从0出发动两次 k==2的时候 cur也动两次到了第三个节点
                //1 2 3 4 5 6 n = 6/2 = 3 k 从0出发动两次 k==3的时候 cur也动三次到了第四个节点
    while (k < n / 2) {
        ++k;
        cur = cur->next;
    }
    return cur;
}
