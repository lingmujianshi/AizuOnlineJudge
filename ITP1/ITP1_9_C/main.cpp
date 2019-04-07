#include <iostream>
#include <string>

int main()
{
    int n,taro,hanako;
    std::cin >> n;

    taro=hanako=0;
    for (int i=0; i<n; i++) {
        std::string ts,hs;
        std::cin >> ts >> hs;
        size_t tl = ts.size();
        size_t hl = hs.size();
        for (int j=0; j<100; j++) {
            if (ts[j]>hs[j]){
                taro+=3;
                break;
            }
            else if (ts[j]<hs[j]){
                hanako+=3;
                break;
            }
            else if (j==tl-1 && j==hl-1) {
                taro++;
                hanako++;
                break;
            }
        }
    }
    std::cout << taro << " " << hanako << std::endl;

    return 0;
}
