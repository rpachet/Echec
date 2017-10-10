#include "joueurBlanc.h"
#include "iostream"
#include "joueur.h"
#include"roi.h"
#include"reine.h"
#include"tour.h"
#include"fou.h"
#include"pion.h"
#include"cavalier.h"


using namespace std;

JoueurBlanc::JoueurBlanc(){

    Roi* rb = new Roi(true);
      m_pieces.push_back(rb);
      Reine* qb = new Reine(true);
      m_pieces.push_back(qb);
      Fou* fbg = new Fou(true,true);
      m_pieces.push_back(fbg);
      Fou* fbd = new Fou(true,false);
      m_pieces.push_back(fbd);
      Tour* tbg = new Tour(true,true);
      m_pieces.push_back(tbg);
      Tour* tbd = new Tour(true,false);
      m_pieces.push_back(tbd);
      Cavalier* cbg = new Cavalier(true,true);
      m_pieces.push_back(cbg);
      Cavalier* cbd = new Cavalier(true,false);
      m_pieces.push_back(cbd);

      Pion* p;
      for (int i=1; i<=8; i++)
        {
          p = new Pion(true,i);
          m_pieces.push_back(p);
        }
}

JoueurBlanc::~JoueurBlanc(){
    vector<Piece*>::iterator p=m_pieces.begin();
      while (p!=m_pieces.end())
        {
          delete *p;
          p++;
        }
}




