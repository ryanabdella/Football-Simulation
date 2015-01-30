#ifndef _DEFSTAT_
#define _DEFSTAT_

#include <iostream>
#include <sstream>
#include<string>

class defstat
{
 public:
  float comp;
  float att;
  float pyds;
  float inter;
  float sack;
  float rush;
  float ruyds;
  float fumb;
  float kickret;
  float kickretyds;
  float puntret;
  float puntretyds;
  float punt;
  float puntyds;
  defstat(ifstream &is)
    {
      stringstream out;
      string temp;
      getline(is, temp);
      out << temp;
      out >> comp >> att >> pyds >> inter >> sack >> rush >> ruyds >> fumb >> kickret >> kickretyds >> puntret >> puntretyds >> punt >> puntyds;
    }
  defstat()
    {
    }
  float comppercent() {return comp/att;}
  float ypcomp() {return pyds/comp;}
  float interrate() {return inter/att;}
  float sackrate() {return sack/att;}
  float ypr() {return ruyds/rush;}
  float fumbrate() {return fumb/(comp+rush+sack);}
  float ypkret() { return kickretyds/kickret;}
  float yppret() {return puntretyds/puntret;}
  float ypp() {return puntyds/punt;}
};

#endif
