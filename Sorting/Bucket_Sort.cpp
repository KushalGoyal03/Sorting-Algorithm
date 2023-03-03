#include <iostream>
#include <climits>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void Bucket_Sort (double Arr [] , int n)
{
    vector<double>B [n];

    for (int i = 0 ; i < n ; i++)
    {
        int Bi = n * Arr [i];
        B [Bi].push_back (Arr [i]);
    }
    
    for (int i = 0 ; i < n ; i++)
        sort(B [i].begin () , B [i].end ());
    
    int index = 0;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < B [i].size () ; j++)
            Arr [index++] = B [i][j];
}

int main ()
{
    //This is for random input.
    srand(time(0));
    int n = rand () % 10 + 5;
    double Arr [n];
    for (int i = 0 ; i < n ; i++)
        Arr [i] = (double) rand () / INT_MAX;
    
    //This is for user input.
    /*
    int n;
    cout << "Enter the no. of elements you want to insert in your array : ";
    cin >> n;
    double Arr [n];
    
    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter the " << i + 1 << "th element : ";
        cin >> Arr [i];
    }*/
    
    cout << "Array :- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    Bucket_Sort (Arr , n);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    return 0;
}

