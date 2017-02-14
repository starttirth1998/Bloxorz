#include "header.h"
#include "init.h"

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        switch (key) {
	case GLFW_KEY_C:
	    rectangle_rot_status = !rectangle_rot_status;
	    break;
	case GLFW_KEY_P:
	    break;
	case GLFW_KEY_X:
	    // do something ..
	    break;
	default:
	    break;
        }
    }
    else if (action == GLFW_PRESS) {
        switch (key) {
	case GLFW_KEY_ESCAPE:
	    quit(window);
	    break;
    case GLFW_KEY_RIGHT:
        if(FLAG_LEFT == 0 && FLAG_DOWN == 0)
        {
            MOVES++;
            FLAG_LEFT = -1;
            if(BLOCK.horizontal_x == 0)
            {
                if(BLOCK.horizontal_z == 0)
                {
                    BLOCK.axis = glm::vec3 (1,0,0);
                    BLOCK.angle_incr = ROTATION_SPEED;
                }
                else
                {
                    BLOCK.z += 2*BLOCK_WIDTH;                    
                    BLOCK.axis = glm::vec3 (1,0,0);
                    BLOCK.angle_incr = ROTATION_SPEED;
                }
            }
            else if(BLOCK.horizontal_x == 1)
            {
                BLOCK.axis = glm::vec3(0,1,0);
                BLOCK.angle_incr = ROTATION_SPEED;
            }
        }
        break;
    case GLFW_KEY_LEFT:
        if(FLAG_LEFT == 0 && FLAG_DOWN == 0)
        {
            MOVES++;
            FLAG_LEFT = 1;
            if(BLOCK.horizontal_x == 0)
            {
                BLOCK.axis = glm::vec3 (1,0,0);
                BLOCK.angle_incr = -ROTATION_SPEED;
            }
            else if(BLOCK.horizontal_x == 1)
            {
                BLOCK.axis = glm::vec3(0,1,0);
                BLOCK.angle_incr = ROTATION_SPEED;
            }
        }
        break;
    case GLFW_KEY_UP:
        if(FLAG_DOWN == 0 && FLAG_LEFT == 0)
        {
            MOVES++;
            FLAG_DOWN = -1;
            //cout << "HZ: " << BLOCK.horizontal_z << " HX : " << BLOCK.horizontal_x << endl;
            if(BLOCK.horizontal_z == 0)
            {
                BLOCK.axis_x = glm::vec3 (0,0,1);
                BLOCK.angle_incr_x = -ROTATION_SPEED;
            }
            else if(BLOCK.horizontal_z == 1)
            {
                BLOCK.axis = glm::vec3 (0,1,0);
                BLOCK.angle_incr_x = ROTATION_SPEED;
            }
        }
        break;
    case GLFW_KEY_DOWN:
        if(FLAG_DOWN == 0 && FLAG_LEFT == 0)
        {
            MOVES++;
            FLAG_DOWN = 1;
            if(BLOCK.horizontal_z == 0)
            {
                if(BLOCK.horizontal_x == 0)
                {   
                    BLOCK.axis_x = glm::vec3 (0,0,1);
                    BLOCK.angle_incr_x = ROTATION_SPEED;
                }
                else
                {
                    BLOCK.axis_x = glm::vec3 (0,0,1);
                    BLOCK.angle_incr_x = -ROTATION_SPEED;
                }
            }
            else if(BLOCK.horizontal_z == 1)
            {
                BLOCK.axis = glm::vec3 (0,1,0);
                BLOCK.angle_incr_x = ROTATION_SPEED;
            }
        }
        break;
	default:
	    break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
    switch (key) {
    case 'Q':
    case 'q':
	quit(window);
	break;
    case 'b':
    BLOCK_VIEW_FLAG = 1;
    FOLLOW_VIEW_FLAG = 0;
    break;
    case 'f':
	FOLLOW_VIEW_FLAG = 1;
    BLOCK_VIEW_FLAG = 0;
	break;
    case 't':
    TOWER_VIEW_FLAG = 1;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye = TOWER_VIEW_EYE;
    target = TOWER_VIEW_TARGET;
    up = TOWER_VIEW_UP;
    break;
    case 'v':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye = TOP_VIEW_EYE;
    target = TOP_VIEW_TARGET;
    up = TOP_VIEW_UP;
    break;
    case 'w':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(0,0.1,0);
    //up = eye*target;
    break;
    case 'x':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(0,-0.1,0);
    //up = eye*target;
    break;
    case 'a':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(-0.1,0,0);
    //up = eye*target;
    break;
    case 'd':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(0.1,0,0);
    //up = eye*target;
    break;
    case 's':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(0,0,0.1);
    //up = eye*target;
    break;
    case 'z':
    TOWER_VIEW_FLAG = 0;
    FOLLOW_VIEW_FLAG = 0;
    BLOCK_VIEW_FLAG = 0;
    eye += glm::vec3(0,0,-0.1);
    //up = eye*target;
    break;
    default:
	break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
    case GLFW_MOUSE_BUTTON_RIGHT:
	if (action == GLFW_RELEASE) {
	    rectangle_rot_dir *= -1;
	}
	break;
    default:
	break;
    }
}


/* Executed when window is resized to 'width' and 'height' */
/* Modify the bounds of the screen here in glm::ortho or Field of View in glm::Perspective */
void reshapeWindow (GLFWwindow* window, int width, int height)
{
    int fbwidth=width, fbheight=height;
    glfwGetFramebufferSize(window, &fbwidth, &fbheight);

    GLfloat fov = M_PI/2;

    // sets the viewport of openGL renderer
    glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

    // Store the projection matrix in a variable for future use
    // Perspective projection for 3D views
    Matrices.projection = glm::perspective(fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1f, 500.0f);

    // Ortho projection for 2D views
    //Matrices.projection = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f, 0.1f, 500.0f);
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void quit(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

/* Initialise glfw window, I/O callbacks and the renderer to use */
/* Nothing to Edit here */
GLFWwindow* initGLFW (int width, int height){
    GLFWwindow* window; // window desciptor/handle

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Sample OpenGL 3.3 Application", NULL, NULL);

    if (!window) {
	exit(EXIT_FAILURE);
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval( 1 );
    glfwSetFramebufferSizeCallback(window, reshapeWindow);
    glfwSetWindowSizeCallback(window, reshapeWindow);
    glfwSetWindowCloseCallback(window, quit);
    glfwSetKeyCallback(window, keyboard);      // general keyboard input
    glfwSetCharCallback(window, keyboardChar);  // simpler specific character handling
    glfwSetMouseButtonCallback(window, mouseButton);  // mouse button clicks

    return window;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL (GLFWwindow* window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    createRectangle ();
    createCam();
    createFloor();
    createBlock();
	
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

	
    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (0.8f, 0.2f, 0.1f, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    // cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    // cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    // cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    // cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

