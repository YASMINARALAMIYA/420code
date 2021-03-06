#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <limits>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

#define sqrt2 (sqrt(2))

typedef struct point
{
    double x,y,z;
} Point;

bool drawAxes = true;
bool drawgrid = true;
float tyreAngle = 0;
int count=1;
float quadAngle = 0;
float boxAngle = 0;
float boxScaleFactorX = 1;
float boxScaleFactorY= 1;
float boxScaleFactorZ= 1;
float tyreScaleFactor = 1;
float tinyBoxAngle = 0;
float background = 0;

Point pos, u, r, l;

void grid()
{
    if(drawgrid)
    {
        glBegin(GL_LINES);
        {
            glColor3f(1.0, 0, 0);

            glVertex3f( 485,0,0); // a point on pos x axis
            glVertex3f(-485,0,0); // a point on neg x axis

            glColor3f(0, 1.0, 0);

            glVertex3f(0,-485,0); // a point on pos y axis
            glVertex3f(0, 485,0); // a point on neg y axis

        }
        glEnd();
    }
}

// start: lamia's code
void displayRay(float rayStart,float rayEnd)
{


		glBegin(GL_LINES);
		{


			glColor3f(1.0, 0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(0, rayEnd,0); // a point on neg y axis


			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(100, rayEnd,0); // a point on neg y axis


             glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-100, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-100.50, rayEnd,0); // a point on neg y axis


			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-200, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-300, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-700, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-800, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-900, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-400, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-500, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-600, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-100, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-200, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-1000, rayEnd,0); // a point on neg y axis

			glColor3f(1.0,0, 0);

			glVertex3f(0,rayStart,0); // a point on pos y axis
			glVertex3f(-1100, rayEnd,0); // a point on neg y axis


		}
		glEnd();

}
// end: lamia's code


void displayAxes()
{
    if(drawAxes)
    {
        glBegin(GL_LINES);
        {
            glColor3f(1.0, 0, 0);

            glVertex3f( 500,0,0); // a point on pos x axis
            glVertex3f(-500,0,0); // a point on neg x axis

            glColor3f(0, 1.0, 0);

            glVertex3f(0,-500,0); // a point on pos y axis
            glVertex3f(0, 500,0); // a point on neg y axis

            glColor3f(0, 0, 1.0);

            glVertex3f(0,0, 500);  // a point on pos z axis
            glVertex3f(0,0,-500);   // a point on neg z axis
        }
        glEnd();
    }
}



Point func(Point vect, Point perp, int dir)
{
    double c = cos(pi/180);
    double s = dir * sin(pi/180);
    Point point;
    point.x = c * vect.x + s * perp.x;
    point.y = c * vect.y + s * perp.y;
    point.z = c * vect.z + s * perp.z;
    c = sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
    point.x /= c;
    point.y /= c;
    point.z /= c;
    return point;
}


void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {
    case '1':
    {
        // analyzed
        Point l1 = func(l, r, -1);
        r = func(r, l, 1);
        l = l1;
        break;
    }
    case '2':
    {
        // analyzed
        Point l1 = func(l, r, 1);
        r = func(r, l, -1);
        l = l1;
        break;
    }

    case '3':
    {
        Point u1 = func(u, l, -1);
        l = func(l, u, 1);
        u = u1;
        break;
    }
    case '4':
    {
        Point u1 = func(u, l, 1);
        l = func(l, u, -1);
        u = u1;
        break;
    }
    case '5':
    {
        Point r1 = func(r, u, -1);
        u = func(u, r, 1);
        r = r1;
        break;
    }
    case '6':
    {
        Point r1 = func(r, u, 1);
        u = func(u, r, -1);
        r = r1;
        break;
    }
    case '7':
    {
        tyreScaleFactor += 0.2;
        break;
    }
    case '8':
    {
        tyreScaleFactor -= 0.2;
        break;
    }
    case '9':   // up arrow
    {
         quadAngle -= 5;

        break;
    }
     case '0':   // up arrow
    {
         quadAngle += 5;

        break;
    }

    default:
        break;
    }
}

