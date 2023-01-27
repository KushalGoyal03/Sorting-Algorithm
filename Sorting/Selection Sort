#include <iostream>
#include <ctime>
using namespace std;

void Selection_Sort (int Arr [] , int n)
{
    int min , t_count = 1;
    cout << "\n\nNo. of comparisons after each pass : ";
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int count = 1;
        min = i;
        for (int j = i + 1 ; j < n ; j++)
        {
            if (Arr [j] < Arr [min])
                min = j;
            count++;
        }
        
        cout << count << " ";
            
        if(min != i)
            swap(Arr [min] , Arr [i]);
            
        t_count += count;
    }
    
    cout << "\n\nTotal no. of comparisons = " << t_count;
    
    cout << "\n\nSorted Array: ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
}

int main () 
{
    //This is for random input.
    int n;
    srand(time(0));
    n = rand () % 50 + 10;
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
        
    Selection_Sort (Arr , n);

    return 0;
}
