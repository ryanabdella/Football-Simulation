#ifndef _ACCUM_
#define _ACCUM_

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

class accum
{
 public:
  string outputQB;
  string outputRB;
  string outputRE;
  string outputK;
  int completions;
  int attempts;
  int passingYards;
  int passingTouchdowns;
  int interceptions;
  int rushes;
  int rushingYards;
  int rushingTouchdowns;
  int targets;
  int receptions;
  int receivingYards;
  int receivingTouchdowns;
  int fieldGoalsMade;
  int fieldGoalsAttempted;
  int extraPointsMade;
  int extraPointsAttempted;

  accum() {
    completions = attempts = passingYards = passingTouchdowns = interceptions = rushes = rushingYards = rushingTouchdowns = targets = receptions = receivingYards = receivingTouchdowns = fieldGoalsMade = fieldGoalsAttempted = extraPointsMade = extraPointsAttempted = 0;
    stringstream convertQ;
    stringstream convertR;
    stringstream convertW;
    stringstream convertK;
    convertQ << completions << "      " << attempts << "      " << passingYards << "      " << passingTouchdowns << "     " << interceptions;
    outputQB = convertQ.str();
    convertR << rushes << "      " << rushingYards << "       " << rushingTouchdowns << "      " << receptions << "      " << receivingYards << "      " << receivingTouchdowns;
    outputRB = convertR.str();
    convertW << receptions << "       " << receivingYards << "       " << receivingTouchdowns;
    outputRE = convertW.str();
    convertK << fieldGoalsMade << "      " << fieldGoalsAttempted << "      " << extraPointsMade << "      " << extraPointsAttempted;
    outputK = convertK.str();
  }

  void updateOutput()
    {
    stringstream convertQ;
    stringstream convertR;
    stringstream convertW;
    stringstream convertK;
    convertQ << completions << "      " << attempts << "      " << passingYards << "      " << passingTouchdowns << "     " << interceptions;
    outputQB = convertQ.str();
    convertR << rushes << "      " << rushingYards << "       " << rushingTouchdowns << "      " << receptions << "      " << receivingYards << "      " << receivingTouchdowns;
    outputRB = convertR.str();
    convertW << receptions << "       " << receivingYards << "       " << receivingTouchdowns;
    outputRE = convertW.str();
    convertK << fieldGoalsMade << "      " << fieldGoalsAttempted << "      " << extraPointsMade << "      " << extraPointsAttempted;
    outputK = convertK.str();
    }
};

#endif
