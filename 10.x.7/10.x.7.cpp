#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <algorithm>

enum ranks { two, three, four, five, six, seven, eight, nine, ten, Jack, Queen, King, Ace };
enum suit { clubs, diamonds, hearts, spades };

struct Card
{
    ranks rank;
    suit suit;
};

std::array<Card, 52> createDeck()
{
	std::array<Card, 52> deck{};

	int count{ 0 };

	for (int i{ 0 }; i < 4; i++)
	{
		for (int j{ 0 }; j < 13; j++)
		{
			deck[count].suit = suit(i);
			deck[count].rank = ranks(j);
			count++;
		}
	}

	return deck;
}

int getCardValue(Card card)
{
	switch (card.rank)
	{
	case Jack:
	case Queen:
	case King:
		return 10;
	case Ace:
		return 11;
	default:
		return static_cast<int>(card.rank) + 2;
	}
}

int countDeck(std::vector<Card> deck)
{
	int total{ 0 };

	for (int i{ 0 }; i < deck.size(); i++)
	{
		total += getCardValue(deck[i]);
	}

	return total;
}

bool playBlackjack(std::array<Card, 52>& deck)
{
	std::vector<Card> dealer, player;
	bool trigger{ false };
	char choice;
	int current_card_index{ 0 }, dealer_index{ 0 }, player_index{ 0 };

	dealer.resize(dealer_index + 1);
	dealer.at(dealer_index) = deck[current_card_index];
	current_card_index++; dealer_index++;

	player.resize(player_index + 1);
	player.at(player_index) = deck[current_card_index];
	current_card_index++; player_index++;

	player.resize(player_index + 1);
	player.at(player_index) = deck[current_card_index];
	current_card_index++; player_index++;

	while (!trigger)
	{
tryagain:
		system("cls");

		std::cout << "\nУ диллера: " << countDeck(dealer)
			<< "\nУ вас: " << countDeck(player);

		if (countDeck(player) == 21)
		{
			std::cout << "\nБлэкджэк. Вы победили.";
			return true;
		}
		else if (countDeck(player) > 21)
		{
			std::cout << "\nБольше 21. Вы проиграли.";
			return false;
		}

		std::cout << "\nВзять(y)/Достаточно(n)? ";
		std::cin >> choice;

		switch (choice)
		{
		case 'y':
			player.resize(player_index + 1);
			player.at(player_index) = deck[current_card_index];
			current_card_index++; player_index++;
			goto tryagain;
		case 'n':
			std::cout << "\nХод диллера.";
			break;
		default:
			goto tryagain;
		}

		while (countDeck(dealer) < 21)
		{
			dealer.resize(dealer_index + 1);
			dealer.at(dealer_index) = deck[current_card_index];
			current_card_index++; dealer_index++;

			if (countDeck(dealer) > 21)
			{
				std::cout << "\nДиллер проиграл. Вы победили.";
				return true;
			}
			else if (countDeck(dealer) > countDeck(player))
			{
				std::cout << "\nДиллер выйграл. Вы проиграли.";
				return false;
			}
			else if (countDeck(dealer) == countDeck(player))
			{
				std::cout << "\nНичья.";
				return false;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	auto random = std::default_random_engine{ static_cast<unsigned int>(time(nullptr)) };

	std::array<Card, 52> cards{ createDeck() };

	std::shuffle(std::begin(cards), std::end(cards), random);

	playBlackjack(cards);
}