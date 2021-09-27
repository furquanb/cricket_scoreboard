#include<string> 
using namespace std;

class player
{
    private:
    string name;
    int runs,fours,sixes,balls;
    bool out;
    public:
    void initializePlayer();
    void setName(string);
    void score(int);
    void playerOut();
    void printPlayerScore(bool);
};