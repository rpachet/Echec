/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */

/* #include "Echiquier.h" Pb ref croisee */
class Echiquier;

class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  virtual ~Piece();
  Piece( const Piece & autre);
  Piece & operator=( const Piece & autre);

  Piece( int x, int y, bool white );
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  virtual char toChar() const;
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  void setPosition(int x,int y);
};

class Roi : public Piece
{
 public:
  Roi(bool white);
  ~Roi();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};

class Tour : virtual public Piece
{
 public:
  Tour(bool white, bool pos);
  ~Tour();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};

class Fou : virtual public Piece
{
 public:
  Fou(bool white, bool pos);
  ~Fou();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};

class Reine : public Tour, public Fou
{
 public:
  Reine(bool white);
  ~Reine();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};

class Cavalier : public Piece
{
 public:
  Cavalier(bool white, bool pos);
  ~Cavalier();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};

class Pion : public Piece
{
 public:
  Pion(bool white, int pos);
  ~Pion();
  char toChar() const;
  bool mouvementValide(Echiquier &e, int x, int y);
};


#endif // !defined Piece_h
