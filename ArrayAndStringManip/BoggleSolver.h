#pragma once
#include "ArrayAndStringManipExp.h"
#include <array>
#include <string>
#include <set>

namespace ArrayAndStringManip
{
	static constexpr int bsize = 3;
	typedef std::array<std::array<char, bsize>, bsize> BoggleBoard;
	typedef std::array<std::array<bool, bsize>, bsize> VisitedBoard;

	class STRING_MANIP_DLLEXPORT BoggleSolver
	{
	public:
		static std::set<std::string> FindWords(BoggleBoard& board);

	private:
		static void FindWordsHelper(BoggleBoard& board, VisitedBoard& visited, std::set<std::string>& result, int i, int j, std::string& current);
	};
}
