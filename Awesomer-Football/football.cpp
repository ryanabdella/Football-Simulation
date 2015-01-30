#include<iostream>
#include<fstream>
using namespace std;
#include<GLUT/glut.h>
#include<string.h>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<sstream>
#include"texture.h"
#include"button.h"
#include<assert.h>
#include"gamesim.h"
#include"team.h"
#include"player.h"
#include"football.h"

int WIDTH = 600;
int HEIGHT = 600;
int gameWIDTH = 1000;
int gameHEIGHT = 1000;
int teamWIDTH = 700;
int teamHEIGHT = 600;
int tradeWIDTH = 1100;
int tradeHEIGHT = 600;
char programName[] = "football";
int footballT, fieldT, iconT;
gamesim gs;
gamesim * gamesimpointer = 0;
team * tptr1 = 0;
team * tptr2 = 0;
team * tra1 = 0;
team * tra2 = 0;
team tarr [32];

player * tplyr1 = 0;
player * tplyr2 = 0;
int Pchoice1 = 0;
int Pchoice2 = 0;
stringstream out;
ifstream myfile;

//main menu button info
double p1a[] = {75, 150, 160, 30}; // upper left, width, height
double p2a[] = {75, 200, 160, 30};
double p3a[] = {75, 250, 160, 30};
double p4a[] = {75, 300, 160, 30};
button p1 (false, false, p1a);
button p2 (false, false, p2a);
button p3 (false, false, p3a);
button p4 (false, false, p4a);

//game window button info
double runa[] = {10, 400, 90, 40};
double passa[] = {10, 450, 90, 40};
double fga[] = {10, 500, 90, 40};
double punta[] = {10, 550, 90, 40};
double conta[] = {10, 600, 90, 40};
button run (false, false, runa);
button pass (false, false, passa);
button fg (false, false, fga);
button punt (false, false, punta);
button cont(false, false, conta);

//Trade window buttons info
double Tradea[] = {460, 65, 80, 40};
double Reseta[] = {560, 65, 80, 40};
double Donea[] = {995, 535, 80, 40};
button Tradeb (false, false, Tradea);
button Resetb (false, false, Reseta);
button Doneb (false, false, Donea);

int statBN;
button ** statB;
int teamBN;
button ** teamB;
team ** TEAM;
int ID[32];

button ** teambarr;
int texarr [32];
int texpos [64];

int mainWindowID = 0;
int gameWindowID = 0;
int teamWindowID = 0;
int tradeWindowID = 0;
int createMainWindow(const char * windowTitle);
int createGameWindow(const char * windowTitle);
int createTeamWindow(const char * windowTitle);
int createTradeWindow(const char * windowTitle);

void teamTextures() {
   texarr[5] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/bears.pam");
   texarr[6] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/bengals.pam");
   texarr[3] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/bills.pam");
   texarr[9] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/broncos.pam");
   texarr[7] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/browns.pam");
   texarr[29] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/buccaneers.pam");
   texarr[0] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/cardinals.pam");
   texarr[25] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/chargers.pam");
   texarr[15] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/chiefs.pam");
   texarr[13] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/colts.pam");
   texarr[8] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/cowboys.pam");
   texarr[16] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/dolphins.pam");
   texarr[23] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/eagles.pam");
   texarr[1] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/falcons.pam");
   texarr[26] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/fortyniners.pam");
   texarr[20] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/giants.pam");
   texarr[14] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/jaguars.pam");
   texarr[21] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/jets.pam");
   texarr[10] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/lions.pam");
   texarr[11] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/packers.pam");
   texarr[4] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/panthers.pam");
   texarr[18] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/patriots.pam");
   texarr[22] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/raiders.pam");
   texarr[28] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/rams.pam");
   texarr[2] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/ravens.pam");
   texarr[31] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/redskins.pam");
   texarr[19] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/saints.pam");
   texarr[27] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/seahawks.pam");
   texarr[24] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/steelers.pam");
   texarr[12] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/texans.pam");
   texarr[30] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/titans.pam");
   texarr[17] = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/vikings.pam");
}

void loadButtons (const char* fileName, button ** & stat, int & num){
  ifstream g(fileName);
  if ( ! g.good() ) {
    cerr << "Warning:  Unable to open " << fileName << ", ignoring it." << endl;
    return;
  }
  g >> num;
  stat = new button* [num];
  for (int i = 0; i<num; ++i){
    stat[i] = new button(g);
  }
}

void loadButtonsTeam (const char * fileName, button ** & teambarr) {
  ifstream f(fileName);
  if ( ! f.good() ) {
    cerr << "Warning: Unable to open " << fileName << ", ignoring it." << endl;
    return;
  }
  int num = 0;
  f >> num;
  teambarr = new button * [num];
  for (int i = 0; i<num; ++i) {
    teambarr[i] = new button(f);
  }
}

void drawBox(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y); // upper left
    glVertex2f(x, y + height); // lower left
    glVertex2f(x + width, y + height); // lower right
    glVertex2f(x + width, y); // upper right
  glEnd();
}

void drawBox(double *pos)
{
  drawBox(pos[0], pos[1], pos[2], pos[3]);
}

void drawText(double x, double y, const char * text)
{
  glRasterPos2f(x, y);
  int length = (int) strlen(text);
  for (int i = 0; i < length; ++i)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void drawText2(double x, double y, const char * text)
{
  glRasterPos2f(x, y);
  int length = (int) strlen(text);
  for (int i = 0; i < length; ++i)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, text[i]);
}

