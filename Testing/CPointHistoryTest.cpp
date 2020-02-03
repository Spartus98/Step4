#include "pch.h"
#include <vector>
#include "CppUnitTest.h"
#include "PointHistory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

namespace Testing
{
    /** Testing stub class, creates a vector from
    * the list. This is done so we can test this
    * before we create the iterator. DO NOT USE
    * THIS CODE to solve the iterator task */
    class CPointHistoryStub : public CPointHistory
    {
    public:
        std::vector<Point> GetPoints()
        {
            std::vector<Point> list;

            // The list we are reading from
            int listNum = 0;

            // The index into the lists
            size_t index = 0;
            while (index < mPotatoLists[listNum].size())
            {
                list.push_back(mPotatoLists[listNum][index]);
                listNum++;
                if (listNum >= NumLists)
                {
                    listNum = 0;
                    index++;
                }
            }

            return list;
        }
    };

    TEST_CLASS(CPointHistoryTest)
    {
    public:

        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
            g_dir[999] = L'\0';
        }

        TEST_METHOD(TestCPointHistoryAdd)
        {

            CPointHistoryStub history;

            // Vector for test data
            vector<Point> testData;

            // Ensure initially empty
            TestEqual(testData, history.GetPoints());

            // Create some simple test data
            for (int i = 0; i < 3; i++)
            {
                Point p(187 - i, 23 + i);
                testData.push_back(p);
                history.Add(p);
            }

            // And test
            auto points = history.GetPoints();
            TestEqual(testData, history.GetPoints());

            // Create some simple test data
            for (int i = 0; i < 117; i++)
            {
                Point p(i, 87 - i);
                testData.push_back(p);
                history.Add(p);
            }

            // And test
            TestEqual(testData, history.GetPoints());

        }

        void TestEqual(vector<Point> a, vector<Point> b)
        {
            Assert::AreEqual(a.size(), b.size());
            for (size_t i = 0; i < a.size(); i++)
            {
                Assert::AreEqual(a[i].X, b[i].X);
                Assert::AreEqual(a[i].Y, b[i].Y);
            }
        }

    };


}