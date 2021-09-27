#include<string> 
#include<vector>
#include "player.h"
using namespace std;
class team
{
    private:
    string name;
    int runs,player_count,extras,wickets;
    vector<player*> pl;
    player *onStrikePlayer, *offStrikePlayer;
    public:
    pair<int,int> overs_played;
    void InitializeTeam(string,int);
    void score(int);
    void scoreExtra();
    void changeStrike(void);
    void playerOut();
    void print_stats();
    void nextPlayer();
    int getTeamScore();
    int getWickets();
    int getExtras();
    string getName();
    void incrementOver();
    void cleanup();
};