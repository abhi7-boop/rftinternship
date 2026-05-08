#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n = "", double p = 0) {
        name = n;
        price = p;
    }
};

class CartItem {
public:
    Product product;
    int quantity;

    CartItem(Product p, int q) {
        product = p;
        quantity = q;
    }
};

class Cart {
private:
    vector<CartItem> items;

public:

    // Add product
    void addProduct(Product p, int qty) {
        // check if product already exists -> increase quantity
        for (auto &item : items) {
            if (item.product.name == p.name) {
                item.quantity += qty;
                cout << "Quantity updated!\n";
                return;
            }
        }
        items.push_back(CartItem(p, qty));
        cout << "Product added to cart!\n";
    }

    // Remove product
    void removeProduct(string name) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].product.name == name) {
                items.erase(items.begin() + i);
                cout << "Product removed!\n";
                return;
            }
        }
        cout << "Product not found!\n";
    }

    // Calculate total
    double calculateTotal() {
        double total = 0;
        for (auto item : items)
            total += item.product.price * item.quantity;
        return total;
    }

    // Apply discount
    double applyDiscount(double total) {
        if (total > 1000) {
            cout << "10% Discount Applied!\n";
            total *= 0.9;
        }
        return total;
    }

    // Display bill summary
    void displayBill() {
        if (items.empty()) {
            cout << "Cart is empty!\n";
            return;
        }

        cout << "\n------ BILL SUMMARY ------\n";
        cout << left << setw(15) << "Product"
             << setw(10) << "Price"
             << setw(10) << "Qty"
             << setw(10) << "Total\n";

        double total = 0;

        for (auto item : items) {
            double itemTotal = item.product.price * item.quantity;
            total += itemTotal;

            cout << left << setw(15) << item.product.name
                 << setw(10) << item.product.price
                 << setw(10) << item.quantity
                 << setw(10) << itemTotal << endl;
        }

        cout << "--------------------------\n";
        cout << "Subtotal: " << total << endl;

        total = applyDiscount(total);

        cout << "Final Amount: " << total << endl;
        cout << "--------------------------\n";
    }
};

int main() {
    Cart cart;
    int choice;

    while (true) {
        cout << "\n1. Add Product\n2. Remove Product\n3. Show Bill\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            double price;
            int qty;

            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> qty;

            cart.addProduct(Product(name, price), qty);
        }

        else if (choice == 2) {
            string name;
            cout << "Enter product name to remove: ";
            cin >> name;
            cart.removeProduct(name);
        }

        else if (choice == 3) {
            cart.displayBill();
        }

        else if (choice == 4) {
            cout << "Thank you!\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }
}