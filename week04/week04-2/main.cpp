#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    printf("%d %d %d %d\n", button, state, x, y);
}

int main (int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04-2");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
