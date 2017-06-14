//
//  main.cpp
//  02.SmartPointer
//
//  Created by jingjing on 2017/6/9.
//  Copyright © 2017年 jingjing. All rights reserved.
//

#include <iostream>
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
    
    auto_ptr<string> films[5] = {
        auto_ptr<string> (new string("卡卡西")),
        auto_ptr<string> (new string("佐助")),
        auto_ptr<string> (new string("宇智波鼬")),
        auto_ptr<string> (new string("凯")),
        auto_ptr<string> (new string("宁次"))
    };
    auto_ptr<string> pwin;
    pwin = films[2];
    
    for (int i = 0; i < 5; i++) {
        cout << *films[i] << endl;
    }
    cout << *pwin << endl;
    cin.get();
    return 0;
}
