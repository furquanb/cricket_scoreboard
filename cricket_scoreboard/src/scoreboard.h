#include<string> 
#include<vector>
#include "team.h"
using namespace std;
class scoreboard
{
    team t1,t2;
    int nbPlayers;
    int overs;
    string nextBall();
    public:
    void initiateMatch();
    void play(team &,int);
    void getResult();
};