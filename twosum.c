
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,k;//定义两个用于循环的变量 
    for (i = 0; i < numsSize; i++ ){//第一个for循环从头开始
        k=(numsSize-1)/2;
        for (j = k+1 ; j > i; j--) {//第二个for循环从后开始，到i停止
            if (nums[i] + nums[j] == target) {//比较等不等于目标值
                int* ret = malloc(sizeof(int) * 2);//创建一个数组存放位置
                ret[0] = i,ret[1] = j;//把位置存入数组
                *returnSize = 2;//数组大小
                return ret;//返回位置
            }
        }
        for (j = k+1 ; j < numsSize; j++){
            if (nums[i] + nums[j] == target) {//比较等不等于目标值
                int* ret = malloc(sizeof(int) * 2);//创建一个数组存放位置
                ret[0] = i,ret[1] = j;//把位置存入数组
                *returnSize = 2;//数组大小
                return ret;//返回位置
            }   
        }
    }
    free(returnSize);
    return 0;//返回0
}
