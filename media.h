#include <iostream>
#include <cstring>

using namespace std;

class Media {
  protected:
    char* title;
    int year;

  public:
    Media(char* title, int year);
    virtual void print();
      
    virtual char* getTitle();
    virtual int getYear();

    ~Media();
};
