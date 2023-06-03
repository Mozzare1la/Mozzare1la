#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("file.txt"); 
    if (!file) {
        std::cout << "Не удалось открыть файл.\n";
        return 1;
    }

    std::vector<int> wordLengths(21, 0); 

    std::string word;
    while (file >> word) {
        int length = word.length();
        if (length <= 20) {
            ++wordLengths[length]; 
        }
    }

    file.close(); 

    for (int i = 1; i <= 20; ++i) {
        std::cout << "Слов из " << i << " символов: " << wordLengths[i] << std::endl;
    }

    // б) выводим гистограмму длин слов
    std::cout << "\nГистограмма длин слов:\n";
    for (int i = 1; i <= 20; ++i) {
        std::cout << i << " символов: ";
        for (int j = 0; j < wordLengths[i]; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // в) определяем общее количество слов в файле
    int totalWords = 0;
    for (int i = 1; i <= 20; ++i) {
        totalWords += wordLengths[i];
    }

    std::cout << "\nОбщее количество слов в файле: " << totalWords << std::endl;

    return 0;
}