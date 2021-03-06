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

//create player
SnowMan* player0 = new SnowMan();

//an array for iamge data
GLubyte* image;
int width, height, max;

using namespace std;

float camPos[] = {5, 5, 10};
float light_pos[] = {5, 10, 5, 0};

//player's status
float playerPos[] = {0, 0, 0};
float playerDir[] = {0, 0, 0};
float playerAngle = 0;

//use flag to change player's view; first person view = 0 or third person view = 1
int view_flag = 0;

static int MAX_SNOWBALLS = 100;
static int MAX_AIs = 10;

//record how many snowballs have been shot
int numbOfSnowBall = 0;
//record how many AI snowman
int numbOfAIs = 0;
//counter used in idle func
int countr;

//material parameters
float m_amb[] = {.33, .22, .03, 1.0};
float m_diff[] = {.78, .57, .11, 1.0};
float m_spec[] = {.99, .91, .91, 1.0};
float shiny = 27.8;

//this func is to update player's position and direction in real time
void PlayerPnD(){
    float *tempPos = player0->getPos();
    playerPos[0] = tempPos[0];
    playerPos[1] = tempPos[1];
    playerPos[2] = tempPos[2];
    
    float *tempDir = player0->getDir();
    playerDir[0] = tempDir[0];
    playerDir[1] = tempDir[1];
    playerDir[2] = tempDir[2];
    
    playerAngle = player0->getAngle();
}

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
        
        //player snowman move forawrd based on his direction
        case 'w':
        case 'W':
            playerPos[0] = player0->getPos()[0];
            playerPos[1] = player0->getPos()[1];
            playerPos[2] = player0->getPos()[2];
            
            playerDir[0] = player0->getDir()[0];
            playerDir[1] = player0->getDir()[1];
            playerDir[2] = player0->getDir()[2];
            
            playerPos[0] += playerDir[0];
            playerPos[1] += playerDir[1];
            playerPos[2] += playerDir[2];
            
            player0->setPos(playerPos);
            break;
        
        //player snowman turns left
        case 'a':
        case 'A':
        {
            float tempAngle = player0->getAngle();
            tempAngle += 1;
            player0->setAngle(tempAngle);
            break;
        }
         
        //player snowman moves backward
        case 's':
        case 'S':
            playerPos[0] = player0->getPos()[0] - 0.1;
            playerPos[1] = player0->getPos()[1];
            playerPos[2] = player0->getPos()[2];
            player0->setPos(playerPos);
            break;
        
        //player snowman turns right
        case 'd':
        case 'D':
        {
            float tempAngle = player0->getAngle();
            tempAngle -= 1;
            player0->setAngle(tempAngle);
            break;
        }
         
        //press v to change first person or third person view
        case 'v':
        case 'V':
            view_flag++;
            view_flag = view_flag % 2;
            break;
        
        //press z to shoot snowballs
        case 'z':
            if (numbOfSnowBall < MAX_SNOWBALLS) {
                //create new snowball
                SnowBall sBall = *new SnowBall(player0->getPos(), player0->getDir());
                SnowBallList_Player->push_back(sBall);
                numbOfSnowBall++;
            }
        default:
            break;
    }
    
    glutPostRedisplay();
}

void special(int key, int x, int y){
    
    
    glutPostRedisplay();
}

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
            //check current snowball, if it hits any snowmans
            for (vector<SnowMan>::iterator i = SnowManList->begin();i != SnowManList->end(); i++) {
                bool hit = iter->isHit(i->getPos(), i->getSize());
                if (hit) {
                    iter->setHP(1);
                    SnowManList->erase(i);//if hit, snowman disappear
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
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    float amb[4] = {1, 1, 1, 1};
    float diff[4] = {.5, .5, .5, 1};
    float spec[4] = {0, 0, 0, 1};
    
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diff);
    glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT1, GL_SPECULAR, spec);
    
}

void display(){
    float origin[3] = {0, 0, 0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
    glColor3f(1, 1, 1);
    
    drawAxis();
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m_spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shiny);
    
    //update player's status every frame
    PlayerPnD();
    
    //here will implement player's view: first person or third person
    if (view_flag == 0) {
        //TODO first person view:
        //gluLookAt();
    }else{
        //TODO third person view:
        //gluLookAt();
    }
    
    //draw player snowman
    player0->DrawSnowman(playerPos, playerAngle);
    
    //use iter in vector SnowBallList_Player to draw each snowball
    //TODO
    for (vector<SnowBall>::iterator iter = SnowBallList_Player->begin(); iter != SnowBallList_Player->end(); iter++) {
        
        glPushMatrix();
        //get snowball position and draw
        glPopMatrix();
        
    }
    
    //use iter in vector SnowManList to draw each AI snowman
    //TODO
    for (vector<SnowMan>::iterator iterM = SnowManList->begin(); iterM != SnowManList->end(); iterM++) {
        
        glPushMatrix();
        //get AI snowman position and draw
        glPopMatrix();
        
    }

    
    
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
    //glutIdleFunc(idle);
    
    
    init();
    
    glutMainLoop();
    return (0);
    
}