#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

typedef long long ll;

struct RGB {
    int R;
    int G;
    int B;
};

ll colorInversion1(vector<vector<RGB>> img, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].R = 255 - img[i][j].R;
            img[i][j].G = 255 - img[i][j].G;
            img[i][j].B = 255 - img[i][j].B;
        }
    }
    auto end = std::chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

ll colorInversion2(vector<vector<RGB>> img, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].R = 255 - img[i][j].R;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].G = 255 - img[i][j].G;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].B = 255 - img[i][j].B;
        }
    }
    auto end = std::chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

ll colorInversion3(vector<vector<RGB>> img, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            img[i][j].R = 255 - img[i][j].R;
            img[i][j].G = 255 - img[i][j].G;
            img[i][j].B = 255 - img[i][j].B;
        }
    }
    auto end = std::chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

ll colorInversion4(vector<vector<RGB>> img, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].R = 255 - img[i][j].R;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            img[i][j].G = 255 - img[i][j].G;
            img[i][j].B = 255 - img[i][j].B;
        }
    }
    auto end = std::chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

ll colorInversion5(vector<vector<RGB>> img, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            img[i][j].R = 255 - img[i][j].R;
            img[i][j].G = 255 - img[i][j].G;
            img[i][j].B = 255 - img[i][j].B;

            img[i][j + 1].R = 255 - img[i][j + 1].R;
            img[i][j + 1].G = 255 - img[i][j + 1].G;
            img[i][j + 1].B = 255 - img[i][j + 1].B;

            img[i + 1][j].R = 255 - img[i + 1][j].R;
            img[i + 1][j].G = 255 - img[i + 1][j].G;
            img[i + 1][j].B = 255 - img[i + 1][j].B;

            img[i + 1][j + 1].R = 255 - img[i + 1][j + 1].R;
            img[i + 1][j + 1].G = 255 - img[i + 1][j + 1].G;
            img[i + 1][j + 1].B = 255 - img[i + 1][j + 1].B;
        }
    }
    auto end = std::chrono::steady_clock::now();
    return chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
    int sizes[] = { 100, 200, 300, 400, 500, 600, 700, 800 };
    for (int s = 0; s < 8; s++) {
        int n = sizes[s];
        printf("size: %.d\n", n);
        vector< vector<RGB> > img;
        for (int i = 0; i < n; i++) {
            vector<RGB> vec(n);
            img.push_back(vec);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j].R = rand() % 256;
                img[i][j].G = rand() % 256;
                img[i][j].B = rand() % 256;
            }
        }
        for (int v = 1; v <= 5; v++) {
            printf("version: %.d\n", v);
            int rep = 100;
            while (rep--) {
                ll time;
                switch(v)
                {
                    case 1:
                        time = colorInversion1(img, n);
                        break;
                    case 2:
                        time = colorInversion1(img, n);
                        break;
                    case 3:
                        time = colorInversion2(img, n);
                        break;
                    case 4:
                        time = colorInversion2(img, n);
                        break;
                    default:
                        time = colorInversion2(img, n);
                        break;
                };
                printf("%.d\n", time);
            }
        }
    }
    return 0;
}
