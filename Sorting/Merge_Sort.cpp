#include <iostream>
#include <climits>
#include <ctime>
using namespace std;
int t_count = 0;

void Merge (int Arr [] , int p , int q , int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L [n1 + 1];
    int R [n2 + 1];
    
    for (int i = 0 ; i < n1 ; i++)
        L [i] = Arr [p + i];
    for (int j = 0 ; j < n2 ; j++)
        R [j] = Arr [q + j + 1];
    
    L [n1] = INT_MAX;
    R [n2] = INT_MAX;
    int i = 0;
    int j = 0;

    for (int k = p ; k <= r ; k++)
    {
        if (L [i] <= R [j])
        {
            Arr [k] = L [i];
            i++;
        }
        else 
        {
            Arr [k] = R [j];
            j++;        
        }
        t_count++;
    }
    t_count++;
}

void Merge_Sort (int Arr [] , int p , int r)
{
    if (p < r)
    {
        t_count++;
        int q = (p + r)/2;
        Merge_Sort (Arr , p , q);
        Merge_Sort (Arr , q + 1 , r);
        Merge (Arr , p , q , r);
    }
    else
        t_count++;
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
        
    Merge_Sort (Arr , 0 , n - 1);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    cout << "\nTotal no. of comparison : " << t_count;
    
    return 0;
}