void drawNumber(double x, double y, double num)
{
  stringstream oss;
  oss << num; oss.flush();
  drawText(x, y, oss.str().c_str());
}

void drawWords(double x, double y, const char * text)
{
  stringstream oss;
  oss << text; oss.flush();
  drawText(x, y, oss.str().c_str());
}

void drawWords2(double x, double y, const char * text)
{
  stringstream oss;
  oss << text; oss.flush();
  drawText2(x, y, oss.str().c_str());
}

bool onButton(int x, int y, button b)
{
  return x >= b.pos[0] && y >= b.pos[1] && x <= b.pos[0] + b.pos[2] && y <= b.pos[1] + b.pos[3];
}

void drawMainWindow()
{
  glutSetWindow(mainWindowID);

  //clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  //draw images
  drawTexture(footballT, 350, 50, 200, 100); // texID, x, y, width, height
  
   if (p1.isPressed) glColor3f(.25, .25, .25);
  else if (p1.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(p1a);

  if (p2.isPressed) glColor3f(.25, .25, .25);
  else if (p2.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(p2a);

  if (p3.isPressed) glColor3f(.25, .25, .25);
  else if (p3.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(p3a);

  if (p4.isPressed) glColor3f(.25, .25, .25);
  else if (p4.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(p4a);

  glColor3f(0.0, 0.0, 0.0);
  drawWords(50, 100, "Main Menu");
  drawWords(80, 170, "1 Player");
  drawWords(80, 220, "2 Player");
  drawWords(80, 270, "Season Simulation");
  drawWords(80, 320, "Edit Teams");

  //switch buffers
  glutSwapBuffers();
}

void drawPlayersTeam(team &t1, int x, int y)
{
  glColor3f(0.0, 0.0, 0.0);
  drawText2(x, y-25, "QB                             Comp%    YPA   Yds/Game  Int/Game");
  drawText2(x, y, t1.quarterbackp->name.c_str());
  drawText2(x, y+25, "RB                             Yds/Rush YPG      Yds/Cat    YPG    Catch%");
  drawText2(x, y+50, t1.runningbackp1->name.c_str());
  drawText2(x, y+75, t1.runningbackp2->name.c_str());
  drawText2(x, y+100, "WR/TE                        Yds/Cat   Yds/Game Catch%");
  drawText2(x, y+125, t1.wideReceiverp1->name.c_str());
  drawText2(x, y+150, t1.wideReceiverp2->name.c_str());
  drawText2(x, y+175, t1.wideReceiverp3->name.c_str());
  drawText2(x, y+200, t1.tightEndp1->name.c_str());
  drawText2(x, y+225, t1.tightEndp2->name.c_str());
  drawText2(x, y+250, "K                                FG%");
  drawText2(x, y+275, t1.kickerp->name.c_str());
  drawText2(x+100, y, t1.quarterbackp->output_season.c_str());
  drawText2(x+100, y+50, t1.runningbackp1->output_season.c_str());
  drawText2(x+100, y+75, t1.runningbackp2->output_season.c_str());
  drawText2(x+100, y+125, t1.wideReceiverp1->output_season.c_str());
  drawText2(x+100, y+150, t1.wideReceiverp2->output_season.c_str());
  drawText2(x+100, y+175, t1.wideReceiverp3->output_season.c_str());
  drawText2(x+100, y+200, t1.tightEndp1->output_season.c_str());
  drawText2(x+100, y+225, t1.tightEndp2->output_season.c_str());
  drawText2(x+100, y+275, t1.kickerp->output_season.c_str());
}

void drawAccumTeam(team &t1, int x, int y)
{
  glColor3f(0.0, 0.0, 0.0);
  drawText2(x, y, "QB                               Comp   Att   Yds   TDs   Int");
  drawText2(x, y+25, t1.quarterbackp->name.c_str());
  drawText2(x, y+50, "RB                                Att   Yds   TDs   Cat   Yds   TDs");
  drawText2(x, y+75, t1.runningbackp1->name.c_str());
  drawText2(x, y+100, t1.runningbackp2->name.c_str());
  drawText2(x, y+125, "WR                                 Cat   Yds   TDs");
  drawText2(x, y+150, t1.wideReceiverp1->name.c_str());
  drawText2(x, y+175, t1.wideReceiverp2->name.c_str());
  drawText2(x, y+200, t1.wideReceiverp3->name.c_str());
  drawText2(x, y+225, t1.tightEndp1->name.c_str());
  drawText2(x, y+250, t1.tightEndp2->name.c_str());
  drawText2(x, y+275, "K                                  FGm   FGa   XPm   XPa");
  drawText2(x, y+300, t1.kickerp->name.c_str());
  drawText2(x+120, y+25, t1.quarterbackp->output_game.c_str());
  drawText2(x+120, y+75, t1.runningbackp1->output_game.c_str());
  drawText2(x+120, y+100, t1.runningbackp2->output_game.c_str());
  drawText2(x+120, y+150, t1.wideReceiverp1->output_game.c_str());
  drawText2(x+120, y+175, t1.wideReceiverp2->output_game.c_str());
  drawText2(x+120, y+200, t1.wideReceiverp3->output_game.c_str());
  drawText2(x+120, y+225, t1.tightEndp1->output_game.c_str());
  drawText2(x+120, y+250, t1.tightEndp2->output_game.c_str());
  drawText2(x+120, y+300, t1.kickerp->output_game.c_str());
}

void drawTeamWindow()
{
  glutSetWindow(teamWindowID);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0, 0.0, 0.0);
  drawWords(10, 50, "Welcome to the Team Select Page.");

  glColor3f(0.0, 0.0, 0.0);
  drawBox(250., 110., 380., 340.);
  glColor3f(155.0, 155.0, 155.0);
  drawBox(255., 115., 370., 330.);

  for (int i = 0; i < 32; ++i) {
    if (teambarr[i]->isPressed) {
      drawTexture(texarr[i], teambarr[i][0].pos[0], teambarr[i][0].pos[1], 50, 50, 0.75);
      drawPlayersTeam(*TEAM[i], 265, 150);
    }
    else if (teambarr[i]->overButton) {
      drawTexture(texarr[i], teambarr[i][0].pos[0], teambarr[i][0].pos[1], 50, 50, 0.50);
      drawPlayersTeam(*TEAM[i], 265, 150);
    } else drawTexture(texarr[i], teambarr[i][0].pos[0], teambarr[i][0].pos[1], 50, 50);
  }

  glutSwapBuffers();
}

void drawGameWindow()
{
  glutSetWindow(gameWindowID);

  glClear(GL_COLOR_BUFFER_BIT);

  drawTexture(fieldT, 10, 100, 503, 260);

    glColor3f(1.0, 1.0, 0.0);
    if (gamesimpointer->poss == gamesimpointer->away) {
        drawBox((gamesimpointer->position-gamesimpointer->tofirst)*4+61, 113, 2, 235);
    }
    else if (gamesimpointer->poss == gamesimpointer->home) {
        drawBox((gamesimpointer->position+gamesimpointer->tofirst)*4+61, 113, 2, 235);
    }
    
  glColor3f(0.0, 0.0, 1.0);
  if (gamesimpointer->poss == gamesimpointer->away) drawBox((gamesimpointer->position*4)+61, 113, 2, 235);
  else if (gamesimpointer->poss == gamesimpointer->home) drawBox((gamesimpointer->position*4)+61, 113, 2, 235);

  glColor3f(0.0, 0.0, 0.0);
  drawBox(10, 10, 980, 80);
  drawBox(110, 380, 400, 250);
  glColor3f(1.0, 1.0, 1.0);
  drawBox(12, 12, 976, 37); 
  drawBox(12, 51, 976, 37);
  drawBox(112, 382, 396, 246);
  if (gamesimpointer->poss == gamesimpointer->home) drawTexture(iconT, 42, 32, 20, 10);
  else drawTexture(iconT, 370, 32, 20, 10);
  glColor3f(0.0, 0.0, 0.0);
  drawNumber(70, 42, gamesimpointer->home->score);
  drawNumber(400, 42, gamesimpointer->away->score);
  drawWords(110, 42, gamesimpointer->home->name.c_str());
  drawWords(440, 42, gamesimpointer->away->name.c_str());
  drawWords(20, 80, "Quarter:           Ball on               Down:         To First:            Time: ");
  drawNumber(90, 80, gamesimpointer->qtr);
  if (gamesimpointer->position <= 50) drawNumber(210, 80, gamesimpointer->position);
  else drawNumber(210, 80, (100-gamesimpointer->position));
  drawNumber(330, 80, gamesimpointer->down);
    if (gamesimpointer->togo == gamesimpointer->tofirst) drawWords(450, 80, "Goal");
    else drawNumber(450, 80, gamesimpointer->tofirst);
  if (gamesimpointer->gametime/60 >= 10) drawNumber(550, 80, gamesimpointer->gametime/60);
  else {
    drawNumber(550, 80, 0);
    drawNumber(560, 80, gamesimpointer->gametime/60);
  }
  drawWords(580, 80, ":");
  if (gamesimpointer->gametime%60 >= 10) drawNumber(590, 80, gamesimpointer->gametime%60);
  else {
    drawNumber(590, 80, 0);
    drawNumber(600, 80, gamesimpointer->gametime%60);
  }
  drawBox(520, 100, 460, 400);
  glColor3f(1.0, 1.0, 1.0);
  drawBox(522, 102, 456, 396);

  glColor3f(0.0, 0.0, 0.0);
  drawText2(115, 420, gamesimpointer->event5.c_str());
  drawText2(115, 460, gamesimpointer->event4.c_str());
  drawText2(115, 500, gamesimpointer->event3.c_str());
  drawText2(115, 540, gamesimpointer->event2.c_str());
  drawText2(115, 580, gamesimpointer->event1.c_str()); 
  drawText(550, 125, gamesimpointer->poss->name.c_str());
  drawAccumTeam(*(gamesimpointer->poss), 550, 150);

  if (run.isPressed) glColor3f(.25, .25, .25);
  else if (run.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(runa);

  if (pass.isPressed) glColor3f(.25, .25, .25);
  else if (pass.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(passa);

  if (fg.isPressed) glColor3f(.25, .25, .25);
  else if (fg.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(fga);

  if (punt.isPressed) glColor3f(.25, .25, .25);
  else if (punt.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(punta);

  if (cont.isPressed) glColor3f(.25, .25, .25);
  else if (cont.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(conta);

  glColor3f(0.0, 0.0, 0.0);
  drawWords(18, 430, "Run");
  drawWords(18, 480, "Pass");
  drawWords(18, 530, "FG");
  drawWords(18, 580, "Punt");
  drawWords(18, 630, "Continue");


  glutSwapBuffers();
}





void drawTradeWindow()
{
  glutSetWindow(tradeWindowID);

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0, 0.0, 0.0);
  drawWords(10, 50, "Welcome to The Edit Teams Page.");

 

  glColor3f(0.0, 0.0, 0.0);
  drawBox(705., 140., 380., 340.);
  drawBox(15., 140., 380., 340.);
  glColor3f(155.0, 155.0, 155.0);
  drawBox(710., 145., 370., 330.);
  drawBox(20., 145., 370., 330.);

  if (Tradeb.isPressed) glColor3f(.25, .25, .25);
  else if (Tradeb.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(Tradea);

  if (Resetb.isPressed) glColor3f(.25, .25, .25);
  else if (Resetb.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(Reseta);

  if (Doneb.isPressed) glColor3f(.25, .25, .25);
  else if (Doneb.overButton) glColor3f(.75, .75, .75);
  else glColor3f(.5, .5, .5);
  drawBox(Donea);

  for (int i = 0; i < statBN; ++i){
    if (tplyr1 != 0 && i == Pchoice1) glColor3f(.5, .5, .25);
    else if (tplyr2 != 0 && i == Pchoice2) glColor3f(.5, .5, .25);
    else if (statB[i][0].overButton && tplyr2 == 0 && tra1 != 0 && tra2 != 0 ) glColor3f(.75, .75, .75);
    else glColor3f(1, 1, 1);
    drawBox(statB[i][0].pos);
  }

  for (int i = 0; i < teamBN; ++i){
    if (tra1 == &TEAM[i][0]) {
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 0.75);
        drawPlayersTeam(TEAM[i][0], 30, 180);
    }
    else if (tra2 == &TEAM[i][0]){
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 0.75);
        drawPlayersTeam(TEAM[i][0], 720, 180);
    }
    else if (teamB[i][0].overButton && tra1 == 0 && tra2 == 0){
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 0.50);
        drawPlayersTeam(TEAM[i][0], 30, 180);
    }
    else if (teamB[i][0].overButton && tra1 != 0 && tra2 == 0){
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 0.50);
        drawPlayersTeam(TEAM[i][0], 720, 180);
    }
    else if (teamB[i][0].overButton && tra1 != 0 && tra2 != 0) {
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 1);
    }
    else {
        drawTexture(texarr[i], teamB[i][0].pos[0], teamB[i][0].pos[1], 50, 50, 1);
    }
  }


  glColor3f(0.0, 0.0, 0.0);
  drawWords(470, 90, "Trade!");
  drawWords(575, 90, "Reset");
  drawWords(1015, 560, "Done");

  glutSwapBuffers();
}
//close the window and finish the program
void exitAll()
{
  if (mainWindowID) glutDestroyWindow(mainWindowID);
  if (gameWindowID) glutDestroyWindow(gameWindowID);
  if (teamWindowID) glutDestroyWindow(teamWindowID);
  if (tradeWindowID) glutDestroyWindow(tradeWindowID);
  exit(0);
}

void keyboard(unsigned char c, int x, int y)
{
  switch(c) {
  case 'q':
  case 'Q':
  case 27:
    exitAll();
    break;
  default:
    break;
  }
  glutPostRedisplay();
}

//the reshape function handles the case where the user changes the size
//of the window.  We need to fix the coordinate system, so that the 
//drawing area is still the unit square.
void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  if (mainWindowID == glutGetWindow()) {
    WIDTH = w; HEIGHT = h;
  } else if (teamWindowID == glutGetWindow()) {
    teamWIDTH = w; teamHEIGHT = h;
  } else if (tradeWindowID == glutGetWindow()) {
    tradeWIDTH = w; tradeHEIGHT = h;
  } else {
    gameWIDTH = w; gameHEIGHT = h;
  } 
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., w-1, h-1, 0., -1.0, 1.0);
}

void mouse(int mouseButton, int state, int x, int y)
{
  if (GLUT_LEFT_BUTTON == mouseButton) {
    if (GLUT_DOWN == state) {
      // the user just pressed down on the mouse-- do something
      if (onButton(x,y,p1)) p1.isPressed = true;
      else p1.isPressed = false;
      if (onButton(x,y,p2)) p2.isPressed = true;
      else p2.isPressed = false;
      if (onButton(x,y,p3)) p3.isPressed = true;
      else p3.isPressed = false;
      if (onButton(x,y,p4)) p4.isPressed = true;
      else p4.isPressed = false;
    } else {
      // the user just let go of the mouse-- do something
      if (onButton(x,y,p1) && p1.isPressed)
	cout << "First player has not been implemented yet, please check back later." << endl;
      p1.isPressed = false;
      if (onButton(x,y,p2) && p2.isPressed) {
	glutInitWindowPosition(100,0);
	glutInitWindowSize(teamWIDTH, teamHEIGHT);
	teamWindowID = createTeamWindow("team select");
	glOrtho(0., teamWIDTH-1, teamHEIGHT-1, 0., -1.0, 1.0);
	teamTextures();
      }
      p2.isPressed = false;
      if (onButton(x,y,p3) && p3.isPressed)
	cout << "Season simulation has not been implemented yet, please check back later." << endl;
      p3.isPressed = false;
      if (onButton(x,y,p4) && p4.isPressed){
	glutInitWindowPosition(100,0);
	glutInitWindowSize(tradeWIDTH, tradeHEIGHT);
	tradeWindowID = createTradeWindow("trade players");
	glOrtho(0., tradeWIDTH-1, tradeHEIGHT-1, 0., -1.0, 1.0);
	teamTextures();
      }
      p4.isPressed = false;
    }
  } else if (GLUT_RIGHT_BUTTON == mouseButton) {
  }
  glutPostRedisplay();
}

void mouse_team(int mouseButton, int state, int x, int y)
{
  if (GLUT_LEFT_BUTTON == mouseButton) {
    if (GLUT_DOWN == state) {
      for (int i = 0; i < 32; ++i){
	if (onButton(x,y,teambarr[i][0])) teambarr[i]->isPressed = true;
	else teambarr[i]->isPressed = false;
      }
    } else {
      for (int i = 0; i < 32; ++i) {
        if (onButton(x,y,teambarr[i][0]) && teambarr[i]->isPressed) {
	  if (tptr1 == 0) tptr1 = &TEAM[i][0];
	  else if (tptr2 == 0) tptr2 = &TEAM[i][0];
	  teambarr[i]->isPressed = false;
	}
      }
      if (tptr1 != 0 && tptr2 != 0) {
	gamesimpointer->setTeams(tptr1, tptr2);
	gamesimpointer->start();
	glutInitWindowPosition(100,0);
	glutInitWindowSize(gameWIDTH,gameHEIGHT);
	gameWindowID = createGameWindow("game simulation");
	glOrtho(0., gameWIDTH-1, gameHEIGHT-1, 0., -1.0, 1.0);
	fieldT = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/field.pam");
	iconT = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/icon.pam");
	glutPostWindowRedisplay(gameWindowID);
      }
    }
  } else if (GLUT_RIGHT_BUTTON == mouseButton) {
  }
  glutPostRedisplay();			   
}

void mouse_gamesim(int mouseButton, int state, int x, int y)
{
  if (GLUT_LEFT_BUTTON == mouseButton) {
    if (GLUT_DOWN == state) {
      if (onButton(x,y,run)) run.isPressed = true;
      else run.isPressed = false;
      if (onButton(x,y,pass)) pass.isPressed = true;
      else pass.isPressed = false;
      if (onButton(x,y,fg)) fg.isPressed = true;
      else fg.isPressed = false;
      if (onButton(x,y,punt)) punt.isPressed = true;
      else punt.isPressed = false;
      if (onButton(x,y,cont)) cont.isPressed = true;
      else cont.isPressed = false;
    } else {
      if (onButton(x,y,run) && run.isPressed && gamesimpointer->playtype == none) {
          gamesimpointer->playtype = rushplay;
          gamesimpointer->simdown();
      }
      run.isPressed = false;
      if (onButton(x,y,pass) && pass.isPressed && gamesimpointer->playtype == none) {
          gamesimpointer->playtype = passplay;
          gamesimpointer->simdown();
      }
      pass.isPressed = false;
      if (onButton(x,y,fg) && fg.isPressed && gamesimpointer->playtype == none) {
          gamesimpointer->playtype = fgoalplay;
          gamesimpointer->simdown();
      }
      fg.isPressed = false;
      if (onButton(x,y,punt) && punt.isPressed && gamesimpointer->playtype == none) {
          gamesimpointer->playtype = puntplay;
          gamesimpointer->simdown();
      }
      punt.isPressed = false;
      if (onButton(x,y,cont) && cont.isPressed) {
          if (gamesimpointer->playtype == koffplay) {
              gamesimpointer->simdown();
          } else if (gamesimpointer->playtype == xpplay) {
              gamesimpointer->simdown();
          }
      }
      cont.isPressed = false;
    }
  } else if (GLUT_RIGHT_BUTTON == mouseButton) {}
  if (gamesimpointer->gametime <= 0 && gamesimpointer->qtr == 4) {
    glutDestroyWindow(gameWindowID);
    gameWindowID = 0;
    glutSetWindow(mainWindowID);
  }
  glutPostRedisplay();
}

void mouse_trade(int mouseButton, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == mouseButton) {
        if (GLUT_DOWN == state) {
            for (int i = 0; i < statBN; ++i){
                if (onButton(x,y,statB[i][0]) && tplyr2 == 0) statB[i]->isPressed = true;
                else statB[i]->isPressed = false;
            }
            for (int i = 0; i < teamBN; ++i) {
                if (onButton(x,y,teamB[i][0]) && tra2 == 0) teamB[i]->isPressed = true;
                else teamB[i]->isPressed = false;
            }
            if (onButton(x,y,Tradeb)) Tradeb.isPressed = true;
            else Tradeb.isPressed = false;
            if (onButton(x,y,Resetb)) Resetb.isPressed = true;
            else Resetb.isPressed = false;
            if (onButton(x,y,Doneb)) Doneb.isPressed = true;
            else Doneb.isPressed = false;
        } else {
            if (onButton(x,y,Doneb) && Doneb.isPressed) {
                glutDestroyWindow(tradeWindowID);
                tradeWindowID = 0;
                glutSetWindow(mainWindowID);
            }
            for (int i = 0; i < statBN; ++i) {
                if (onButton(x,y,statB[i][0]) && statB[i]->isPressed && tra1 != 0 && tra2 != 0) {
                    if (tplyr1 == 0) {
                        if (i == 0) {tplyr1 = tra1->quarterbackp;}
                        else if (i == 1) {tplyr1 = tra1->runningbackp1;}
                        else if (i == 2) {tplyr1 = tra1->runningbackp2;}
                        else if (i == 3) {tplyr1 = tra1->wideReceiverp1;}
                        else if (i == 4) {tplyr1 = tra1->wideReceiverp2;}
                        else if (i == 5) {tplyr1 = tra1->wideReceiverp3;}
                        else if (i == 6) {tplyr1 = tra1->tightEndp1;}
                        else if (i == 7) {tplyr1 = tra1->tightEndp2;}
                        else if (i == 8) {tplyr1 = tra1->kickerp;}
                        else if (i == 9) {tplyr1 = tra2->quarterbackp;}
                        else if (i == 10) {tplyr1 = tra2->runningbackp1;}
                        else if (i == 11) {tplyr1 = tra2->runningbackp2;}
                        else if (i == 12) {tplyr1 = tra2->wideReceiverp1;}
                        else if (i == 13) {tplyr1 = tra2->wideReceiverp2;}
                        else if (i == 14) {tplyr1 = tra2->wideReceiverp3;}
                        else if (i == 15) {tplyr1 = tra2->tightEndp1;}
                        else if (i == 16) {tplyr1 = tra2->tightEndp2;}
                        else if (i == 17) {tplyr1 = tra2->kickerp;}
                        Pchoice1 = i;
                    } else if (tplyr2 == 0 && Pchoice1 < 9) {
                        if (Pchoice1 == 0 && i == 9) {
                            tplyr2 = tra2->quarterbackp;
                            Pchoice2 = i;
                        } else if (0 < Pchoice1 && Pchoice1 <= 2 && 9 < i && i <= 11) {
                            if (i == 10) {tplyr2 = tra2->runningbackp1;}
                            else {tplyr2 = tra2->runningbackp2;}
                            Pchoice2 = i;
                        } else if (2 < Pchoice1 && Pchoice1 <= 5 && 11 < i && i <= 14) {
                            if (i == 12) {tplyr2 = tra2->wideReceiverp1;}
                            else if (i == 13) {tplyr2 = tra2->wideReceiverp2;}
                            else {tplyr2 = tra2->wideReceiverp3;}
                            Pchoice2 = i;
                        } else if (5 < Pchoice1 && Pchoice1 <= 7 && 14 < i && i <= 16) {
                            if (i == 15) {tplyr2 = tra2->tightEndp1;}
                            else {tplyr2 = tra2->tightEndp2;}
                            Pchoice2 = i;
                        } else if (Pchoice1 == 8 && i == 17) {
                            tplyr2 = tra2->kickerp;
                            Pchoice2 = i;
                        }
                    } else if (tplyr2 == 0 && Pchoice1 > 8) {
                        if (i == 0 && Pchoice1 == 9) {
                            tplyr2 = tra1->quarterbackp;
                            Pchoice2 = i;
                        } else if (0 < i && i <= 2 && 9 < Pchoice1 && Pchoice1 <= 11) {
                            if (i == 1) {tplyr2 = tra1->runningbackp1;}
                            else {tplyr2 = tra1->runningbackp2;}
                            Pchoice2 = i;
                        } else if (2 < i && i <= 5 && 11 < Pchoice1 && Pchoice1 <= 14) {
                            if (i == 3) {tplyr2 = tra1->wideReceiverp1;}
                            else if (i == 4) {tplyr2 = tra1->wideReceiverp2;}
                            else {tplyr2 = tra1->wideReceiverp3;}
                            Pchoice2 = i;
                        } else if (5 < i && i <= 7 && 14 < Pchoice1 && Pchoice1 <= 16) {
                            if (i == 6) {tplyr2 = tra1->tightEndp1;}
                            else {tplyr2 = tra1->tightEndp2;}
                            Pchoice2 = i;
                        } else if (i == 8 && Pchoice1 == 17) {
                            tplyr2 = tra1->kickerp;
                            Pchoice2 = i;
                        }
                    }
                }
            }
            for (int i = 0; i < teamBN; ++i) {
                if (onButton(x,y,teamB[i][0]) && teamB[i]->isPressed) {
                    if (tra1 == 0) tra1 = &TEAM[i][0];
                    else if (tra2 == 0) tra2 = &TEAM[i][0];
                }
            }
            if (onButton(x,y,Tradeb) && tra1 != 0 && tra2 != 0 && tplyr1 !=0 && tplyr2 != 0 && Tradeb.isPressed) {
                if (tplyr1->position == "QB")
                {
                    quarterback * temp = tra1->quarterbackp;
                    tra1->quarterbackp = tra2->quarterbackp;
                    tra2->quarterbackp = temp;
                } else if (tplyr1->position == "RB")
                {
                    runningback * temp;
                    if ((tplyr1->name == tra1->runningbackp1->name || tplyr2->name == tra1->runningbackp1->name) && (tplyr1->name == tra2->runningbackp1->name || tplyr2->name == tra2->runningbackp1->name))
                    {
                        temp = tra1->runningbackp1;
                        tra1->runningbackp1 = tra2->runningbackp1;
                        tra2->runningbackp1 = temp;
                    } else if ((tplyr1->name == tra1->runningbackp1->name || tplyr2->name == tra1->runningbackp1->name) && (tplyr1->name == tra2->runningbackp2->name || tplyr2->name == tra2->runningbackp2->name))
                    {
                        temp = tra1->runningbackp1;
                        tra1->runningbackp1 = tra2->runningbackp2;
                        tra2->runningbackp2 = temp;
                    } else if ((tplyr1->name == tra1->runningbackp2->name || tplyr2->name == tra1->runningbackp2->name) && (tplyr1->name == tra2->runningbackp1->name || tplyr2->name == tra2->runningbackp1->name))
                    {
                        temp = tra1->runningbackp2;
                        tra1->runningbackp2 = tra2->runningbackp1;
                        tra2->runningbackp1 = temp;
                    } else if ((tplyr1->name == tra1->runningbackp2->name || tplyr2->name == tra1->runningbackp2->name) && (tplyr1->name == tra2->runningbackp2->name || tplyr2->name == tra2->runningbackp2->name))
                    {
                        temp = tra1->runningbackp2;
                        tra1->runningbackp2 = tra2->runningbackp2;
                        tra2->runningbackp2 = temp;
                    }
                } else if (tplyr1->position == "WR")
                {
                    wideReceiver * temp;
                    if ((tplyr1->name == tra1->wideReceiverp1->name || tplyr2->name == tra1->wideReceiverp1->name) && (tplyr1->name == tra2->wideReceiverp1->name || tplyr2->name == tra2->wideReceiverp1->name))
                    {
                        temp = tra1->wideReceiverp1;
                        tra1->wideReceiverp1 = tra2->wideReceiverp1;
                        tra2->wideReceiverp1 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp1->name || tplyr2->name == tra1->wideReceiverp1->name) && (tplyr1->name == tra2->wideReceiverp2->name || tplyr2->name == tra2->wideReceiverp2->name))
                    {
                        temp = tra1->wideReceiverp1;
                        tra1->wideReceiverp1 = tra2->wideReceiverp2;
                        tra2->wideReceiverp2 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp1->name || tplyr2->name == tra1->wideReceiverp1->name) && (tplyr1->name == tra2->wideReceiverp3->name || tplyr2->name == tra2->wideReceiverp3->name))
                    {
                        temp = tra1->wideReceiverp1;
                        tra1->wideReceiverp1 = tra2->wideReceiverp3;
                        tra2->wideReceiverp3 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp2->name || tplyr2->name == tra1->wideReceiverp2->name) && (tplyr1->name == tra2->wideReceiverp1->name || tplyr2->name == tra2->wideReceiverp1->name))
                    {
                        temp = tra1->wideReceiverp2;
                        tra1->wideReceiverp2 = tra2->wideReceiverp1;
                        tra2->wideReceiverp1 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp2->name || tplyr2->name == tra1->wideReceiverp2->name) && (tplyr1->name == tra2->wideReceiverp2->name || tplyr2->name == tra2->wideReceiverp2->name))
                    {
                        temp = tra1->wideReceiverp2;
                        tra1->wideReceiverp2 = tra2->wideReceiverp2;
                        tra2->wideReceiverp2 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp2->name || tplyr2->name == tra1->wideReceiverp2->name) && (tplyr1->name == tra2->wideReceiverp3->name || tplyr2->name == tra2->wideReceiverp3->name))
                    {
                        temp = tra1->wideReceiverp2;
                        tra1->wideReceiverp2 = tra2->wideReceiverp3;
                        tra2->wideReceiverp3 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp3->name || tplyr2->name == tra1->wideReceiverp3->name) && (tplyr1->name == tra2->wideReceiverp1->name || tplyr2->name == tra2->wideReceiverp1->name))
                    {
                        temp = tra1->wideReceiverp3;
                        tra1->wideReceiverp3 = tra2->wideReceiverp1;
                        tra2->wideReceiverp1 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp3->name || tplyr2->name == tra1->wideReceiverp3->name) && (tplyr1->name == tra2->wideReceiverp2->name || tplyr2->name == tra2->wideReceiverp2->name))
                    {
                        temp = tra1->wideReceiverp3;
                        tra1->wideReceiverp3 = tra2->wideReceiverp2;
                        tra2->wideReceiverp2 = temp;
                    } else if ((tplyr1->name == tra1->wideReceiverp3->name || tplyr2->name == tra1->wideReceiverp3->name) && (tplyr1->name == tra2->wideReceiverp3->name || tplyr2->name == tra2->wideReceiverp3->name))
                    {
                        temp = tra1->wideReceiverp3;
                        tra1->wideReceiverp3 = tra2->wideReceiverp3;
                        tra2->wideReceiverp3 = temp;
                    }
                } else if (tplyr1->position == "TE")
                {
                    tightEnd * temp;
                    if ((tplyr1->name == tra1->tightEndp1->name || tplyr2->name == tra1->tightEndp1->name) && (tplyr1->name == tra2->tightEndp1->name || tplyr2->name == tra2->tightEndp1->name))
                    {
                        temp = tra1->tightEndp1;
                        tra1->tightEndp1 = tra2->tightEndp1;
                        tra2->tightEndp1 = temp;
                    } else if ((tplyr1->name == tra1->tightEndp1->name || tplyr2->name == tra1->tightEndp1->name) && (tplyr1->name == tra2->tightEndp2->name || tplyr2->name == tra2->tightEndp2->name))
                    {
                        temp = tra1->tightEndp1;
                        tra1->tightEndp1 = tra2->tightEndp2;
                        tra2->tightEndp2 = temp;
                    } else if ((tplyr1->name == tra1->tightEndp2->name || tplyr2->name == tra1->tightEndp2->name) && (tplyr1->name == tra2->tightEndp1->name || tplyr2->name == tra2->tightEndp1->name))
                    {
                        temp = tra1->tightEndp2;
                        tra1->tightEndp2 = tra2->tightEndp1;
                        tra2->tightEndp1 = temp;
                    } else if ((tplyr1->name == tra1->tightEndp2->name || tplyr2->name == tra1->tightEndp2->name) && (tplyr1->name == tra2->tightEndp2->name || tplyr2->name == tra2->tightEndp2->name))
                    {
                        temp = tra1->tightEndp2;
                        tra1->tightEndp2 = tra2->tightEndp2;
                        tra2->tightEndp2 = temp;
                    }
                } else if (tplyr1->position == "K")
                {
                    kicker * temp = tra1->kickerp;
                    tra1->kickerp = tra2->kickerp;
                    tra2->kickerp = temp;
                }
                tra1 = 0;
                tra2 = 0;
                tplyr1 = 0;
                tplyr2 = 0;
            }
            Tradeb.isPressed = false;
            if (onButton(x,y,Resetb) && Resetb.isPressed) {
                tra1 = 0;
                tra2 = 0;
                tplyr1 = 0;
                tplyr2 = 0;
            }
            Resetb.isPressed = false;
            Doneb.isPressed = false;
        }
    } else if (GLUT_RIGHT_BUTTON == mouseButton) {}
        glutPostRedisplay();
}

