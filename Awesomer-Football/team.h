#ifndef _TEAM_
#define _TEAM_

#include <iostream>
#include<fstream>
#include <math.h>
#include<string>
#include "ColorPoint2.h"
#include"player.h"
#include"defstat.h"
#include<cstdlib>

class team
{
public:
    string name;
    quarterback * quarterbackp;
    runningback * runningbackp1;
    runningback * runningbackp2;
    wideReceiver * wideReceiverp1;
    wideReceiver * wideReceiverp2;
    wideReceiver * wideReceiverp3;
    tightEnd * tightEndp1;
    tightEnd * tightEndp2;
    kicker * kickerp;
    player * parr [9];
    defstat defense;
    bool poss;
    int score;
    team(ifstream & is) : defense (is)
    {
        getline(is, name);
        poss = false;
        score = 0;
        quarterbackp = new quarterback (is);
        runningbackp1 = new runningback (is);
        runningbackp2 = new runningback (is);
        wideReceiverp1 = new wideReceiver (is);
        wideReceiverp2 = new wideReceiver (is);
        wideReceiverp3 = new wideReceiver (is);
        tightEndp1 = new tightEnd (is);
        tightEndp2 = new tightEnd (is);
        kickerp = new kicker (is);
    }
    team()
    {

    }

  ~team()
  {
      delete quarterbackp;
      delete runningbackp1;
      delete runningbackp2;
      delete wideReceiverp1;
      delete wideReceiverp2;
      delete wideReceiverp3;
      delete tightEndp1;
      delete tightEndp2;
      delete kickerp;
  }

  float tartotal()
  {
      float sum = (runningbackp1->tpg() + runningbackp2->tpg() + wideReceiverp1->tpg() + wideReceiverp2->tpg() + wideReceiverp3->tpg() + tightEndp1->tpg() + tightEndp2->tpg());
      return sum;
  }

  float rate() {return (quarterbackp->attempts/(quarterbackp->attempts+runningbackp1->rushes+runningbackp2->rushes));}

  player * detplayer()
  {
    float det = drand48() * tartotal();
    float to1 = runningbackp1->tpg();
    float to2 = to1 + runningbackp2->tpg();
    float to3 = to2 + wideReceiverp1->tpg();
    float to4 = to3 + wideReceiverp2->tpg();
    float to5 = to4 + wideReceiverp3->tpg();
    float to6 = to5 + tightEndp1->tpg();
    float to7 = to6 + tightEndp2->tpg();
    if (det <= to1) return runningbackp1;
    else if (det <= to2 && det > to1) return runningbackp2;
    else if (det <= to3 && det > to2) return wideReceiverp1;
    else if (det <= to4 && det > to3) return wideReceiverp2;
    else if (det <= to5 && det > to4) return wideReceiverp3;
    else if (det <= to6 && det > to5) return tightEndp1;
    else if (det <= to7 && det > to6) return tightEndp2;
    else return wideReceiverp1;
  }
};


#endif
