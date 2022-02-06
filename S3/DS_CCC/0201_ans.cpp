#include <iostream>

#include <iomanip>

#include <stdlib.h>

#define MAX_PIXELS 2000000

using namespace std;

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
    int w;

    int h;

    int m;

    Pixel *pixel;

    Image();

    Image(int w, int h);

    ~Image();

    Image *Rotate();

    int GetValue(int row, int col);

    void SetValue(int row, int col, int val);

    Image &Subimage(int top, int bottom, int left, int right);

    int *Histogram(int top, int bottom, int left, int right);

    void ShowImg();
};

Image::Image()

{

    pixel = new Pixel[MAX_PIXELS];

    this->w = 1000;

    this->h = 1000;

    this->m = 0;
}

Image::Image(int h, int w)

{

    pixel = new Pixel[MAX_PIXELS];

    this->w = w;

    this->h = h;

    this->m = 0;
}

Image::~Image()

{

    delete[] pixel;

    w = h = m = 0;
}

Image *RandomImage(int h, int w, int n_pixels)

{

    srand(0);

    Image *img = new Image(h, w);

    int i, r, c, v;

    for (i = 0; i < n_pixels; i++)

    {

        r = rand() % h;

        c = rand() % w;

        v = rand() % 255 + 1;

        img->SetValue(r, c, v);
    }

    return img;
}

Image *Image::Rotate()

{

    Image *img = new Image(w, h);

    int *rowSize = new int[w]();

    int *rowStart = new int[w]();

    int i, j;

    for (i = 0; i < m; i++)

        rowSize[pixel[i].col]++;

    rowStart[0] = rowSize[0];

    for (i = 1; i < w; i++)

        rowStart[i] = rowStart[i - 1] + rowSize[i];

    for (i = 0; i < m; i++)
    {

        j = rowStart[pixel[i].col] - 1;

        img->pixel[j].row = pixel[i].col;

        img->pixel[j].col = img->w - pixel[i].row - 1;

        img->pixel[j].val = pixel[i].val;

        rowStart[pixel[i].col]--; // update the new location for this row to put the next transposed term

        // rowStart[0] = 0;

        // for (i=1; i<w; i++)

        //     rowStart[i] = rowStart[i-1] + rowSize[i-1];

        // for (i = 0 ; i < m ; i++) {

        //   j = rowStart[pixel[i].col];

        //   img->pixel[j].row= pixel[i].col;

        //   img->pixel[j].col = pixel[i].row;

        //   img->pixel[j].val = pixel[i].val;

        //   rowStart[pixel[i].col]++; // update the new location for this row to put the next transposed term
    }

    img->m = m;

    delete[] rowSize;

    delete[] rowStart;

    return img;
}

int Image::GetValue(int row, int col)

{

    int i;

    for (i = 0; i < m; i++)

    {

        if ((pixel[i].row == row) && (pixel[i].col == col))

            return pixel[i].val;
    }

    return 0;
}

void Image::SetValue(int row, int col, int val)

{

    int i = 0, j;

    while ((i < m) && ((pixel[i].row < row) || ((pixel[i].row == row) && (pixel[i].col < col))))

    {

        i++;
    }

    if ((pixel[i].row == row) && (pixel[i].col == col))

        pixel[i].val = val;

    else

    {

        for (j = m; j >= i + 1; j--)

        {

            pixel[j].row = pixel[j - 1].row;

            pixel[j].col = pixel[j - 1].col;

            pixel[j].val = pixel[j - 1].val;
        }

        pixel[j].row = row;

        pixel[j].col = col;

        pixel[j].val = val;

        m++;
    }
}

Image &Image::Subimage(int top, int bottom, int left, int right)

{

    Image *img = new Image(bottom - top + 1, right - left + 1);

    int i, n = 0;

    for (i = 0; i < m; i++)

    {

        if (pixel[i].row >= top && pixel[i].row <= bottom

            && pixel[i].col >= left && pixel[i].col <= right)

        {

            img->pixel[n].row = pixel[i].row - top;

            img->pixel[n].col = pixel[i].col - left;

            img->pixel[n].val = pixel[i].val;

            n++;
        }

        img->m = n;
    }

    return *img;
}

int *Image::Histogram(int top, int bottom, int left, int right)

