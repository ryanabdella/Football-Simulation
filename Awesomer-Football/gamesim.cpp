//using namespace std;
#include "gamesim.h"

static boost::mt19937 eng_run((const unsigned int) time(NULL));
static boost::gamma_distribution<> gamma_run(2.0);
static boost::variate_generator<boost::mt19937&,boost::gamma_distribution<> > gen_run(eng_run, gamma_run);

static boost::mt19937 eng_pass((const unsigned int) time(NULL));
static boost::gamma_distribution<> gamma_pass(2.0);
static boost::variate_generator<boost::mt19937&,boost::gamma_distribution<> > gen_pass(eng_pass, gamma_pass);

gamesim::gamesim (team * t1, team * t2)
{
  fumble = interception = sack = complete = fg = touchback = xp = td = false;
  event1 = event2 = event3 = event4 = event5 = event = "";
  playtype = koffplay;
  yardage = 0;
  home = t1;
  away = t2;
  rbp = 0;
  wrp = 0;
  tep = 0;
  pptr = 0;
  gametime = 900;
  qtr = 1;
  down = 1;
  tofirst = 10;
  togo = 100;
}

gamesim::gamesim()
{
  fumble = interception = sack = complete = fg = touchback = xp = td = false;
  event1 = event2 = event3 = event4 = event5 = event = "";
  playtype = koffplay;
  yardage = 0;
  rbp = 0;
  wrp = 0;
  tep = 0;
  pptr = 0;
  gametime = 900.;
  qtr = 1;
  down = 1;
  tofirst = 10;
  togo = 100;
}

void gamesim::start()
{
  float flip = drand48();
  if (flip < 0.5) {
    poss = home;
    initposs = home;
    notposs = away;
    position = 0;
    event = "The home team has won the coin toss and elected to receive.";
  } else {
    poss = away;
    initposs = away;
    notposs = home;
    position = 100;
    event = "The away team has won the coin toss and elected to receive.";
  }
  playtype = koffplay;
  simdown();
}

void gamesim::updateOutput()
{
  stringstream convert, convert2;
  string temp;
  if (playtype == koffplay) {
    if (yardage == 0) event = "The kickoff resulted in a touchback.";
    if (yardage == 100) event = "The kickoff was returned for a touchdown!";
    else {
      convert << yardage;
      temp = convert.str();
      event = "The kickoff was returned for " + temp + " yards.";
    }
  } else if (playtype == puntplay) {
    if (touchback == true) event = "The punt resulted in a touchback.";
    else if (togo <= 0) {
      convert << puntlength;
      temp = convert.str();
      event = "The punt of " + temp + " yards was returned for a touchdown!";
    }
    else {
      convert << puntlength;
      temp = convert.str();
      event = "The punt of " + temp + " yards was returned for ";
      convert2 << returnlength;
      temp = convert2.str();
      event += temp + " yards.";
    }
  } else if (playtype == xpplay) {
    if (xp == true) event = notposs->kickerp->name + " made the extra point.";
    else event = notposs->kickerp->name + " missed the extra point.";
  } else if (playtype == fgoalplay) {
    convert << (togo+17);
    temp = convert.str();
    if (fg == true) event += " kicked a " + temp + " yard field goal.";
    else event += " mised a " + temp + " yard field goal.";
  } else if (playtype == passplay) {
    if (interception == true) event += " threw an interception. TURNOVER.";
    else if (complete == false && sack == false) event += " threw an incomplete pass.";
    else if (sack == true && fumble == false) {
      convert << yardage;
      temp = convert.str();
      event += " was sacked for a loss of " + temp + " yards.";
    }
    else if (sack == true && fumble == true) {
      convert << yardage;
      temp = convert.str();
      event += " was sacked for a loss of " +temp + " yards and fumbled. TURNOVER.";
    }
    else if (complete == true && fumble == false) {
      convert << yardage;
      temp = convert.str();
      event += " for " + temp + " yards.";
    } else if (complete == true && fumble == true) {
      convert << yardage;
      temp = convert.str();
      event += " for " + temp + " yards and he fumbled. TURNOVER.";
    }
  } else if (playtype == rushplay) {
    if (fumble == true) {
      convert << yardage;
      temp = convert.str();
      event += " rushed for a gain of " + temp + " yards and fumbled. TURNOVER.";
    }
    else {
      convert << yardage;
      temp = convert.str();
      event += " rushed for " + temp + " yards.";
    }
  }
  if (td == true) event += " TOUCHDOWN.";
  event5 = event4;
  event4 = event3;
  event3 = event2;
  event2 = event1;
  event1 = event;
  cout << event << endl;
}

