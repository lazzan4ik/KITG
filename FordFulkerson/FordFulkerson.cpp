// FordFulkerson.cpp: определяет точку входа для приложения.
//

#include "FordFulkerson.h"

void print_graph(const std::vector<std::vector<Edge>>& graph) {
    for (int u = 0; u < graph.size(); ++u) {
        std::cout << "Vertex " << u << ": ";
        for (const auto& edge : graph[u]) {
            std::cout << "(" << edge.to << ", cap=" << edge.capacity << ", flow=" << edge.flow << ") ";
        }
        std::cout << std::endl;
    }
}

// Функция для тестирования алгоритма
void test_fordFulkerson() {

    int n = 5;
    std::vector<std::vector<Edge>> graph(n);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 6);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 7);

    int source = 0;
    int sink = 4;

    // Запускаем алгоритм Форда-Фалкерсона
    int max_flow = fordFulkerson(graph, source, sink);

    // Выводим результат
    // Максимальный поток: 9
    std::cout << "Maximum flow from " << source << " to " << sink << " is " << max_flow << std::endl;
}

int main() {
    test_fordFulkerson();
    return 0;
}