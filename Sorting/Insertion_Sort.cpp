#include <iostream>
#include <ctime>
using namespace std;

void Insertion_Sort (int Arr [] , int n)
{
    cout << "\n\nNo. of comparisons after each pass : ";
    int t_count = 1;
    for (int j = 1 ; j < n ; j++)
    {
        int key = Arr [j];
        int i = j - 1;
        int count = 1;
        while (i >= 0 && Arr [i] > key)
        {
            Arr [i + 1] = Arr [i];
            i--;
            count++;
        }
        cout << " " << count;
        Arr [i + 1] = key;
        t_count += count;
    }
    
    cout << "\n\nSorted Array : ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
        
    cout << "\n\nTotal no. of comparisons = " << t_count;
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
        
    Insertion_Sort (Arr , n);

    return 0;
}

