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
  eColor map_[kRowSize_][kColSize_];

  int placePiece(eColor turn);
  bool canPut(int pos);
  void put(eColor color, int pos);
  eColor judgeCol();
  eColor judgeRow();
  eColor judgeSlantRightDown();
  eColor judgeSlantRightUp();
  eColor judge();
  void showMap();
};

#endif
