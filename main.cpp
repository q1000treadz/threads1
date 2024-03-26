#include <iostream>
#include "omp.h"
#include <algorithm>
#include <mutex>
#include<vector>
using namespace std;
int main() {
    int k, N;
    cout << "Num of threads: ";
    cin >> k;
    cout << "Value of N: ";
    cin >> N;

    int total_sum = N;
    #pragma omp parallel num_threads(k) reduction(+:total_sum)
    {
        int id = omp_get_thread_num();
        int start = N/k * id;
        int end = N / k * (id +1);
        int partial_sum = 0;
        for (int i = start; i < end; i += 1)
        {
            partial_sum += i;
        }
        #pragma omp critical
        {
            cout << "[" << id << "]: Sum = " << partial_sum << endl;
        }
        total_sum += partial_sum;
    }
    cout << "Sum = " << total_sum << endl;

    return 0;
}