#include <bits/stdc++.h>

using namespace std;

int maxOverlappingSum(vector<int>& v , int low , int high , int mid)
{
    int leftSum = INT_MIN , sum = 0;
    for(int i = mid ; i >= low ; i--)
    {
        sum += v[i];
        if(leftSum < sum)
        {
            leftSum = sum;
        }
    }

    sum = 0;

    int rightSum = INT_MIN;
    for(int i = mid + 1 ; i <= high ; i++)
    {
        sum += v[i];
        if(rightSum < sum)
        {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubarraySum(vector<int>& v , int low , int high)
{
    if(low == high)
    {
        return v[low];
    }
    if(low > high)
    {
        return INT_MIN;
    }

    int mid = (low + high) >> 1;

    int leftMaxSum = maxSubarraySum(v , low , mid);
    int rightMaxSum = maxSubarraySum(v , mid + 1 , high);
    int leftRightOverlap = maxOverlappingSum(v , low , high , mid);
    return max( leftMaxSum , max(rightMaxSum , leftRightOverlap) );
}

int main()
{
    cout << endl;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n , 0);

    cout << "Enter the elements of the array: " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    int maxSum = maxSubarraySum(v , 0 , n - 1);
    
    cout << "The maximum subarray sum is: " << maxSum << endl;

    cout << endl;

    return 0;
}