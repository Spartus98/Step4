/**
* \file BuildingCounter.h
*
* \author Zach Fincher
*
* Class that implements counting the objhects of type building
*/



#pragma once
#include "TileVisitor.h"


/**
 * Implements a building counter that we can see as a pop up 
 */
class CBuildingCounter :
	public CTileVisitor
{
public:

    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(CTileBuilding* building);

private:

    /// Buildings counter
    int mNumBuildings = 0;

    

};

