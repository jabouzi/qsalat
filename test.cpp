#include <iostream>
 
 void swap(int *x, int *y);
 void function1(int *arr);
 void function2(int *arr);
 
 int main()
 {
     int x = 5, y = 10;
 
     std::cout << "Main. Before swap, x: " << x << " y: " << y << "\n";
     swap(&x,&y);
     std::cout << "Main. After swap, x: " << x << " y: " << y << "\n";
     
     int * array = new int[2];
     std::cout << "arr1 &: " << array << "\n";
     function1(array);
     function2(array);
     
     std::cout << "Array, 0: " << array[0] << " 1: " << array[1] << "\n";
     //delete[] array;
     //array = NULL;
     std::cout << "Array, 0: " << array[0] << " 1: " << array[1] << "\n";
     
     return 0;
 }
 
 void function1(int *arr)
 {
     std::cout << "arr2 &: " << arr << "\n";
     arr[0] = 100;
     arr[1] = 200;
     function2(arr);
 }
 
 void function2(int * arr)
 {
    std::cout << "arr3 &: " << arr << "\n";
    arr[0] = 400;
    arr[1] = 300;    
 }
 
 void swap (int *px, int *py)
 {
     int temp;
 
     std::cout << "Swap. Before swap, *px: " << *px << " *py: " << *py << "\n";

 
     temp = *px;
     *px = *py;
     *py = temp;
 
     std::cout << "Swap. After swap, *px: " << *px << " *py: " << *py << "\n";

 }
