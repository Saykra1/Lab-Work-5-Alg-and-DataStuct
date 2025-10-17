#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    // Матрица расстояний между городами
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = dist.size();
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }

    int min_path = INT_MAX;
    vector<int> best_path;

    // Перебор всех перестановок городов
    do {
        int current_path = 0;
        // Суммируем расстояния между городами в перестановке
        for (int i = 0; i < n - 1; i++) {
            current_path += dist[cities[i]][cities[i + 1]];
        }
        // Возвращаемся в начальный город
        current_path += dist[cities[n - 1]][cities[0]];

        // Проверяем на новый минимум
        if (current_path < min_path) {
            min_path = current_path;
            best_path = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    // Вывод результата
    cout << "Минимальный путь: " << min_path << endl;
    cout << "Маршрут: ";
    for (int city : best_path) {
        cout << city << " ";
    }
    cout << best_path[0] << endl;

    return 0;
}