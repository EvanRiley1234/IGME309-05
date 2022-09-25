#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif
#include<math.h>

void keyboard(unsigned char key, int x, int y);

// the window's width and height
int width, height;

//number of circle vertices
int cVerts = 30;

void DrawFrameCircle(float red, float green, float blue, float cx, float cy, float r, float lineWidth)
{
    glColor3f(red, green, blue);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < cVerts; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(cVerts);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void DrawFilledCircle(float red, float green, float blue, float cx, float cy, float r)
{
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < cVerts; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(cVerts);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //draw the circle
    //body circle
    DrawFilledCircle(0.5f, 0.2f, 0.0f, 5, 4.1, 2.1);
    //body circle 2
    DrawFilledCircle(1, 1, 1, 5, 3.7, 1.5);
    //head circle
    DrawFrameCircle(0.0, 0.0, 0.0, 5, 7.5, 1.4, 1.0);
    //eye circles
    DrawFilledCircle(0.0, 0.0, 0.0, 4.3, 7.5, 0.4);
    DrawFilledCircle(0.0, 0.0, 0.0, 5.7, 7.5, 0.4);
    //ear circles
    DrawFilledCircle(0.0, 0.0, 0.0, 3.8, 9.1, 0.6);
    DrawFilledCircle(0.0, 0.0, 0.0, 6.2, 9.1, 0.6);
    //feet circles
    DrawFilledCircle(0.0, 0.0, 0.0, 3.5, 1.8, 0.8);
    DrawFilledCircle(0.0, 0.0, 0.0, 6.5, 1.8, 0.8);
    //hand circles
    DrawFilledCircle(0.0, 0.0, 0.0, 3.3, 6.2, 0.7);
    DrawFilledCircle(1, 1, 1, 3.3, 6.2, 0.4);
    DrawFilledCircle(0.0, 0.0, 0.0, 6.7, 6.2, 0.7);
    DrawFilledCircle(1, 1, 1, 6.7, 6.2, 0.4);
    //finger circles
    DrawFrameCircle(0.0, 0.0, 0.0, 3.4, 7, 0.2, 1.0);
    DrawFrameCircle(0.0, 0.0, 0.0, 6.6, 7, 0.2, 1.0);
    DrawFrameCircle(0.0, 0.0, 0.0, 2.7, 6.8, 0.2, 1.0);
    DrawFrameCircle(0.0, 0.0, 0.0, 7.3, 6.8, 0.2, 1.0);
    DrawFrameCircle(0.0, 0.0, 0.0, 2.5, 6.2, 0.2, 1.0);
    DrawFrameCircle(0.0, 0.0, 0.0, 7.5, 6.2, 0.2, 1.0);
    
    glutSwapBuffers();
    glutKeyboardFunc(keyboard);
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
    // update thescreen dimensions
    width = w;
    height = h;

    //do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    //glViewport((GLsizei) width/2, (GLsizei) height/2, (GLsizei) width, (GLsizei) height);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == '=' && cVerts < 100)
    {
        cVerts++;
    }
    else if (key == '-' && cVerts > 3)
    {
        cVerts--;
    }
    else if (key == 27)
    {
        exit(0);
    }
}

int main(int argc, char* argv[])
{
    // before create a glut window,
    // initialize stuff not opengl/glut dependent
    init();

    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    //set the initial window size */
    glutInitWindowSize((int)width, (int)height);

    // create the window with a title
    glutCreateWindow("First OpenGL Program");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    glutIdleFunc(display);
    //start the glut main loop
    glutMainLoop();

    return 0;
}