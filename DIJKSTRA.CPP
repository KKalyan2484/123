#include <iostream>

class DijkstrasAlgorithm {
private:
    int n;
    int c[10][10];
    int src;

public:
    DijkstrasAlgorithm() {
        n = 0;
        src = 0;
    }

    void getInput() {
        std::cout << "Enter the number of vertices: ";
        std::cin >> n;

        std::cout << "Enter the cost matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> c[i][j];
            }
        }

        std::cout << "Enter the source node: ";
        std::cin >> src;
    }

    void findShortestPaths() {
        int vis[10], dist[10];
        int u, j, count, min;

        for (j = 1; j <= n; j++) {
            dist[j] = c[src][j];
        }

        for (j = 1; j <= n; j++) {
            vis[j] = 0;
        }

        dist[src] = 0;
        vis[src] = 1;
        count = 1;

        while (count != n) {
            min = 9999;

            for (j = 1; j <= n; j++) {
                if (dist[j] < min && vis[j] != 1) {
                    min = dist[j];
                    u = j;
                }
            }

            vis[u] = 1;
            count++;

            for (j = 1; j <= n; j++) {
                if (min + c[u][j] < dist[j] && vis[j] != 1) {
                    dist[j] = min + c[u][j];
                }
            }
        }

        std::cout << "\nThe shortest distances from source node " << src << " are:\n";
        for (j = 1; j <= n; j++) {
            std::cout << src << " -----> " << j << " = " << dist[j] << std::endl;
        }
    }
};

int main() {
    DijkstrasAlgorithm dijkstrasObj;
    dijkstrasObj.getInput();
    dijkstrasObj.findShortestPaths();

    return 0;
}
