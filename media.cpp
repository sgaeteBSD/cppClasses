#include "Media.h"

using namespace std;

Media::Media(char* title, int year) : year(year) {
    if (title) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    } else {
        this->title = nullptr;
    }
}

Media::~Media() {
  delete[] title;
  title = nullptr;
}

void Media::print() {
  cout << "Unknown media type..." << endl;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
