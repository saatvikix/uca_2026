#include <iostream>
#include <vector>
using namespace std;
vector<int> getFibonacciSequence(int n) {

    if(n <= 0) return {};

    //initial
    vector<int> fib(2,1);
    int prev = 1;
    int secondPrev = 0;

    int num = 0;

    while(num <= n) {
        
        num = fib[prev] + fib[secondPrev];

        if(num > n) break;

        fib.push_back(num);

        prev++;
        secondPrev++;
        
    }

    return fib;
}

int main() {

    vector<int> fibonacciNums = getFibonacciSequence(50);
    int sum = 0;

    for(int x: fibonacciNums) {
        if(x%2 == 0) {
            sum += x;
        }
    }

    cout<<"Sum: "<<sum<<endl;

}