void runningSum(int* nums, int size)
{
    for(int i=1; i<size; i++)
    	*(nums + i) += *(nums + i - 1);
}
