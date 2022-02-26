// QUESTION : Given an array having both positive and negative integers.Find length of the largest subarray with sum 0.

// ~Notes :

//     if prefix(0,x) == prefix(0,y)
//     => sum of subarray from (x+1) to (y) is zero . arr[x+1,y]=0
//     Now if at any point prefix_sum==0 , ie subarry from (0) to (y) is zero
//     => that's why we set first_occ[0]=-1;

// ~Algorithm : PREFIX SUM

//     we first take one hashmap 'first_occ' which will store the first occurance of the prefix sum
//     set first_occ[0]=-1
//     Iterate over the array
//     3.1) calculate the prefix_sum.
//     3.2) check if our hashmap 'first_occ' contains prefix_sum or not
//     3.2.1) If prefix_sum doesnot exist -> set it's first occurance as 'i'. (first_occ[prefix_sum]=i)
//     3.3) Now calculate the size of zero subarray . int size = i - first_occ[arr[i]];
//     3.4) Now update the value of max_size (variable storing the maximum size of subarray having sum=0)
//     return the max_size

//FUNCTION
int maxLen(int arr[], int n)
{
    int max_size = 0; //It will store the maxsize of subarray having sum=0
    int prefix_sum = 0;
    unordered_map<int, int> first_occ;
    //This hashmap will contain the 'first occurnce' of the element.

    first_occ[0] = -1;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (first_occ.find(prefix_sum) == first_occ.end()) //if prefix_sum, doesnot exist in hashmap
            first_occ[prefix_sum] = i;                     // setting it's first occurance

        int curr_size = i - first_occ[prefix_sum];
        max_size = max(max_size, curr_size);
    }

    return max_size;
}

