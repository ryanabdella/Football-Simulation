#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include<iomanip>

class player
{
 public:
  string name;
  string position;
  string output_season;
  string output_game;
  float games;
  
  player & operator = (const player & p)
    {
      name = p.name;
      position = p.position;
      output_season = p.output_season;
        output_game = p.output_game;
      games = p.games;
      return *this;
    }

  player (ifstream& is) {}
    
  player () {}

};

class quarterback : public player
{
public:
    float completions;
    float attempts;
    float passingYards;
    float interceptions;
    float sacks;
    float fumbles;
    float completions_game;
    float attempts_game;
    float passingYards_game;
    float interceptions_game;
    float sacks_game;
    float fumbles_game;
    float passingTouchdowns_game;
    
    quarterback & operator = (const quarterback & p)
    {
        name = p.name;
        position = p.position;
        output_season = p.output_season;
        output_game = p.output_game;
        games = p.games;
        completions = p.completions;
        attempts = p.attempts;
        passingYards = p.passingYards;
        interceptions = p.interceptions;
        sacks = p.sacks;
        fumbles = p.fumbles;
        completions_game = p.completions_game;
        attempts_game = p.attempts_game;
        passingYards_game = p.passingYards_game;
        interceptions_game = p.interceptions_game;
        sacks_game = p.sacks_game;
        fumbles_game = p.fumbles_game;
        passingTouchdowns_game = p.passingTouchdowns_game;
        return *this;
    }
    
    quarterback(ifstream& is)
    {
        stringstream out;
        string temp;
        getline(is, position);
        getline(is, name);
        getline(is, temp);
        out << temp;
        out >> games >> completions >> attempts >> passingYards >> interceptions >> sacks >> fumbles;
        stringstream convert;
        convert << " " << setprecision(3) << ((completions/attempts)*100) << "%       " << setprecision(3) << (passingYards/attempts) << "       " << setprecision(3) << (passingYards/games) << "        " << setprecision(3) << (interceptions/games);
        output_season = convert.str();
        output_game = "";
        completions_game = attempts_game = passingYards_game = interceptions_game = sacks_game = fumbles_game = passingTouchdowns_game = 0;
    }
    
    quarterback()
    {
        position = "QB";
        name = "";
        output_season = "";
        output_game = "";
        games = completions = attempts = passingYards = interceptions = sacks = fumbles = completions_game = attempts_game = passingYards_game = interceptions_game = sacks_game = fumbles_game = passingTouchdowns_game = 0;
    }
    
    float comppercent() {return completions/attempts;}
    float ypcomp() {return passingYards/completions;}
    float interrate() {return interceptions/attempts;}
    float sackrate() {return sacks/attempts;}
    float fumbrate() {return fumbles/(attempts+sacks);}

    void updateOutput()
    {
        stringstream convertQ;
        convertQ << completions_game << "      " << attempts_game << "      " << passingYards_game << "      " << passingTouchdowns_game << "     " << interceptions_game;
        output_game = convertQ.str();
    }
};

class runningback : public player
{
public:
    float rushes;
    float rushingYards;
    float targets;
    float receptions;
    float receivingYards;
    float fumbles;
    float rushes_game;
    float rushingYards_game;
    float targets_game;
    float receptions_game;
    float receivingYards_game;
    float fumbles_game;
    float rushingTouchdowns_game;
    float receivingTouchdowns_game;
    
    runningback & operator = (const runningback & p)
    {
        name = p.name;
        position = p.position;
        output_season = p.output_season;
        output_game = p.output_game;
        games = p.games;
        rushes = p.rushes;
        rushingYards = p.rushingYards;
        targets = p.targets;
        receptions = p.receptions;
        receivingYards = p.receivingYards;
        fumbles = p.fumbles;
        rushes_game = p.rushes_game;
        rushingYards_game = p.rushingYards_game;
        targets_game = p.targets_game;
        receptions_game = p.receptions_game;
        receivingYards_game = p.receivingYards_game;
        fumbles_game = p.fumbles_game;
        rushingTouchdowns_game = p.rushingTouchdowns_game;
        receivingTouchdowns_game = p.receivingTouchdowns_game;
        return *this;
    }
    
