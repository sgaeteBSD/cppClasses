#include "media.h"

using namespace std;

Media::Media(char* title, int year) {
  this->title = new char[strlen(title) + 1]; //convert to cstring
  strcpy(this->title, title); //copy in
  this->year = year;
}

Media::~Media() {
  delete[] title;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
