/**
 * \file PruneTilesVisitor.cpp
 *
 * \author Zach Fincher
 *
 * Makes a vistior that can visit the tiles of type garden
 */

#include "pch.h"
#include "PruneTilesVisitor.h"
#include "TileGarden.h"


/**
 * Takes a garden and allows us to visit it 
 * \param garden item that we are visiting
 */
void CPruneTilesVisitor::VisitGarden(CTileGarden* garden)
{
	garden->Prune();
}


