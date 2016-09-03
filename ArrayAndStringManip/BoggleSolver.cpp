#include "stdafx.h"
#include "BoggleSolver.h"
#include <algorithm>
#include <set>

using std::array;
using std::set;
using std::string;
using std::ostringstream;
using std::find;
using std::begin;
using std::end;

namespace ArrayAndStringManip
{
	const array<string, 4> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

	// Check if the word is in our dictionary.
	bool IsWord(const string& word)
	{
		auto present = find(begin(dictionary), end(dictionary), word);
		return (present != end(dictionary));
	}

	void BoggleSolver::FindWordsHelper(BoggleBoard& board, VisitedBoard& visited, set<string>& result, int i, int j, string& current)
	{
		visited[i][j] = true;
		current += board[i][j];

		if(IsWord(current))
		{
			result.insert(current);
		}

		// Iterate over all neighbors
		for(int row = i - 1; (row <= i + 1 && row < bsize); row++)
		{
			for(int col = j - 1; (col <= j + 1 && col < bsize); col++)
			{
				if(row >= 0 && col >= 0 && !visited[row][col])
				{
					FindWordsHelper(board, visited, result, row, col, current);
				}
			}
		}

		current.erase(current.length() - 1);
		visited[i][j] = false;
	}

	set<string> BoggleSolver::FindWords(BoggleBoard& board)
	{
		set<string> result;

		VisitedBoard visited = {{false}};

		// Iterate over all possible starting points
		for(int row = 0; row < bsize; row++)
		{
			for(int col = 0; col < bsize; col++)
			{
				string str;
				FindWordsHelper(board, visited, result, row, col, str);
			}
		}

		return result;
	}
}