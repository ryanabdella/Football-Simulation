//
//  football.h
//  Football
//
//  Created by Ryan H Abdella on 5.30.14.
//
//

#ifndef Football_football_h
#define Football_football_h

void teamTextures();

void loadButtons (const char* fileName, button ** & stat, int & num);

void loadButtonsTeam (const char * fileName, button ** & teambarr);

void drawBox(double x, double y, double width, double height);

void drawBox(double *pos);

void drawText(double x, double y, const char * text);

void drawText2(double x, double y, const char * text);

void drawNumber(double x, double y, double num);

void drawWords(double x, double y, const char * text);

void drawWords2(double x, double y, const char * text);

bool onButton(int x, int y, button b);

void drawMainWindow();

void drawPlayersTeam(team &t1, int x, int y);

void drawAccumTeam(team &t1, int x, int y);

void drawTeamWindow();

void drawGameWindow();

void drawTradeWindow();

void exitAll();

void keyboard(unsigned char c, int x, int y);

void reshape(int w, int h);

void mouse(int mouseButton, int state, int x, int y);

void mouse_team(int mouseButton, int state, int x, int y);

void mouse_gamesim(int mouseButton, int state, int x, int y);

void mouse_trade(int mouseButton, int state, int x, int y);

void mouse_motion(int x, int y);

void mouse_motion_team(int x, int y);

void mouse_motion_trade(int x, int y);

void mouse_motion_gamesim(int x, int y);

void init_gl_window();



#endif
