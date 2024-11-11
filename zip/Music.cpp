#include "Music.h"

using namespace std;

Music::Music(char* title, int year, char* artist, char* publisher, int duration) : Media(title, year) {
  this->artist = new char[strlen(artist) + 1]; //convert to cstring of needed size
  strcpy(this->artist, artist); //copy the passed in director into our object's director

  this->publisher = new char[strlen(publisher) + 1]; 
  strcpy(this->publisher, publisher); 

  this->duration = duration; //copy passed in duration into object's duration
}

Music::~Music() {
  delete[] artist;
  delete[] publisher;
}

void Music::print() {
  cout << "Music: " << title << ", Year: " << year << ", Artist: " << artist << ", Publisher: " << publisher <<
    ", Duration: " << duration << " minutes" << endl;
}

char* Music::getArtist() {
  return artist;
}

char* Music::getPublisher() {
  return publisher;
}

int Music::getDuration() {
  return duration;
}
