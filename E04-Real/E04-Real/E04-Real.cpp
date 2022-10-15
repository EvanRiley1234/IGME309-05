#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif


// the window's width and height
int width, height;

void init(void)
{
    // initialize the size of the window
    width = 1200;
    height = 600;
}

void DrawGrid(int GridNum)
{
    glBegin(GL_LINES);
    

    for (int i = -GridNum; i <= GridNum; i++)
    {
        if(i == 0)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((float)i, 0, (float)-GridNum);
            glVertex3f((float)i, 0, (float)GridNum);

            glVertex3f((float)-GridNum, 0, (float)i);
            glVertex3f((float)GridNum, 0, (float)i);
        }
        else
        {
            glColor3f(0.75f, 0.75f, 0.75f);
            glVertex3f((float)i, 0, (float)-GridNum);
            glVertex3f((float)i, 0, (float)GridNum);

            glVertex3f((float)-GridNum, 0, (float)i);
            glVertex3f((float)GridNum, 0, (float)i);
        }
        
    }
    glEnd();
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);

    // specify the color for new drawing
    glColor3f(0.0, 0.0, 1.0);

    // draw the origin of the canvas
    glPointSize(30.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glPointSize(1.0f);

    // specify the color for new drawing
    glColor3f(0.0, 0.0, 0.0);

    //draw the grid
    DrawGrid(12);

    glutSwapBuffers();
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
    // update thescreen dimensions
    width = w;
    height = h;

    //do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(20, 20, -20, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(45, w / h, 0.1, 1000);
    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
;
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

    //start the glut main loop
    glutMainLoop();

    return 0;
}

