#ifndef _BUTTON_
#define _BUTTON_

class button
{
 public:
  bool isPressed;
  bool overButton;
  double pos[4];
  button(bool p, bool o, double bp[4]) {isPressed = p; overButton = o; for (int i = 0; i < 4; ++i) {pos[i] = bp[i];}};

  button() {isPressed = false; overButton = false; for (int i = 0; i < 4; ++i)pos[i]=0;
  }

  button(istream & is){
    isPressed = false; overButton = false;
    is >> pos[0] >> pos[1] >> pos[2] >> pos[3];
  }

  void print() {
    cout << isPressed << " " << overButton << " ";
    for (int i = 0; i < 4; ++i) cout << pos[i] << " ";
    cout << endl;
  }

};

#endif
