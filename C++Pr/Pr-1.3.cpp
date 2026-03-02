#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    double speed;   

public:
 
    void setModel(string m) {
        model = m;
    }

    void setSpeed(double s) {
        speed = s;
    }

    string getModel() {
        return model;
    }

    double getSpeed() {
        return speed;
    }
};

class Car : public Vehicle {
public:
    double calculateTime(double distance) {
        return distance / getSpeed();  
    }
};

class Bike : public Vehicle {
public:
    double calculateTime(double distance) {
        return distance / getSpeed(); 
    }
};

int main() {

    double distance;

    Car car;
    car.setModel("Honda City");
    car.setSpeed(80); 

    Bike bike;
    bike.setModel("Yamaha R15");
    bike.setSpeed(60); 

    cout << "Enter Distance (in km): ";
    cin >> distance;

    cout << "\n--- Time Calculation ---\n";
    cout << "Car Model: " << car.getModel() << endl;
    cout << "Time taken by Car: " << car.calculateTime(distance) << " hours\n";

    cout << "\nBike Model: " << bike.getModel() << endl;
    cout << "Time taken by Bike: " << bike.calculateTime(distance) << " hours\n";

    return 0;
}


//output
//Enter Distance (in km): 100
//
//--- Time Calculation ---
//Car Model: Honda City
//Time taken by Car: 1.25 hours
//
//Bike Model: Yamaha R15
//Time taken by Bike: 1.66667 hours