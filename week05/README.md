## rotate
```cpp
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(180, 0 ,0 ,1);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05ªºµøµ¡");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
```

## mouseRotate
```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef( angle, 0 ,0 ,1);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05ªºµøµ¡");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
```

## mouse_motion_rotate
```cpp
#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef( angle, 0 ,0 ,1);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int buttnon, int state, int x, int y)
{
    oldX = x;
}
void motion(int x, int y)
{
    angle += (x-oldX);
    oldX = x;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05ªºµøµ¡");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
```

## mouse
```cpp
#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[1000], y[1000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int  i=0; i<N; i++)
    {
            glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0 );
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int buttnon, int state, int mouseX, int mouseY)
{
    if(state==GLUT_DOWN)
    {
        N++;
        x[N-1]=mouseX;
        y[N-1]=mouseY;
        printf("現在按下滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1]);
    }
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05的視窗");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
```

## motion
```cpp
#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[1000], y[1000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int  i=0; i<N; i++)
    {
            glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0 );
    }
    glEnd();
    glutSwapBuffers();
}
void motion(int mouseX, int mouseY)
{
    N++;
    x[N-1]=mouseX;
    y[N-1]=mouseY;
    printf("現在按住滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1]);
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05的視窗");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
```
