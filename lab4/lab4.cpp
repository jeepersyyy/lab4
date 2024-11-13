#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

void task38() {
    std::cout << "Task: 38\n";
    int n;

    while (true) {
        std::cout << "Введите число n: ";
        std::cin >> n;

        if (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректно, введите натуральное число \n";
        }
        else {
            break;
        }
    }

    double result = 0.0;

    for (int k = 1; k <= n; ++k) {
        result += 1.0 / std::pow((2 * k + 1), 2);
    }
    std::cout << "Итог: " << result << std::endl;
}

void task64() {
    std::cout << "Task: 64\n";
    double a;
    int n;

    while (true) {
        std::cout << "Введите вещественное число a: ";
        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректно, введите вещественное число \n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Введите натуральное число n: ";
        std::cin >> n;
        if (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректно, введите натуральное число \n";
        }
        else {
            break;
        }
    }

    double* values = new double[n];
    values[0] = a;

    for (int i = 1; i < n; ++i) {
        values[i] = values[i - 1] * a;
    }

    std::cout << "Значения a_1, a_2, ..., a_" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "a_" << i + 1 << " = " << values[i] << "\n";
    }

    delete[] values;
}

void task101() {
    int numStudents;
    std::cout << "Введите количество учеников в каждом классе: ";
    std::cin >> numStudents;

    if (numStudents <= 0) {
        std::cout << "Некорректно, число должно быть положительным.\n";
        return;
    }

    vector<int> class1(numStudents);
    std::vector<int> class2(numStudents);

    std::cout << "Введите оценки для первого класса:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cin >> class1[i];
    }

    std::cout << "Введите оценки для второго класса:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cin >> class2[i];
    }

    int excellent1 = 0, good1 = 0, satisfactory1 = 0, unsatisfactory1 = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (class1[i] == 5) {
            excellent1++;
        }
        else if (class1[i] == 4) {
            good1++;
        }
        else if (class1[i] == 3) {
            satisfactory1++;
        }
        else {
            unsatisfactory1++;
        }
    }

    int excellent2 = 0, good2 = 0, satisfactory2 = 0, unsatisfactory2 = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (class2[i] == 5) {
            excellent2++;
        }
        else if (class2[i] == 4) {
            good2++;
        }
        else if (class2[i] == 3) {
            satisfactory2++;
        }
        else {
            unsatisfactory2++;
        }
    }

    std::cout << "Результаты для первого класса:\n";
    std::cout << "Отлично: " << excellent1 << "\n";
    std::cout << "Хорошо: " << good1 << "\n";
    std::cout << "Удовлетворительно: " << satisfactory1 << "\n";
    std::cout << "Неудовлетворительно: " << unsatisfactory1 << "\n";

    std::cout << "Результаты для второго класса:\n";
    std::cout << "Отлично: " << excellent2 << "\n";
    std::cout << "Хорошо: " << good2 << "\n";
    std::cout << "Удовлетворительно: " << satisfactory2 << "\n";
    std::cout << "Неудовлетворительно: " << unsatisfactory2 << "\n";
}

void task162() {
    int n;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Некорректно, введите натуральное число.\n";
        return;
    }

    int sum1 = 0, sum2 = 0;
    int position = 0;

    while (n > 0) {
        int digit = n % 10;

        if (position % 2 == 0) {
            sum1 += digit;
        }
        else {
            sum1 -= digit;
        }

        if (position % 2 == 0) {
            sum2 = digit - sum2;
        }
        else {
            sum2 = digit + sum2;
        }

        n /= 10;
        position++;
    }

    std::cout << "Сумма знакочередующихся цифр по формуле 1: " << sum1 << std::endl;
    std::cout << "Сумма знакочередующихся цифр по формуле 2: " << sum2 << std::endl;
}

