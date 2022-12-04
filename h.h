#include <iostream>

using namespace std;

class Sneakers {
private:
    string brand_;
    int size_;
    string color_;
    string material_;
    double price_;
    int quantity_;
    int numberOfSales_;

public:
    Sneakers() {}
    Sneakers(string brand, int size, string color, string material, double price,
             int quantity, int numberOfSales) {
        brand_ = brand;
        size_ = size;
        color_ = color;
        material_ = material;
        price_ = price;
        quantity_ = quantity;
        numberOfSales_ = numberOfSales;
    }

    string GetBrand() { return brand_; }

    string GetColor() { return color_; }

    string GetMaterial() { return material_; }

    int GetSize() { return size_; }

    double GetPrice() { return price_; }

    void SetPrice(double value) { price_ = value; }

    int GetQuantity() { return quantity_; }

    int GetNumberOfSales() { return numberOfSales_; }

    void SetNumberOfSales(double value) { numberOfSales_ = value; }
};

class SportShoesStore {
public:
    Sneakers assortment[5]{};

    void priceSorting() {
        Sneakers temp;
        cout << " " << endl;
        cout << "SORTING BY PRICE" << endl; cout << " " << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (assortment[j].GetPrice() < assortment[i].GetPrice()) {
                    temp = assortment[i];
                    assortment[i] = assortment[j];
                    assortment[j] = temp;
                }
            }
        };
        for (int i = 4; i >= 0; i--) {
            cout << assortment[i].GetBrand()
                 << "   Price: " << assortment[i].GetPrice()
                 << "   Quantity: " << assortment[i].GetQuantity() << endl;
        }
    }

    void numberOfSalesSorting() {
        Sneakers temp;
        cout << " " << endl; cout << " " << endl; cout << " " << endl;
        cout << "TOP 3 BY NUMBER OF SALES" << endl;
        cout << " " << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (assortment[j].GetNumberOfSales() < assortment[i].GetNumberOfSales())
                {
                    temp = assortment[i];
                    assortment[i] = assortment[j];
                    assortment[j] = temp;
                }
            }
        };

        for (int i = 4; i >= 2; i--) {
            cout << assortment[i].GetBrand()
                 << "   Number of sales: " << assortment[i].GetNumberOfSales()
                 << "   Price: " << assortment[i].GetPrice()
                 << "   Quantity: " << assortment[i].GetQuantity() << endl;
        }
    }
};

int main() {
    SportShoesStore a = SportShoesStore();
    a.assortment[0] = Sneakers("Nike", 36, "White", "Plastic", 2399.9, 310, 34);
    a.assortment[1] = Sneakers("Bibi", 37, "Blue", "Plastic", 2499.9, 250, 99);
    a.assortment[2] = Sneakers("Adidas", 43, "Black", "Plastic", 2999.9, 350, 55);
    a.assortment[3] = Sneakers("Fop", 39, "White", "Plastic", 6999.9, 201, 150);
    a.assortment[4] = Sneakers("Nirt", 38, "Pink", "Metal", 8999.9, 99, 10);

    a.priceSorting();
    a.numberOfSalesSorting();

    return 0;
}