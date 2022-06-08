[week13 Blogger](https://2022graphicsb.blogspot.com/2022/05/6z0-week13.html)

## rect_TRT
```cpp
#include <GL/glut.h>
float angle = 45, oldX=0;
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1, 1, 1);
    glRectf(0.5, 0.5, -0.5, -0.5);
    glPushMatrix();
        glTranslatef( 0.5, 0.5, 0);
        glRotatef( angle, 0, 0, 1);
        glTranslatef( -0.5, -0.4, 0);
        glColor3f(1,0,0);
        glRectf(0.5, 0.5, 1.0, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13ªºµøµ¡");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```

## rect_TRT_TRT
```cpp
#include <GL/glut.h>
float angle = 0, oldX=0;
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);
    glPushMatrix();
        glTranslatef( 0.3, 0.5, 0);
        //glRotatef( angle, 0, 0, 1);
        glTranslatef( -0.3, -0.4, 0);
        glColor3f(1,0,0);
        glRectf(0.3, 0.5, 0.8 , 0.3);
        glPushMatrix();
            glTranslatef( 0.8, 0.4, 0);
            glRotatef( angle, 0, 0, 1);
            glTranslatef( -0.8, -0.4, 0);
            glColor3f(0,1,0);
            glRectf(0.8, 0.5, 1.1, 0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13ªºµøµ¡");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```

## rect_many_TRT
```cpp
#include <GL/glut.h>
float angle[20], oldX=0;
int angleID=0;
void keyboard( unsigned char key , int x, int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{
    angle[angleID]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f( 1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);
    glPushMatrix();
        glTranslatef( 0.3, 0.5, 0);
        glRotatef( angle[0], 0, 0, 1);
        glTranslatef( -0.3, -0.4, 0);
        glColor3f(1,0,0);
        glRectf(0.3, 0.5, 0.8 , 0.3);
        glPushMatrix();
            glTranslatef( 0.8, 0.4, 0);
            glRotatef( angle[1], 0, 0, 1);
            glTranslatef( -0.8, -0.4, 0);
            glColor3f(0,1,0);
            glRectf(0.8, 0.5, 1.1, 0.3);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef( -0.3, 0.5, 0);
        glRotatef( angle[2], 0, 0, 1);
        glTranslatef( +0.3, -0.4, 0);
        glColor3f(1,0,0);
        glRectf(-0.3, 0.5, -0.8 , 0.3);
        glPushMatrix();
            glTranslatef( -0.8, 0.4, 0);
            glRotatef( angle[3], 0, 0, 1);
            glTranslatef( +0.8, -0.4, 0);
            glColor3f(0,1,0);
            glRectf(-0.8, 0.5, -1.1, 0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13ªºµøµ¡");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}
```
