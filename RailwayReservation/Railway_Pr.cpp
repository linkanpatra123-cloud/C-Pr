#include <iostream>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        trainName[0] = '\0';
        source[0] = '\0';
        destination[0] = '\0';
        trainTime[0] = '\0';
        trainCount++;
    }

    Train(int num, const char name[], const char src[],
          const char dest[], const char time[]) {

        trainNumber = num;

        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    ~Train() {
        trainCount--;
    }
 
    void strcpy(char destination[], const char source[]) {
        int i = 0;
        while (source[i] != '\0') {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0';
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }

    void inputTrainDetails() {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "\n-----------------------------";
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime;
        cout << "\n-----------------------------\n";
    }
};

int Train::trainCount = 0;


class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 3;

        trains[0] = Train(22973, "GIMB Puri Sup Exp", "Surat", "Bhubaneswar", "06:00");
        trains[1] = Train(12844, "ADI Puri Sup Exp", "Ahemdavad", "Puri", "07:30");
        trains[2] = Train(19021, "BAM Amrit Bharat", "Udhna", "Berhampur", "09:15");
    }

    void addTrain() {
        if (totalTrains >= 100) {
            cout << "Storage Full!\n";
            return;
        }

        trains[totalTrains].inputTrainDetails();
        totalTrains++;
        cout << "Train Added Successfully!\n";
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "No Records Available!\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train Not Found!\n";
    }
};


int main() {
    RailwaySystem system;
    int choice, number;

    do {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting Program...\n";
            break;            

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}