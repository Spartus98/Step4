/**
 * \file TileGarden.h
 *
 * \author Zach Fincher
 *
 * Class that implements a tile that is a garden
 */

#pragma once
#include "Tile.h"


/**
 * Creates a tile of type garden and updates when time meets cerrtain specs
 */
class CTileGarden :
	public CTile
{
public:
    void Update(double elapsed);

    void Prune();

    CTileGarden(CCity* city);

    ///  Default constructor (disabled)
    CTileGarden() = delete;

    ///  Copy constructor (disabled)
    CTileGarden(const CTileGarden&) = delete;

    ~CTileGarden();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);


    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitGarden(this); }

private:
    double mSincePruning = 0;   ///< keep time since pruned
};
