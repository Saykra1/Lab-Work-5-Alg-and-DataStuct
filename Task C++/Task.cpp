#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    // ������� ���������� ����� ��������
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

    // ������� ���� ������������ �������
    do {
        int current_path = 0;
        // ��������� ���������� ����� �������� � ������������
        for (int i = 0; i < n - 1; i++) {
            current_path += dist[cities[i]][cities[i + 1]];
        }
        // ������������ � ��������� �����
        current_path += dist[cities[n - 1]][cities[0]];

        // ��������� �� ����� �������
        if (current_path < min_path) {
            min_path = current_path;
            best_path = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    // ����� ����������
    cout << "����������� ����: " << min_path << endl;
    cout << "�������: ";
    for (int city : best_path) {
        cout << city << " ";
    }
    cout << best_path[0] << endl;

    return 0;
}