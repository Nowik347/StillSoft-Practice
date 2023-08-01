#include <iostream>
#include <array>
#include <random>
#include <algorithm>

enum ranks { two, three, four, five, six, seven, eight, nine, ten, Jack, Queen, King, Ace }; 
enum suit { clubs, diamonds, hearts, spades };

struct Card
{
    ranks rank;
    suit suit;
};

void printCard(const Card card)
{
	switch (card.rank)
	{
	case two:
		std::cout << "2";
		break;
	case three:
		std::cout << "3";
		break;
	case four:
		std::cout << "4";
		break;
	case five:
		std::cout << "5";
		break;
	case six:
		std::cout << "6";
		break;
	case seven:
		std::cout << "7";
		break;
	case eight:
		std::cout << "8";
		break;
	case nine:
		std::cout << "9";
		break;
	case ten:
		std::cout << "10";
		break;
	case Jack:
		std::cout << "J";
		break;
	case Queen:
		std::cout << "Q";
		break;
	case King:
		std::cout << "K";
		break;
	case Ace:
		std::cout << "A";
		break;
	}

	switch (card.suit)
	{
	case clubs:
		std::cout << "C ";
		break;
	case diamonds:
		std::cout << "D ";
		break;
	case hearts:
		std::cout << "H ";
		break;
	case spades:
		std::cout << "S ";
		break;
	}
}

void printDeck(std::array<Card, 52> deck)
{
	for (int i { 0 }; i < deck.size(); i++)
	{
		printCard(deck[i]);
	}
}

std::array<Card, 52> createDeck()
{
	std::array<Card, 52> deck{};

	int count{ 0 };

	for (int i { 0 }; i < 4; i++)
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

int main()
{
	auto random = std::default_random_engine{};

	std::array<Card, 52> cards{ createDeck() };

	std::shuffle(std::begin(cards), std::end(cards), random);

	printDeck(cards);

	std::cout << getCardValue(cards[3]);
}