void mouse_motion(int x, int y)
{
    if ( onButton(x,y,p1) ) p1.overButton = true;
    else p1.overButton = false;
    if ( onButton(x,y,p2) ) p2.overButton = true;
    else p2.overButton = false;
    if ( onButton(x,y,p3) ) p3.overButton = true;
    else p3.overButton = false;
    if ( onButton(x,y,p4) ) p4.overButton = true;
    else p4.overButton = false;
    glutPostRedisplay();
}

void mouse_motion_team(int x, int y)
{
 for (int i = 0; i < 32; ++i) {
   if( onButton(x,y,teambarr[i][0]) ) teambarr[i]->overButton = true;
   else teambarr[i]->overButton = false;
 }
  glutPostRedisplay();
}


void mouse_motion_trade(int x, int y)//Trade mouse motion
{
  for (int i = 0; i < statBN; ++i) {
    if( onButton(x,y,statB[i][0]) ) statB[i]->overButton = true;
    else statB[i]->overButton = false;
  }
  for (int i = 0; i < teamBN; ++i) {
    if( onButton(x,y,teamB[i][0]) ) teamB[i]->overButton = true;
    else teamB[i]->overButton = false;
  }
  if ( onButton(x,y,Tradeb) ) Tradeb.overButton = true;
  else Tradeb.overButton = false;
  if ( onButton(x,y,Resetb) ) Resetb.overButton = true;
  else Resetb.overButton = false;
  if ( onButton(x,y,Doneb) ) Doneb.overButton = true;
  else Doneb.overButton = false;   
  glutPostRedisplay();
}