void gamesim::setTeams(team * t1, team * t2)
{
  home = t1;
  away = t2;
}

void gamesim::updateStats()
{
	if (playtype == passplay) {
		if (complete == true) {
			poss->quarterbackp->passingYards_game += yardage;
			poss->quarterbackp->completions_game += 1;
			poss->quarterbackp->attempts_game += 1;
			if (pptr->position == "RB") {
				rbp = (runningback *) pptr;
				rbp->receivingYards_game += yardage;
				rbp->receptions_game += 1;
				rbp->targets_game += 1;
			}
			else if (pptr->position == "WR") {
				wrp = (wideReceiver *) pptr;
				wrp->receivingYards_game += yardage;
				wrp->receptions_game += 1;
				wrp->targets_game += 1;
			}
			else {
				tep = (tightEnd *) pptr;
				tep->receivingYards_game += yardage;
				tep->receptions_game += 1;
				tep->targets_game += 1;
			}
			if (td == true) {
				poss->quarterbackp->passingTouchdowns_game += 1;
				if (pptr->position == "RB") {rbp->receivingTouchdowns_game += 1;}
				else if (pptr->position == "WR") {wrp->receivingTouchdowns_game += 1;}
				else {tep->receivingTouchdowns_game += 1;}
			}
		} else {
			if (sack == false) {
				poss->quarterbackp->attempts_game += 1;
				if (pptr->position == "RB") {rbp->targets_game += 1;}
				else if (pptr->position == "WR") {wrp->targets_game += 1;}
				else {tep->targets_game += 1;}
			}
			if (interception == true) {
				poss->quarterbackp->interceptions_game += 1;
				if (pptr->position == "RB") {rbp->targets_game += 1;}
				else if (pptr->position == "WR") {wrp->targets_game += 1;}
				else {tep->targets_game += 1;}
			}
		}
	} else if (playtype == rushplay) {
		rbp->rushingYards_game += yardage;
		if (td == true) rbp->rushingTouchdowns_game += 1;
		rbp->rushes_game += 1;
	} else if (playtype == fgoalplay) {
		if (fg == true) {
			if (togo < (30-17)) {
				poss->kickerp->fieldGoals20YardsMade_game += 1;
				poss->kickerp->fieldGoals20YardsAttempted_game += 1;
			} else if (togo < (40-17) && togo >= (30-17)) {
				poss->kickerp->fieldGoals30YardsMade_game += 1;
				poss->kickerp->fieldGoals30YardsAttempted_game += 1;
			} else if (togo < (50-17) && togo >= (40-17)) {
				poss->kickerp->fieldGoals40YardsMade_game += 1;
				poss->kickerp->fieldGoals40YardsAttempted_game += 1;
			} else if (togo >= (50-17)) {
				poss->kickerp->fieldGoals50YardsMade_game += 1;
				poss->kickerp->fieldGoals50YardsAttempted_game += 1;
			}
		} else {
			if (togo < (30-17)) {
				poss->kickerp->fieldGoals20YardsAttempted_game += 1;
			} else if (togo < (40-17) && togo >= (30-17)) {
				poss->kickerp->fieldGoals30YardsAttempted_game += 1;
			} else if (togo < (50-17) && togo >= (40-17)) {
				poss->kickerp->fieldGoals40YardsAttempted_game += 1;
			} else if (togo >= (50-17)) {
				poss->kickerp->fieldGoals50YardsAttempted_game += 1;
			}
		}
	} else if (playtype == xpplay) {
		if (xp == true) {
			poss->kickerp->extraPointsMade_game += 1;
			poss->kickerp->extraPointsAttempted_game += 1;
		} else poss->kickerp->extraPointsAttempted_game += 1;
	}
	poss->quarterbackp->updateOutput();
	poss->runningbackp1->updateOutput();
	poss->runningbackp2->updateOutput();
	poss->wideReceiverp1->updateOutput();
	poss->wideReceiverp2->updateOutput();
	poss->wideReceiverp3->updateOutput();
	poss->tightEndp1->updateOutput();
	poss->tightEndp2->updateOutput();
	poss->kickerp->updateOutput();
}

