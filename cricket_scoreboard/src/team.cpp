#include<iostream>
#include "team.h"
using namespace std;


void team::InitializeTeam(string name,int cnt)
{
    this->name=name;
    this->player_count=cnt;
    this->runs=0;
    this->extras=0;
    wickets=0;
    string pname;
    overs_played.first=0;
    overs_played.second=1;

    for(int i=0;i<this->player_count;i++)
    {
        this->pl.push_back(new player());
    }
    for(int i=0;i<this->player_count;i++)
    {
        cout<<endl<<"Name of Player "<<i+1<<":";
        cin>>pname;
        pl[i]->initializePlayer();
        pl[i]->setName(pname);
    }
    if(pl[1])
    {
        onStrikePlayer=pl[0];
        offStrikePlayer=pl[1];
    }
}
void team::score(int run)
{
    this->runs=this->runs+run;
    onStrikePlayer->score(run);
    if(run%2==1)
        changeStrike();
}
void team::scoreExtra()
{
    this->runs++;
    this->extras++;
}
void team::changeStrike()
{
    player* temp=onStrikePlayer;
    onStrikePlayer=offStrikePlayer;
    offStrikePlayer=temp;
    temp=NULL;
}
void team::playerOut()
{
    onStrikePlayer->playerOut();
    wickets++;
}
void team::nextPlayer()
{
    if((wickets+1)<player_count)
    {
        onStrikePlayer=pl[wickets+1];
        print_stats();
        return;
    }
    print_stats();
}

int team::getTeamScore()
{
    return this->runs;
}
int team::getWickets()
{
    return this->wickets;
}
int team::getExtras()
{
    return this->extras;
}
void team::incrementOver()
{
    if(overs_played.second==5)
    {
        overs_played.first++;
        overs_played.second=0;

    }
    else if(overs_played.second==0 && overs_played.first>0)
    {
        changeStrike();
        print_stats();
        overs_played.second++;
    }
    else
        overs_played.second++;

}
string team::getName()
{
    return this->name;
}

void team::print_stats()
{
    cout<<endl<<"Player\t\tScore\t4s\t6s\tBalls";
    for(int i=0;i<this->player_count;i++)
    {
        if(pl[i]==onStrikePlayer || pl[i]==offStrikePlayer)
            pl[i]->printPlayerScore(true);
        else
            pl[i]->printPlayerScore(false);
    }
    cout<<endl<<getName()+":"<<getTeamScore()<<"/"<<getWickets()<<"\t\tExtra:"<<getExtras()<<endl;
}

void team::cleanup()
{
    for(int i=0;i<this->player_count;i++)
    {
        delete(this->pl[i]);
        this->pl[i]=NULL;
    }

}
