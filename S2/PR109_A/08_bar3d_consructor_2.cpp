// 請設計一個類別 bar3d 代表一個長方體，該類別中要有公開的屬性 width，height 跟 depth 分別代表寬，長跟高。

// 請設計一個建構子給 bar3d 這類別，該建構子以三個整數為參數，依序用來設定 width，height 跟 depth。

// width，height 跟 depth 的有效範圍是零到一千，如果有任何一個屬性不在範圍內，就將三個屬性都設成零。

// 請設計一個預設建構子給 bar3d 類別，該建構子沒有參數，會將 width，height 跟 depth 都設為 0。

// Please design a class bar3D represent a 3D bar, the class bar3D must include at less three public member width, height and depth.

// Please design a constructor for bar3d. The constructor hold three parameter to set width, height and depth in order.

// The valid range for width, height and depth is greater than 0 and smaller than 1000.

// If any one of three member are out of range, then set all of them to 0.

// Please design a default constructor who setwidth, height and depth to 0.
class bar3d
{
public:
    int width;
    int height;
    int depth;
    bar3d()
    {
        width = height = depth = 0;
    }
    bar3d(int a, int b, int c)
    {
        if (a < 1000 && a > 0 && b < 1000 && b > 0 && c < 1000 && c > 0)
        {
            width = a;
            height = b;
            depth = c;
        }
        else
            width = height = depth = 0;
    }
};