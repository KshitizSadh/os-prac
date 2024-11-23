#include <iostream>
#include <pthread.h>
#include <vector>

struct ThreadData {
    std::vector<int>* data;
    int start, end;
    int sum;
};

void* sum_partial(void* arg) {
    ThreadData* td = (ThreadData*)arg;
    td->sum = 0;
    for (int i = td->start; i < td->end; ++i) {
        td->sum += (*td->data)[i];
    }
    return nullptr;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> data(n);
    std::cout << "Enter the numbers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    pthread_t threads[2];
    ThreadData td1 = {&data, 0, n / 2, 0};
    ThreadData td2 = {&data, n / 2, n, 0};

    pthread_create(&threads[0], nullptr, sum_partial, &td1);
    pthread_create(&threads[1], nullptr, sum_partial, &td2);

    pthread_join(threads[0], nullptr);
    pthread_join(threads[1], nullptr);

    int total_sum = td1.sum + td2.sum;
    std::cout << "Total sum: " << total_sum << std::endl;

    return 0;
}
