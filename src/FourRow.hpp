#ifndef FOURROW_HPP
#define FOURROW_HPP

enum eColor {
  NOCOLOR,
  WHITE,
  BLACK
};

class FourRow {
 public:
  FourRow();
  FourRow(const FourRow& rhs);
  FourRow& operator=(const FourRow& rhs);
  ~FourRow();

  void newGame();

 private:
  static const int kRowSize_ = 6;
  static const int kColSize_ = 7;
  int map_[kRowSize_][kColSize_];

  void showPrompt();
  void showMap();
  int canPut(eColor color, int pos);
};

#endif