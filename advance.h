#pragma once
class Bird;

class Advance
{
    public:
        void advance(Bird *bird);
    
    protected:
        void inertia(Bird *bird);
        virtual void drag(Bird* bird) {}
        virtual void buoyancy(Bird *bird){}
        virtual void turn(Bird *bird){}


};

class StandardAdvance : public Advance {
   void drag(Bird* bird);
   void buoyancy(Bird *bird){}
   void turn(Bird *bird){}
};

 class SinkerAdvance : public Advance {
    void drag(Bird *bird) {}
     void buoyancy(Bird* bird);
     void turn(Bird *bird) {}
 };

class CrazyAdvance : public Advance {
    void drag(Bird *bird){}
    void buoyancy(Bird *bird){}
    void turn(Bird *bird);
};

class FloaterAdvance :  public Advance {
    void drag(Bird *bird);
    void buoyancy(Bird* bird);
    void turn(Bird* bird){}
};