void task100() {
    const int numRegions = 10;
    double areas[numRegions];
    double yields[numRegions];

    for (int i = 0; i < numRegions; ++i) {
        std::cout << "Введите площадь, которую засеете пшеницей в районе " << (i + 1) << " (в гектарах): ";
        std::cin >> areas[i];
        if (areas[i] <= 0) {
            std::cout << "Площадь не может быть отрицательной \n";
            return;
        }

        std::cout << "Введите среднюю урожайность в районе " << (i + 1) << " (в центнерах с гектара): ";
        std::cin >> yields[i];
        if (yields[i] <= 0) {
            std::cout << "Урожайность не может быть отрицательной \n";
            return;
        }
    }

    double totalWheat = 0;
    double totalArea = 0;

    // количество пшеницы и площади
    for (int i = 0; i < numRegions; ++i) {
        totalWheat += areas[i] * yields[i];
        totalArea += areas[i];
    }

    // Вычисление средней урожайности
    double averageYield = totalWheat / totalArea;

    std::cout << "Околичество пшеницы собранное в области: " << totalWheat << " центнеров\n";
    std::cout << "Средняя урожайность по области: " << averageYield << " центнеров с гектара\n";
}

void task269() {
    int n;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Некорректно, введите натуральное число.\n";
        return;
    }

    int max1 = -1, max2 = -1;
    int min1 = 10, min2 = 10;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;

        if (digit > max1) {
            max2 = max1;
            max1 = digit;
        }
        else if (digit > max2) {
            max2 = digit;
        }

        if (digit < min1) {
            min2 = min1;
            min1 = digit;
        }
        else if (digit < min2) {
            min2 = digit;
        }
    }

    std::cout << "Две максимальные цифры: " << max1 << " и " << max2 << std::endl;
    std::cout << "Две минимальные цифры: " << min1 << " и " << min2 << std::endl;

}

void task197() {
    const double epsilon = 1e-6; //значение 10^-6
    double previous = 1.0;
    double current;
    int i = 2;

    while (true) {
        current = 1.0 / i;

        if (std::abs(previous - current) < epsilon) {
            std::cout << "Первые два рядом стоящих элемента, разность которых меньше " << epsilon << ": " << previous << " и " << current << std::endl;
            break;
        }

        previous = current;
        i++;
    }
}

void task45() {
    int n;

    while (true) {
        std::cout << "Введите число n: ";
        std::cin >> n;
        if (std::cin.fail() || n <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректно, введите натуральное число.\n";
        }
        else {
            break;
        }
    }

    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        sum += static_cast<double>(i + 1) / i;
    }

    std::cout << "Результат: " << sum << std::endl;
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void task206() {
    int n;
    double E;
    double sum = 0.0;

    std::cout << "Введите количество членов ряда n: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Некорректно, введите натуральное число.\n";
        return;
    }

    std::cout << "Введите пороговое значение для модуля членов ряда E: ";
    std::cin >> E;
    if (E < 0) {
        std::cout << "Некорректно, введите неотрицательное число.\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        double term = (std::pow(3, i) * i) / (2.0 * i);
        if (std::abs(term) >= E) {
            sum += term;
        }
    }

    std::cout << "Сумма членов ряда, модуль которых больше или равен " << E << ": " << sum << std::endl;

}



void task253() {

    auto F = [](double x) -> double {
        return 2.6 * x * x - 1.4 * x + 3;
        };

    double a, b, h;


    std::cout << "Введите начальное значение a: ";
    std::cin >> a;
    std::cout << "Введите конечное значение b: ";
    std::cin >> b;
    std::cout << "Введите шаг h: ";
    std::cin >> h;

    if (h <= 0) {
        std::cerr << "Некорректно, шаг должен быть положительным числом\n";
        return;
    }
    if (a > b) {
        std::cerr << "Начальное значение должно быть меньше или равно конечному значению\n";
        return;
    }

    std::cout << std::setw(10) << "x" << std::setw(15) << "F(x)" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    for (double x = a; x <= b; x += h) {
        double fx = F(x);
        std::cout << std::setw(10) << x << std::setw(15) << fx << std::endl;
    }

}

int main() {
    //task38();
    //task45();
    //task64();
    //task101();
    //task162();
    //task253();
    //task100();
    //task269();
    //task206();
    //task197();
    return 0;
}