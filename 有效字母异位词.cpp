



//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;
    int arr[26]{ 0 };//重点如果打算用数组索引法记得数组要初始化为0
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (arr[t[i] - 'a'] == 0)
            return false;
        arr[t[i] - 'a']--;
    }
    return true;

}

