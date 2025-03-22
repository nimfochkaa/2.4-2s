#include "pch.h"
#include "CppUnitTest.h"
#include "../2.4/Matrix.h"
#include "../2.4/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int data[3][3] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};

			Matrix m(data);
			Assert::AreEqual(1, m[0][0]);
			Assert::AreEqual(5, m[1][1]);
			Assert::AreEqual(9, m[2][2]);
		}
	};
}
