#ifndef _ITEM
#define _ITEM
#include"cellule.h"
#include"balle.h"


class Item 
{  
    private:

    Cellule item;
    
    Balle ball;

    TypeItem i_typ;


    public:


    bool estAtteint(Balle b); ///booléen 

    void EffetParType(TypeItem i_type);









};

enum TypeItem
{   TLP=1,BONUS=2,TEMPSG=3,PLUSPTS=4

};









#endif

