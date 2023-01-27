#include <iostream>
#include <ctime>
using namespace std;

void Bubble_Sort (int Arr [] , int n)
{
    int t_count = 1;
    cout << "\n\nNo. of comparisons after each pass : ";
    
    for (int i = 0 ; i < n - 1 ; i++)
    {
        int count = 1;
        for (int j = 0 ; j < n - i - 1 ; j++)
        {
            if (Arr [j] > Arr [j + 1])
                swap (Arr [j] , Arr [j + 1]);
            count++;
        }
        cout << count << " ";
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
        
    Bubble_Sort (Arr , n);

    return 0;
}
