#include <iostream>
using namespace std;

void processArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
}

void processArray(double arr[], int size){
    double sum = 0;
    for(int i = 0;i < size; i++){
        sum += arr[i];
    }
    cout << "ave = " << sum/size << endl;
}
int main(int argc,char *argv[])
{
    int arr_int[] = {1,2,3,4,5};
    double arr_double[] = {1.1,2.2,3.3,4.4,5.5};

    processArray(arr_int,sizeof(arr_int)/sizeof(arr_int[0]));
    processArray(arr_double,sizeof(arr_double)/sizeof(arr_double[0]));
    return 0;
}

