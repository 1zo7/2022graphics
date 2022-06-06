[week06 Blogger](https://2022graphicsb.blogspot.com/2022/03/6z0-week06.html)

## keyboard
```cpp
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y)
{
    printf("現在按下一個鍵:%c 座標在:%d %d\n", key, x, y);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06的視窗");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
```


## keyboard_mouse_motion
```cpp
#include <GL/glut.h>
#include <stdio.h>
float x=250, y=250, z=0, oldX, oldY, scale=1.0, angle=0.0;
int now=1;
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-250)/250.0, -(y-250)/250.0, z);
        glRotatef(angle, 0, 0, 1);
        glScalef( scale, scale, scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY)
{
    if(key=='w'||key=='W') now=1;
    if(key=='e'||key=='E') now=2;
    if(key=='r'||key=='R') now=3;
}
void mouse( int button, int state, int mouseX, int mouseY)
{
    oldX = mouseX; oldY = mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now==1)
    {
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }
    else if(now==2)
    {
        angle += (mouseX-oldX);
    }
    else if(now==3)
    {
        if(mouseX>oldX) scale=scale*1.01;
        if(mouseX<oldX) scale=scale*0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week06ªºµøµ¡");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
```
