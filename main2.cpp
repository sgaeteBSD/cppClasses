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
            cout << "Pointer to Game pushed to med, address: " << nGame << endl;
        } else {
            cout << "Failed to create Game object!" << endl;
        }
    }
    // Repeat for MOVIE and MUSIC as before...
}

void search(vector<Media*>& med) {
    if (med.empty()) {
        cout << "No media available to search." << endl;
        return;
    }

    cout << "Before search, vector size: " << med.size() << endl;
    cout << "First item in med before search address: " << med[0] << endl;

    if (med[0] == nullptr) {
        cout << "First item in med is nullptr!" << endl;
        return;
    }

    cout << "First item in med before search: " << med[0]->getTitle() << endl;

    // Continue with search logic...
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

            cout << "Inspecting media object at address: " << *it << endl;

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

            cout << "Inspecting media object at address: " << *it << endl;

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
