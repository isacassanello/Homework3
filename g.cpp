#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <functional> // Para std::greater

int main() {
    // Min-heap: menor número tiene más prioridad
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(20); pq.push(40);
    pq.push(10); pq.push(30);
    // Se imprimen elementos en orden de prioridad (menor a mayor)
    cout << "Contenido ordenado por prioridad (min-heap):\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}