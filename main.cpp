#include <iostream>
#include <string>
#include <map>

using namespace std;

class Product {
private:
    string name;
    int stock;
    double price;

public:
    Product(const string &name = "", int stock = 0, double price = 0.0) {
        this->name = name;
        this->stock = stock;
        this->price = price;
    }

    void updateStock(int quantity) {
        stock += quantity;
        if (stock < 0) {
            stock = 0;
        }
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    string getName() const {  // Getter olarak düzelttik
        return name;
    }

    int getStock() const {  // Getter olarak düzelttik
        return stock;
    }

    double getPrice() const {  // Getter olarak düzelttik
        return price;
    }
};

class Inventory {
private:
    map<string, Product> products;

public:
    void addProduct(const string &name, int stock, double price) {
        products[name] = Product(name, stock, price);
    }

    void updateStock(const string &name, int quantity) {
        if (products.find(name) != products.end()) {
            products[name].updateStock(quantity);
        } else {
            cout << "Ürün bulunamadý..." << endl;
        }
    }

    void setPrice(const string &name, double price) {
        if (products.find(name) != products.end()) {
            products[name].setPrice(price);
        } else {
            cout << "Ürün bulunamadý..." << endl;
        }
    }

    void sellProduct(const string &name, int quantity) {
        if (products.find(name) != products.end()) {
            products[name].updateStock(-quantity);
        } else {
            cout << "Ürün bulunamadý..." << endl;
        }
    }

    void listProducts() const {
        cout << "--- ÜRÜNLER ---" << endl;
        for (const auto &entry : products) {
            cout << "Ad: " << entry.second.getName()
                 << ", Stok: " << entry.second.getStock()
                 << ", Fiyat: " << entry.second.getPrice() << endl;
        }
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct("Bakliyat", 100, 60);
    inventory.addProduct("Sebze", 200, 70);
    inventory.addProduct("Meyve", 120, 75);

    inventory.updateStock("Bakliyat", 60);
    inventory.updateStock("Sebze", -30);

    inventory.setPrice("Bakliyat", 55);
    inventory.setPrice("Meyve", 85);

    inventory.listProducts();

    return 0;
}
