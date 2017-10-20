/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

void choice(int &x, int &y)
{
  cout << "Coordonnees X de la piece (horizontal) :";
  cin>>x;

    cout << "Coordonnees Y de la piece (vertical) :";
    cin>>y;
}

void verifCoordonnees()
{
  int x;
  int y;
    while(true)
    {
        cout << "\nX = ";
        cin >> x;
        cout << "\nY = ";
        cin >> y;

        if((x>=1) && (x<=8) && (y>=1) && (y<=8))
        {
            break;
        }
        else
        {
            cout << "\nCoordonnees incorrectes. Ressaisissez les valeurs :";
        }
    }
}

bool compare(const Piece &p1, const Piece &p2)
{
  return ( (p1.x()==p2.x()) && (p1.y()==p2.y()) );
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );

  Piece p2( 4, 4, false);

  // On l'affiche
  p1.affiche();
  p2.affiche();
  cout << (p1.isBlack() ? "oui" : "non") << endl;

  /*
  Joueur jb(true);
  Joueur jn(false);
  */
  JoueurBlanc jb;
  JoueurNoir jn;
  jb.affiche();
  jn.affiche();

  //Joueur j; // classe abstraite

  cout << "compare" << endl;
  if (compare(p1,p2))
    cout << "meme coordonnees" << endl;
  else
    cout << "differentes coordonnees" << endl;

  Piece p3=p2;
  p3=p2=p1;

  Echiquier e;
  e.affiche();

  jb.placerPieces(e);
  jn.placerPieces(e);

  Roi rb(true);
  Roi rn(false);
  Reine qb(true);
  Reine qn(false);

  Piece *ptr;

  ptr=e.enleverPiece(5,1);
  e.placer(&rb);
  ptr=e.enleverPiece(5,8);
  e.placer(&rn);
  ptr=e.enleverPiece(4,1);
  cout << qb.x() << qb.y() << endl;
  e.placer(&qb);
  ptr=e.enleverPiece(4,8);
  cout << qn.x() << qn.y() << endl;
  e.placer(&qn);

  Tour tbg(true,true);
  ptr=e.enleverPiece(1,1);
  e.placer(&tbg);
  Tour tbd(true,false);
  ptr=e.enleverPiece(8,1);
  e.placer(&tbd);
  Tour tng(false,true);
  ptr=e.enleverPiece(1,8);
  e.placer(&tng);
  Tour tnd(false,false);
  ptr=e.enleverPiece(8,8);
  e.placer(&tnd);

  Fou fbg(true,true);
  ptr=e.enleverPiece(3,1);
  e.placer(&fbg);
  Fou fbd(true,false);
  ptr=e.enleverPiece(6,1);
  e.placer(&fbd);
  Fou fng(false,true);
  ptr=e.enleverPiece(3,8);
  e.placer(&fng);
  Fou fnd(false,false);
  ptr=e.enleverPiece(6,8);
  e.placer(&fnd);

  Cavalier cbg(true,true);
  ptr=e.enleverPiece(2,1);
  e.placer(&cbg);
  Cavalier cbd(true,false);
  ptr=e.enleverPiece(7,1);
  e.placer(&cbd);
  Cavalier cng(false,true);
  ptr=e.enleverPiece(2,8);
  e.placer(&cng);
  Cavalier cnd(false,false);
  ptr=e.enleverPiece(7,8);
  e.placer(&cnd);

  ptr=&rb;
  ptr->mouvementValide(e,1,1);
  ptr=&qb;
  ptr->mouvementValide(e,1,1);


  e.affiche();


    int x,y;
    int newx, newy;
    bool finPartie = false;
    bool joeurTurn =true; //true = black false = white
    Piece *a;

    while(finPartie == false){
      bool mouvementValide = false;
      e.affiche();
      x=0,y=0;

      if (joeurTurn == true)
      {
        cout <<"tour du joueur blanc" << endl;
      }
     else
     {
        cout <<"tour du joueur noir" << endl;
     }

      while(!mouvementValide){
        x=0,y=0;
        choice(x,y);

        if(e.getPiece(x,y) != NULL){
          if ((joeurTurn && e.getPiece(x, y)->isWhite()) || (!joeurTurn && e.getPiece(x, y)->isBlack()))
          {
            cout << "\nnouvelle coordonnee X = ";
            cin >> newx;
            cout << "\n nouvelle coordonnee Y = ";
            cin >> newy;

            if (e.getPiece(x,y)->mouvementValide(e,newx,newy))
            {
              e.deplacer(e.getPiece(x,y), newx, newy);
               mouvementValide = true;
               e.affiche();
               joeurTurn =false;
            }

            else{
                cout<<"Mouvement invalide !!"<< endl;
            }
          }
          else
          {
            cout << "La piece choisie n'est pas à vous ! "<<endl;
          }
        }
      }
    }


    delete a;

    return 0;

}
