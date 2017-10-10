/**
 * Header de piece.cpp
 *
 * @file piece.h
 */

#if !defined piece_h
#define piece_h



/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */

class Echiquier;

class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  Piece(int x, int y, bool white);
  Piece(const Piece & autre);
  ~Piece();
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  Piece & operator=(const Piece & autre);
  virtual char toChar() const;
  Piece plusForteQue(const Piece & p) const;

  virtual bool mouvementValide(Echiquier &e, int x , int y);// polymorphisme: je peux redeclarer la fonction pour les classes enfants

};

#endif // !defined piece_h
