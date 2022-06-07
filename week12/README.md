[week12 Blogger](https://2022graphicsb.blogspot.com/2022/05/blog-post.html)
## TRT
```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef( angle, 0, 0, 1);
        glTranslatef( 0.4, -0.07, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12ªºµøµ¡");
    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();

}
```

## TRT_TRT
```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);
    glPushMatrix();
        glTranslatef(0.3,0,0);
        glRotatef( angle, 0, 0, 1);
        glTranslatef( 0.2, 0, 0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef( angle, 0, 0, 1);
            glTranslatef( 0.2, 0, 0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=1.6;
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12ŞşľřľĄ");
    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();

}
```
