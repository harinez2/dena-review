#include "FourRow.hpp"

#include <iostream>

FourRow::FourRow() {
  for (int i = 0; i < kRowSize_; ++i)
    for (int j = 0; j < kColSize_; ++j)
      map_[i][j] = 0;
}

FourRow::FourRow(const FourRow& rhs) { *this = rhs; }

FourRow& FourRow::operator=(const FourRow& rhs) {
  if (this != &rhs) {

  }
  return *this;
}

FourRow::~FourRow() {}

void FourRow::newGame() {
  showPrompt();
}

void FourRow::showPrompt() {
  
	int		i;
  
  showMap();

	std::cout << "<〇's turn> Where to put? : ";
	std::cin >> i;
	if (std::cin.bad() || std::cin.eof())
	{
		std::cout << std::endl << "Aborted." << std::endl;
		std::exit(1);
	}
	else if (std::cin.fail() || i < 0 || kColSize_ <= i || !canPut())
	{
		std::cout << "Invalid number." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  showMap();
}

int FourRow::canPut(int color, int n) {

}

void FourRow::showMap() {
  for (int i = kRowSize_ - 1; i >= 0; --i) {
    std::cout << i + 1 << " ";
    for (int j = 0; j < kColSize_; ++j) {
      if (map_[i][j] == 1)
        std::cout << "〇 ";
      else if (map_[i][j] == 2)
        std::cout << "● ";
      else
        std::cout << "   ";
    }
    std::cout << std::endl;
  }
  std::cout << "   ";
  for (int i = 0; i < kColSize_; ++i)
    std::cout << i + 1<< "  ";
  std::cout << std::endl;
}