    runningback (ifstream& is)
    {
        stringstream out;
        string temp;
        getline(is, position);
        getline(is, name);
        getline(is, temp);
        out << temp;
        out >> games >> rushes >> rushingYards >> targets >> receptions >> receivingYards >> fumbles;
        stringstream convert;
        convert << " " <<  setprecision(3) << (rushingYards/rushes) << "         " << setprecision(4) << (rushingYards/games) << "       " << setprecision(3) << (receivingYards/receptions) << "      " << setprecision(3) << (receivingYards/games) << "      " << setprecision(3) << ((receptions/targets)*100) << "%";
        output_season = convert.str();
        output_game = "";
        rushes_game = rushingYards_game = targets_game = receptions_game = receivingYards_game = fumbles_game = rushingTouchdowns_game = receivingTouchdowns_game = 0;
    }
    
    runningback ()
    {
        position = "RB";
        name = "";
        output_season = "";
        output_game = "";
        games = rushes = rushingYards = targets = receptions = receivingYards = fumbles = rushes_game = rushingYards_game = targets_game = receptions_game = receivingYards_game = fumbles_game = rushingTouchdowns_game = receivingTouchdowns_game = 0;
    }
    
    float ypr() {return rushingYards/rushes;}
    float tpg() {return targets/games;}
    float catchrate() {return receptions/targets;}
    float ypcat() {return receivingYards/receptions;}
    float fumbrate() {return fumbles/(rushes+receptions);}
    
    void updateOutput()
    {
        stringstream convertR;
        convertR << rushes_game << "      " << rushingYards_game << "       " << rushingTouchdowns_game << "      " << receptions_game << "      " << receivingYards_game << "      " << receivingTouchdowns_game;
        output_game = convertR.str();
    }
};

class wideReceiver : public player
{
public:
    float targets;
    float receptions;
    float receivingYards;
    float fumbles;
    float targets_game;
    float receptions_game;
    float receivingYards_game;
    float fumbles_game;
    float receivingTouchdowns_game;
    
    wideReceiver & operator = (const wideReceiver & p)
    {
        name = p.name;
        position = p.position;
        output_season = p.output_season;
        output_game = p.output_game;
        games = p.games;
        targets = p.targets;
        receptions = p.receptions;
        receivingYards = p.receivingYards;
        fumbles = p.fumbles;
        targets_game = p.targets_game;
        receptions_game = p.receptions_game;
        receivingYards_game = p.receivingYards_game;
        fumbles_game = p.fumbles_game;
        receivingTouchdowns_game = p.receivingTouchdowns_game;
        return *this;
    }
    
    wideReceiver (ifstream& is)
    {
        stringstream out;
        string temp;
        getline(is, position);
        getline(is, name);
        getline(is, temp);
        out << temp;
        out >> games >> targets >> receptions >> receivingYards >> fumbles;
        stringstream convert;
        convert << " " << setprecision(3) << (receivingYards/receptions) << "           " << setprecision(4) << (receivingYards/games) << "             " << setprecision(3) << ((receptions/targets)*100) << "%";
        output_season = convert.str();
        output_game = "";
        targets_game = receptions_game = receivingYards_game = fumbles_game = receivingTouchdowns_game = 0;
    }
    
    wideReceiver ()
    {
        position = "WR";
        name = "";
        output_season = "";
        output_game = "";
        games = targets = receptions = receivingYards = fumbles = targets_game = receptions_game = receivingYards_game = fumbles_game = receivingTouchdowns_game = 0;
    }
    
    float tpg() {return targets/games;}
    float catchrate() {return receptions/targets;}
    float ypcat() {return receivingYards/receptions;}
    float fumbrate() {return fumbles/receptions;}
    