void specialKeyListener(int key, int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_DOWN: // down arrow
    {
        // quadAngle += 5;
        // printf("Quad Angle %f\n", quadAngle);
        pos.x+=2.12;
        pos.y+=2.12;
        break;
    }

    case GLUT_KEY_UP:   // up arrow
    {
        // quadAngle -= 5;
        //printf("Quad Angle %f\n", quadAngle);
        pos.x-=2.12;
        pos.y-=2.12;
        break;
    }

    case GLUT_KEY_RIGHT:    // right arrow
    {
        // boxAngle += 5;
        // printf("Box Angle %f\n", boxAngle);
        pos.x-=2.12;
        pos.y+=2.12;
        break;
    }

    case GLUT_KEY_LEFT:     // left arrow
    {
        //boxAngle -= 5;
        // printf("Box Angle %f\n", boxAngle);
        pos.x+=2.12;
        pos.y-=2.12;
        break;
    }

    case GLUT_KEY_PAGE_UP:
    {
        // boxScaleFactor += 0.2;
        pos.z+=3;
        break;
    }

    case GLUT_KEY_PAGE_DOWN:
    {
        // boxScaleFactor -= 0.2;
        pos.z-=3;
        break;
    }

    case GLUT_KEY_HOME:
    {
        boxScaleFactorX +=0.2;
        boxScaleFactorY +=0.2;
        boxScaleFactorZ +=0.2;
        break;
//        tyreAngle += 5;
//        break;

    }

    case GLUT_KEY_END:
    {
        boxScaleFactorX -=0.2;
        boxScaleFactorY -=0.2;
        boxScaleFactorZ -=0.2;
        break;
//        tyreAngle -= 5;
//        break;
    }

    default:
        break;
    }
}


void mouseListener(int button, int state, int x, int y) 	//x, y is the x-y of the screen (2D)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN) // 2 times?? in ONE click? -- solution is checking DOWN or UP
        {
            printf("Mouse Left Button Clicked\n");
        }
        else if(state == GLUT_UP)
        {
            printf("Mouse Left Button Released\n");
        }
        break;
    default:
        break;
    }
}

void displayTyre(float tyreRadius, float tyreWidth)
{
    int tyreSlices = 36;
    float sliceWidth = (2 * M_PI * tyreRadius) / tyreSlices;
    float sliceAngle = 360 / tyreSlices;

    float halfTyreWidth = tyreWidth / 2, quartTyreWidth = halfTyreWidth / 2;
    float halfSliceWidth = sliceWidth / 2;

    glPushMatrix();
    //glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);

    /*** Horizontal ***/
    glPushMatrix();
    glColor3f(1,1,1);
    // test color: glColor3f(0.25,0.5,0.749);

    glTranslatef(3, 0, 0);

    glBegin(GL_QUADS);
    {
        glVertex3f(halfTyreWidth/2, tyreRadius, 0);
        glVertex3f(-halfTyreWidth/2, tyreRadius, 0);
        glVertex3f(-halfTyreWidth/2, -tyreRadius, 0);
        glVertex3f(halfTyreWidth/2, -tyreRadius, 0);


    }
    glEnd();
    glPopMatrix();

    /*** Horizontal ***/
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-3, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(halfTyreWidth/2, tyreRadius, 0);
        glVertex3f(-halfTyreWidth/2, tyreRadius, 0);
        glVertex3f(-halfTyreWidth/2, -tyreRadius, 0);
        glVertex3f(halfTyreWidth/2, -tyreRadius, 0);


    }
    glEnd();
    glPopMatrix();

    /**** Vertical ****/
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(3, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(halfTyreWidth/2, 0, tyreRadius);
        glVertex3f(halfTyreWidth/2, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth/2, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth/2, 0, tyreRadius);
    }
    glEnd();
    glPopMatrix();

    /*** Vertical ***/
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-3, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(halfTyreWidth/2, 0, tyreRadius);
        glVertex3f(halfTyreWidth/2, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth/2, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth/2, 0, tyreRadius);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();


    for(int i=0; i<tyreSlices; i++)
    {
        glPushMatrix();
        glRotatef(sliceAngle*i, 1, 0, 0);
        glTranslatef(0, tyreRadius, 0);

        glBegin(GL_QUADS);
        {
            if(i%2==0)
            {
                glColor3f(1, 1, 1);
                glVertex3f(halfTyreWidth, 0, halfSliceWidth);
                glVertex3f(halfTyreWidth, 0, -halfSliceWidth);
                glVertex3f(-halfTyreWidth, 0, -halfSliceWidth);
                glVertex3f(-halfTyreWidth, 0, halfSliceWidth);
            }
            else
            {
                glColor3f(1, 0, 0);
                glVertex3f(halfTyreWidth, 0, halfSliceWidth);
                glVertex3f(halfTyreWidth, 0, -halfSliceWidth);
                glVertex3f(-halfTyreWidth, 0, -halfSliceWidth);
                glVertex3f(-halfTyreWidth, 0, halfSliceWidth);
            }

        }
        glEnd();
        glPopMatrix();
    }
}

