#include <bits/stdc++.h>

using namespace std;

void merge(vector< pair<int , int> >& v , vector<int>& count , int low , int mid , int high)
{
    // Total number of elements = mid - low + 1 + high - (mid + 1) + 1 = mid - low + 1 + high - mid - 1 + 1 = high - low + 1
    vector< pair<int , int> > temp(high - low + 1);
    
    int i = low , j = mid + 1 , k = 0;

    while(i <= mid && j <= high)
    {
        if(v[i].first > v[j].first)
        {
            count[ v[i].second ] += (high - j + 1);
            // temp.push_back(v[i]);
            temp[k] = v[i];
            i += 1;
            k++;
        }
        else if(v[i].first <= v[j].first)
        {
            // temp.push_back(v[j]);
            temp[k] = v[j];
            j += 1;
            k++;
        }
    }

    while(i <= mid)
    {
        // temp.push_back(v[i]);
        temp[k] = v[i];
        k++;
        i += 1;
    }

    while(j <= high)
    {
        // temp.push_back(v[j]);
        temp[k] = v[j];
        k++;
        j += 1;
    }

    for(int i = 0 ; i < (high - low + 1) ; i++)
    {
        v[low + i] = temp[i];
    }

    return;
}

void countOfSmallerNumbersAfterSelf(vector< pair<int , int> >& v , vector<int>& count , int low , int high)
{
    if(low >= high)
    {
        return;
    }

    int mid = (low + high)/2;

    countOfSmallerNumbersAfterSelf(v , count , low , mid);
    countOfSmallerNumbersAfterSelf(v , count , mid + 1 , high);
    merge(v , count , low , mid , high);
}

int main()
{
    cout << endl;

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << endl;

    vector< pair<int , int> > v;

    cout << "Enter the elements of the array: " << endl;
    for(int i = 0 ; i < n ; i++)
    {
        pair <int , int> p;

        int x;
        cin >> x;

        p.first = x;
        p.second = i;

        v.push_back(p);
    }

    vector<int> count(n , 0);

    countOfSmallerNumbersAfterSelf(v , count ,  0 , n - 1);

    for(auto it : count)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}