    void updateOutput()
    {
        stringstream convertW;
        convertW << receptions_game << "       " << receivingYards_game << "       " << receivingTouchdowns_game;
        output_game = convertW.str();
    }
};

class tightEnd : public wideReceiver
{
public:
    tightEnd & operator = (const tightEnd & p)
    {
        name = p.name;
        position = p.position;
        output_season = p.output_season;
        output_game = p.output_game;
        games = p.games;
        targets = p.targets;
        receptions = p.receptions;
        receivingYards = p.receivingYards;
        fumbles = p.fumbles;
        targets_game = p.targets_game;
        receptions_game = p.receptions_game;
        receivingYards_game = p.receivingYards_game;
        fumbles_game = p.fumbles_game;
        receivingTouchdowns_game = p.receivingTouchdowns_game;
        return *this;
    }
    
    tightEnd (ifstream& is)
    {
        stringstream out;
        string temp;
        getline(is, position);
        getline(is, name);
        getline(is, temp);
        out << temp;
        out >> games >> targets >> receptions >> receivingYards >> fumbles;
        stringstream convert;
        convert << " " << setprecision(3) << (receivingYards/receptions) << "           " << setprecision(4) << (receivingYards/games) << "             " << setprecision(3) << ((receptions/targets)*100) << "%";
        output_season = convert.str();
        output_game = "";
        targets_game = receptions_game = receivingYards_game = fumbles_game = receivingTouchdowns_game = 0;
    }
    
    tightEnd ()
    {
        position = "TE";
        name = "";
        output_season = "";
        output_game = "";
        games = targets = receptions = receivingYards = fumbles = targets_game = receptions_game = receivingYards_game = fumbles_game = receivingTouchdowns_game = 0;
    }
};

class kicker : public player
{
public:
    float fieldGoals20YardsAttempted;
    float fieldGoals20YardsMade;
    float fieldGoals30YardsAttempted;
    float fieldGoals30YardsMade;
    float fieldGoals40YardsAttempted;
    float fieldGoals40YardsMade;
    float fieldGoals50YardsAttempted;
    float fieldGoals50YardsMade;
    float fieldGoals20YardsAttempted_game;
    float fieldGoals20YardsMade_game;
    float fieldGoals30YardsAttempted_game;
    float fieldGoals30YardsMade_game;
    float fieldGoals40YardsAttempted_game;
    float fieldGoals40YardsMade_game;
    float fieldGoals50YardsAttempted_game;
    float fieldGoals50YardsMade_game;
    float extraPointsMade;
    float extraPointsMade_game;
    float extraPointsAttempted;
    float extraPointsAttempted_game;
    
    kicker & operator = (const kicker & p)
    {
        name = p.name;
        position = p.position;
        output_season = p.output_season;
        output_game = p.output_game;
        games = p.games;
        fieldGoals20YardsAttempted = p.fieldGoals20YardsAttempted;
        fieldGoals20YardsMade = p.fieldGoals20YardsMade;
        fieldGoals30YardsAttempted = p.fieldGoals30YardsAttempted;
        fieldGoals30YardsMade = p.fieldGoals30YardsMade;
        fieldGoals40YardsAttempted = p.fieldGoals40YardsAttempted;
        fieldGoals40YardsMade = p.fieldGoals40YardsMade;
        fieldGoals50YardsAttempted = p.fieldGoals50YardsAttempted;
        fieldGoals50YardsMade = p.fieldGoals50YardsMade;
        fieldGoals20YardsAttempted_game = p.fieldGoals20YardsAttempted_game;
        fieldGoals20YardsMade_game = p.fieldGoals20YardsMade_game;
        fieldGoals30YardsAttempted_game = p.fieldGoals30YardsAttempted_game;
        fieldGoals30YardsMade_game = p.fieldGoals30YardsMade_game;
        fieldGoals40YardsAttempted_game = p.fieldGoals40YardsAttempted_game;
        fieldGoals40YardsMade_game = p.fieldGoals40YardsMade_game;
        fieldGoals50YardsAttempted_game = p.fieldGoals50YardsAttempted_game;
        fieldGoals50YardsMade_game = p.fieldGoals50YardsMade_game;
        extraPointsMade = p.extraPointsMade;
        extraPointsMade_game = p.extraPointsMade_game;
        extraPointsAttempted = p.extraPointsAttempted;
        extraPointsAttempted_game = p.extraPointsAttempted_game;
        return *this;
    }
    
