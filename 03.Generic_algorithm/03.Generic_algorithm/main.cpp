//
//  main.cpp
//  03.Generic_algorithm
//
//  Created by Jingjing on 2017/6/12.
//  Copyright © 2017年 Jingjing. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <string>
using namespace std;

void elimDups(std::vector<std::string>& words)
{
    //按字典排序
    sort(words.begin(), words.end());
    //重排输出入范围，使得每个单词只出现一次,返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    //使用容器操作删除重复元素
    words.erase(end_unique, words.end());
}
void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    
    stable_sort(words.begin(), words.end(), [](const string& a, const string& b)
                {return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(), [sz](const string& a)
                      {return a.size() >= sz;});
    auto count = words.end() - wc;
    cout << count << endl;
    
}

int main(int argc, const char * argv[]) {
    
    
    vector<int> vec = {5, 6, 42, 78};
    vec.push_back(42);
    
    int val = 42;
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "the val " << val
    << (result == vec.cend() ? " is not present." : " is present") << endl;
    
    list<string> lst;
    string sval = "fuck";
    lst.push_back("shit");
    lst.push_back("fuck");
    auto result2 = find(lst.cbegin(), lst.cend(), sval);
    
    int ia[] = {2,4,3,5,7};
    auto result3 = find(begin(ia), end(ia), val);
    result3 = find(ia+1, ia+3, val);
    
    auto temp = count(vec.cbegin(), vec.cend(), val);
    cout << temp << endl;
    
    //accumulate
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    string sum2 = accumulate(lst.cbegin(), lst.cend(), string(""));
    cout << "sum:" << sum << endl;
    cout << "sum2:" << sum2 << endl;
    
    
    vector<string> words = {"the", "fox", "jump", "over", "quick", "red", "slow", "the", "red", "turtle" };
    
    //lambda
    //[capture list] (parameter list) -> return type {function body}
    auto f = [] {return 42;};
    std::cout << "Hello, lambda!\n" << f() << endl;
    
    //lambda 不能有默认参数
    stable_sort(words.begin(), words.end(), [](const string& a, const string& b)
                {return a.size() < b.size();});
    for(auto& it : words)
    {
        cout << it << endl;
    }
    
    return 0;
}
