#include "201.cpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#define MAX_PIXELS 60000
using namespace std;

Image::Image()
{
    this->w = 1000;
    this->h = 1000;
    this->m = 0;
    pixel = new Pixel[MAX_PIXELS];
}

Image::Image(int h, int w)
{
    this->w = w;
    this->h = h;
    this->m = 0;
    pixel = new Pixel[MAX_PIXELS];
}

Image::~Image()
{
    delete[] pixel;
    w = h = m = 0;
}

Image *Image::Rotate()
{
    Image *res = new Image(w, h);
    if (m > 0)
    {
        res->m = m;
        int row_size[w] = {0};
        int row_start[w] = {0};
        for (int i = 0; i < m; ++i)
            ++row_size[pixel[i].col];
        row_start[0] = 0;
        for (int i = 1; i < w; ++i)
            row_start[i] = row_size[i - 1] + row_start[i - 1];
        for (int i = 0; i < m; ++i)
        {
            int j = row_start[pixel[i].col] + --row_size[pixel[i].col];
            res->pixel[j].row = pixel[i].col;
            res->pixel[j].col = h - 1 - pixel[i].row;
            res->pixel[j].val = pixel[i].val;
        }
    }
    return res;
}

int Image::GetValue(int row, int col)
{
    int index = 0;
    while (index < m && (pixel[index].row != row || pixel[index].col != col))
        ++index;
    if (index < m)
        return pixel[index].val;
    else
        return -1;
}

void Image::SetValue(int row, int col, int val)
{
    int index = 0;
    while (pixel[index].row < row && index < m)
        ++index;
    while (pixel[index].row == row && pixel[index].col < col && index < m)
        ++index;

    if (pixel[index].row == row && pixel[index].col == col)
    {
        pixel[index].row = row;
        pixel[index].col = col;
        pixel[index].val = val;
        return;
    }
    int t = m - 1;
    while (t >= index)
    {
        pixel[t + 1].row = pixel[t].row;
        pixel[t + 1].col = pixel[t].col;
        pixel[t + 1].val = pixel[t].val;
        --t;
    }
    pixel[index].row = row;
    pixel[index].col = col;
    pixel[index].val = val;
    ++m;
    return;
}

Image &Image::Subimage(int top, int bottom, int left, int right)
{
    Image *res = new Image(bottom - top + 1, right - left + 1);
    int index = 0;
    for (int i = top; i <= bottom; ++i)
    {
        while (index < m && pixel[index].row < i)
            ++index;
        for (int j = left; j <= right; ++j)
        {
            while (index < m && pixel[index].row == i && pixel[index].col < j)
                ++index;
            if (pixel[index].row == i && pixel[index].col == j)
            {
                res->SetValue(i - top, j - left, pixel[index].val);
                ++index;
            }
        }
    }
    return *res;
}

int *Image::Histogram(int top, int bottom, int left, int right)
{
    Image t = this->Subimage(top, bottom, left, right);
    int *res = new int[t.w];
    for (int i = 0; i < t.w; ++i)
        res[i] = 0;
    for (int i = 0; i < t.m; ++i)
    {
        res[t.pixel[i].col] += t.pixel[i].val * t.pixel[i].row;
    }
    return res;
}

void Image::ShowImg()
{
    // for (int i = 0; i < m; ++i)
    // {
    //     cout << pixel[i].row << " " << pixel[i].col << "    " << pixel[i].val << endl;
    // }

    int pos = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (pixel[pos].row == i && pixel[pos].col == j)
            {
                cout << setw(4) << pixel[pos].val;
                ++pos;
            }
            else
                cout << setw(4) << "0";
        }
        cout << endl;
    }
    return;
}

void PrintHistogram(int *hv, int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        if (i != start)
            cout << " ";
        cout << hv[i];
    }
    cout << endl;
}

int *FailureFunction(int *data, int length)
{
    int *f = new int[length];
    f[0] = -1;
    for (int i = 1; i < length; ++i)
    {
        int j = f[i - 1];
        while ((data[i] != data[j + 1]) && j >= 0)
        {
            j = f[j];
        }
        if (data[i] == data[j + 1])
            f[i] = j + 1;
        else
            f[i] = -1;
    }
    return f;
}

int KMP(int start, int *pat, int length_p, int *data, int length_d, int *f)
{
    int i = start;
    int j = 0;
    while (i < length_d && j < length_p)
    {
        if (pat[j] == data[i])
        {
            ++j;
            ++i;
        }
        else
        {
            if (j == 0)
                ++i;
            else
                j = f[j - 1] + 1;
        }
    }
    if (j < length_p)
        return -1;
    else
        return i - length_p;
}

void Detect(Image &img, Image &obj, int *r, int *c)
{
    int *pat = obj.Histogram(0, obj.h - 1, 0, obj.w - 1);
    PrintHistogram(pat, 0, obj.w - 1);
    int *f = FailureFunction(pat, obj.w);
    int k = -1;
    *r = -1;
    *c = -1;
    for (int i = 0; i < img.h - obj.h; ++i)
    {
        int *t = img.Histogram(i, obj.h + i - 1, 0, img.w - 1);
        k = KMP(0, pat, obj.w, t, img.w, f);
        // cout << i << " " << k << endl;
        if (i == 120)
        {
            PrintHistogram(t, 600, 800);
            cout << k << endl;
        }
        if (k != -1)
        {
            *r = i;
            *c = k;
            return;
        }
    }
}

