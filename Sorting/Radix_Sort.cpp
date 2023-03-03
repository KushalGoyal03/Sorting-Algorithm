#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

int maxim (int Arr [] , int n)
{
    int max = Arr [0];
    for (int i = 1 ; i < n ; i++)
    {
        if (max < Arr [i])
            max = Arr [i];
    }
    
    return max;
}

void Counting_Sort (int Arr [] , int n , int x)
{
    int k = maxim (Arr , n);
    int C [k + 1];
    int B [n];
    for (int i = 0 ; i <= k ; i++)
        C [i] = 0;

    for (int j = 0 ; j < n ; j++)
        C [(Arr [j] / x) % 10] ++;

    for (int i = 1 ; i <= k ; i++)
        C [i] += C [i - 1];
    
    for (int j = n - 1 ; j >= 0 ; j--)
    {
        B [C [(Arr [j] / x) % 10] - 1] = Arr [j];
        C [(Arr [j] / x) % 10]--;
    }
    
    for (int i = 0 ; i < n ; i++)
        Arr [i] = B [i];
}

void Radix_Sort (int Arr [] , int n)
{
    int max = maxim (Arr, n);
    for (int i = 1; max / i > 0 ; i *= 10)
        Counting_Sort (Arr , n , i);
}


int main ()
{
    //This is for random input.
    srand(time(0));
    int n = rand () % 10 + 5;
    int Arr [n];
    for (int i = 0 ; i < n ; i++)
        Arr [i] = rand () % 1000 + 1;
        
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
    
    Radix_Sort (Arr , n);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    return 0;
}
