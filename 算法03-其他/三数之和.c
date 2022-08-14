# include "stdio.h"

/*  TODO: 
    三数之和
        给你一个包含n个整数的数组nums, 判断nums中是否存在三个元素a, b, c, 使得 a + b + c = 0.
        找出所有满足条件且不重复的三元组.

        注意: 答案中不可以包含重复的三元组。

        示例:
            给定数组 nums = [-1, 0, 1, 2, -1, -4]，
            满足要求的三元组集合为: [ [-1, 0, 1], [-1, -1, 2] ]

    使用双指针法
    拿这个nums数组来举例, 首先将数组排序, 然后有一层for循环, i从下标0的地方开始
    同时定一个下标left定义在i+1的位置上, 定义下标right在数组结尾的位置上.
    
    依然还是在数组中找到abc使得a+b+c=0, 这里相当于a=nums[i], b=nums[left], c=nums[right].

    接下来如何移动left和right呢
    如果nums[i]+nums[left]+nums[right]>0 说明此时三数之和大了, 因为数组是排序后了, 所以right下标就应该向左移动, 这样才能让三数之和小一些.
    如果nums[i]+nums[left]+nums[right]<0 说明此时三数之和小了, left 就向右移动, 才能让三数之和大一些, 直到left与right相遇为止.

    时间复杂度: O(n²)
*/


struct tuple{
    int a, b, c;
} saveTuple[128];


void three_sum(int *array, size_t lenght){

}


int main(){

    return 0;
}