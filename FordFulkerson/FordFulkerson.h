// FordFulkerson.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Edge {
    int to;
    int capacity;
    int flow;
    int reverse;
};

void addEdge(std::vector<std::vector<Edge>>& graph, int from, int to, int capacity) {
    Edge forward_edge = { to, capacity, 0, (int)graph[to].size() };
    Edge backward_edge = { from, 0, 0, (int)graph[from].size() };
    graph[from].push_back(forward_edge);
    graph[to].push_back(backward_edge);
}

// Функция для выполнения BFS и поиска augmenting path
bool bfs(const std::vector<std::vector<Edge>>& graph, std::vector<int>& parent, int source, int sink) {
    int n = graph.size();
    parent.assign(n, -1);  // Инициализируем массив предков
    parent[source] = -2;   // Исходная вершина

    std::queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            if (parent[v] == -1 && edge.capacity > edge.flow) {
                parent[v] = u;
                q.push(v);

                if (v == sink) {
                    return true;  // Найден путь от истока к стоку
                }
            }
        }
    }

    return false;  // Путь не найден
}

// Функция для обновления потока по найденному пути
int dfs(std::vector<std::vector<Edge>>& graph, const std::vector<int>& parent, int u, int sink, int flow) {
    if (u == sink) {
        return flow;  // Достигли стока, возвращаем поток
    }

    for (auto& edge : graph[u]) {
        int v = edge.to;
        if (parent[v] != -1 && edge.capacity > edge.flow) {
            int pushed = dfs(graph, parent, v, sink, std::min(flow, edge.capacity - edge.flow));
            if (pushed > 0) {
                edge.flow += pushed;
                graph[v][edge.reverse].flow -= pushed;
                return pushed;
            }
        }
    }

    return 0; 
}

int fordFulkerson(std::vector<std::vector<Edge>>& graph, int source, int sink) {
    int max_flow = 0;
    std::vector<int> parent;

    while (bfs(graph, parent, source, sink)) {
        int flow = dfs(graph, parent, source, sink, INT_MAX);
        if (flow == 0) {
            break; 
        }
        max_flow += flow;
    }

    return max_flow;
}
