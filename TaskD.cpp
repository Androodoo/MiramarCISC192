#include <iostream>
#include <iomanip>
int main() {
    int items = 0; //my solution to bug 1
    double price = 0.00;
    std::cout << "Enter items and price: ";
    std::cin >> items >> price; //but would items & price be initialized here?

    // BUG 1: uninitialized total
    double total = (static_cast<double>(items)) * price; 

    // BUG 2: integer division
    int discountPercent = 15;
    double discount = total * (static_cast<double>(discountPercent) / 100.0); //is this not correct? it turns 15 into a double that allows it to divide 15.0/100.0

    // BUG 3: precedence & shipping

    double afterDiscount = total - discount;
    double shipping;
    if (afterDiscount >= 100.0){
        shipping = 0;
    }
    else{
        shipping = 5.0 + (2.0 * static_cast<double>(items));
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total: $" << total << "\n";
    std::cout << "Discount: $" << discount << "\n";
    std::cout << "Shipping: $" << shipping << "\n";
    std::cout << "Grand Total: $" << (afterDiscount + shipping) << "\n";
}