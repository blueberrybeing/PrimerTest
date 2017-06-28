//
//  main.cpp
//  01.IO
//
//  Created by jingjing on 2017/6/6.
//  Copyright © 2017年 jingjing. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setfill;
using std::setprecision;

inline void eatline(){while (cin.get() != '\n') continue;}
struct planet {
    char name[20];
    double population;
    double g;
};

int main(int argc, const char * argv[]) {
    using namespace std;
    
    //cout
    //1.输出和指针
    /**
     const signed char*
     const unsigned char*
     const char*
     void*
     **/
    
//    char name[10] = "fuckyou";
//    const char* pn = "holy shit";
//    cout << name << endl;
//    cout << pn << endl;
//    cout << (void*)pn << endl;
//    
//    //2.其他ostream输出方法
//    //basic_ostream& put(char_type __c);
//    cout.put('a')<< endl;;
//    
//    //basic_ostream& write(const char_type* __s, streamsize __n);
//    const char* s1 = "fuck123";
//    const char* s2 = "shit456";
//    const char* s3 = "nbat789";
//    auto len = strlen(s2);
//    
//    decltype(len) i;
//    
//    for (i = 1; i != len+1; ++i) {
//        cout.write(s2, i) << endl;
//    }
//    cout << "^^^^^^^^^^^^----------" << endl;
//    for (i = len; i != 0; --i) {
//        cout.write(s2, i) << endl;
//    }
//    
//    cout << "Exceeding string length" << endl;
//    cout.write(s2, len+ 5);
//    cout << s1 << endl << s3 << endl;
    
    //    //basic_ostream& write(const char_type* __s, streamsize __n);
    //    const char * state1 = "Florida";
    //    const char * state2 = "Kansas";
    //    const char * state3 = "Euphoria";
    //    std::size_t len = std::strlen(state2);
    //    cout << "Increasing loop index:\n";
    //    int i = 0;
    //    for (i = 1; i < len; i ++) {
    //        cout.write(state2, i);
    //        cout << endl;
    //    }
    //
    //    cout << "Decreasing loop index:\n";
    //    for (i = (int)len; i > 0; i--) {
    //        cout.write(state2, i) << endl;
    //    }
    //    cout << "Exceeding string length:\n";
    //    cout.write(state2, len + 5) << endl;
    
    //    cout << state1 << endl;
    //    cout << state3 << endl;
    
    //    //write()方法并不会在遇到空字符时停止打印字符，而只是打印指定数目的字符，即使超出了字符串的边界
    //    //write()方法也可用于数值数据，可以将数字的地址强制转换为char *，然后传递给它
    //    long val = 560031841;
    //    std::cout.write((char *) & val, sizeof(val));
    
    //    cout << "输入一个数字:";
    //    int n;
    //    cin >> n;
    //    std::string str(5,' ');
    //    cout << "n" << str << "n*n\n";
    //    cout << n << str << n*n << "(decimal)\n";
    //    //设置成十六进制系统
    //    cout << std::hex;
    //    cout << n << str << n*n << "  (hexadecimal)\n";
    //
    //    //设置为八进制系统
    //    cout << std::oct << n << str << n * n << "  (octal)\n";
    //
    //    dec(cout);
    //    cout << n << str << n * n << "  (decimal)\n";
    
    //    size_t w = cout.width(30);
    //    cout << "Default field width = " << w << ":\n";
    //    cout.width(5);
    //    cout << "N" << ':';
    //    cout.width(8);
    //    cout << "N * N" << ":\n";
    //
    //    cout.fill('*');
    //    for (long i = 1; i <= 100; i *= 10)
    //    {
    //        cout.width(5);
    //        cout << i << ':';
    //        cout.width(8);
    //        cout << i * i << ":\n";
    //    }
    
        cout << std::right << std::fixed;
        cout << std::setw(6) << "N" << std::setw(14) << "square root"
        << std::setw(15) << "fourth root\n";
        double root;
        for (int n = 10; n <= 100; n += 10) {
            root = sqrt(double(n));
            cout << setw(6) << setfill('.') << n << setfill(' ')
            << setw(12) << setprecision(3) << root
            << setw(14) << setprecision(4) << sqrt(root)
            << endl;
        }
    //    int input;
    //    int sum = 0;
    //    while (cin >> input) {
    //        sum += input;
    //    }
    //    cout << "最后一个输入的值 = " << input << endl;
    //    cout << "Sum = " << sum << endl;
    //    if (cin.fail() && !cin.eof()) {
    //        cin.clear();
    //        while (!isspace(cin.get())) {
    //            continue;
    //        }
    //    }
    //    else{
    //        cout << "不能继续\n";
    //        exit(1);
    //    }
    //    cout << "请重新输入数据:\n";
    //    cin >> input;
    
    //    string filename;
    //    cout << "Enter name for new file:\n";
    //    cin >> filename;
    //
    //    ofstream fout(filename.c_str());
    //    fout << "For your eyes only!\n";
    //    cout << "Enter your secret number:\n";
    //    float secret;
    //    cin >> secret;
    //    fout << "Your secret number is " << secret << endl;
    //    fout.close();
    //
    //    ifstream fin(filename.c_str());
    //    cout << "Here are the contents of " << filename << ": \n";
    //    char ch;
    //    while (fin.get(ch)) {
    //        cout << ch;
    //    }
    //    cout << "Done\n";
    //    fin.close();
    
    //     const char * file = "guests.txt";
    //    char ch;
    //    //show initial contents
    //    ifstream fin;
    //    fin.open(file);
    //
    //    if(fin.is_open()){
    //        cout << "Here are the current contents of the " << file << " file: \n";
    //        while (fin.get(ch)) {
    //            cout << ch;
    //        }
    //        fin.close();
    //    }
    //
    //    //add new names
    //    ofstream fout(file,ios_base::out | ios_base::ate);
    //    if (!fout.is_open()) {
    //        cerr << "Can't open " << file << " file for output.\n";
    //        exit(EXIT_FAILURE);
    //    }
    //    cout << "Enter guest names (enter a blank line to quit):\n";
    //
    //    fout << endl;
    //    string name;
    //    while (getline(cin, name) && name.size() > 0) {
    //        fout << name.c_str() << endl;
    //    }
    //    fout.close();
    //
    //    //show revised file
    //    fin.clear();
    //    fin.open(file);
    //    if (fin.is_open()) {
    //        cout << "Here are the new contents of the " << file << " file:\n";
    //        while (fin.get(ch)) {
    //            cout << ch;
    //        }
    //        fin.close();
    //    }
    //    cout << "Done.\n";
    
    /*binary*/
//    const char* planetData = "planets.dat";
//    planet p1;
//    cout << fixed << right;
//    
//    ifstream fin;
//    fin.open(planetData, ios_base::in | ios_base::binary);
//    if (fin.is_open()) {
//        cout << "Here are the current contents of the " << planetData
//        << " file:\n";
//        while (fin.read((char*)&p1, sizeof(p1))) {
//            cout << setw(20) << p1.name << ": "
//            << setprecision(0) << setw(12) << p1.population
//            << setprecision(2) << setw(6) << p1.g << endl;
//        }
//        fin.close();
//    }
//    
//    // add new data
//    ofstream fout(planetData, ios_base::out | ios::app | ios_base::binary);
//    if (!fout.is_open()) {
//        cerr << "Can't open " << planetData << " file for output:\n";
//        exit(EXIT_FAILURE);
//    }
//    
//    cout << "Enter planet name (enter a blank line to quit):\n";
//    cin.get(p1.name, 20);
//    while (p1.name[0] != '\0') {
//        eatline();
//        cout << "Enter planet population:";
//        cin >> p1.population;
//        cout << "Enter planet's acceleration of gravity:";
//        cin >> p1.g;
//        eatline();
//        fout.write((char*)&p1, sizeof(p1));
//        
//        cout << "Enter planet name (enter a blank line to quit):\n";
//        cin.get(p1.name, 20);
//    }
//    fout.close();
//    
//    //show revised file
//    fin.clear();
//    fin.open(planetData, ios_base::in | ios_base::binary);
//    if (fin.is_open()) {
//        cout << "Here are the current contents of the " << planetData
//        << " file:\n";
//        while (fin.read((char*)&p1, sizeof(p1))) {
//            cout << setw(20) << p1.name << ": "
//            << setprecision(0) << setw(12) << p1.population
//            << setprecision(2) << setw(6) << p1.g << endl;
//        }
//        fin.close();
//    }
//    
//    cout << "Done.\n";
    
    return 0;
}
