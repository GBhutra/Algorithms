#include<iostream>
#include<vector>

void print2Sums(std::vector<int>& arr, int k)   {
    std::vector<bool> hash(false,k);
    for (auto i: arr)   {
        if (i<k)    {
            int temp=k-i;
            if(hash[temp]==1)   {
                std::cout<<temp<<", "<<i;
                hash[temp] = false;
            }
            else
                hash[i]=true;
        }
    }
}

int main()  {
    std::vector<int> arr {1,2,3,4,5,6,7,8,9};
    print2Sums(arr,10);
    return 0;
}