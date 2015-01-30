#ifndef _ColorStruct_
#define _ColorStruct_

#include<iostream>
using namespace std;

struct Color {
  unsigned red, green, blue;
  Color(const unsigned &r, const unsigned &g, const unsigned &b) {red = r; green = g; blue = b; }
  Color() { red = 255; green = 0; blue = 0; }
  Color(const Color &c) { red = c.red; green = c.green; blue = c.blue; }
  Color(int r, int g, int b) { red = r; green = g; blue = b; }
  Color(istream & is) { is >> red >> green >> blue; }
  void display() { cout << red << " " << green << " " << blue; }
  void setColor(istream & is) { is >> red >> green >> blue; }
};

struct Point2 {
  int x, y;
  Point2(const int &a, const int &b) { x = a; y = b; }
  Point2() { x = 240; y = 320; }
  Point2(const Point2 &p) { x = p.x; y = p.y; }
  void display() { cout << x << " " << y; }
};

#endif