void mouse_motion_gamesim(int x, int y)
{
  if ( onButton(x,y,run) ) run.overButton = true;
  else run.overButton = false;
  if ( onButton(x,y,pass) ) pass.overButton = true;
  else pass.overButton = false;
  if ( onButton(x,y,fg) ) fg.overButton = true;
  else fg.overButton = false;
  if ( onButton(x,y,punt) ) punt.overButton = true;
  else punt.overButton = false;
  if ( onButton(x,y,cont) ) cont.overButton = true;
  else cont.overButton = false;
  glutPostRedisplay();
}

int createMainWindow(const char * windowTitle)
{
  int id = glutCreateWindow(windowTitle);
  assert (0!=id);

  glClearColor(155.0, 155.0, 155.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutPassiveMotionFunc(mouse_motion);
  glutDisplayFunc(drawMainWindow);

  return id;
}

int createTeamWindow(const char * windowTitle)
{
  int id = glutCreateWindow(windowTitle);
  assert (0!=id);

  glClearColor(155.0, 155.0, 155.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse_team);
  glutMotionFunc(mouse_motion_team);
  glutPassiveMotionFunc(mouse_motion_team);
  glutDisplayFunc(drawTeamWindow);

  return id;
}

int createGameWindow(const char * windowTitle)
{
  int id = glutCreateWindow(windowTitle);
  assert (0!=id);

  glClearColor(155.0, 155.0, 155.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse_gamesim);
  glutMotionFunc(mouse_motion_gamesim);
  glutPassiveMotionFunc(mouse_motion_gamesim);
  glutDisplayFunc(drawGameWindow);

  return id;
  }

int createTradeWindow(const char * windowTitle)
{
  
  int id = glutCreateWindow(windowTitle);
  assert (0!=id);

  glClearColor(155.0, 155.0, 155.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse_trade);
  glutMotionFunc(mouse_motion_trade);
  glutPassiveMotionFunc(mouse_motion_trade);
  glutDisplayFunc(drawTradeWindow);

  return id;

}

void init_gl_window()
{
  char *argv[] = {programName};
  int argc = sizeof(argv)/sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  mainWindowID = createMainWindow(programName);
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
  footballT = loadTexture("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/images/footballT.pam");

  glutMainLoop();
}

int main()
{
  loadButtons ("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/textfiles/tradePlayerButtons.txt",statB,statBN);
  loadButtons ("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/textfiles/tradeTeamButtons.txt",teamB,teamBN);
  myfile.open("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/textfiles/teams.txt");
  TEAM = new team * [32];
  for (int i = 0; i < 32; ++i)
    TEAM [i] = new team(myfile);
  if (myfile.is_open()) {myfile.close();}

  myfile.open("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/textfiles/teams.txt");
  gs = *(new gamesim());
  gamesimpointer = &gs;
  srand48(time(NULL));

  loadButtonsTeam("/users/ryanabdella/Documents/School/Computer Science/Software Design/Football/Awesomer-Football/textfiles/buttons.txt", teambarr);

  if (myfile.is_open()) {myfile.close();}
  init_gl_window();
  for (int i = 0; i < 32; ++i) delete TEAM[i];
  delete TEAM;
  delete gamesimpointer;
}
