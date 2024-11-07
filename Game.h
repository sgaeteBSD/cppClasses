#include "Media.h"

class Game : public Media {
private:
  char* publisher;
  int rating;
public:
  Game(char* title, int year, char* publisher, int rating);
  virtual ~Game();

  virtual void print();

  char* getPublisher();
  int getRating();
};
  
