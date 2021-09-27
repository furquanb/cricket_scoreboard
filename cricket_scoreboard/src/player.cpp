#include<iostream>
#include "player.h"
using namespace std;

void player::initializePlayer()
{
    runs=fours=sixes=balls=0;
    out=false;
}
void player::setName(string name)
{
    this->name=name;
}
void player::score(int run)
{
    this->runs+=run;
    balls++;
    if(run==4)
        fours++;
    else if(run==6)
        sixes++;
}
void player::playerOut()
{
    balls++;
    this->out=true;
}
void player::printPlayerScore(bool is_current)
{
    if(is_current && ! this->out)
        cout<<endl<<name<<"*\t\t"+to_string(runs)+"\t"+to_string(fours)+"\t"+to_string(sixes)+"\t"+to_string(balls);
    else
        cout<<endl<<name<<"\t\t"+to_string(runs)+"\t"+to_string(fours)+"\t"+to_string(sixes)+"\t"+to_string(balls);
}