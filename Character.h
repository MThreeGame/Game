


class Character{
  private:
    int LocationX;
    int LocationY;
    int height;
    int width;
    //positionToX // |----------------| PreviousX minX maxX ?
     

  public:
    Character();
    //accessor
    int getLocationx();
    int getLocationY();
    int getHeight();
    int getwidth();

    //mutator
    void setLocationX(int x);
    void setLocationY(int y);
    void setHeight(int heightIn);
    void setWidth(int widthIn);

    virtual void move(); // update location



};