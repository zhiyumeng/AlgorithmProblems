#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct node{
    int value;
    node * next;
    node(int val):value(val),next(NULL){};
};

node * make_list(int N){
    if(N < 1)
        return NULL;
    node *head = new node(1);
    node * temp = head;
    for(int i=2;i<=N;i++) {
        temp->next = new node(i);
        temp = temp->next;
    }
    temp->next = head;
    return temp;
}

int main( int argc, char* argv[]) {
   /*
    1、  用户输入M, N值，从1至N开始顺序循环数数，每数到M输出该数值，直至全部输出。
    输入每行为“M,N”，输出用英文逗号分隔
    程序运行方法：demo1 q1_testfile
    */
    int M,N;
    sscanf(argv[1],"%d",&M);
    sscanf(argv[2],"%d",&N);
    node * loop_list_rear = make_list(N);
    node * temp = loop_list_rear;
    node * node_to_delete= NULL;
    while (temp->next != temp) {
        for(int i=0;i<M-1;i++)
            temp = temp->next;
    //    cout<<"\ntemp val:"<<temp->value<<endl;
        cout<<temp->next->value<<",";
        node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;
    }
    cout<<temp->value<<endl;
    return 0;
}