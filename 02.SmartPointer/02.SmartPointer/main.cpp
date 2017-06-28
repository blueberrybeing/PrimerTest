//
//  main.cpp
//  02.SmartPointer
//
//  Created by jingjing on 2017/6/9.
//  Copyright © 2017年 jingjing. All rights reserved.
//

#include <iostream>
#include "StrBlob.hpp"
#include <vector>
#include <memory>

class Report
{
public:
    Report(const std::string& s):str(s)
    {
        std::cout << "创建了对象:" << str << "!\n";
    }
    
    ~Report()
    {
        std::cout << "销毁了对象:" << str << "!\n";
    }
    
    void comment() const
    {
        std::cout << str << std::endl;
    }
private:
    std::string str;
};

std::unique_ptr<int> clone(int p)
{
    std::unique_ptr<int> pInt(new int(p));
    return pInt;    // 返回unique_ptr
}

int main(int argc, const char * argv[])
{
    using namespace std;
    //    {
    //        auto_ptr<Report> ps(new Report("using auto_ptr"));
    //        ps->comment();
    //    }
    //    {
    //        shared_ptr<Report> ps(new Report("using shared_ptr"));
    //        ps->comment();
    //    }
    //    {
    //        unique_ptr<Report> ps(new Report("using unique_ptr"));
    //        ps->comment();
    //    }
    
//    auto_ptr<string> films[5] = {
//        auto_ptr<string> (new string("卡卡西")),
//        auto_ptr<string> (new string("佐助")),
//        auto_ptr<string> (new string("宇智波鼬")),
//        auto_ptr<string> (new string("凯")),
//        auto_ptr<string> (new string("宁次"))
//    };
//    auto_ptr<string> pwin;
//    pwin = films[2];
//    
//    for (int i = 0; i < 5; i++) {
//        cout << *films[i] << endl;
//    }
//    cout << *pwin << endl;
//    cin.get();
    
//    StrBlob b;
//    {
//    StrBlob a{"fuck","shit","holy"};
//    
//    b = a;
//    }
    //std::cout << a.data.use_count() << endl;
//    std::cout << "fuck " << endl;
    
    
    
//    shared_ptr<string>ps =  make_shared<string>(10,'a');
//    cout << ps.use_count() << endl;
//    shared_ptr<int> p, q, r;
//    cout << "p:" << p.use_count() << " " << "q:" << q.use_count() << " " << "r:" << r.use_count() << endl;
//    
//    p = make_shared<int>(13);//p 指向的对象只有p一个引用者
//    cout << p.use_count() << endl;
//    
//    q=p;//此时对象有两个引用者
//    cout << "p:" << p.use_count() << " " << "q:" << q.use_count() << " " << "r:" << r.use_count() << endl;
//    
//    r = make_shared<int>(10);
//    p = r;
//    cout << "p:" << p.use_count() << " " << "q:" << q.use_count() << " " << "r:" << r.use_count() << endl;
//    
//    r = q;
//    cout << "p:" << p.use_count() << " " << "q:" << q.use_count() << " " << "r:" << r.use_count() << endl;
    unique_ptr<int> pInt(new int(1));
    cout << *pInt << endl;
    unique_ptr<int> pInt2 = std::move(pInt);//移动赋值
    cout << *pInt2 << endl;
    *pInt2 = 100;
    //cout << *pInt << endl;//报错
    
    unique_ptr<int> pInt3(std::move(pInt2));//移动构造
    cout << *pInt3 << endl;
    
    int temp = 100;
    auto pTemp = clone(temp);
    *pTemp = 1024;
    cout << temp << " " << *pTemp << endl;
    
    
    vector<int> vec;
    vec.push_back(temp);
    temp = 112;
    cout << vec.front() << " " << temp << endl;
    
    vector<unique_ptr<int>> vec_unique;
    unique_ptr<int> p(new int(5));
    vec_unique.push_back(std::move(p));    // 使用移动语义
    
    return 0;
}