{

    int *h = new int[right - left + 1]();

    int i;

    // for (i=0; i<right-left+1; i++)

    //     h[i] = 0;

    for (i = 0; i < m; i++)

    {

        if (pixel[i].row >= top && pixel[i].row <= bottom &&

            pixel[i].col >= left && pixel[i].col <= right)

        {

            int w = pixel[i].row - top;

            h[pixel[i].col - left] += w * pixel[i].val;

            // k ++;

            // cout << k << "," << pixel[i].row << "," << pixel[i].col << "," << pixel[i].val << endl;
        }
    }

    // cout << k << endl;

    return h;
}

void Image::ShowImg()

{

    int r, c;

    for (r = 0; r < h; r++)

    {

        for (c = 0; c < w; c++)

            cout << setw(4) << GetValue(r, c);

        cout << endl;
    }

    cout << endl;
}

void PrintHistogram(int *hv, int start, int end)

{

    int i;

    cout << hv[start];

    for (i = start + 1; i <= end; i++)

        cout << " " << hv[i];

    cout << endl;

    delete[] hv;
}

int *FailureFunction(int *data, int length)

{

    int *f = new int[length]();

    f[0] = -1;

    for (int j = 1; j < length; j++)

    {

        int i = f[j - 1];

        while ((data[j] != data[i + 1]) && i != -1)

            i = f[i];

        if (data[j] == data[i + 1])

            f[j] = i + 1;

        else

            f[j] = -1;
    }

    return f;
}

int KMP(int start, int *pat, int length_p, int *data, int length_d, int *f)

{ // find the location of the occurrence of pat in data

    int posP = 0, posS = start;

    while ((posP < length_p) && (posS < length_d))

    {

        if (pat[posP] == data[posS])

        {

            posP++;

            posS++;
        }

        else if (posP == 0)

            posS++;

        else
            posP = f[posP - 1] + 1;
    }

    if (posP < length_p)

        return -1;

    else

        return posS - length_p;
}

void Detect(Image &img, Image &obj, int *r, int *c)

{

    int i;

    int *ho = obj.Histogram(0, obj.h - 1, 0, obj.w - 1);

    int *f = FailureFunction(ho, obj.w);

    int *hi, posc;

    for (i = 0; i < img.h - obj.h + 1; i++)

    {

        hi = img.Histogram(i, i + obj.h - 1, 0, img.w);

        posc = KMP(0, ho, obj.w, hi, img.w, f);

        if (posc >= 0)

        {

            *r = i;

            *c = posc;

            return;
        }
    }
}

int main()

{

    Image *img1, *rimg, img2;

    int w = 8000, h = 8000, n_pixels = 50000;

    int y1 = 120, y2 = 600, x1 = 600, x2 = 800;

    int r, c;

    cout << "--- Test small random generation" << endl;

    img1 = RandomImage(10, 8, 20);

    img1->ShowImg();

    cout << "--- Test subimage" << endl;

    img1->Subimage(3, 6, 2, 5).ShowImg();

    cout << "--- Test rotating image" << endl;

    rimg = img1->Rotate();

    rimg->ShowImg();

    cout << "--- Test super large random generation" << endl;

    img1 = RandomImage(h, w, n_pixels);

    cout << "--- Test histogram computation" << endl;

    int *hv1 = img1->Histogram(y1, y2, 0, img1->w);

    PrintHistogram(hv1, x1, x2);

    img2 = img1->Subimage(y1, y2, x1, x2);

    int *hv2 = img2.Histogram(0, img2.h, 0, img2.w);

    PrintHistogram(hv2, 0, img2.w);

    cout << "--- Test failure function and KMP" << endl;

    int p[10] = {1, 2, 3, 1, 2, 3, 1, 3, 1, 2}, t[18] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 3, 1, 2, 2, 1, 2, 1, 1};

    int *f = FailureFunction(p, 10);

    for (int i = 0; i < 10; i++)

        cout << f[i] << " ";

    cout << endl;

    int pos = KMP(0, p, 10, t, 18, f);

    cout << pos << endl;

    cout << "--- Test object detection on a super large image" << endl;

    Detect(*img1, img2, &r, &c);

    cout << "object found at: " << r << ", " << c << endl;

    return 0;
}