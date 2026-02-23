#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

protected:
    static int totalVehicles;

public:
	
    Vehicle() {
        vehicleID = 0;
        manufacturer = " ";
        model = " ";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }


    void setVehicleID(int id) { vehicleID = id; }
    int getVehicleID() const { return vehicleID; }

    void setManufacturer(string manu) { manufacturer = manu; }
    string getManufacturer() const { return manufacturer; }

    void setModel(string mod) { model = mod; }
    string getModel() const { return model; }

    void setYear(int yr) { year = yr; }
    int getYear() const { return year; }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    virtual void display() {
        cout << "ID: " << vehicleID
             << "\nManufacturer: " << manufacturer
             << "\nModel: " << model
             << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr) {
        fuelType = fuel;
    }

    void display() override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int yr,
                string fuel, int battery)
        : Car(id, manu, mod, yr, fuel) {
        batteryCapacity = battery;
    }

    void display() override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
    }
};

class Aircraft {
protected:
    int flightRange;

public:
    Aircraft(int range) {
        flightRange = range;
    }

    void showRange() {
        cout << "Flight Range: " << flightRange << " km\n";
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string manu, string mod, int yr,
              string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() override {
        Car::display();
        showRange();
    }
};


class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int yr,
              string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery) {
        topSpeed = speed;
    }

    void display() override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h\n";
    }
};

class Sedan : public Car {
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
};

class SUV : public Car {
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
};

class VehicleRegistry {
private:
    Vehicle* vehicles[100];  
    int count;

public:
    VehicleRegistry() { count = 0; }

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            vehicles[count++] = v;
            cout << "Vehicle Added Successfully!\n";
        } else {
            cout << "Registry Full!\n";
        }
    }

    void displayAll() {
        for (int i = 0; i < count; i++) {
            cout << "\n--- Vehicle " << i + 1 << " ---\n";
            vehicles[i]->display();
        }
    }

};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n===== Vehicle Registry System =====\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. Add Flying Car\n";
        cout << "4. Add Sports Car\n";
        cout << "5. View All Vehicles\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            int id, year;
            string manu, model, fuel;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Manufacturer: ";
            cin >> manu;
            cout << "Model: ";
            cin >> model;
            cout << "Year: ";
            cin >> year;
            cout << "Fuel Type: ";
            cin >> fuel;

            if (choice == 1) {
                registry.addVehicle(new Car(id, manu, model, year, fuel));
            }
            else if (choice == 2) {
                int battery;
                cout << "Battery Capacity: ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
            }
            else if (choice == 3) {
                int range;
                cout << "Flight Range: ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
            }
            else if (choice == 4) {
                int battery, speed;
                cout << "Battery Capacity: ";
                cin >> battery;
                cout << "Top Speed: ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
            }
        }
        else if (choice == 5) {
            registry.displayAll();
        }
        
    } while (choice != 6);

    cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
    return 0;
}

//output
//1. Add Car
//2. Add Electric Car
//3. Add Flying Car
//4. Add Sports Car
//5. View All Vehicles
//6. Exit
//Enter choice: 1
//Enter ID: 15252
//Manufacturer: India
//Model: Audi7
//Year: 2025
//Fuel Type: Diesel
//Vehicle Added Successfully!
//
//===== Vehicle Registry System =====
//1. Add Car
//2. Add Electric Car
//3. Add Flying Car
//4. Add Sports Car
//5. View All Vehicles
//6. Exit
//Enter choice: 2
//Enter ID: 10102
//Manufacturer: India
//Model: MahindraBe6
//Year: 202
//Fuel Type: Electric
//Battery Capacity: 450
//Vehicle Added Successfully!
