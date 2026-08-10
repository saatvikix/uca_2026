#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RunningMedian {

private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:

    RunningMedian() {}


    void insert(int num) {

        if (left.empty() || num <= left.top()) {
            left.push(num);
        }
        else {
            right.push(num);
        }


        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }


    float getMedian() {

        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0f;
        }

        return left.top();
    }
};

int main() {

    RunningMedian rm;

    int stream[] = {5, 15, 1, 3};

    for (int num : stream) {

        rm.insert(num);

        cout << "Inserted: " << num
             << "  Median: " << rm.getMedian()
             << endl;
    }

    return 0;
}