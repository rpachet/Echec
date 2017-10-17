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

void choiceXY(int &x, int &y)
{
    string message;
    if(x==0)
    {
        message = "Choisir une piece";
    }
    else
    {
        message = "Case de Destination";
    }
    while(x<1 || x>8 && y<1 || y>8)
    {
        cout << "Entrer des chiffres entre 1 et 8" << endl;
        cout << message << endl;
        cout << "X : ";
        cin >> x;
        cout << "Y : ";
        cin >> y;
        cout << endl;
    }
}

void playerTurn(JoueurBlanc &jb, JoueurNoir &jn)
{
    if(!jb.getTurn() && !jn.getTurn())
    {
        string joueur;
        cout << "Choisir le joueur qui commence" << endl;
        cout << "Ecrire 'noir' ou 'blanc'" << endl;
        cin >> joueur;
        cout << joueur << endl;
        while(joueur != "noir" && joueur != "blanc") {
            cout << "Vous n'avez pas choisis 'noir' ou 'blanc'" << endl;
            cin >> joueur;
        }
        if(joueur == "blanc")
        {
            jb.setTurn(true);
            cout << "Tour du joueur blanc" << endl;
        }
        else
        {
            jn.setTurn(true);
            cout << "Tour du joueur noir" << endl;
        }
    }
    else if(jb.getTurn())
    {
        jb.setTurn(false);
        jn.setTurn(true);
        cout << "Tour du joueur noir" << endl;
    }
    else
    {
        jb.setTurn(true);
        jn.setTurn(false);
        cout << "Tour du joueur blanc" << endl;
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

  ptr=&rb;
  Roi* rptr;
  rptr=dynamic_cast<Roi*>(ptr);
  if (rptr!=nullptr)
    cout << "rb dynamic_cast<Roi*>  ok" << endl;
  else
    cout << "rb dynamic_cast<Roi*> nok" << endl;

  ptr=&qb;
  rptr=dynamic_cast<Roi*>(ptr);
  if (rptr!=nullptr)
    cout << "qb dynamic_cast<Roi*>  ok" << endl;
  else
    cout << "qb dynamic_cast<Roi*> nok" << endl;

  e.affiche();

  // les objets definis dans cette fonction sont automatiquement d�truits.

    int x,y;


    Piece *a;

    while(true)
    {
        playerTurn(jb,jn);
        x=0,y=0;
        while(e.getPiece(x,y)==NULL)
        {
            x=0,y=0;
            choiceXY(x,y);
        }
        a=e.getPiece(x,y);
        x=-1;y=-1;
        while(a->mouvementValide(e,x,y)==false)
        {
            x=-1,y=-1;
            choiceXY(x,y);
        }
        e.deplacer(a,x,y);
        e.affiche();
    }

    delete a;

    return 0;

}
