给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

##这道题的主要思路是分治，将问题的规模不断缩小。回溯中好多的题目都是使用这个思想来解题的。

IP地址被三个”.”分割成了4个部分，这里我把每一个部分叫做一个段，依次为第0段，第1段，第2段，第3段。

那么给定一个只包含数字的字符串，如果求出有效的ip地址呢？ 
以25525511135为例来分析。考虑第0段可能的取值，由于每一个段可以包含1位，2位或3位，那么第0段可能的取值是： 
2 
25 
255

##第0段取值以后后面的字符串需要被分割成3段，那么后面的字符能否被分割成3段呢？ 

##第0段取上面的值后，剩余的部分依次为： 

##5525511135 ，字符串的长度为10，而3段最长也只能为9，所以第0段取2时没有对应的有效ip地址。 

##525511135 ，这里字符串的长度为9，即这个字符串还可能被分割成有效的3段。 

##25511135 ，这里字符串的长度为8，即这个字符串还可能被分割成有效的3段。 

##然后再对525511135和25511135求分割成3段的方法。这里问题规模就缩小了。需要被分割的段由4段变成了3了，字符串的长度也变短了。

##递归退出的条件是遍历到字符串尾端并且字符串被分割成了4段。

还需要注意的是:

##如果一个段包含3个字符，那么这三个字符不能大于”255”,这是ip地址的基本知识；

##如果一个字符包括2个或3个字符，它的第一个字符不能为0。

```
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string path;
        helper(s,0,0,path,result);
        return result;
    }

    void helper(string &s,int num,int pos,string &path,vector<string>& result)
    {
        //遍历完给定字符串，并且生成了个段时
        if(pos==s.size()&&num==4)
        {
            //这里需要去除掉path最后的.
            result.push_back(path.substr(0,path.size()-1));
            return;
        }

        //如果该段包含的字符数大于规定的最大数目，那么直接退出，可以把这个判断放在下面的if中，
        //但是三个if都需要加，所以放在这儿更简洁一些。
        if(s.size()-pos>3*(4-num))
            return;

        //该段只含有一个字符
        if(pos<s.size())
        {
            path+=s.substr(pos,1)+".";
            helper(s,num+1,pos+1,path,result);
            path=path.substr(0,path.size()-2);
        }

        //该段含有两个字符，并且第一个字符不能是'0'
        if(pos<s.size()-1&&s[pos]!='0')
        {
            path+=s.substr(pos,2)+".";
            helper(s,num+1,pos+2,path,result);
            path=path.substr(0,path.size()-3);
        }

        //该段含有3个字符并且第一个字符不能是'0'，前三个字符串不能大于"255"
        if(pos<s.size()-2&&s[pos]!='0'&&s.substr(pos,3)<="255")
        {
            path+=s.substr(pos,3)+".";
            helper(s,num+1,pos+3,path,result);
            path=path.substr(0,path.size()-4);
        }

    }
};

```
