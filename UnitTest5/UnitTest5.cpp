#include "CppUnitTest.h"
#include "..//proj_1OPO/FigureList.h"
#include "..//proj_1OPO/Cuboid.h"
#include "..//proj_1OPO/Sphere.h"
#include "..//proj_1OPO/Cylinder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
	TEST_CLASS(UnitTest5)
	{
	public:
		
		TEST_METHOD(ADD)
		{
			FigureList list;
			list.push_back(new Cuboid(4.5, "name", 1, 2, 3));
			Assert::AreEqual(list.getSize(), 1);
		}
		TEST_METHOD(REMOVE)
		{
			FigureList list;
			list.push_back(new Cuboid(4.5, "name", 1, 2, 3));
			Assert::AreEqual(list.getSize(), 1);
			list.removeIfMatches("Density < 4.6");
			Assert::AreEqual(list.getSize(), 0);
		}
		TEST_METHOD(Test3)
		{
			FigureList list;
			list.push_back(new Cuboid(5.1, "name1", 1, 3, 2));
			list.push_back(new Sphere(8, "name2", 5));
			list.push_back(new Cylinder(6, "name3", 7.3, 3.3, 6.7, 5.2));
			Assert::AreEqual(list.getSize(), 3);
			list.removeIfMatches("Density < 5.2"); // del name1
			Assert::AreEqual(list.getSize(), 2);
			list.removeIfMatches("Owner = name2"); // del name2
			Assert::AreEqual(list.getSize(), 1);
			list.push_back(new Cylinder(4.1, "name4", 2.7, 3.5, 4.7, 7.2));
			list.push_back(new Cylinder(4.5, "name5", 2.9, 3.2, 2.7, 5.9));
			Assert::AreEqual(list.getSize(), 3);
			list.removeIfMatches("BaseX < 3.8"); // del name4, name5
			Assert::AreEqual(list.getSize(), 1);
			list.push_back(new Cylinder(4.5, "name6", 2.9, 3.2, 2.7, 5.9));
			Assert::AreEqual(list.getSize(), 2);
			list.removeIfMatches("Owner = name6"); // del name6
			Assert::AreEqual(list.getSize(), 1);
			list.push_back(new Cuboid(5, "name1", 1, 3, 2));
			Assert::AreEqual(list.getSize(), 2);
		}
	};
}
