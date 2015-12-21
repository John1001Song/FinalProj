//
//  main.cpp
//  FinalProj
//
//  Created by Jinyue Song on 2015-12-19.
//  Copyright © 2015 Jinyue Song. All rights reserved.
//

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include "snowMan.h"
#include "snowBall.h"
#include "snow.h"
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

SnowMan* player0 = new SnowMan();


//an array for iamge data
GLubyte* image;
int width, height, max;

using namespace std;

float camPos[] = {5, 5, 10};
float light_pos[] = {5, 10, 5, 1};
static int MAX_SNOWBALLS = 100;
static int MAX_AIs = 10;

float angle = 0;
int numbOfSnowBall = 0;
int numbOfAIs = 0;
int countr;




/* drawAxis() -- draws an axis at the origin of the coordinate system
 *   red = +X axis, green = +Y axis, blue = +Z axis
 */
//draw axis to find XYZ direction
void drawAxis()
{
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3f(0,0,0);
    glVertex3f(500,0,0);
    
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,500,0);
    
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,500);
    glEnd();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
            break;
            
        case 'w':
        case 'W':
            break;
            
        case 'a':
        case 'A':
            break;
            
        case 's':
        case 'S':
            break;
        
        case 'd':
        case 'D':
            break;
        
        default:
            break;
    }
    
    glutPostRedisplay();
}

void special(int key, int x, int y){}

void mouse(int button, int state, int x, int y){}

void idle(){
    countr++;
    
    //every 15s there will be a new AI appear
    while ((countr % 15) == 0) {
        if (numbOfAIs < MAX_AIs) {
            SnowManList->push_back(*new SnowMan());
            numbOfAIs++;
        }
    }
    
    //update snowballs and check if they have a hit on the snowmans
    
    //create iterator to check each snowball shot by player, if this snowball hit some AI
    for (vector<SnowBall>::iterator iter = SnowBallList_Player->begin(); iter != SnowBallList_Player->end(); iter++) {
        
        if (iter->getHP() >= 0) {
            iter->update();
            
            for (vector<SnowMan>::iterator i = SnowManList->begin();i != SnowManList->end(); i++) {
                bool hit = iter->isHit(i->getPos(), i->getSize());
                if (hit) {
                    iter->setHP(1);
                    SnowManList->erase(i);
                    numbOfAIs--;
                    break;
                }
                
            }
            
        }else{
            numbOfSnowBall--;
            SnowBallList_Player->erase(iter);
        }
    }
    
    player0->update();
    
    glutPostRedisplay();
    
}

void init(){
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
}

void display(){
    float origin[3] = {0, 0, 0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
    glColor3f(1, 1, 1);
    
    drawAxis();
    
    
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char ** argv){
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    
    glutCreateWindow("Snowman fighting");
    
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    
    
    init();
    
    glutMainLoop();
    return (0);
    
}