Image *RandomImage(int h, int w, int n) //randomly generate an Image object of h x w pixels with at most n non-black pixels
{
    srand(time(nullptr));
    // srand(0);
    Image *img = new Image(h, w);
    int i, r, c, v;
    for (i = 0; i < n; i++)
    {
        r = rand() % h;
        c = rand() % w;
        v = rand() % 255 + 1;
        // cout << i << endl;
        img->SetValue(r, c, v);
    }
    return img;
}

void show_data(Image &jj)
{
    for (int i = 0; i < jj.m; ++i)
        cout << jj.pixel[i].row << " " << jj.pixel[i].col << "    " << jj.pixel[i].val << endl;

    cout << jj.m << endl;
}

int main()
{
    double START, END;
    START = clock();

    // Image *img1, *rimg;
    // img1 = RandomImage(15, 12, 40); // generate a small Image object of 10x8 pixels with at most 20 non-black pixels.
    // img1->ShowImg();                // display the generated image
    // cout << "--- Test Histogram" << endl;
    // int *p = img1->Histogram(0, 6, 0, 11); // get the specified subimage from the image
    // PrintHistogram(p, 0, 11);
    // int p[30];
    // for (int i = 0; i < 30; ++i)
    // {
    //     int t = rand() % 5;
    //     p[i] = t;
    // }
    // int *f = FailureFunction(p, 30); // compute the values of the failure function from sequence p
    // for (int i = 0; i < 30; i++)     // display the computed values of the failure function
    //     cout << p[i] << " ";
    // cout << endl;
    // for (int i = 0; i < 30; i++) // display the computed values of the failure function
    //     cout << f[i] << " ";

    // Image *img1, *rimg;

    // cout << "--- Test small random generation" << endl;
    // img1 = RandomImage(10, 8, 20); // generate a small Image object of 10x8 pixels with at most 20 non-black pixels.
    // img1->ShowImg();               // display the generated image
    // cout << "--- Test subimage" << endl;
    // img1->Subimage(3, 6, 2, 5).ShowImg(); // get the specified subimage from the image
    // cout << "--- Test rotating image" << endl;
    // rimg = img1->Rotate(); // rotate the generated image clockwise by 90 degrees
    // rimg->ShowImg();       // display the rotated image
    // int *a = img1->Histogram(3, 6, 2, 5);
    // for (int i = 0; i < 4; ++i)
    //     cout << a[i] << endl;
    // return 0;
    // int p[25] = {1, 1, 2, 1, 1, 3, 3, 1, 1, 2, 1, 1, 2, 1, 1, 3, 1, 2, 1, 3, 2, 1, 2, 1, 3}; // a shorter number sequence p
    // int *f = FailureFunction(p, 25);                                                         // compute the values of the failure function from sequence p
    // for (int i = 0; i < 25; i++)                                                             // display the computed values of the failure function
    //     cout << f[i] << " ";

    Image *img1, *rimg, img2;
    int w = 8000, h = 8000, n_pixels = 50000;
    int y1 = 120, y2 = 200, x1 = 600, x2 = 800;
    int r, c;

    cout << "--- Test super large random generation" << endl;
    img1 = RandomImage(h, w, n_pixels); // generate a super large image
    cout << "--- Test histogram computation" << endl;
    int *hv1 = img1->Histogram(y1, y2, 0, img1->w);  // compute the histogram vector for an image slice by specifying a search window
    PrintHistogram(hv1, x1, x1 + 200);               // print out a part of the histogram vector
    img2 = img1->Subimage(y1, y2, x1, x2);           // get the subimage from the specified search window
    int *hv2 = img2.Histogram(0, img2.h, 0, img2.w); // compute the histogram vector for the subimage
    PrintHistogram(hv2, 0, 200);                     // print out the histogram vector computed from the subimage
    cout << "--- Test failure function and KMP" << endl;
    int p[10] = {1, 2, 3, 1, 2, 3, 1, 3, 1, 2};                         // a shorter number sequence p
    int t[18] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 3, 1, 2, 2, 1, 2, 1, 1}; // a longer number sequence t
    int *f = FailureFunction(p, 10);                                    // compute the values of the failure function from sequence p
    for (int i = 0; i < 10; i++)                                        // display the computed values of the failure function
        cout << f[i] << " ";
    cout << endl;
    int pos = KMP(0, p, 10, t, 18, f); // perform the KMP algorithm using p and t
    cout << pos << endl;               // output the located position
    cout << "--- Test object detection on a super large image" << endl;
    Detect(*img1, img2, &r, &c);                           // detect the subimage img2 (object) on the super large image img1
    cout << "object found at: " << r << ", " << c << endl; // display the location of the detected object
    END = clock();
    cout << "using time >> " << (END - START) / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
