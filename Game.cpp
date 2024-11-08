#include "Game.h"

using namespace std;

Game::Game(char* title, int year, char* publisher, int rating) : Media(title, year) {
  this->publisher = new char[strlen(publisher) + 1]; //convert to cstring of needed size
  strcpy(this->publisher, publisher); //copy the passed in publisher into our object's publisher
  this->rating = rating; //copy passed in rating into object's rating
}

Game::~Game() {
  delete[] publisher;
}

void Game::print() {
  cout << "Video Game: " << title << ", Year: " << year << ", Publisher: " << publisher << ", Rating: " << rating << endl;
}

char* Game::getPublisher() {
  return publisher;
}

int Game::getRating() {
  return rating;
}
