#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

namespace score
{
	class Score
	{
	public:
		string scoreName;
		int score;
	};

	class ScoreManagement
	{
	public:
		list<Score> scoreList;

		void addScore(Score newScore);
		void sortList();
		Score getHighScore();
		list<Score> returnScoreList() const;
	};
}
