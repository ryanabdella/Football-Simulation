#ifndef _TEXTURE_
#define _TEXTURE_

void drawTexture(int texNum, double x, double y, double width, double height, double alpha=1.0, double rotationAngle=0.0);
void drawTexture(int texNum, double *arr, double alpha=1.0);
int loadTexture(const char *filename);
pair<double, double> rotatePt(double x0, double y0, double x, double y, double theta);
int power_of_two(int val);


#endif // _TEXTURE_
