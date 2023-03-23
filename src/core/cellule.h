#ifndef _CELLULE
#define _CELLULE

class Cellule
{

    private:
    unsigned int pos_x;
    unsigned int pos_y; // en haut a gauche 
   
    //TypeCell c_type;

    


    public:
    
    Cellule();
    

    void SetX (unsigned int x);
    
    void SetY(unsigned int y);

    unsigned int GetX() const;

    unsigned int GetY() const;

    // operateur pour siplifier lutilisation dans le tableau de cellule dans terrain

    Cellule& operator = (const Cellule& c);







    




    // dans terrains Cellule& GetCellule()const;
    // void set Cellule ()


};

//enum TypeCell
//{  BALLE=1, OBSTACLE=2,ITEM1=3,ITEM2=4,ITEM3=5,ITEM4=6};





#endif