void displayQuad(float quadLength, float quadWidth) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;

//    glBegin(GL_QUADS);
//    {
//        /** Solid Fill Quad **/
//
//        glColor3f(0, 0, 1);
//
//        glVertex3f(halfQuadWidth, 0, halfQuadLength);
//        glVertex3f(halfQuadWidth, 0, -halfQuadLength);
//        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
//        glVertex3f(-halfQuadWidth, 0, halfQuadLength);

    /** Gradient Fill Quad **/


//        glColor3f(1, 1, 0);
//
//        glVertex3f(halfQuadWidth, 0, halfQuadLength);
//        glVertex3f(halfQuadWidth, 0, -halfQuadLength);
//
//        glColor3f(0, 1, 1);
//
//        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
//        glVertex3f(-halfQuadWidth, 0, halfQuadLength);

//    }
//    glEnd();
}




void displayBIGBox(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 9;


    glBegin(GL_QUADS);
    {
        // car bottom box: 2 headlight plane color 51, 191, 191
        // convert to feed for opengl lib: 51/255=0.2, 191/255 = 0.749
        glColor3f(0.2, 0.749, 0.749);

        glVertex3f(halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);

        glVertex3f(halfBoxLength, -halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);

        // car sidebox above wheel: 64, 128, 191
        // convert to feed for opengl lib: 64/255 = 0.25, 128/255 = 0.502, 191/255 = 0.749
        glColor3f(0.25, 0.502, 0.749);

        glVertex3f(halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, halfBoxHeight);

        // car sidebox above wheel: 128, 64, 64
        // convert to feed for opengl lib: 128/255 = 0.502, 64/255 = 0.25, 64/255 = 0.25
        glColor3f(0.502, 0.25, 0.25);

        glVertex3f(halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, halfBoxHeight);
        // car tinny backplane: 64, 128, 0
        // convert to feed for opengl lib: 64/255 = 0.25, 128/255 = 0.502, 0
        glColor3f(0.25, 0.502, 0);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, halfBoxHeight);

        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
    }
    glEnd();
}

void displaySMALLBox(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength /1.5, halfBoxWidth = boxWidth /2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        // car upper bigbox: front glass color 181, 181, 255
        // convert to feed for opengl lib: 181/255 = 0.71, 1

        glColor3f(0.71, 0.71, 1);
        glVertex3f(halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glColor3f(1, 1, 1);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);  ///Gradiant color

        glColor3f(0, 1, 1);
        glVertex3f(halfBoxLength, -halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);


        // car bigbox: side glass color 71, 255, 255
        // convert to feed for opengl lib: 71/255 = 0.2784, 1
        glColor3f(0.2784, 1, 1);

        glVertex3f(halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*3, halfBoxHeight);


        glVertex3f(-halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*3, halfBoxHeight);

        // car bigbox: rooftop color 0, 6, 255
        // convert to feed for opengl lib: 0/255 = 0, 6/255 = 0.0235, 1
        glColor3f(0, 0.0235, 1);

        glVertex3f(halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*3, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*3, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*3, halfBoxHeight);


        glVertex3f(halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth*5, -halfBoxHeight);
    }
    glEnd();
}

void displayLIGHTBOX(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(1, 0, 0);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);

        glColor3f(1, 1, 1);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);


        glColor3f(1, 1, 1);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glColor3f(1, 1, 1);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
    }
    glEnd();
}

