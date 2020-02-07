/**
 * \file TileGarden.cpp
 *
 * \author Zach Fincher
 * 
 * Class that implements a Garden tile
 */

#include "pch.h"
#include "TileGarden.h"

using namespace std;
using namespace Gdiplus;

/// Image when the garden is pruned
const wstring PruneImage = L"garden.png ";

/// Base prune time
const double PruneTime = 0;

/// Image when the garden is overgrown state 1
const wstring Overgrown1Image = L"garden1.png ";

/// Time to reach Overgrown1 in seconds
const double Overgrown1Time = 2;

/// Image when the garden is overgrown state 2
const wstring Overgrown2Image = L"garden2.png ";

/// Time to reach Overgrown2 in seconds
const double Overgrown2Time = 4;

/// Image when the garden is overgrown state 3
const wstring Overgrown3Image = L"garden3.png ";

/// Time to reach Overgrown3 in seconds
const double Overgrown3Time = 7;

/// Image when the garden is overgrown state 4
const wstring Overgrown4Image = L"garden4.png";

/// Time to reach Overgrown4 in seconds
const double Overgrown4Time = 10;

/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void CTileGarden::Update(double elapsed)
{
    CTile::Update(elapsed);

    mSincePruning += elapsed;

    if (PruneTime <= mSincePruning && mSincePruning > Overgrown1Time)
    {
        SetImage(PruneImage);
    }
    if(Overgrown1Time <= mSincePruning && mSincePruning > Overgrown2Time)
    {
        SetImage(Overgrown1Image);
    }
    if (Overgrown2Time <= mSincePruning && mSincePruning > Overgrown3Time)
    {
        SetImage(Overgrown2Image);
    }
    if (Overgrown3Time <= mSincePruning && mSincePruning > Overgrown4Time)
    {
        SetImage(Overgrown3Image);
    }
    if (Overgrown4Time <= mSincePruning)
    {
        SetImage(Overgrown4Image);
    }
}


/**
 * Called To Prune a garden tile, will set it back to prunestate and place
 * mSincePruning back to the base case of 0 seconds
 */
void CTileGarden::Prune()
{
    mSincePruning = 0;
    SetImage(PruneImage);
}


/** Constructor
* \param city The city this is a member of
*/
CTileGarden::CTileGarden(CCity* city) : CTile(city)
{
    SetImage(PruneImage);
}

/**
*  Destructor
*/
CTileGarden::~CTileGarden()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileGarden::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"garden");
    itemNode->SetAttribute(L"file", GetFile());

    return itemNode;
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileGarden::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CTile::XmlLoad(node);
    SetImage(node->GetAttributeValue(L"file", L""));
}