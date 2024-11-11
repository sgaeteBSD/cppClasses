#include "Media.h"
#include "Game.h"
#include "Movie.h"
#include "Music.h"

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

void add(vector<Media*>& med);
void search(vector<Media*>& med);
//void deleter(vector<Media*>& med);
//void quit(vector<Media*>& med, bool& input);

int main() {
    vector<Media*> med;

    bool input = true;
    while (input == true) {

        cout << "Input a command." << endl;
        char command[6] = "";

        cin >> command;
        cin.ignore();

        if (strcmp(command, "ADD") == 0) {
            add(med);
            input = true; // run command loop again
        }
        else if (strcmp(command, "SEARCH") == 0) {
            search(med);
            input = true;
        }
        else if (strcmp(command, "DELETE") == 0) {
            //deleter(med);
            input = true;
        }
        else if (strcmp(command, "QUIT") == 0) {
            //quit(med, input);
        }
        else { // if command isn't one of the 4
            cout << "Invalid input! Try again." << endl;
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}

void add(vector<Media*>& med) {
    cout << "GAME. MOVIE, or MUSIC?" << endl;
    char medType[5] = "";
    char tempTitle[80];
    int tempYear;
    cin >> medType;
    cin.ignore();

    if (strcmp(medType, "GAME") == 0) {
        char tempPub[80];
        int tempRat;
        cout << "Title?" << endl;
        cin.getline(tempTitle, 80, '\n');
        cout << "Year?" << endl;
        cin >> tempYear;
        cin.ignore();
        cout << "Publisher?" << endl;
        cin.getline(tempPub, 80, '\n');
        cout << "Rating? (out of 10)" << endl;
        cin >> tempRat;
        cin.ignore();

        Game* nGame = new Game(tempTitle, tempYear, tempPub, tempRat);
        if (nGame != nullptr) {
            cout << nGame->getTitle() << endl;
            med.push_back(nGame);
            nGame->print();
        }
    }
    else if (strcmp(medType, "MOVIE") == 0) {
        char tempDirector[80];
        int tempDur;
        int tempRat;
        cout << "Title?" << endl;
        cin.getline(tempTitle, 80, '\n');
        cout << "Year?" << endl;
        cin >> tempYear;
        cin.ignore();
        cout << "Director?" << endl;
        cin.getline(tempDirector, 80, '\n');
        cout << "Duration (minutes)?" << endl;
        cin >> tempDur;
        cin.ignore();
        cout << "Rating? (out of 10)" << endl;
        cin >> tempRat;
        cin.ignore();

        Movie* nMovie = new Movie(tempTitle, tempYear, tempDirector, tempDur, tempRat);
        if (nMovie != nullptr) {
            med.push_back(nMovie);
            nMovie->print();
        }
    }
    else if (strcmp(medType, "MUSIC") == 0) {
        char tempArtist[80];
        char tempPub[80];
        int tempDur;
        cout << "Title?" << endl;
        cin.getline(tempTitle, 80, '\n');
        cout << "Year?" << endl;
        cin >> tempYear;
        cin.ignore();
        cout << "Artist?" << endl;
        cin.getline(tempArtist, 80, '\n');
        cout << "Publisher?" << endl;
        cin.getline(tempPub, 80, '\n');
        cout << "Duration (minutes)?" << endl;
        cin >> tempDur;
        cin.ignore();

        Music* nMusic = new Music(tempTitle, tempYear, tempArtist, tempPub, tempDur);
        if (nMusic != nullptr) {
            med.push_back(nMusic);
            nMusic->print();
        }
    }
    else {
        cout << "Invalid media type." << endl;
    }

    // Ensure the vector has elements and print the first element
    if (!med.empty()) {
        cout << "First element in med after adding: " << med[0]->getTitle() << endl;
    } else {
        cout << "No elements in med." << endl;
    }
}

void search(vector<Media*>& med) {
    if (med.empty()) {
        cout << "No media available to search." << endl;
        return;
    }

    cout << "Would you like to search by TITLE or YEAR?" << endl;
    char selector[6];
    cin >> selector;
    cin.ignore();

    if (strcmp(selector, "TITLE") == 0) {
        cout << "Enter title to search for:" << endl;
        char searcher[80];
        cin.getline(searcher, 80, '\n');

        bool matchFound = false; // Keep track if we find any matches
        for (auto it = med.begin(); it != med.end(); ++it) {
            Game* gamePtr = dynamic_cast<Game*>(*it); // Safe casting
            if (gamePtr && strcmp(gamePtr->getTitle(), searcher) == 0) {
                gamePtr->print();
                matchFound = true;
            }
        }

        if (!matchFound) {
            cout << "No matching title found." << endl;
        }
    } 
    else if (strcmp(selector, "YEAR") == 0) {
        cout << "Enter year to search for:" << endl;
        int searchYear;
        cin >> searchYear;
        cin.ignore();

        bool matchFound = false; // Keep track if we find any matches
        for (auto it = med.begin(); it != med.end(); ++it) {
            if ((*it)->getYear() == searchYear) {
                (*it)->print();
                matchFound = true;
            }
        }

        if (!matchFound) {
            cout << "No matching year found." << endl;
        }
    }
    else {
        cout << "Invalid search criteria." << endl;
    }
}
