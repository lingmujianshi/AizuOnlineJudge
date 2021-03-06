//ALDS1_4_C Search - Dictionary
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define M 1046527
#define NIL (-1)
#define L 14

class Dictionary
{
public:
    char** H; /* Hash Table */

    Dictionary(){
        H = new char* [M];
        for (int i = 0; i < M; i++)
        {
            H[i] = new char[L];
            H[i][0] = '\0';
        }
    }
    ~Dictionary(){
        delete[] H;
        H=0;
    }

    int getChar(char ch)
    {
        if (ch == 'A')
            return 1;
        else if (ch == 'C')
            return 2;
        else if (ch == 'G')
            return 3;
        else if (ch == 'T')
            return 4;
        else
            return 0;
    }

    /* convert a string into an integer value */
    long long getKey(char str[])
    {
        long long sum = 0, p = 1, i;
        for (i = 0; i < strlen(str); i++)
        {
            sum += p * (getChar(str[i]));
            p *= 5;
        }
        return sum;
    }

    int h1(int key) { return key % M; }
    int h2(int key) { return 1 + (key % (M - 1)); }

    int find(char str[])
    {
        long long key, i, h, ha, hb;
        key = getKey(str); //文字列を数値に変換
        for (i = 0;; i++)
        {
            ha = h1(key);
            hb = h2(key);
            h = (ha + i * hb) % M;
            if (strcmp(H[h], str) == 0)
                return 1;
            else if (strlen(H[h]) == 0)
                return 0;
        }
        return 0;
    }

    int insert(char str[])
    {
        long long key, i, h, ha, hb;
        key = getKey(str); //文字列を数値に変換
        for (i = 0;; i++)
        {
            ha = h1(key);
            hb = h2(key);
            h = (ha + i * hb) % M;
            if (strcmp(H[h], str) == 0)
                return 1;
            else if (strlen(H[h]) == 0)
            {
                strcpy(H[h], str);
                return 0;
            }
        }
        return 0;
    }
};

int main()
{
    int i, n, h;
    char str[L], com[9];
    Dictionary dic;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s %s", com, str);

        if (com[0] == 'i')
        {
            dic.insert(str);
        }
        else
        {
            if (dic.find(str))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }

    return 0;
}