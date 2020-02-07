/**
 * \file BuildingCounter.cpp
 *
 * \author Zach Fincher
 *
 * Allows us to count all buildings and display to user in pop up
 */

#include "pch.h"
#include "BuildingCounter.h"
/** Visit a CTileBuilding object
* \param building Building we are visiting */
void CBuildingCounter::VisitBuilding(CTileBuilding* building)
{
    mNumBuildings++;
}