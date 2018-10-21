//
// Created by fyyc on 2018/10/18.
//

#include "Computer.h"

void Computer::readExpression(const string &file_path) {
        //读取表达式
        ifstream in(file_path);
        stringstream buffer;
        buffer << in.rdbuf();
        expression = buffer.str();
        //去除四则运算字符串中的所有空格
        string pattern1("\\s+");
        regex regex1(pattern1);
        expression = regex_replace(expression,regex1,"");
        //若表达式以-开头，则在表达式最前面加上数字0
        if( expression[0] == '-' ) expression.insert(expression.begin(),'0');
}



void Computer::compute() {
        //判断是否含有非法字符
        checkIllegalCharacter();
        if(!isExpressionRight)
	{
	  cout<<"ERROR"<<endl;
	  return;
	}

        //将中缀转为后缀表达式直接运算
        int sub_start = 0,index = 0;
        while (index < expression.size() ){
                char c = expression[index];
                if(c>='0' && c <='9' || c=='.') ++index;
                else {
                        //1.遇到操作数：直接输出（添加到后缀表达式中）
                        if(index > sub_start) {
                                getNumber(sub_start,index);
                                sub_start = index;
                        }

                        char op = expression[index];
                        // 2.栈为空时，遇到运算符，直接入栈
                        // 3.遇到左括号：将其入栈
                        if(op_stack.empty()|| op=='(') op_stack.push(op);
                        //4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
                        else if( op==')'){
                                while (op_stack.top()!='(') {
                                        operate();
                                        //未找到左括号，括号不匹配
                                        if(op_stack.empty() || !isExpressionRight) {
                                                cout<<"ERROR"<<endl;
						return ;                
                                        }
                                }
                                op_stack.pop();
                        }
                                //5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
                        else {
                                int prior = priority(op);
                                while (!op_stack.empty() && priority(op_stack.top()) >= prior){
                                        operate();
                                }
                                op_stack.push(op);
                        }
                        index++;sub_start++;
                }
        }
        //取出四则运算最后一个运算符右边的数字（如果存在的话）
        getNumber(sub_start,index);
        // 6.最终将栈中的元素依次出栈，输出。
        while (!op_stack.empty() && isExpressionRight) {
	  operate();
	}
        if(isExpressionRight && !num_stack.empty()) {
	  cout<<num_stack.top()<<endl;
	}
        else cout<<"ERROR"<<endl;
}

int Computer::priority(char op) {
        switch (op){
                case '+':
                case '-':
                        return 1;
                case '*':
                case '/':
                        return 2;
                default:
                        return -1;
        }
}

void Computer::operate(){      
        if(num_stack.getSize() < 2 || op_stack.empty()) {
                isExpressionRight = false;
                return;
        }
        char op = op_stack.top();op_stack.pop();
        double num2 = num_stack.top();num_stack.pop();
        double num1 = num_stack.top();num_stack.pop();
        switch (op){
                case '+': num_stack.push(num1+num2);
                break;
                case '-': num_stack.push(num1-num2);
                break;
                case '*': num_stack.push(num1*num2);
                break;
                case '/': num_stack.push(num1/num2);
                break;
		default:
		  isExpressionRight = false;
        }
}

void Computer::getNumber(int sub_start, int sub_end) {
        //取出数字
        if(sub_end > sub_start) {
                double  num ;
                //测试将0.23写作.23的情况是否能正确读取：测试通过。
                sscanf(expression.substr(sub_start,sub_end-sub_start).c_str(),"%lf",&num);
                num_stack.push(num);
        }
}

bool Computer::checkIllegalCharacter() {
        string pattern2 = "^[0-9+*/().\\-]*";
        regex re(pattern2);
        if(!regex_match(expression,re))
                isExpressionRight = false;
}
