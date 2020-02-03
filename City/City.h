/**
 * \file City.h
 *
 * \author Charles B. Owen
 *
 *  Class that implements a simple city with tiles we can manipulate
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>

#include "XmlNode.h"
#include "Tile.h"

/**
 *  Implements a simple city with tiles we can manipulate
 */
class CCity
{
public:
    CCity();
    virtual ~CCity();

    /// The spacing between grid locations
    static const int GridSpacing = 32;


    void Add(std::shared_ptr<CTile> item);
    std::shared_ptr<CTile> HitTest(int x, int y);
    void MoveToFront(std::shared_ptr<CTile> item);
    void DeleteItem(std::shared_ptr<CTile> item);

    void OnDraw(Gdiplus::Graphics *graphics);

    void Save(const std::wstring &filename);
    void Load(const std::wstring &filename);
    void Clear();

    void Update(double elapsed);
    void SortTiles();

    std::shared_ptr<CTile> GetAdjacent(std::shared_ptr<CTile> tile, int dx, int dy);
    std::shared_ptr<CTile> GetAdjacent(CTile *tile, int dx, int dy);

private:
	void XmlTile(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void BuildAdjacencies();

	/// All of the tiles that make up our city
	std::vector<std::shared_ptr<CTile> > mTiles;

	/// Adjacency lookup support
	std::map<std::pair<int, int>, std::shared_ptr<CTile> > mAdjacency;
};

