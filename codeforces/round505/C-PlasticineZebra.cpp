/**
 * 该题的关键是理解 cut & reverse & stick 操作实际上可看作顺时针或者逆时针旋转数字轮盘
 * 例如将某一输入 wbwwbwbww 看出数字环如下
 *                  w
 *               w      b
 *               w      w
 *               b      w
 *                w   b
 *                  
 *  无论怎么旋转，环中最大zebra长度且对应该长度的序列是不变的，图中指 wbwbw 。
 */
#include <cstdio>
#include <algorithm>

#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int
#define FIO ""
#define dbug(...) fprintf(stderr, __VA_ARGS__)

template <typename Y> inline bool updmin(Y &a, Y b){if (a > b) {a = b; return 1;} return 0;}
template <typename Y> inline bool updmax(Y &a, Y b){if (a < b) {a = b; return 1;} return 0;}
template <typename Y> inline Y abs(Y a){if (a < 0) a = -a; return a;}
template <typename Y> inline Y sqr(Y a){return a * a;}

typedef std::pair<int, int> par;
#define fx first
#define fy second
#define mpar std::make_pair
#define pb push_back

int read() {
    int w = 1, q = 0, ch = ' ';
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
    return q * w;
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

const int N = 100010;
int n, fir, ed, ans = 0;
char s[N];

#include <cstring>

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i % n + 1]) {
            if (!fir) {
                fir = i;
            }
            if (ed) {
                updmax(ans, i - ed);
            }
            ed = i;
        }
        printf("i = %d fir = %d ed = %d ans = %d\n",
                i,fir,ed,ans);
    }
    updmax(ans, fir + n - ed);
    printf("%d\n", ans);
    return 0;
}
