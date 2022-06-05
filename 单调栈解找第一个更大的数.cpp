//单调栈求下一个更大的元素
//leetcode第 503 题  leeetcode 496题
/*
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
*/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    stack<int>st;
    vector<int>vec(size1);//vec的长度肯定还是跟num1一样长
    unordered_map<int, int>Map;//哈希表查表
    for (int i = size2 - 1; i >= 0; i--)//从nums2的尾巴开始遍历 一直找nums2中每个元素的下一个最大值 如果没有那就直接-1，
                                        //哈希表就是用来记录nums2中每个元素最大值
    {
        int num = nums2[i];
        while (!st.empty() && num >= st.top())//栈是用来逐一逐一从后往前求每个元素的更大值，例如 1 4 11 9 10  10进栈 为-1，9比10小 那9的更大值就是10，
                                              //这个11比9大 那么 9出栈，11> 10 10出栈因为 11已经大于9，
                                              //就算1 或者4 要找更大的数那也越不过11因为11靠 4 1 更近所以栈里保留的是尤其是栈顶保留的是离num最近的更大数
        {
            st.pop();//如果 num都大于 栈顶，那就把栈顶弹出去，再找下面的
        }
        Map[num] = st.empty() ? -1 : st.top();//哈希记录该数的更大值，如果把栈顶弹完了说明他是在从他开始到后面的数里最大的 所以值为-1
        st.push(num);//把 num放进栈顶
    }
    for (int i = 0; i < size1; i++)//记录更大值
        vec[i] = Map[nums1[i]];
    return vec;

}

//变式503
//给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 
/*
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
*/
//这道题也用单调栈，但是栈里保存的是数组下标
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int>vec(n, -1);//初始化为-1
    stack<int>stk;
    for (int i = 0; i < 2 * n - 1; i++)//既然是循环的，那么把数组下标拉长然后再跟数组长度取余那么i还是在循环数组里面,从数组头开始循环，所以while不同
    {
        while (!stk.empty() && nums[stk.top()] < nums[i % n])//一开始栈内没东西，先把i = 0放进去，也就是先把你要找的更大数的数字的下标放进去然后再找
                                                             //更大的那个nums[i],如果元素比栈顶的小，那肯定是比你要找的元素小，所以一直放进去
                                                             //直到找到一个元素比你要找的更大数的数更大，再把栈内的下标一个个弹出然后处理vec
                                                             //例如1 1 2 4 3 5    下标进栈0 进 1 进 nums[2]大于 1 和 1 所以就把0 1 都出栈 然后再 2 进栈
                                                             // 2 比 4 小 4 是 2 后面更大数 2 出栈并记录 4进栈 5 > 4 4出
                                                             //只有要找更大数的数字才进栈 找到的都出栈了.全都循环了还没找到 那就是-1了.
        {
            vec[stk.top()] = nums[i % n];//找到了这个元素就按照下标把他放进去
            stk.pop();//
        }
        stk.push(i % n);
    }
    return vec;
}
