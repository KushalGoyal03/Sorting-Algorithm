#include <iostream>
#include <ctime>
using namespace std;
int heap_size = 0;
int count = 0;

void Max_Heapify (int Arr [] , int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l <= heap_size && Arr [l] > Arr [i])
    {
        largest = l;
        count += 2;
    }
    else
        count++;

    if (r <= heap_size && Arr [r] > Arr [largest])
    {
        largest = r;
        count += 2;
    }
    else
        count++;
    
    if (largest != i)
    {
        swap (Arr [i] , Arr [largest]);
        count++;
        Max_Heapify (Arr , largest);
    }
    else
        count++;
    
}

void Build_Max_Heap (int Arr [] , int n)
{
    heap_size = n;
    for (int i = n/2 ; i > 0 ; i--)
    {
        Max_Heapify (Arr , i);
        count++;
    }
    count++;
}

void Heap_Sort (int Arr [] , int n)
{
    heap_size = n;
    Build_Max_Heap (Arr , n);
    for (int i = n ; i > 0 ; i--)
    {
        swap (Arr [0] , Arr [i]);
        count++;
        heap_size--;
        Max_Heapify (Arr , 0);
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

