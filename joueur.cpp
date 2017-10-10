#include "joueur.h"

#include "iostream"



Joueur::Joueur()
{
  // cout << "Construction Joueur par defaut" << endl;
}

Joueur::~Joueur(){
    // cout << "Destruction Joueur " << endl;
}





void Joueur::affiche(){
    for (int i=0; i<m_pieces.size(); i++)
        m_pieces[i]->affiche();

}

void Joueur::placerPieces(Echiquier &e){
    vector<Piece*>::iterator p=m_pieces.begin();
     while (p!=m_pieces.end())
       {
         e.placer(*p);
         p++;
       }

}



