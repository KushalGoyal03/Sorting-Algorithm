#include <iostream>
#include <ctime>
using namespace std;
int heap_size = 0;
int count = 0;

void Min_Heapify (int Arr [] , int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l <= heap_size && Arr [l] < Arr [i])
    {
        smallest = l;
        count += 2;
    }
    else
        count++;

    if (r <= heap_size && Arr [r] < Arr [smallest])
    {
        smallest = r;
        count += 2;
    }
    else
        count++;
    
    if (smallest != i)
    {
        swap (Arr [i] , Arr [smallest]);
        count++;
        Min_Heapify (Arr , smallest);
    }
    else
        count++;
    
}

void Build_Min_Heap (int Arr [] , int n)
{
    heap_size = n - 1;
    for (int i = n/2 ; i >= 0 ; i--)
    {
        Min_Heapify (Arr , i);
        count++;
    }
    count++;
}

void Heap_Sort (int Arr [] , int n)
{
    heap_size = n - 1;
    Build_Min_Heap (Arr , n);
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        swap (Arr [0] , Arr [i]);
        count++;
        heap_size--;
        Min_Heapify (Arr , 0);
    }
    count++;
}

int main ()
{
    //This is for random input.
    int n;
    srand(time(0));
    n = rand () % 10 + 5;
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
    
    Heap_Sort (Arr , n);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";

    cout << "\nTotal no. of comparison : " << count;
    
    return 0;
}
