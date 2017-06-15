//
//  StrBlob.hpp
//  02.SmartPointer
//
//  Created by Jingjing on 2017/6/15.
//  Copyright © 2017年 jingjing. All rights reserved.
//

#ifndef StrBlob_hpp
#define StrBlob_hpp

#include <vector>
#include <string>
#include <memory>

class StrBlob {
    
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    
    size_type size() const { return data->size();}
    bool empty() {return data->empty();}
    
    void push_back(const std::string& t) { return data->push_back(t);}
    void pop_back();
    std::string& front();
    std::string& back();
    
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

#endif /* StrBlob_hpp */
