// Description

// 請寫一個可用來保存長方型的 class。

// 請將 data members 置於 private 段；將 member functions 置於 public 段。

// data member:

// w: 寬
// h: 高
// member functions:

// void setW(W): 設定寬度
// void setH(H): 設定高度
// int getW() const: 讀取寬度
// int getH() const: 讀取高度
// int getArea() const: 讀取面積
class Rectangle
{
private:
    int w;
    int h;

public:
    void setW(int W)
    {
        w = W;
    }
    void setH(int H)
    {
        h = H;
    }
    int getW() const
    {
        return w;
    }
    int getH() const
    {
        return h;
    }
    int getArea() const
    {
        return w * h;
    }
};
