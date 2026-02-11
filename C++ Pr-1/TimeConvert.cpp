#include<iostream>
using namespace std;

class TimeConverter {
private:
    int hours, minutes, seconds, totalSeconds;

public:
    void secondsToTime(int sec) {
        hours = sec / 3600;
        minutes = (sec % 3600) / 60;
        seconds = sec % 60;

        cout << "HH:MM:SS => "
             << hours << ":" 
             << minutes << ":" 
             << seconds << endl;
    }

    void timeToSeconds(int h, int m, int s) {
        totalSeconds = (h * 3600) + (m * 60) + s;

        cout << "Total Seconds => " 
             << totalSeconds << endl;
    }
};

int main() {
    TimeConverter obj;

    int choice;

    cout << "1. Convert Seconds to HH:MM:SS\n";
    cout << "2. Convert HH:MM:SS to Seconds\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int sec;
        cout << "Enter total seconds: ";
        cin >> sec;
        obj.secondsToTime(sec);
    }
    else if (choice == 2) {
        int h, m, s;
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
        obj.timeToSeconds(h, m, s);
    }
    else {
        cout << "Invalid Choice!";
    }

    return 0;
}

//output
//1. Convert Seconds to HH:MM:SS
//2. Convert HH:MM:SS to Seconds
//Enter your choice: 1
//Enter total seconds: 4200
//HH:MM:SS => 1:10:0

//1. Convert Seconds to HH:MM:SS
//2. Convert HH:MM:SS to Seconds
//Enter your choice: 2
//Enter hours: 4
//Enter minutes: 34
//Enter seconds: 30
//Total Seconds => 16470