void gamesim::simdown()
{
	if (playtype == passplay || playtype == rushplay) {
		if (playtype == passplay) passPlay();
		else runPlay();
		updateYardage();
		if (interception == false && fumble == false) {
			if (togo >= 100) {
				gameTime();
				updateOutput();
				event += " SAFETY.";
				notposs->score += 2;
				updateStats();
				changePoss();
				playtype = koffplay;
			} else if (togo == 0) {
				td = true;
				poss->score += 6;
				updateStats();
				gameTime();
				updateOutput();
				if (poss == home) {
					position = 98;
					togo = 2;
					tofirst = 2;
					down = 1;
				} else {
					position = 2;
					togo = 2;
					tofirst = 2;
					down = 1;
				}
				playtype = xpplay;
			} else if (tofirst > 0) {
				updateStats();
				gameTime();
				updateOutput();
				if (down == 1 || down == 2 || down == 3) {
					++down;
					playtype = none;
				}
				else {
					changePoss();
					down = 1;
					tofirst = 10;
					playtype = none;
				}
			} else {
				updateStats();
				gameTime();
				updateOutput();
				down = 1;
				tofirst = 10;
				if (togo < 10) {
					tofirst = togo;
				}
				playtype = none;
			}
		} else {
			updateStats();
			gameTime();
			updateOutput();
			changePoss();
			down = 1;
			tofirst = 10;
			playtype = none;
		}
	} else if (playtype == fgoalplay) {
		fieldgoal();
		updateStats();
		if (fg == true) {
			poss->score += 3;
			if (poss == home) {
				position = 35;
				tofirst = 0;
			} else {
				position = 65;
				tofirst = 0;
			}
			gameTime();
			updateOutput();
			changePoss();
			fg = false;
			playtype = koffplay;
		}
		else {
			yardage = 0;
			updateYardage();
			changePoss();
			down = 1;
			tofirst = 10;
			gameTime();
			updateOutput();
			playtype = none;
		}
	} else if (playtype == koffplay) {
		kickoff();
		updateYardage();
		down = 1;
		if (togo > 10) tofirst = 10;
		else tofirst = togo;
		gameTime();
		updateOutput();
		playtype = none;
	} else if (playtype == xpplay) {
		extrapoint();
		td = false;
		updateStats();
		if (poss == home) {
			position = 35;
			tofirst = 0;
		} else {
			position = 65;
			tofirst = 0;
		}
		tofirst = 0;
		changePoss();
		gameTime();
		updateOutput();
		xp = false;
		playtype = koffplay;
	} else if (playtype == puntplay) {
		punt();
		updateYardage();
		changePoss();
		down = 1;
		tofirst = 10;
		gameTime();
		updateOutput();
		playtype = none;
	} else {};
}

void gamesim::updateYardage()
{
	if (poss == home) {
		position += yardage;
		togo = 100 - position;
		tofirst -= yardage;
	} else {
		position -= yardage;
		togo = position;
		tofirst -= yardage;
	}
}

ptype gamesim::cpuPlayType()
{
  float r = drand48();
  if (down == 1 || down == 2 || down == 3) {
    if (r > poss->rate()) playtype = rushplay;
    else playtype = passplay;
  } else {
    if (togo <= 35) playtype = fgoalplay;
    else if (togo < 50 && togo > 35 && tofirst < 2) {
      if (r > poss->rate()) playtype = rushplay;
      else playtype = passplay;
    } else playtype = puntplay;
  }
  return playtype;
}

