#include "pch.h"
#include "CppUnitTest.h"
#include "../1.4/RealMatrix.h"
#include "../1.4/RealMatrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
	TEST_CLASS(UnitTest14)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			RealMatrix matrix;
			matrix.Init(3, 4);
			Assert::AreEqual(3, matrix.getRows());
		}
	};
}