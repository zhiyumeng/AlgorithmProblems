//
// Created by fyyc on 2018/10/18.
//

#ifndef LAI_YE_PROBLEM2_COMPUTER_H
#define LAI_YE_PROBLEM2_COMPUTER_H

#include <iostream>
#include <string>
#include "Stack.h"
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

class Computer {
public:
    void readExpression(const string &file_path);//从文件中读取表达式
    bool checkIllegalCharacter();//判断是否存在非法字符
    void compute();
    int priority(char op);//返回操作符的优先级
    void operate( ); //执行操作符对应的算术操作
    void getNumber(int sub_start,int sub_end);//读取数字


private:
    bool isExpressionRight = true;
    string expression;
    Stack<double> num_stack;
    Stack<char> op_stack;
};


#endif //LAI_YE_PROBLEM2_COMPUTER_H
