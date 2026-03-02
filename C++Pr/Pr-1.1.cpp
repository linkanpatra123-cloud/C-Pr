#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    string title;
    string genre;
    int releasedYear;

    void input() {
        cout << "Enter Movie Title: ";
        getline(cin, title);

        cout << "Enter Genre: ";
        getline(cin, genre);

        cout << "Enter Released Year: ";
        cin >> releasedYear;
        cin.ignore();  
    }

    void display() {
        cout <<endl<< "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Released Year: " << releasedYear << endl;
        cout << "------------------------" << endl;
    }
};

int main() {

    int n;
    cout << "Enter number of movies: ";
    cin >> n;
    cin.ignore(); 

    Movie movies[n]; 

    for(int i = 0; i < n; i++) {
        cout <<endl<< "Enter details for Movie " << i + 1 << endl;
        movies[i].input();
    }

    cout << "\n--- Movie Details ---\n";
    for(int i = 0; i < n; i++) {
        movies[i].display();
    }

    return 0;
}
//output
//Title: Avengers
//Genre: Action
//Released Year: 2012
//-------------------------
//Title: Avengers Infinity War
//Genre: Action
//Released Year: 2018
//-------------------------
//Title: Avengers End Game
//Genre: Action
//Released Year: 2019