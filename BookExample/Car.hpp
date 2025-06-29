//
//  Car.hpp
//  xcodetest
//
//  Created by Fatemeh Paknejad on 08.06.25.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>

#endif /* Car_hpp */



class Car {
    
private:
    int m_speed, m_direction;
public:
    Car();
    Car(int speed, int direction);
    ~Car();
    
    int getSpeed() const;
    int getDirection() const;
    
    void accelerate(int speed);
    void decelerate(int speed);
    void turnRight(int degrees);
    void turnLeft(int degrees);
};
