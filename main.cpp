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

SnowMan* players = new SnowMan(player);

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




/* LoadPPM -- loads the specified ppm file, and returns the image data as a GLubyte
 *  (unsigned byte) array. Also returns the width and height of the image, and the
 *  maximum colour value by way of arguments
 *  usage: GLubyte myImg = LoadPPM("myImg.ppm", &width, &height, &max);
 */
GLubyte* LoadPPM(char* file, int* width, int* height, int* max)
{
    GLubyte* img;
    FILE *fd;
    int n, m;
    int  k, nm;
    char c;
    int i;
    char b[100];
    float s;
    int red, green, blue;
    
    /* first open file and check if it's an ASCII PPM (indicated by P3 at the start) */
    fd = fopen(file, "r");
    fscanf(fd,"%[^\n] ",b);
    if(b[0]!='P'|| b[1] != '3')
    {
        printf("%s is not a PPM file!\n",file);
        exit(0);
    }
    printf("%s is a PPM file\n", file);
    fscanf(fd, "%c",&c);
    
    /* next, skip past the comments - any line starting with #*/
    while(c == '#')
    {
        fscanf(fd, "%[^\n] ", b);
        printf("%s\n",b);
        fscanf(fd, "%c",&c);
    }
    ungetc(c,fd);
    
    /* now get the dimensions and max colour value from the image */
    fscanf(fd, "%d %d %d", &n, &m, &k);
    
    printf("%d rows  %d columns  max value= %d\n",n,m,k);
    
    /* calculate number of pixels and allocate storage for this */
    nm = n*m;
    img = (GLubyte*)malloc(3*sizeof(GLuint)*nm);
    s=255.0/k;
    
    /* for every pixel, grab the read green and blue values, storing them in the image data array */
    for(i=0;i<nm;i++)
    {
        fscanf(fd,"%d %d %d",&red, &green, &blue );
        img[3*nm-3*i-3]=red*s;
        img[3*nm-3*i-2]=green*s;
        img[3*nm-3*i-1]=blue*s;
    }
    
    /* finally, set the "return parameters" (width, height, max) and return the image array */
    *width = n;
    *height = m;
    *max = k;
    
    return img;
}

//this func is used to draw sky which is made of polygons at top, front, back, left and right side
void drawSky(){
    glBegin(GL_POLYGON);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glColor3f(.5,.5,.5);
    
    glTexCoord2f(0, 0);
    glVertex3f(-10,10,-10);
    
    glTexCoord2f(1, 1);
    glVertex3f(10,10,10);
    
    glTexCoord2f(0, 1);
    glVertex3f(-10,10,10);
    
    glTexCoord2f(1, 0);
    glVertex3f(10,10,-10);
    
    glEnd();
    
    glFlush();

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
            
            
        
        default:
            break;
    }
    
    glutPostRedisplay();
}

void special(int key, int x, int y){}

void mouse(int button, int state, int x, int y){}

void idle(){
    countr++;
    
    
    
}

void init(){
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void display(){
    float origin[3] = {0, 0, 0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(camPos[0], camPos[1], camPos[2], 0, 0, 0, 0, 1, 0);
    glColor3f(1, 1, 1);
    
    drawAxis();
    //draw the sky
    drawSky();
    
    
    
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
    
    //image = LoadPPM("sky-3.ppm", &width, &height, &max);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, image);
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glEnable(GL_TEXTURE_2D);
    
    
    init();
    
    glutMainLoop();
    return (0);
    
}