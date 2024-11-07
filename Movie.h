#include "Media.h"

class Movie : public Media {
private:
  char* director;
  int duration;
  int rating;
public:
  Movie(char* title, int year, char* director, int duration, int rating);
  virtual ~Movie();

  virtual void print();

  char* getDirector();
  int getDuration();
  int getRating();
};

