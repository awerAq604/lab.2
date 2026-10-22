#include <iostream>
using namespace std;

void task1() {
    double cost;
    int student;

    cout << "Enter order cost and student status (0/1): ";
    cin >> cost >> student;

    if (cost < 0 || (student != 0 && student != 1)) {
        cout << "Invalid input\n";
        return;
    }

    int discount = 0;

    if (cost >= 60)
        discount = 10;
    else if (cost >= 30)
        discount = 5;

    if (student == 1 && discount < 7)
        discount = 7;

    double total = cost * (1 - discount / 100.0);

    cout << "Discount: " << discount << "%\n";
    cout << "Total: " << total << '\n';
}

void task2() {
    double foodCost;
    int people, tableService;

    cout << "Enter food cost, number of people "
        "and table service status (0/1): ";
    cin >> foodCost >> people >> tableService;

    if (foodCost < 0 || people <= 0 ||
        (tableService != 0 && tableService != 1)) {
        cout << "Invalid input\n";
        return;
    }

    double serviceFee = 0;

    if (tableService == 1) {
        serviceFee = foodCost * 0.10;

        if (serviceFee < 2)
            serviceFee = 2;

        if (foodCost < 100)
            serviceFee /= 2;
    }

    cout << "Food cost: " << foodCost << '\n';
    cout << "Service fee: " << serviceFee << '\n';
    cout << "Total: " << foodCost + serviceFee << '\n';
}

void task3() {
    char code;
    int portions;
    double price;
    const char* category;

    cout << "Enter dish code (M/S/D) and number of portions: ";
    cin >> code >> portions;

    if (portions < 1 || portions > 20) {
        cout << "Invalid number of portions\n";
        return;
    }

    switch (code) {
    case 'M':
        category = "Main course";
        price = 9;
        break;
    case 'S':
        category = "Soup";
        price = 6;
        break;
    case 'D':
        category = "Dessert";
        price = 4;
        break;
    default:
        cout << "Unknown dish code\n";
        return;
    }

    double cost = price * portions;
    int discount = 0;

    if (portions >= 5)
        discount = 8;

    double total = cost * (1 - discount / 100.0);

    cout << "Category: " << category << '\n';
    cout << "Cost before discount: " << cost << '\n';
    cout << "Total: " << total << '\n';
}

void task4() {
    char code;
    int portions, student, delivery;
    double price;

    cout << "Enter dish code (M/S/D), number of portions,\n"
        "student status (0/1) and delivery status (0/1): ";
    cin >> code >> portions >> student >> delivery;

    if (portions < 1 || portions > 20 ||
        (student != 0 && student != 1) ||
        (delivery != 0 && delivery != 1)) {
        cout << "Invalid input\n";
        return;
    }

    switch (code) {
    case 'M':
        price = 9;
        break;
    case 'S':
        price = 6;
        break;
    case 'D':
        price = 4;
        break;
    default:
        cout << "Unknown dish code\n";
        return;
    }

    double cost = price * portions;
    int discount = 0;

    if (portions >= 5)
        discount = 8;

    if (student == 1)
        discount = 10;

    double discountAmount = cost * discount / 100.0;
    double discountedCost = cost - discountAmount;
    double deliveryCost = 0;

    if (delivery == 1 && discountedCost < 50)
        deliveryCost = 5;

    cout << "Food cost: " << cost << '\n';
    cout << "Discount: " << discount << "% ("
        << discountAmount << ")\n";
    cout << "Delivery cost: " << deliveryCost << '\n';
    cout << "Total: " << discountedCost + deliveryCost << '\n';
}

int main() {
    int choice;

    cout << "Choose a task (1-4): ";

    if (!(cin >> choice)) {
        cout << "Invalid input\n";
        return 0;
    }

    switch (choice) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    default:
        cout << "Invalid task number\n";
    }

    return 0;
}