#include<iostream>
#include "scoreboard.h"
using namespace std;

void scoreboard::initiateMatch()
{
    string name;
    do
    {
        cout<<"Enter nos of players per team:";
        cin>>this->nbPlayers;
        if(this->nbPlayers<=1)
            cout<<"no of player should be minimum 2";
    } while (this->nbPlayers<=1);
    
    cout<<endl<<"Enter no of overs:";
    cin>>this->overs;

    cout<<endl<<"Name of Team 1:";
    cin>>name;
    t1.InitializeTeam(name,this->nbPlayers);
    cout<<endl<<"Name of Team 2:";
    cin>>name;
    t2.InitializeTeam(name,this->nbPlayers);

    play(t1,-1);
    play(t2,t1.getTeamScore());
    getResult();
}
string scoreboard::nextBall()
{
    string res;
    cin>>res;
    return res;
}
void scoreboard::play(team &t,int target)
{
    string c;
    cout<<endl<<t.getName()<<" is batting.";
    while (t.overs_played.first<overs||t.overs_played.second<1)
    {
        if(target!=-1 && t.getTeamScore()>target)
        {
            t2.print_stats();
            return;
        }
        cout<<endl<<"Ball "<<to_string(t.overs_played.first)+"."+to_string(t.overs_played.second)<<":";
        c=nextBall();
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        if(c.compare("w")==0)
        {
            t.playerOut();
            t.incrementOver();
            if(t.getWickets()==this->nbPlayers-1)
            {
                t.print_stats();
                break;
            }
            else
            {
                t.nextPlayer();
            }
        }
        else if(c.compare("wd")==0 || c.compare("nb")==0)
        {
            t.scoreExtra();
        }
        else if(c.length()==1 && c[0]-'0'<=6 && c[0]-'0'>=0)
        {
            t.score(stoi(c));
            t.incrementOver();
        }
        else
        {
            cout<<"wrong input";
        }
        
    }
}
void scoreboard::getResult()
{
    cout<<"endl"<<"Results:"<<endl;
    cout<<t1.getName()+":"<<t1.getTeamScore()<<"/"<<t1.getWickets()<<"\t\tExtra:"<<t1.getExtras()<<endl;
    cout<<t2.getName()+":"<<t2.getTeamScore()<<"/"<<t2.getWickets()<<"\t\tExtra:"<<t2.getExtras()<<endl;
    if(t1.getTeamScore()>t2.getTeamScore())
    {
        cout<<t1.getName()<<" won the match by "<<t1.getTeamScore()-t2.getTeamScore()<<" runs.";
    }
    else if(t1.getTeamScore()<t2.getTeamScore())
    {
        cout<<t2.getName()<<" won the match by "<<this->nbPlayers-t2.getWickets()-1<<" wickets.";
    }
    else
        cout<<"Match is Draw!!";

    cout<<endl;
    t1.cleanup();
    t2.cleanup();
}

int main()
{
    scoreboard s;
    s.initiateMatch();

}