import java.util.*;

class TSP {
    public static void main(String[] args) {
        // Матрица расстояний между городами
        int[][] dist = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
        };
        int n = dist.length;
        List<Integer> cities = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cities.add(i);
        }

        int minPath = Integer.MAX_VALUE;
        List<Integer> bestPath = new ArrayList<>();

        // Генерация всех перестановок
        PermutationGenerator pg = new PermutationGenerator();
        for (List<Integer> perm : pg.permutations(cities)) {
            int currentPath = 0;
            // Суммируем расстояния между городами
            for (int i = 0; i < n - 1; i++) {
                currentPath += dist[perm.get(i)][perm.get(i + 1)];
            }
            // Возвращаемся в начальный город
            currentPath += dist[perm.get(n - 1)][perm.get(0)];

            // Проверяем на новый минимум
            if (currentPath < minPath) {
                minPath = currentPath;
                bestPath = new ArrayList<>(perm);
            }
        }

        // Вывод результата
        System.out.println("Минимальный путь: " + minPath);
        System.out.print("Маршрут: ");
        for (int city : bestPath) {
            System.out.print(city + " ");
        }
        System.out.println(bestPath.get(0));
    }
}

// Генератор перестановок
class PermutationGenerator {
    public <T> List<List<T>> permutations(List<T> elements) {
        List<List<T>> result = new ArrayList<>();
        generatePermutations(elements, 0, result);
        return result;
    }

    private <T> void generatePermutations(List<T> elements, int index, List<List<T>> result) {
        if (index == elements.size() - 1) {
            result.add(new ArrayList<>(elements));
            return;
        }
        for (int i = index; i < elements.size(); i++) {
            Collections.swap(elements, i, index);
            generatePermutations(elements, index + 1, result);
            Collections.swap(elements, i, index);
        }
    }
}