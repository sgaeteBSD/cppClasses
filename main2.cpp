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
            cout << "Before search, vector size: " << med.size() << endl;
            if (med.size() > 0) {
                cout << "First item in med before search: " << med[0]->getTitle() << endl;
            }
            search(med);
            input = true;
        }
        else if (strcmp(command, "QUIT") == 0) {
            input = false; // Quit the loop
        }
        else { // if command isn't one of the four
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
            cout << "Created Game: " << nGame->getTitle() << endl;
            med.push_back(nGame);
            cout << "Pointer to Game pushed to med, first item in med: " << med[0]->getTitle() << endl;
        } else {
            cout << "Failed to create Game object!" << endl;
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
            cout << "Created Movie: " << nMovie->getTitle() << endl;
            med.push_back(nMovie);
            cout << "Pointer to Movie pushed to med, first item in med: " << med[0]->getTitle() << endl;
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
            cout << "Created Music: " << nMusic->getTitle() << endl;
            med.push_back(nMusic);
            cout << "Pointer to Music pushed to med, first item in med: " << med[0]->getTitle() << endl;
        }
    }
    else {
        cout << "Invalid media type." << endl;
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

        bool matchFound = false;
        for (auto it = med.begin(); it != med.end(); ++it) {
            if (*it == nullptr) {
                cout << "Null pointer detected in med vector!" << endl;
                continue;
            }

            cout << "Inspecting media object: " << (*it)->getTitle() << endl;
            
            Game* gamePtr = dynamic_cast<Game*>(*it);
            if (gamePtr != nullptr) {
                cout << "Found Game: " << gamePtr->getTitle() << endl;
                if (strcmp(gamePtr->getTitle(), searcher) == 0) {
                    gamePtr->print();
                    matchFound = true;
                }
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

        bool matchFound = false;
        for (auto it = med.begin(); it != med.end(); ++it) {
            if (*it == nullptr) {
                cout << "Null pointer detected in med vector!" << endl;
                continue;
            }

            cout << "Inspecting media object with year: " << (*it)->getYear() << endl;

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
