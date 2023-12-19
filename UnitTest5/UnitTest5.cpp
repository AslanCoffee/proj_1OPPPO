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
			list.removeIfMatches("Density < 5");
			Assert::AreEqual(list.getSize(), 0);
		}
		TEST_METHOD(Test3)
		{
			FigureList list;
			list.push_back(new Cuboid(5.3, "name1", 1, 3, 2));
			list.push_back(new Sphere(2.3, "name2", 5));
			list.push_back(new Cylinder(4.5, "name3", 2.3, 3.3, 4.7, 5.2));
			Assert::AreEqual(list.getSize(), 3);
			list.removeIfMatches("Owner = name2");
			Assert::AreEqual(list.getSize(), 2);
		}
	};
}
