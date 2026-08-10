#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        double loadA = (double)a.first / a.second;
        double loadB = (double)b.first / b.second;

        return loadA < loadB; 
    }
};

int main() {

    int n, k;

    cout << "Enter the number of villages: ";
    cin >> n;

    cout << "Enter the number of clinics: ";
    cin >> k;

    vector<int> population(n);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   Compare> pq;


    for (int i = 0; i < n; i++) {

        cout << "Enter the population of village " << i << ": ";
        cin >> population[i];

        pq.push({population[i], 1});

        k--;
    }


    while (k > 0) {

        pair<int, int> village = pq.top();
        pq.pop();

  
        village.second++;

        pq.push(village);

        k--;
    }

  
    pair<int, int> answer = pq.top();

    double maxLoad = (double)answer.first / answer.second;

    cout << fixed << setprecision(2);
    cout << maxLoad << endl;

    return 0;
}