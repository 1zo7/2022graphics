[week14 Blogger](https://2022graphicsb.blogspot.com/2022/05/weeh14.html)

## 
```cpp
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");
    printf("Hello World\n");
    fprintf(fout, "Hello World\n");
    fclose(fout);
}
```


## fscanf
```cpp
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout, "angle1 %d\n", 999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line , &a);
    printf("Åª¨ì¤F¦r¦ê:%s ¤Î¾ã¼Æ%d\n", line, a);
    fclose(fin);
}

```

## angle_write
```cpp
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;///0:第0個關節，1:第一個關節，2:第二個關節
FILE * fout = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.2f", angle[i]);
        fprintf(fout, "%.2f ", angle[i] );
    }
    printf("\n");
    fprintf(fout,"\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0')angleID=0;///預設這是第一個
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button, int state , int x, int y)///mouse按下去
{
    oldX = x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.2);///身體,瘦身
    glPushMatrix();///右半邊，掛的位置也改了
        glTranslatef(0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[0],0,0,1);///(2)旋轉
        glTranslatef(-0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.8,0.3);///右上手臂
        glPushMatrix();
        glTranslatef(0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[1],0,0,1);///(2)旋轉
        glTranslatef(-0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(0.8,0.5,1.1,0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊，掛的位置也改了
        glTranslatef(-0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[2],0,0,1);///(2)旋轉
        glTranslatef(+0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.8,0.3);///左上手臂
        glPushMatrix();
        glTranslatef(-0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[3],0,0,1);///(2)旋轉
        glTranslatef(+0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## TRT_angle_write_and_read
```cpp
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;///0:第0個關節，1:第一個關節，2:第二個關節
FILE * fout = NULL, *fin = NULL;
void myWrite(){
    if(fout!=NULL)
    {
        fclose(fout);
        fin=NULL;
    }
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.2f", angle[i]);
        fprintf(fout, "%.2f ", angle[i] );
    }
    printf("\n");
    fprintf(fout,"\n");
}
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout);
        fout=NULL;
    }
    if(fin=NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++)
    {
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0')angleID=0;///預設這是第一個
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
    if(key=='r')
    {
        myRead();
    }
}
void mouse(int button, int state , int x, int y)///mouse按下去
{
    oldX = x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.2);///身體,瘦身
    glPushMatrix();///右半邊，掛的位置也改了
        glTranslatef(0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[0],0,0,1);///(2)旋轉
        glTranslatef(-0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.8,0.3);///右上手臂
        glPushMatrix();
        glTranslatef(0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[1],0,0,1);///(2)旋轉
        glTranslatef(-0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(0.8,0.5,1.1,0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊，掛的位置也改了
        glTranslatef(-0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[2],0,0,1);///(2)旋轉
        glTranslatef(+0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.8,0.3);///左上手臂
        glPushMatrix();
        glTranslatef(-0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[3],0,0,1);///(2)旋轉
        glTranslatef(+0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## timer
```cpp
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){ ///t 單位為ms 1000代表1秒
    printf("鬧鐘%d, 我起床了\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);
    glutTimerFunc( 1000, timer, t+1);
    printf("設好鬧鐘，再回去睡\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_timer");

    glutTimerFunc(3000, timer, 0); ///3秒後，叫timer()
    glutDisplayFunc(display);
    glutMainLoop();
}
```
