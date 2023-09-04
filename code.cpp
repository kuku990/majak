// #include<bits/stdc++.h>

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <string>

// using namespace std;

// struct Product {
//     string name;
//     double length;
//     double width;
//     double height;
//     string dimension_unit;
//     double weight;
//     string weight_unit;
//     int quantity;
// };

// struct SizeClass {
//     string name;
//     double min_dim;
//     double max_dim;
//     double min_weight;
//     double max_weight;
//     double price;
// };

// vector<SizeClass> sizeClasses = {
//     {"X-Small",0.0, 25.0,0.0, 1000.0, 100},
//     {"Small", 0.0,55.0,0.0, 5000.0, 200},
//     {"Medium", 0.0,105.0, 0.0,25000.0, 300},
//     {"Large", 0.0,105.0, 0.0,25000.0, 400}
// };

// double getPriceBasedUnit(const Product& product){
//     double length = 0.0;
//     double width = 0.0;
//     double weight =0.0;
//     double maxminunit = 0.0;
//     double unitPrice =0.0;
//     if (product.dimension_unit == "M"){
//       length = product.length * 100;
//       width = product.width * 100;
//     }else{
//       length = product.length;
//       width = product.width;
//     }
//   if (product.weight_unit == "KG"){
//       weight = product.weight * 1000;
//     }else{
//         weight = product.weight ;
//     }
  
//   cout<< weight;
//   maxminunit = length + width;
//   cout<< "max unit"<< maxminunit<<endl;
//   for (const SizeClass& sizeClass : sizeClasses) {
//       cout<<"here "<<sizeClass.max_weight<<" "<< sizeClass.max_dim<<endl;
//         if ((weight > sizeClass.min_weight && weight <= sizeClass.max_weight) && (maxminunit > sizeClass.min_dim && maxminunit <= sizeClass.max_dim)) {
//             unitPrice = sizeClass.price;
//             cout<<"unit price"<< unitPrice;
//         }
//     }
//   return unitPrice;
  
// }

// int main() {
//     vector<Product> products = {
//         {"ToyOne", 90, 50, 40, "CM", 8000, "GM", 45},
//         {"ToyTwo", 1.2, 0.3, 0.2, "M", 9000, "GM", 28}
//     };

//     int totalCost = 0;
   
//     for (const Product& product : products){
//         int unitPrice = getPriceBasedUnit(product);
//         totalCost += unitPrice * product.quantity;
//     }
//     cout << "Total fulfillment cost: $" << totalCost << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string name;
    double length;
    double width;
    double height;
    string dimension_unit;
    double weight;
    string weight_unit;
    int quantity;
};

struct SizeClass {
    string name;
    double min_dim;
    double max_dim;
    double min_weight;
    double max_weight;
    double price;
};

vector<SizeClass> sizeClasses = {
    {"X-Small", 0.0, 25.0, 0.0, 1000.0, 100},
    {"Small", 0.0, 55.0, 0.0, 5000.0, 200},
    {"Medium", 0.0, 105.0, 0.0, 25000.0, 300},
    {"Large", 0.0, 105.0, 0.0, 25000.0, 400}
};

double getPriceBasedUnit(const Product& product) {
    double length = product.length;
    double width = product.width;
    double weight = product.weight;
    double maxminunit = length + width;
    double unitPrice = 0.0;

    // Convert dimensions and weight to appropriate units
    if (product.dimension_unit == "M") {
        length *= 100.0;
        width *= 100.0;
    }
    if (product.weight_unit == "KG") {
        weight *= 1000.0;
    }


    // if (maxminunit <= 25.0 && weight <= 1000.0) {
    //     unitPrice = 100.0;
    // } else if (maxminunit <= 55.0 && weight <= 5000.0) {
    //     unitPrice = 200.0;
    // } else if (maxminunit <= 105.0 && weight <= 25000.0) {
    //     unitPrice = 300.0;
    // } else {
    //     unitPrice = 400.0;
    // }
    for (const SizeClass& sizeClass : sizeClasses) {
        if ((weight >= sizeClass.min_weight && weight <= sizeClass.max_weight) &&
            (maxminunit >= sizeClass.min_dim && maxminunit <= sizeClass.max_dim)) {
            unitPrice = sizeClass.price;
            cout<<unitPrice<<endl;
            break; // Stop searching once a matching size class is found.
        }else{
            unitPrice = 400;
        }
    }

    return unitPrice;
}


int main() {
    vector<Product> products = {
        {"ToyOne", 90, 50, 40, "CM", 8000, "GM", 45},//140, 8000 = 300 *45
        {"ToyTwo", 1.2, 0.3, 0.2, "M", 9000, "GM", 28} //400 * 28
    };

    double totalCost = 0;

    for (const Product& product : products) {
        cout<<"here 1"<<endl;
        double unitPrice = getPriceBasedUnit(product);
        totalCost += unitPrice * product.quantity;
    }

    cout << "Total fulfillment cost: $" << totalCost << endl;

    return 0;
}
