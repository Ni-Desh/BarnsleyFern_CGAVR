#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Initial values for x and y coordinates
float x = 0.0, y = 0.0;

// Function to draw the Barnsley Fern
void drawFern() {
    float nextX, nextY;
    int i;

    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glBegin(GL_POINTS); // Begin drawing points

    // Iterating to generate the fern pattern
    for (i = 0; i < 100000; i++) {
        float r = (float)rand() / RAND_MAX;

        if (r < 0.01) {
            nextX = 0.0;
            nextY = 0.16 * y;
        } else if (r < 0.86) {
            nextX = 0.85 * x + 0.04 * y;
            nextY = -0.04 * x + 0.85 * y + 1.6;
        } else if (r < 0.93) {
            nextX = 0.20 * x - 0.26 * y;
            nextY = 0.23 * x + 0.22 * y + 1.6;
        } else {
            nextX = -0.15 * x + 0.28 * y;
            nextY = 0.26 * x + 0.24 * y + 0.44;
        }

        // Update the current position
        x = nextX;
        y = nextY;

        // Plot the point
        glVertex2f(x, y);
    }

    glEnd(); // End drawing points
    glFlush(); // Force the OpenGL commands to be executed
}

// Function to initialize OpenGL
void init() {
    glClearColor(0, 0, 0, 1); // Set the background color (black)
    glColor3f(0.0, 1.0, 0.0); // Set the drawing color (green for the fern)
    gluOrtho2D(-2.5, 2.5, 0.0, 10.0); // Define 2D orthographic projection
}

// Main function to set up OpenGL and start the rendering loop
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitWindowSize(600, 800); // Set the window size
    glutCreateWindow("Barnsley Fern - OpenGL"); // Create the window
    init(); // Call the init function
    glutDisplayFunc(drawFern); // Register the drawing function
    glutMainLoop(); // Enter the GLUT main loop
    return 0;
}

