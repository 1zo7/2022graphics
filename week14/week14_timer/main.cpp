#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){ ///t ��쬰ms 1000�N��1��
    printf("�x��%d, �ڰ_�ɤF\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);
    glutTimerFunc( 1000, timer, t+1);
    printf("�]�n�x���A�A�^�h��\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(3000, timer, 0); ///3���A�stimer()
    glutDisplayFunc(display);
    glutMainLoop();
}
