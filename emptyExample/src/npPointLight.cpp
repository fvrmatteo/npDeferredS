//
//  npPointLight.cpp
//  emptyExample
//
//  Created by Kris Temmerman on 23/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "npPointLight.h"
void npPointLight::setup(float radius,float  r,float g,float b, float radiusDraw )
{
    
    npMaterial mat;
    mat.hasColor =true;
    mat.hasUV = false;
    mat.r =r;
    mat.g =g;
    mat.b =b;
    
    
    npMaterial mat2;
    mat2.hasColor =true;
    mat2.hasUV = false;
    mat2.r =r*3;
    mat2.g =g*3;
    mat2.b =b*3;
    
    drawSphere.setup(mat2,radiusDraw ,4,3);
    
    rangeSphere.setup(mat,radius,8,6);

   
}

void npPointLight::setPos(float _x, float _y,float _z)
{
    drawSphere.setPos(_x,_y,_z) ;  
    rangeSphere.setPos(_x,_y,_z) ;  
}