void gamesim::gameTime()
{
  int runoff = 30;
  int minimum = 3;
  int kickmin = 4;
  int diff = yardage * 0.15;
  float out = drand48();
  if (playtype == rushplay) {
      if (out < 0.25) gametime -= diff + minimum;
      else gametime -= diff + minimum + runoff;
  } else if (playtype == passplay && !complete) {
    gametime -= minimum;
  } else if (playtype == passplay && complete) {
    if (out < 0.25) gametime -= diff + minimum;
    else gametime -= diff + minimum + runoff;
  } else if (playtype == koffplay) {
    gametime -= diff + kickmin;
  } else if (playtype == puntplay) {
    gametime -= diff + kickmin;
  } else if (playtype == fgoalplay) {
    gametime -= kickmin;
  }
  if (gametime <= 0) {
    if (qtr == 1 || qtr == 3) {
      gametime = 900;
      qtr += 1;
    } else if (qtr == 2) {
      gametime = 900;
      qtr += 1;
      if (initposs == home) {
	poss = away;
	notposs = home;
	position = 100;
	down = 1;
	tofirst = 10;
      } else {
	poss = home;
	notposs = away;
	position = 0;
	down = 1;
	tofirst = 10;
      }
      playtype = koffplay;
      simdown();
    } else if (qtr == 4) {
    }
  }
}

void gamesim::changePoss()
{
  if (poss == home) {
    poss = away;
    notposs = home;
    togo = 100 - position;
  } else {
    poss = home;
    notposs = away;
    togo = position;
  }
}

void gamesim::kickoff()
{
  if (poss == home) position = 0;
  else position = 100;
  touchback = false;
  float factor1 = drand48();
  float factor2 = drand48();
  if (factor1 <= 0.12) {
    touchback = true;
    yardage = 0;
    if (poss == home) position = 20;
    else position = 80;
  } else if (factor1 >= 0.99) {
    yardage = 100;
  } else if (factor1 >= 0.90) {
    yardage = 100 * factor2;
  } else {
    float high = poss->defense.ypkret() * 2;
    float low = poss->defense.ypkret() -10;
    float diff = high - low;
    yardage = low - 5 + diff * factor2;
  }
}

void gamesim::runPlay()
{
  fumble = interception = false;
  float r = drand48();
  float factor = drand48();
  float factor2 = drand48();
  float factor3 = drand48();
  if (r < 0.75) rbp = poss->runningbackp1;
  else rbp = poss->runningbackp2;
  event = rbp->name;
  if (factor3 < getfumbrate(rbp)) fumble = true;
  else fumble = false;
  if (factor >= 0.98) yardage = togo;
  else if (factor < 0.1) yardage = factor2 * -5;
  else if (factor > 0.94 && factor < 0.98) yardage = togo * factor2;
  else {
    yardage = (getypr(rbp)/2)*gen_run();
  }
  if (yardage >= togo) yardage = togo;
}

void gamesim::passPlay()
{
  interception = sack = fumble = complete = false;
  float r = drand48();
  float factor = drand48();
  float factor2 = drand48();
  float completionpercent;
  pptr = poss->detplayer();
	if (pptr->position == "RB") {rbp = (runningback *) pptr;}
	else if (pptr->position == "WR") {wrp = (wideReceiver *) pptr;}
	else {tep = (tightEnd *) pptr;}
  if (pptr->position == "RB") {
	  completionpercent = getcomppercent(rbp);
  } else if (pptr->position == "WR") {
	  completionpercent = getcomppercent(wrp);
  } else {
	  completionpercent = getcomppercent(tep);
  }
  if (factor <= getsackrate()) {
    yardage = -10.0 * r;
    sack = true;
    event = poss->quarterbackp->name;
    if (factor2 <= getfumbrate(poss->quarterbackp)) fumble = true;
  } else if (factor <= (getinterrate() + getsackrate()) && factor > getsackrate()) {
    event = poss->quarterbackp->name;
    if (pptr->position == "RB") {
        yardage = getypcatch(rbp) * 2 * r;
    } else if (pptr->position == "WR") {
        yardage = getypcatch(wrp) * 2 * r;
    } else {
        yardage = getypcatch(tep) * 2 * r;
    }
    interception = true;
  } else if (factor >= (1 - completionpercent)) {
    event = poss->quarterbackp->name + " passed to " + pptr->name;
    complete = true;
    if (factor >= 0.96) yardage = togo;
    else {
		if (pptr->position == "RB") {
			yardage = (getypcatch(rbp) / 2) * gen_pass();
		} else if (pptr->position == "WR") {
			yardage = (getypcatch(wrp) / 2) * gen_pass();
		} else {
			yardage = (getypcatch(tep) / 2) * gen_pass();
		}
    }
  } else {
    complete = false;
    yardage = 0;
    event = poss->quarterbackp->name;
  }
  if (yardage >= togo) yardage = togo;
}

