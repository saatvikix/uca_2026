#include <iostream>

using namespace std;

int evenFibonacciSum(int n) {
    
    if(n<=1) return 0;

    //initial fib sequence
    int prev = 1;
    int secondPrev = 1;

    int num = 0;
    int sum = 0;

    while( num <= n ) {

        num = prev + secondPrev;

        if(num > n) {
            break;
        }

        if(num % 2 == 0) {
            sum += num;

        }


        secondPrev = prev;
        prev = num;
    }

    return sum;
}

int main() {

    cout<<evenFibonacciSum(50)<<endl;
}