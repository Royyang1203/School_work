#include <iostream>

class Pixel
{
public:
    int row; // the row index of the pixel
    int col; // the column index of the pixel
    int val; // the intensity value of the pixel
};

class Image final // final means that this class cannot be inherited by any other class
{
public:
    int h;
    int w;
    int m;
    Pixel *pixel;
    Image();
    Image(int h, int w);
    ~Image();
    Image *Rotate();
    int GetValue(int row, int col);
    void SetValue(int row, int col, int val);
    Image &Subimage(int top, int bottom, int left, int right);
    int *Histogram(int top, int bottom, int left, int right);
    void ShowImg();
};