void gamesim::punt()
{
  touchback = false;
  float puntr = drand48();
  float returnr = drand48();
  float r = drand48();
  float high = (poss->defense.ypp()) + 15;
  float low = (poss->defense.ypp()) - 10;
  float diff = high - low;
  puntlength = low + puntr * diff;
  int newtogo = 100 - togo + puntlength;
  if (newtogo >= 100) {
    returnlength = 0;
    touchback = true;
    yardage = togo - 20;
  } else {
    if (returnr >= 0.99) returnlength = newtogo;
    else if (returnr >= 0.92 && returnr < 0.99) returnlength = newtogo * r;
    else if (returnr < 0.92) returnlength = notposs->defense.yppret() * 2 * r;
    yardage = puntlength - returnlength;
  }
}

void gamesim::fieldgoal()
{
  int distance = togo + 17;
  float r = drand48();
  event = poss->kickerp->name;
  if (distance < 30) {
    if (r <= poss->kickerp->fg20()) fg = true;
    else fg = false;
  } else if (distance < 40 && distance >= 30) {
    if (r <= poss->kickerp->fg30()) fg = true;
    else fg = false;
  } else if (distance < 50 && distance >= 40) {
    if (r <= poss->kickerp->fg40()) fg = true;
    else fg = false;
  } else if (distance < 60 && distance >= 50) {
    if (r <= poss->kickerp->fg50()) fg = true;
    else fg = false;
  } else fg = false;
}

void gamesim::extrapoint()
{
  float r = drand48();
  if (r <= 0.01) xp = false;
  else {
    xp = true;
    poss->score += 1;
  }
}

float gamesim::getcomppercent(wideReceiver * p)
{
  return ((poss->quarterbackp->comppercent() + p->catchrate() + notposs->defense.comppercent())/3);
}

float gamesim::getcomppercent(tightEnd * p)
{
    return ((poss->quarterbackp->comppercent() + p->catchrate() + notposs->defense.comppercent())/3);
}

float gamesim::getcomppercent(runningback * p)
{
    return ((poss->quarterbackp->comppercent() + p->catchrate() + notposs->defense.comppercent())/3);
}

float gamesim::getypcatch(runningback * p)
{
  return ((poss->quarterbackp->ypcomp() + p->ypcat() + notposs->defense.ypcomp())/3);
}

float gamesim::getypcatch(wideReceiver * p)
{
    return ((poss->quarterbackp->ypcomp() + p->ypcat() + notposs->defense.ypcomp())/3);
}

float gamesim::getypcatch(tightEnd * p)
{
    return ((poss->quarterbackp->ypcomp() + p->ypcat() + notposs->defense.ypcomp())/3);
}

float gamesim::getinterrate()
{
  return ((poss->quarterbackp->interrate() + notposs->defense.interrate())/2);
}

float gamesim::getsackrate()
{
  return ((poss->quarterbackp->sackrate() + notposs->defense.sackrate())/2);
}

float gamesim::getypr(runningback * p)
{
  return ((p->ypr() + notposs->defense.ypr())/2);
}

float gamesim::getfumbrate(runningback * p)
{
  return ((p->fumbrate() + notposs->defense.fumbrate())/2);
}

float gamesim::getfumbrate(quarterback * p)
{
    return ((p->fumbrate() + notposs->defense.fumbrate())/2);
}

float gamesim::getfumbrate(wideReceiver * p)
{
    return ((p->fumbrate() + notposs->defense.fumbrate())/2);
}

float gamesim::getfumbrate(tightEnd * p)
{
    return ((p->fumbrate() + notposs->defense.fumbrate())/2);
}
