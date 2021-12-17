#include "FourRow.hpp"

#include <iostream>
#include <limits>
#include <cstdlib>

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
  
  int i;
  eColor turn = WHITE;
  
  showMap();

  if (turn == WHITE)
    std::cout << "<〇's turn> Where to put? : ";
  else
    std::cout << "<●'s turn> Where to put? : ";
  std::cin >> i;
  if (std::cin.bad() || std::cin.eof())
  {
    std::cout << std::endl << "Aborted." << std::endl;
    std::exit(1);
  }
  else if (std::cin.fail() || i < 0 || kColSize_ <= i || !canPut(0))
  {
    std::cout << "Invalid number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  put();
  showMap();
}

bool FourRow::canPut(int pos) {
  for (int i = kRowSize_ - 1; i >= 0; --i) {
    if (map_[i][pos] == 0)
      return true;
  }
  return false;
}

void FourRow::put(eColor color, int pos) {
  for (int i = kRowSize_ - 1; i >= 0; --i) {
    if (map_[i][pos] == 0) {
      map_[i][pos] = color;
      return;
    }
  }
}

eColor FourRow::judgeCol() {
  eColor color = NOCOLOR;
  int count = 0;
  for (int i = 0; i < kRowSize_; ++i) {
    for (int j = 0; j < kColSize_; ++j) {
      if (map_[i][j] == 0)
        continue;
      if (map_[i][j] == color) {
        ++count;
      } else {
        count = 1;
      }
      if (count >= 4)
        return color;
    }
  }
  return NOCOLOR;
}

eColor FourRow::judgeRow() {
  eColor color = NOCOLOR;
  int count = 0;
  for (int i = 0; i < kColSize_; ++i) {
    for (int j = 0; j < kRowSize_; ++j) {
      if (map_[i][j] == 0)
        continue;
      if (map_[i][j] == color) {
        ++count;
      } else {
        count = 1;
      }
      if (count >= 4)
        return color;
    }
  }
  return NOCOLOR;
}

eColor FourRow::judgeSlantRightDown() {
  eColor color = NOCOLOR;
  int count = 0;
  for (int i = -2; i < kColSize_ - 2; ++i) {
    for (int i2 = i, j = 0; j < kRowSize_; ++i2, ++j) {
      if (i2 < 0 || j < 0 || map_[i][j] == 0)
        continue;
      if (map_[i2][j] == color) {
        ++count;
      } else {
        count = 1;
      }
      if (count >= 4)
        return color;
    }
  }
  return NOCOLOR;
}

eColor FourRow::judgeSlantRightUp() {
  eColor color = NOCOLOR;
  int count = 0;
  for (int i = -2; i < kRowSize_ - 2; ++i) {
    for (int i2 = i, j = 0; j < kColSize_; ++i2, ++j) {
      if (i2 < 0 || j < 0 || map_[i][j] == 0)
        continue;
      if (map_[i2][j] == color) {
        ++count;
      } else {
        count = 1;
      }
      if (count >= 4)
        return color;
    }
  }
  return NOCOLOR;
}

eColor FourRow::judge() {
  eColor win_color = judgeCol();
  if (win_color == NOCOLOR)
    win_color = judgeRow();
  if (win_color == NOCOLOR)
    win_color = judgeSlantRightDown();
  if (win_color == NOCOLOR)
    win_color = judgeSlantRightUp();
  return win_color;
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
