
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
    float x;
    float y;
    float z;
    float angle;
}Floor;

extern Floor FLOOR[105];

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);

void createRectangle ();
void createCam ();
void createFloor();

extern VAO *rectangle, *cam, *floor_vao;
extern float TILE_WIDTH;
extern float TILE_HEIGHT;
