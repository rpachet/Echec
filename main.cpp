/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "piece.h"
#include "joueur.h"
#include "echiquier.h"
#include "joueurBlanc.h"
#include "joueurNoir.h"
#include "roi.h"
#include "reine.h"
#include "cavalier.h"
#include "fou.h"
#include "tour.h"
#include "pion.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */

bool compare( const Piece p1, const Piece p2){

    return{ (p1.x() == p2.x()) && (p1.y() == p2.y())};
}

int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1(3,3,true);
  Piece p2(4,4,false);

  // On l'affiche

  p1.affiche();
  p2.affiche();

  Piece tbl[4];

  /*Joueur JBlanc(true);
  Joueur JNoir(false);*/

  JoueurBlanc JBlanc;
  JoueurNoir JNoir;


  if(compare(p1,p2)){
      cout << "Meme coordonnées" << endl;
  } else
      cout << "Differentes coordonnées" << endl;


  Echiquier e;

  JBlanc.placerPieces(e);
  JNoir.placerPieces(e);


  /*JBlanc.affiche();
  JNoir.affiche();*/

  e.affiche();

  int x;
  cout << "coordonnee x de la piece :"<< endl;
  cin >> x;

  int y;
  cout << "coordonnee y de la piece :"<< endl;
  cin >> y;

  e.enleverPiece(x,y);
  cout << "Piece" << x <<":" << y << " supprimee" <<endl;
  e.affiche();

  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1
}