void displayLIGHTSTAND(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(0, 0, 1.0);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);


        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);


        glColor3f(0, 1.0, 0);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);

    }
    glEnd();
}



void displayScene()
{
    //Primitive Object dimensions
    float quadLength = 100, quadWidth = 60;
    float largeBoxLength = 200, largeBoxWidth = 100, largeBoxHeight = 100;
    float smallBoxLength = 150, smallBoxWidth = 70, smallBoxHeight = 50;
    float tinyBoxLength = 10, tinyBoxWidth = 10, tinyBoxHeight = 10;
    float tyreRadius = 35, tyreWidth = 10;
    float lightstandLength = 20, lightstandWidth = 20, lightstandHeight = 70;
    float lightboxLength = 40, lightboxWidth = 40, lightboxHeight = 40;

    /**** Principal Axes ****/
    displayAxes();



//    glRotatef(quadAngle, 1, 0, 0); // rotates with respect to x axis
//    glRotatef(quadAngle, 0, 1, 0); // rotates with respect to y axis
//    glRotatef(quadAngle, 0, 0, 1); // rotates with respect to z axis

//    glPushMatrix();
//


    glTranslatef(0, 0, 25);

    /**** CAR TYRE ****/
    glPushMatrix();
    glTranslatef(90, 170, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90, -170, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90, 170, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-90, -170, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, (tyreRadius/2.5)+(largeBoxHeight/2.5));





    /**** CAR BODY ****/
    displayBIGBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/5) + (largeBoxHeight/5)); // places the small box on top of the large box
    displaySMALLBox(smallBoxLength, smallBoxWidth, smallBoxHeight);
    glPopMatrix();


    /**** LIGHT BOX ****/
    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/5) + (largeBoxHeight/5)+(lightboxHeight/2) + (lightstandHeight/2));
    displayLIGHTSTAND(lightstandLength, lightstandWidth, lightstandHeight);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, (lightboxHeight/2) + (lightstandHeight/2)+(smallBoxHeight/5) + (largeBoxHeight/5)+(lightboxHeight/2) + (lightstandHeight/2));
    //glTranslatef(0, 0, (lightboxHeight/2) + (lightstandHeight/2));
    glRotatef(quadAngle, 0, 0, 1);
    displayLIGHTBOX(lightboxLength, lightboxWidth, lightboxHeight);

    // start: lamia's code
    glPushMatrix();
    displayRay(30,450);
    glPopMatrix();
    // end: lamia's code

    glPopMatrix();
    glPopMatrix();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(background, background, background,0);	//sets background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // sets the current matrix to identity
    gluLookAt(pos.x, pos.y, pos.z, pos.x+l.x, pos.y+l.y, pos.z+l.z, u.x, u.y, u.z); // sets camera position and direction

    displayScene();

    glutSwapBuffers();
}



void animate()
{
    tinyBoxAngle += 0.05;
    glutPostRedisplay();
}

void init()
{
    glClearColor(background, background, background,0); 	//sets background color

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity(); // sets the current matrix to identity
    gluPerspective(80,	1,	1,	1000.0);

    // to understand the following values, read the specification pdf
    double d = 1 / sqrt2;
    pos = {300, 300, 150};
    u = {0, 0, 1};
    r = {-d, d, 0};
    l = {-d, -d, 0};
}

void subMenu(int id)
{
    if(id == 3)
    {
        background = 1;
    }
    else if(id == 4)
    {
        background = 0;
    }
}

void mainMenu(int id)
{
    if(id == 1)
    {
        drawAxes = true;
    }
    else if(id == 2)
    {
        drawAxes = false;
    }

}


int main(int argc, char **argv)
{

    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color
    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    int subMenuNo = glutCreateMenu(subMenu);
    glutAddMenuEntry("White", 3);
    glutAddMenuEntry("Black", 4);

    glutCreateMenu(mainMenu);
    glutAddMenuEntry("Axes On", 1);
    glutAddMenuEntry("Axes Off", 2);
    glutAddSubMenu("Background", subMenuNo);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutMainLoop();		//The main loop of OpenGL, this function never returns

    return 0;
}
