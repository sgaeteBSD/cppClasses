#include <iostream>
#include <cstring>

using namespace std;

class media {
  protected:
    char title* = title[80];
    int year;

  public:
    virtual void printDetails(); //virtual destructor
      
    virtual char getTitle();
    virtual int getYear();

    virtual ~media();
};
