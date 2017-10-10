#include "joueurNoir.h"
#include "iostream"
#include "joueur.h"
#include"roi.h"
#include"reine.h"
#include"tour.h"
#include"fou.h"
#include"pion.h"
#include"cavalier.h"



using namespace std;

JoueurNoir::JoueurNoir(){

    Roi* rb = new Roi(false);
    m_pieces.push_back(rb);
    Reine* qb = new Reine(false);
    m_pieces.push_back(qb);
    Fou* fbg = new Fou(false,true);
    m_pieces.push_back(fbg);
    Fou* fbd = new Fou(false,false);
    m_pieces.push_back(fbd);
    Tour* tbg = new Tour(false,true);
    m_pieces.push_back(tbg);
    Tour* tbd = new Tour(false,false);
    m_pieces.push_back(tbd);
    Cavalier* cbg = new Cavalier(false,true);
    m_pieces.push_back(cbg);
    Cavalier* cbd = new Cavalier(false,false);
    m_pieces.push_back(cbd);

    Pion* p;
    for (int i=1; i<=8; i++)
      {
        p = new Pion(false,i);
        m_pieces.push_back(p);
      }
}

JoueurNoir::~JoueurNoir(){
    vector<Piece*>::iterator p=m_pieces.begin();
     while (p!=m_pieces.end())
       {
         delete *p;
         p++;
       }
}







