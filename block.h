
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
    float x;
    float y;
    float z;
    float angle;
}Floor;

extern Floor FLOOR[105];

typedef struct Block{
    VAO* block;
    float x;
    float y;
    float z;
    float angle;
    int horizontal_x;
    int horizontal_z;
    glm::vec3 axis;
}Block;

extern Block BLOCK;

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);

void createBlock ();

extern float BLOCK_WIDTH;
extern float BLOCK_HEIGHT;