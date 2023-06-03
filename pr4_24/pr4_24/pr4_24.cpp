#include <iostream>
#include <vector>

// Структура для хранения информации о станке
struct Machine {
    std::string name;  // Наименование станка
    int downtime;      // Время простоя в месяц
    int uptime;        // Время работы в месяц
};

// Функция для вычисления общего времени простоя на заводе
int calculateTotalDowntime(const std::vector<Machine>& machines) {
    int totalDowntime = 0;
    for (const Machine& machine : machines) {
        totalDowntime += machine.downtime;
    }
    return totalDowntime;
}

// Функция для составления списка станков без простоя
std::vector<std::string> findMachinesWithoutDowntime(const std::vector<Machine>& machines) {
    std::vector<std::string> machinesWithoutDowntime;
    for (const Machine& machine : machines) {
        if (machine.downtime == 0) {
            machinesWithoutDowntime.push_back(machine.name);
        }
    }
    return machinesWithoutDowntime;
}

// Функция для вычисления относительного времени простоя каждого станка в процентах
std::vector<double> calculateRelativeDowntime(const std::vector<Machine>& machines) {
    std::vector<double> relativeDowntime;
    int totalUptime = 0;
    for (const Machine& machine : machines) {
        totalUptime += machine.uptime;
    }
    for (const Machine& machine : machines) {
        double downtimePercentage = static_cast<double>(machine.downtime) / totalUptime * 100.0;
        relativeDowntime.push_back(downtimePercentage);
    }
    return relativeDowntime;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание и инициализация списка станков
    std::vector<Machine> machines = {
        {"Станок 1", 10, 200},
        {"Станок 2", 5, 180},
        {"Станок 3", 0, 220},
        {"Станок 4", 15, 190},
    };

    // Вычисление общего времени простоя на заводе
    int totalDowntime = calculateTotalDowntime(machines);
    std::cout << "Общее время простоя на заводе: " << totalDowntime << " часов" << std::endl;

    // Составление списка станков без простоя
    std::vector<std::string> machinesWithoutDowntime = findMachinesWithoutDowntime(machines);
    std::cout << "Станки без простоя:" << std::endl;
    for (const std::string& machine : machinesWithoutDowntime) {
        std::cout << "- " << machine << std::endl;
    }

    // Вычисление относительного времени простоя каждого станка в процентах
    std::vector<double> relativeDowntime = calculateRelativeDowntime(machines);
    std::cout << "Относительное время простоя станков (%):" << std::endl;
    for (size_t i = 0; i < machines.size(); ++i) {
        std::cout << "- " << machines[i].name << ": " << relativeDowntime[i] << "%" << std::endl;
    }

    return 0;
}