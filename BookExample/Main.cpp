//
//  Main.cpp
//  xcodetest
//
//  Created by Fatemeh Paknejad on 09.06.25.
//

#include <stdio.h>
#include <IOStream>
using namespace std;
#include "Car.hpp"

int main(){
    Car redVolvo;
    cout << "Red Volvo Speed: " << redVolvo.getSpeed()
    << " miles/hour" << ", Direction: "
    << redVolvo.getDirection() << " degrees" << endl;
    redVolvo.accelerate(30);
    redVolvo.turnRight(30);
    cout << "Red Volvo Speed: " << redVolvo.getSpeed()
    << " miles/hour" << ", Direction: "
    << redVolvo.getDirection() << " degrees" << endl;
    redVolvo.decelerate(10);
    redVolvo.turnLeft(10);
    cout << "Red Volvo Speed: " << redVolvo.getSpeed()
    << " miles/hour" << ", Direction: "
    << redVolvo.getDirection() << " degrees" << endl;
}
