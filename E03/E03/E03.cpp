#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif
#include<math.h>

void keyboard(unsigned char key, int x, int y);

// the window's width and height
int width, height;

// the three vertices of a triangle
float v0[2];
float v1[2];
float v2[2];

//number of circle vertices
int cVerts = 30;


void createTriangle()
{
    // initialize the triangle's vertices
    v0[0] = 0.0f;
    v0[1] = 0.0f;
    v1[0] = 5.0f;
    v1[1] = 0.0f;
    v2[0] = 2.5f;
    v2[1] = 3.0f;
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

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
    createTriangle();
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

    // specify the color for drawing
    glColor3f(1.0, 0.0, 0.0);

    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    /*
    glBegin(GL_TRIANGLES);
    glVertex2fv(v0);
    glVertex2fv(v1);
    glVertex2fv(v2);
    glEnd();
    */
    
    //draw the circle
    DrawCircle(5, 5, 3, cVerts);
    /*
    // specify the color for new drawing
    glColor3f(0.0, 0.0, 1.0);

    // draw the origin of the canvas
    glPointSize(30.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
    glPointSize(1.0f);
    */
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
    if (key == '=' && cVerts<100)
    {
        cVerts++;
    }
    else if (key == '-' && cVerts>3)
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