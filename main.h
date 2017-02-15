
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

typedef struct Floor{
    VAO* floor;
    int index;
    int flag;
    int goal;
    int fragile;
    int key;
    float x;
    float y;
    float z;
    float angle;
}Floor;

Floor FLOOR[105];

typedef struct Block{
    VAO* block;
    float x;
    float y;
    float z;
    float angle;
    float angle_x;
    float angle_incr;
    float angle_incr_x;
    float trans_incr;
    int horizontal_z;
    int horizontal_x;
    glm::vec3 axis;
    glm::vec3 axis_x;
}Block;

Block BLOCK;

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    GLuint MatrixID;
} Matrices;

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);
void level1();
void level2();
void gameOver();
void restart();
void createCam();
void createFloor();
void createRectangle();
void createBlock();


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);
void draw3DObject (struct VAO* vao);

int do_rot, floor_rel;
GLuint programID;
double last_update_time, current_time;
glm::vec3 rect_pos, floor_pos;
float rectangle_rotation = 15;

float rectangle_rot_dir = 1;
bool rectangle_rot_status = true;

VAO *rectangle, *cam, *floor_vao;

float camera_rotation_angle = 0;
float TILE_WIDTH = 1.0;
float TILE_HEIGHT = 0.5;
float BLOCK_WIDTH = TILE_WIDTH;
float BLOCK_HEIGHT = 2.0;

glm::vec3 up;
glm::vec3 target;
glm::vec3 eye;

glm::vec3 TOWER_VIEW_EYE = glm::vec3(-3, 14, -2); 
glm::vec3 TOWER_VIEW_TARGET = glm::vec3(8,0,8); 
glm::vec3 TOWER_VIEW_UP = glm::vec3(1,3,1);

//glm::vec3 TOWER_VIEW_UP = glm::cross(TOWER_VIEW_EYE,TOWER_VIEW_TARGET);

glm::vec3 TOP_VIEW_EYE = glm::vec3(9,15,4); 
glm::vec3 TOP_VIEW_TARGET = glm::vec3(9,0,4); 
glm::vec3 TOP_VIEW_UP = glm::vec3(1,0,1);

//glm::vec3 TOP_VIEW_UP = glm::cross(TOP_VIEW_EYE,TOP_VIEW_TARGET);

int FOLLOW_VIEW_FLAG = 0;
int BLOCK_VIEW_FLAG = 0;
int TOWER_VIEW_FLAG = 1;
int FLAG_LEFT = 0;
int FLAG_DOWN = 0;

float ROTATION_SPEED = 6.0f;

GLFWwindow* window;

int LEVEL = 1;
int MOVES = 0;
float HELI_VIEW_SPEED = 0.3f;

double posx = 0.0;
double posy = 0.0;
double posz = 0.0;
int DRAG_STATUS = 0;

int AVA_TIME = 90;
int TIME = AVA_TIME;