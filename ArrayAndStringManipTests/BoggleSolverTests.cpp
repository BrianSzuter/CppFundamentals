#include "stdafx.h"
#include "BoggleSolver.h"
#include "CppUnitTest.h"
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ArrayAndStringManip;
using namespace std;

namespace ArrayAndStringManipTests
{		
	TEST_CLASS(BoggleSolverTests)
	{
	public:
		TEST_METHOD(BoggleSolver_Classic)
		{
			BoggleBoard boggle = {{{'G', 'I', 'Z'},
			                       {'U', 'E', 'K'},
			                       {'Q', 'S', 'E'}}};

			set<string> results = BoggleSolver::FindWords(boggle);

			Assert::AreEqual(2u, results.size());
			Assert::IsTrue(results.find("GEEKS") != end(results));
			Assert::IsTrue(results.find("QUIZ") != end(results));
		}
	};
}