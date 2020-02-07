/**
 * \file PruneTilesVisitor.h
 *
 * \author Zach Fincher
 *
 * Class that maintains a visitor of garden objects.
 */

#pragma once
#include "TileVisitor.h"


 /**
 * A garden visitor 
 */
class CPruneTilesVisitor :
	public CTileVisitor
{
public:


	virtual void VisitGarden(CTileGarden* garden) override;
};
