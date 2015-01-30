#ifndef _GAMESIM_
#define _GAMESIM_

#include<string.h>
#include<iostream>
#include<fstream>
#include"team.h"
#include<GLUT/glut.h>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include"texture.h"
#include"button.h"
#include"accum.h"
#include<assert.h>
#include"team.h"
#include<cstring>
#include<stdlib.h>
#include</usr/local/boost_1_57_0/boost/random.hpp>
#include<iomanip>
#include<sstream>

enum ptype {none, rushplay, passplay, fgoalplay, puntplay, koffplay, xpplay};

class gamesim
{
 public:
  int gametime;
  team * poss;
  team * notposs;
  team * initposs;
  int togo;
  int down;
  int tofirst;
  int qtr;
  int position;
  int pint;
  string event1, event2, event3, event4, event5, event;
  ptype playtype;
  int yardage;
  bool fumble, interception, sack, complete, fg, touchback, xp, td;
  int returnlength, puntlength;
  team * home;
  team * away;
  player * pptr;
  runningback * rbp;
  wideReceiver * wrp;
  tightEnd * tep;
  void gameTime();
  void updateYardage();
  ptype cpuPlayType();
  void simdown();
  void changePoss();
  void kickoff();
  void runPlay();
  void passPlay();
  void punt();
  void fieldgoal();
  void extrapoint();
  void setTeams(team *, team *);
  void updateOutput();
  void updateStats();

  float getcomppercent(runningback *);
  float getcomppercent(wideReceiver *);
  float getcomppercent(tightEnd *);
  float getypcatch(wideReceiver *);
  float getypcatch(tightEnd *);
  float getypcatch(runningback *);
  float getinterrate();
  float getsackrate();
  float getypr(runningback *);
  float getfumbrate(quarterback *);
  float getfumbrate(runningback *);
  float getfumbrate(wideReceiver *);
  float getfumbrate(tightEnd *);

  gamesim(team *, team *);
  gamesim();
  void start();
};

#endif
