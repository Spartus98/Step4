 /**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

    /**
    * Class that maintains a iter of Point objects in a list of lists.
    */
    class Iter
    {
    public:
        /** Constructor
         * \param pointHistory The pointHistory we are iterating over
         * \param list The current list we are iterating over
         * \param pos The current pos we are iterating over
         */
        Iter(CPointHistory *pointHistory,int list, int pos) : mPointHistory(pointHistory ),mList(list) ,mPos(pos) {}

        /** Test for end of the iterator
         *\param other Item we are comparing too
         *\returns True if we this position equals not equal to the other position
         *
         */
        bool operator!=(const Iter& other) const
        {
            
         return mPos != other.mPos || mList != other.mList;
            
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const { return mPointHistory->mPotatoLists[mList][mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        { 
            mList++;
            if (mList % NumLists == 0) 
            {
                mList = 0;
                mPos++;
            }
            
            return *this; 
        }


    private:
        CPointHistory * mPointHistory;   ///< mouseHistory we are iterating over
        int mList;      ///< Current list we are looking at
        int mPos;       ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mCurrentList, mPotatoLists[mCurrentList].size()); }
    // (currentList+1) % numlist

protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

