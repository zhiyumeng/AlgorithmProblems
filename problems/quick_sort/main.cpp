#include <iostream>
using namespace std;

void exchange(int &a,int &b){
    if(&a==&b)
        return;
    a = a+b;
    b = a-b;
    a = a-b;
}

int partition(int *nums, int p, int r){

    int pivot = nums[r];
    int left_index = p-1;
    for(int i=p;i<r;i++)
        if(nums[i] < pivot) {
            exchange(nums[i],nums[++left_index]);
        }
    exchange(nums[++left_index],nums[r]);
    return left_index;
}

void quick_sort(int *nums,int p,int r){//算法导论第三版第95页伪代码版本
    if(p < r){
        int pivot_index = partition(nums,p,r);
        quick_sort(nums,p,pivot_index-1);
        quick_sort(nums,pivot_index+1,r);
    }
}


int main() {
    int nums[] = {1,3,2,4,5,6,7};
    for(int i=0;i<7;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    quick_sort(nums,0,6);
    for(int i=0;i<7;i++)
        cout<<nums[i]<<" ";
    return 0;
}