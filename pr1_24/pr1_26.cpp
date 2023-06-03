#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_product_of_two_primes(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (is_prime(i) && num % i == 0) {
            int factor = num / i;
            if (is_prime(factor)) {
                return true;
            }
        }
    }
    return false;
}

bool is_cube_of_prime(int num) {
    int cube_root = round(pow(num, 1.0 / 3.0));
    if (pow(cube_root, 3) == num) {
        return is_prime(cube_root);
    }
    return false;
}

int getValidInput() {
    int num;
    while (true) {
        std::cout << "Введите натуральное число: ";
        std::cin >> num;

        if (std::cin.fail() || num <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, введите натуральное число." << std::endl;
        }
        else {
            break;
        }
    }
    return num;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int num = getValidInput();

    bool is_product = is_product_of_two_primes(num);
    bool is_cube = is_cube_of_prime(num);

    if (is_product) {
        std::cout << num << " можно представить в виде произведения двух простых чисел." << std::endl;
    }
    else {
        std::cout << num << " нельзя представить в виде произведения двух простых чисел." << std::endl;
    }

    if (is_cube) {
        std::cout << num << " можно представить в виде куба какого-либо простого числа." << std::endl;
    }
    else {
        std::cout << num << " нельзя представить в виде куба какого-либо простого числа." << std::endl;
    }

    return 0;
}