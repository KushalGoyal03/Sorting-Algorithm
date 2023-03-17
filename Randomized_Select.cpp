#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

int Partition (int Arr [] , int p , int r)
{
    int k = Arr [r];
    int i = p - 1;
    
    for (int j = p ; j < r ; j++)
    {
        if (Arr [j] <= k)
        {
        	i++;
        	swap (Arr [i] , Arr [j]);
		}
    }
    swap (Arr [i + 1] , Arr [r]);
    return i + 1;
}

//This function chooses any random integer from the array as a pivot element.
int Partition_r (int Arr [] , int p , int r)
{
    srand(time(0));
    int x = p + rand () % (r - p);
    swap (Arr [r] , Arr [x]);
    return Partition (Arr , p , r);
}

void Quick_Sort (int Arr [] , int p , int r)
{
    if (p < r)
    {
        int q = Partition_r (Arr , p , r);
        Quick_Sort (Arr , p , q - 1);
        Quick_Sort (Arr , q + 1 , r);
    }
}

int Randomized_Select (int Arr [] , int p , int r , int i)
{
    if (p == r)
        return Arr [p];
    int q = Partition_r (Arr , p , r);
    int k = q - p + 1;
    if (i == k)
        return Arr [q];
    else if (i < k)
        return Randomized_Select (Arr , p , q - 1 , i);
    else
        return Randomized_Select (Arr , q + 1 , r , i - k);
}

int main ()
{
    //This is for random input.
    srand(time(0));
    int n = rand () % 10 + 5;
    int Arr [n];
    for (int i = 0 ; i < n ; i++)
        Arr [i] = rand () % 100 + 1;
    
    //This is for user input.
    /*int n;
    cout << "Enter the no. of elements you want to insert in your array : ";
    cin >> n;
    int Arr [n];
    
    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter the " << i + 1 << "th element : ";
        cin >> Arr [i];
    }*/
    
    cout << "Array :- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    
    Quick_Sort (Arr , 0 , n - 1);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";

    int i;
    cout << "\nEnter the position of element u want to find: ";
    cin >> i;
    
    int pos = Randomized_Select (Arr , 0 , n - 1 , i);
    cout << i << "th smallest element is " << pos;
    
    
    return 0;
}
