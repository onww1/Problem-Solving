#include <cstdio>
#include <string>
using namespace std;

struct album
{
    int year;
    string title;
};

int main(void){
    int t, s, e;
    scanf("%d", &t);
    
    album albums[25] = {
        {1967, "DavidBowie"},
        {1969, "SpaceOddity"},
        {1970, "TheManWhoSoldTheWorld"},
        {1971, "HunkyDory"},
        {1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
        {1973, "AladdinSane"},
        {1973, "PinUps"},
        {1974, "DiamondDogs"},
        {1975, "YoungAmericans"},
        {1976, "StationToStation"},
        {1977, "Low"},
        {1977, "Heroes"},
        {1979, "Lodger"},
        {1980, "ScaryMonstersAndSuperCreeps"},
        {1983, "LetsDance"},
        {1984, "Tonight"},
        {1987, "NeverLetMeDown"},
        {1993, "BlackTieWhiteNoise"},
        {1995, "1.Outside"},
        {1997, "Earthling"},
        {1999, "Hours"},
        {2002, "Heathen"},
        {2003, "Reality"},
        {2013, "TheNextDay"},
        {2016, "BlackStar"}
    };
    
    while(t--){
        scanf("%d %d", &s, &e);
        int si = -1, ei = -1;
        bool flag = true;
        for(int i=0; i<25; i++){
            if(s <= albums[i].year && albums[i].year <= e){
                if(flag){
                    si = i;
                    flag = false;
                }
                ei = i;
            }
            else if(albums[i].year > e){
                break;
            }
        }
        

        if(si != -1){
            printf("%d\n", ei-si+1);
            for(int i=si; i<=ei; i++){
                printf("%d %s\n", albums[i].year, albums[i].title.c_str());
            }
        } else printf("0\n");
    }
   
    return 0;
}

