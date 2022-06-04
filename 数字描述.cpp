

/*
给定一个正整数 n ，输出外观数列的第 n 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1 
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
*/

string countAndSay(int n) {
    if (n == 1)
        return "1";
    string previous = countAndSay(n - 1), result = "";//previous是递归前一个的数字串
                                                //result是对previous的描述，然后把这个描述返回
    int count = 1;
    for (int i = 0; i < previous.size(); i++)
    {
        if (previous[i] == previous[i + 1])//计算有几个重复数字
        {
            count++;
        }
        else//没有则对这个重复数字进行描述然后写进数字串resul然后继续遍历描述
        {
            result += to_string(count) + previous[i];
            count = 1;
        }
    }
    return result;
}

