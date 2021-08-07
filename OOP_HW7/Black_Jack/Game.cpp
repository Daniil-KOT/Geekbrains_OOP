#include "Game.h"

//–еализовать класс Game, который представл€ет собой основной процесс игры.” этого класса будет 3 пол€:
//	колода карт
//	рука дилера
//	вектор игроков.
// онструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков.¬ конструкторе создаетс€ колода карт и затем перемешиваетс€.
//“акже класс имеет один метод play().¬ этом методе раздаютс€ каждому игроку по две стартовые карты, а перва€ карта дилера пр€четс€.
//ƒалее выводитс€ на экран информаци€ о картах каждого игра, в т.ч.и дл€ дилера.«атем раздаютс€ игрокам дополнительные карты.
//ѕотом показываетс€ перва€ карта дилера и дилер набирает карты, если ему надо.ѕосле этого выводитс€ сообщение, кто победил, а кто проиграл.¬ конце руки всех игроков очищаютс€.

Game::Game(vector<string>& player_names)
{
	for (int i = 0; i < player_names.size(); i++)
	{
		players_.push_back(Player(player_names.at(i)));
	}

	srand(static_cast<unsigned int>(time(0)));

	deck_.Populate();
	deck_.Shuffle();
}

void Game::Play()
{
	for (int i = 0; i < START_CARDS; i++)
	{
		for (int j = 0; j < players_.size(); j++)
		{
			deck_.Deal(players_.at(j));
		}
		deck_.Deal(house_);
	}

	house_.FlipFirstCard();

	for (int j = 0; j < players_.size(); j++)
	{
		cout << players_.at(j) << endl;
	}

	cout << house_ << endl;

	for (int j = 0; j < players_.size(); j++)
	{
		deck_.DealAdditionalCards(players_.at(j));
	}

	house_.FlipFirstCard();
	cout << house_ << endl;

	deck_.DealAdditionalCards(house_);

	if (house_.IsBusted())
	{
		for (int j = 0; j < players_.size(); j++)
		{
			if (players_.at(j).IsBusted() == false)
				players_.at(j).Win();
		}
	}
	else
	{
		for (int j = 0; j < players_.size(); j++)
		{
			if (players_.at(j).IsBusted() == false)
			{
				if (players_.at(j).GetValue() > house_.GetValue())
				{
					players_.at(j).Win();
				}
				else if (players_.at(j).GetValue() < house_.GetValue())
				{
					players_.at(j).Lose();
				}
				else
				{
					players_.at(j).Push();
				}
			}
		}
	}

	for (int j = 0; j < players_.size(); j++)
	{
		players_.at(j).Clear();
	}
	house_.Clear();
}