    kicker (ifstream& is)
    {
        stringstream out;
        string temp;
        getline(is, position);
        getline(is, name);
        getline(is, temp);
        out << temp;
        out >> games >> fieldGoals20YardsMade >> fieldGoals20YardsAttempted >> fieldGoals30YardsMade >> fieldGoals30YardsAttempted >> fieldGoals40YardsMade >> fieldGoals40YardsAttempted >> fieldGoals50YardsMade >> fieldGoals50YardsAttempted;
        stringstream convert;
        convert << " " << setprecision(2) << (((fieldGoals20YardsMade+fieldGoals30YardsMade+fieldGoals40YardsMade+fieldGoals50YardsMade)/(fieldGoals20YardsAttempted+fieldGoals30YardsAttempted+fieldGoals40YardsAttempted+fieldGoals50YardsAttempted))*100) << "%";
        output_season = convert.str();
        output_game = "";
        fieldGoals20YardsAttempted_game = fieldGoals20YardsMade_game = fieldGoals30YardsAttempted_game = fieldGoals30YardsMade_game = fieldGoals40YardsAttempted_game = fieldGoals40YardsMade_game = fieldGoals50YardsAttempted_game = fieldGoals50YardsMade_game = extraPointsMade_game = extraPointsAttempted_game = 0;
    }
    
    kicker ()
    {
        position = "K";
        name = "";
        output_season = "";
        output_game = "";
        games = fieldGoals20YardsMade = fieldGoals20YardsAttempted = fieldGoals30YardsAttempted = fieldGoals30YardsMade = fieldGoals40YardsMade = fieldGoals40YardsAttempted = fieldGoals50YardsMade = fieldGoals50YardsAttempted = fieldGoals20YardsAttempted_game = fieldGoals20YardsMade_game = fieldGoals30YardsAttempted_game = fieldGoals30YardsMade_game = fieldGoals40YardsAttempted_game = fieldGoals40YardsMade_game = fieldGoals50YardsAttempted_game = fieldGoals50YardsMade_game = extraPointsMade_game = extraPointsAttempted_game = 0;
    }
    
    float fg20() {return fieldGoals20YardsMade/fieldGoals20YardsAttempted;}
    float fg30() {return fieldGoals30YardsMade/fieldGoals30YardsAttempted;}
    float fg40() {return fieldGoals40YardsMade/fieldGoals40YardsAttempted;}
    float fg50() {return fieldGoals50YardsMade/fieldGoals50YardsAttempted;}
    float xp() {return extraPointsMade/extraPointsAttempted;}
    
    float totalFieldGoals() {
        return (fieldGoals20YardsMade+fieldGoals30YardsMade+fieldGoals40YardsMade+fieldGoals50YardsMade)/(fieldGoals20YardsAttempted+fieldGoals30YardsAttempted+fieldGoals40YardsAttempted+fieldGoals50YardsAttempted);
    }
    
    void updateOutput()
    {
        stringstream convertK;
        convertK << fieldGoals20YardsMade_game+fieldGoals30YardsMade_game+fieldGoals40YardsMade_game+fieldGoals50YardsMade_game << "      " << fieldGoals20YardsAttempted_game+fieldGoals30YardsAttempted_game+fieldGoals40YardsAttempted_game+fieldGoals50YardsAttempted_game << "      " << extraPointsMade_game << "      " << extraPointsAttempted_game;
        output_game = convertK.str();
    }
};

#endif
