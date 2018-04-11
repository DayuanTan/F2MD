/*******************************************************************************
* @author  Joseph Kamel
* @date    11/04/2014
* @version 1.0
*
* SCA (Secure Cooperative Autonomous systems)
* Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
* All rights reserved.
*******************************************************************************/

#include "NodeHistory.h"

NodeHistory::NodeHistory() {
    nodeId = 0;
    bsmNum = 0;
}

NodeHistory::NodeHistory(int id) {
    nodeId = id;
    bsmNum = 0;
}

NodeHistory::NodeHistory(int id, BasicSafetyMessage bsm) {
    nodeId = id;
    bsmNum = 0;
    addBSM(bsm);
}

BasicSafetyMessage NodeHistory::getLatestBSM() {
    return bsmList[0];
}

BasicSafetyMessage NodeHistory::getSecondLatestBSM() {
    return bsmList[1];
}

BasicSafetyMessage NodeHistory::getBSM(int index) {
    return bsmList[index];
}


double NodeHistory::getArrivalTime(int index) {
    return bsmList[index].getArrivalTime().dbl();
}

Coord NodeHistory::getSenderPos(int index) {
    return bsmList[index].getSenderPos();
}

Coord NodeHistory::getSenderSize(int index) {
    return Coord(bsmList[index].getSenderWidth(),
            bsmList[index].getSenderLength());
}

double NodeHistory::getSenderSpeed(int index) {
    return sqrt(
            pow(bsmList[index].getSenderSpeed().x, 2.0)
                    + pow(bsmList[index].getSenderSpeed().y, 2.0)
                    + pow(bsmList[index].getSenderSpeed().z, 2.0));
}

Coord NodeHistory::getSenderHeading(int index) {
    return bsmList[index].getSenderHeading();
}

double NodeHistory::getDeltaTime(int index1, int index2) {
    return fabs(
            bsmList[index1].getArrivalTime().dbl()
                    - bsmList[index2].getArrivalTime().dbl());
}

BasicSafetyMessage* NodeHistory::getBSMList() {
    return bsmList;
}

int NodeHistory::getBSMNum() {
    return bsmNum;
}

void NodeHistory::addBSM(BasicSafetyMessage bsm) {
    if (bsmNum < MAXBSMLENGTH) {
        bsmNum++;
    }
    for (int var = bsmNum - 1; var > 0; --var) {
        bsmList[var] = bsmList[var - 1];
    }
    bsmList[0] = bsm;
}