#include "header.h"
#include "main.h"

/**************************
 * Customizable functions *
 **************************/


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw (GLFWwindow* window, float x, float y, float w, float h, int doM, int doV, int doP)
{
    int fbwidth, fbheight;
    glfwGetFramebufferSize(window, &fbwidth, &fbheight);
    glViewport((int)(x*fbwidth), (int)(y*fbheight), (int)(w*fbwidth), (int)(h*fbheight));


    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram(programID);


    // Compute Camera matrix (view)
    if(doV)
	Matrices.view = glm::lookAt(eye, target, up); // Fixed camera for 2D (ortho) in XY plane
    else
	Matrices.view = glm::mat4(1.0f);

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    glm::mat4 VP;
    if (doP)
	VP = Matrices.projection * Matrices.view;
    else
	VP = Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    
    for(int i=0;i<100;i++)
    {
        glm::mat4 MVP;	// MVP = Projection * View * Model

        // Load identity to model matrix
        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translateRectangle = glm::translate (glm::vec3(FLOOR[i].x,FLOOR[i].y,FLOOR[i].z));
        glm::mat4 rotateRectangle = glm::rotate((float)(FLOOR[i].angle*M_PI/180.0f), glm::vec3(0,0,1));
        Matrices.model *= (translateRectangle * rotateRectangle);
        if(floor_rel)
            Matrices.model = Matrices.model * glm::translate(floor_pos);
        if(doM)
            MVP = VP * Matrices.model;
        else
            MVP = VP;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // draw3DObject draws the VAO given to it using current MVP matrix
        draw3DObject(FLOOR[i].floor);
    }
    

    //cout << "X: " << rect_pos.x << " Y: " << rect_pos.y << " Z: " << rect_pos.z << " Angle: " << rectangle_rotation << endl;

    
    glm::mat4 MVP;	// MVP = Projection * View * Model
    
    BLOCK.angle += BLOCK.angle_incr;
    BLOCK.angle_x += BLOCK.angle_incr_x;
    
    
    // Load identity to model matrix
    Matrices.model = glm::mat4(1.0f);

    if(BLOCK.horizontal_x == 0 && BLOCK.horizontal_z == 0)
    {
        //cout << " X: " << BLOCK.x << " Y: " << BLOCK.y << " Z: " << BLOCK.z << endl;
        glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
        glm::mat4 rotateBlock = glm::rotate((float)((0)*M_PI/180.0f), glm::vec3(1,0,0));
        Matrices.model *= (translateBlock * rotateBlock);
    }

    else if(BLOCK.horizontal_x == 1 && BLOCK.horizontal_z == 0)
    {
        glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
        glm::mat4 rotateBlock = glm::rotate((float)((90)*M_PI/180.0f), glm::vec3(0,0,1));
        Matrices.model *= (translateBlock * rotateBlock);
    }

    else if(BLOCK.horizontal_x == 0 && BLOCK.horizontal_z == 1)
    {
        glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
        glm::mat4 rotateBlock = glm::rotate((float)((90)*M_PI/180.0f), glm::vec3(1,0,0));
        Matrices.model *= (translateBlock * rotateBlock);
    }

    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);


    if(FLAG_LEFT == -1)
    {
        if(BLOCK.horizontal_x == 0)
        {
            if(BLOCK.horizontal_z == 0)
            {       
                Matrices.model = glm::mat4(1.0f);

                glm::mat4 translateBlockToOrigin = glm::translate(glm::vec3(0,-BLOCK_HEIGHT,BLOCK_WIDTH));
                glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock = glm::rotate((float)((BLOCK.angle)*M_PI/180.0f), BLOCK.axis);
                glm::mat4 translateFromOrigin = glm::translate(glm::vec3(0,BLOCK_HEIGHT,-BLOCK_WIDTH));
                Matrices.model *= (translateBlockToOrigin * translateBlock *  rotateBlock * translateFromOrigin);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle >= 90)
                {
                    BLOCK.angle = 90;
                    BLOCK.angle_incr = 0;
                    FLAG_LEFT = 0;
                    BLOCK.horizontal_z = 1;
                    BLOCK.y += -BLOCK_WIDTH;
                    BLOCK.z += BLOCK_HEIGHT + BLOCK_WIDTH;
                    //BLOCK.axis = glm::vec3(1,0,0);
                }
            }
            else
            {
                Matrices.model = glm::mat4(1.0f);

                glm::mat4 translateBlockToOrigin = glm::translate(glm::vec3(BLOCK.x,BLOCK.y-BLOCK_HEIGHT,BLOCK.z+BLOCK_WIDTH));
                //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock = glm::rotate((float)((90)*M_PI/180.0f), BLOCK.axis);
                glm::mat4 translateFromOrigin = glm::translate(glm::vec3(0,BLOCK_HEIGHT,-BLOCK_WIDTH));
                Matrices.model *= (translateBlockToOrigin * rotateBlock);


                glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(0,-BLOCK_HEIGHT+BLOCK_WIDTH,-BLOCK_WIDTH));
                //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock2 = glm::rotate((float)((BLOCK.angle+90)*M_PI/180.0f), BLOCK.axis);
                glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(0,BLOCK_HEIGHT,BLOCK_WIDTH));
                Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle >= 180)
                {
                    BLOCK.angle = 0;
                    BLOCK.angle_incr = 0;
                    FLAG_LEFT = 0;
                    BLOCK.horizontal_z = 0;
                    BLOCK.y += BLOCK_HEIGHT-BLOCK_WIDTH;
                    BLOCK.z += BLOCK_WIDTH;
                    //BLOCK.axis = glm::vec3(0,1,0);
                }
            }
        }
        else if(BLOCK.horizontal_x == 1)
        {
            glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,0,BLOCK_WIDTH));
            //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
            glm::mat4 rotateBlock2 = glm::rotate((float)((-BLOCK.angle)*M_PI/180.0f), BLOCK.axis);
            glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,0,-BLOCK_WIDTH));
            Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
            MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
            if(BLOCK.angle >= 90)
            {
                BLOCK.angle = 0;
                BLOCK.angle_incr = 0;
                FLAG_LEFT = 0;
                //BLOCK.horizontal_z = 0;
                BLOCK.y += 0;
                BLOCK.z += 2*BLOCK_WIDTH;
                //BLOCK.axis = glm::vec3(0,1,0);
            }
        }
    }

    else if(FLAG_LEFT == 1)
    {
        if(BLOCK.horizontal_x == 0)
        {
            if(BLOCK.horizontal_z == 0)
            {       
                Matrices.model = glm::mat4(1.0f);

                glm::mat4 translateBlockToOrigin = glm::translate(glm::vec3(0,-BLOCK_HEIGHT,-BLOCK_WIDTH));
                glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock = glm::rotate((float)((BLOCK.angle)*M_PI/180.0f), BLOCK.axis);
                glm::mat4 translateFromOrigin = glm::translate(glm::vec3(0,BLOCK_HEIGHT,BLOCK_WIDTH));
                Matrices.model *= (translateBlockToOrigin * translateBlock *  rotateBlock * translateFromOrigin);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle <= -90)
                {
                    BLOCK.angle = 90;
                    BLOCK.angle_incr = 0;
                    FLAG_LEFT = 0;
                    BLOCK.horizontal_z = 1;
                    BLOCK.y += -BLOCK_WIDTH;
                    BLOCK.z += -BLOCK_HEIGHT - BLOCK_WIDTH;

                    //BLOCK.axis = glm::vec3(1,0,0);
                }
            }
            else
            {
                glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(0,-BLOCK_HEIGHT,BLOCK_WIDTH));
                //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock2 = glm::rotate((float)((BLOCK.angle+270)*M_PI/180.0f), BLOCK.axis);
                glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(0,BLOCK_HEIGHT,-BLOCK_WIDTH));
                Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle <= 0)
                {
                    BLOCK.angle = 0;
                    BLOCK.angle_incr = 0;
                    FLAG_LEFT = 0;
                    BLOCK.horizontal_z = 0;
                    BLOCK.y += BLOCK_WIDTH;
                    BLOCK.z += -BLOCK_HEIGHT-BLOCK_WIDTH;
                    //BLOCK.axis = glm::vec3(0,1,0);
                }
            }
        }
        else if(BLOCK.horizontal_x == 1)
        {
            glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,0,-BLOCK_WIDTH));
            //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
            glm::mat4 rotateBlock2 = glm::rotate((float)((BLOCK.angle)*M_PI/180.0f), BLOCK.axis);
            glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,0,BLOCK_WIDTH));
            Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
            MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
            if(BLOCK.angle >= 90)
            {
                BLOCK.angle = 0;
                BLOCK.angle_incr = 0;
                FLAG_LEFT = 0;
                //BLOCK.horizontal_z = 0;
                BLOCK.y += 0;
                BLOCK.z += -2*BLOCK_WIDTH;
                //BLOCK.axis = glm::vec3(0,1,0);
            }
        }
    }

    else if(FLAG_DOWN == -1)
    {
        if(BLOCK.horizontal_z == 0)
        {
            if(BLOCK.horizontal_x == 0)
            {  
                Matrices.model = glm::mat4(1.0f);

                glm::mat4 translateBlockToOrigin = glm::translate(glm::vec3(BLOCK_WIDTH,-BLOCK_HEIGHT,0));
                glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock = glm::rotate((float)((BLOCK.angle_x)*M_PI/180.0f), BLOCK.axis_x);
                glm::mat4 translateFromOrigin = glm::translate(glm::vec3(-BLOCK_WIDTH,BLOCK_HEIGHT,0));
                Matrices.model *= (translateBlockToOrigin * translateBlock *  rotateBlock * translateFromOrigin);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle_x <= -90)
                {
                    BLOCK.angle_x = 90;
                    BLOCK.angle_incr_x = 0;
                    FLAG_DOWN = 0;
                    BLOCK.horizontal_x = 1;
                    BLOCK.y += -BLOCK_WIDTH;
                    BLOCK.x += BLOCK_HEIGHT + BLOCK_WIDTH;
                    BLOCK.axis = glm::vec3(0,0,1);
                }
            }
            else
            {
                glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,-BLOCK_HEIGHT,0));
                //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock2 = glm::rotate((float)((BLOCK.angle_x+270)*M_PI/180.0f), BLOCK.axis_x);
                glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,BLOCK_HEIGHT,0));
                Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle_x <= 0)
                {
                    BLOCK.angle_x = 0;
                    BLOCK.angle_incr_x = 0;
                    FLAG_DOWN = 0;
                    BLOCK.horizontal_x = 0;
                    BLOCK.y += BLOCK_HEIGHT-BLOCK_WIDTH;
                    BLOCK.x += BLOCK_HEIGHT+BLOCK_WIDTH;
                    //BLOCK.axis = glm::vec3(0,1,0);
                }
            }
        }
        else if(BLOCK.horizontal_z == 1)
        {
            glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,0,BLOCK_WIDTH));
            //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
            glm::mat4 rotateBlock2 = glm::rotate((float)((-BLOCK.angle_x)*M_PI/180.0f), BLOCK.axis);
            glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,0,-BLOCK_WIDTH));
            Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
            MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
            if(BLOCK.angle_x >= 90)
            {
                BLOCK.angle_x = 0;
                BLOCK.angle_incr_x = 0;
                FLAG_DOWN = 0;
                //BLOCK.horizontal_z = 0;
                BLOCK.y += 0;
                BLOCK.x += 2*BLOCK_WIDTH;
                //BLOCK.axis = glm::vec3(0,1,0);
            }
        }
    }

    else if(FLAG_DOWN == 1)
    {
        if(BLOCK.horizontal_z == 0)
        {
            if(BLOCK.horizontal_x == 0)
            {  
                Matrices.model = glm::mat4(1.0f);

                glm::mat4 translateBlockToOrigin = glm::translate(glm::vec3(-BLOCK_WIDTH,-BLOCK_HEIGHT,0));
                glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock = glm::rotate((float)((BLOCK.angle_x)*M_PI/180.0f), BLOCK.axis_x);
                glm::mat4 translateFromOrigin = glm::translate(glm::vec3(BLOCK_WIDTH,BLOCK_HEIGHT,0));
                Matrices.model *= (translateBlockToOrigin * translateBlock *  rotateBlock * translateFromOrigin);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle_x >= 90)
                {
                    BLOCK.angle_x = 90;
                    BLOCK.angle_incr_x = 0;
                    FLAG_DOWN = 0;
                    BLOCK.horizontal_x = 1;
                    BLOCK.y += -BLOCK_WIDTH;
                    BLOCK.x += -BLOCK_HEIGHT-BLOCK_WIDTH;
                    BLOCK.axis = glm::vec3(0,0,1);
                }
            }
            else
            {
                glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,BLOCK_HEIGHT,0));
                //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
                glm::mat4 rotateBlock2 = glm::rotate((float)((-BLOCK.angle_x-270)*M_PI/180.0f), BLOCK.axis_x);
                glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,-BLOCK_HEIGHT,0));
                Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
                MVP = VP * Matrices.model;
                glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
                if(BLOCK.angle_x <= 0)
                {
                    BLOCK.angle_x = 0;
                    BLOCK.angle_incr_x = 0;
                    FLAG_DOWN = 0;
                    BLOCK.horizontal_x = 0;
                    BLOCK.y += BLOCK_WIDTH;
                    BLOCK.x += -BLOCK_HEIGHT-BLOCK_WIDTH;
                    //BLOCK.axis = glm::vec3(0,1,0);
                }
            }
        }
        else if(BLOCK.horizontal_z == 1)
        {
            glm::mat4 translateBlockToOrigin2 = glm::translate(glm::vec3(-BLOCK_WIDTH,0,BLOCK_WIDTH));
            //glm::mat4 translateBlock = glm::translate(glm::vec3(BLOCK.x,BLOCK.y,BLOCK.z));
            glm::mat4 rotateBlock2 = glm::rotate((float)((BLOCK.angle_x)*M_PI/180.0f), BLOCK.axis);
            glm::mat4 translateFromOrigin2 = glm::translate(glm::vec3(BLOCK_WIDTH,0,-BLOCK_WIDTH));
            Matrices.model *= (translateBlockToOrigin2 * rotateBlock2 * translateFromOrigin2);
            MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
            if(BLOCK.angle_x >= 90)
            {
                BLOCK.angle_x = 0;
                BLOCK.angle_incr_x = 0;
                FLAG_DOWN = 0;
                //BLOCK.horizontal_z = 0;
                BLOCK.y += 0;
                BLOCK.x += -2*BLOCK_WIDTH;
                //BLOCK.axis = glm::vec3(0,1,0);
            }
        }
    }
    // draw3DObject draws the VAO given to it using current MVP matrix
    draw3DObject(BLOCK.block);

}

int main (int argc, char** argv)
{
    int width = 600;
    int height = 600;
    for(int i=0;i<10;i++)
    {
        FLOOR[10*i].x = 2*i-4;
        FLOOR[10*i].y = 0;
        FLOOR[10*i].z = -4;
        FLOOR[10*i].angle = 0;
        FLOOR[10*i].index = 0;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            int cur = 10*i+j;
            FLOOR[cur].index = cur;
            FLOOR[cur].x = FLOOR[cur-1].x;
            FLOOR[cur].y = FLOOR[cur-1].y;
            FLOOR[cur].z = FLOOR[cur-1].z+2.0;
            FLOOR[cur].angle = FLOOR[cur-1].angle;
        }
    }
    BLOCK.x = 0; BLOCK.y = 0; BLOCK.z = 0; BLOCK.angle = 0;BLOCK.angle_x = 0;
    BLOCK.axis = glm::vec3(0,1,0);BLOCK.horizontal_z = 0;BLOCK.horizontal_x = 0;
    BLOCK.angle_incr=0;
    if(BLOCK.horizontal_x == 0 && BLOCK.horizontal_z == 0)
    {
        BLOCK.y = BLOCK_HEIGHT;
    }
    else if(BLOCK.horizontal_x == 1 && BLOCK.horizontal_z == 0)
    {
        BLOCK.y = BLOCK_WIDTH;
        BLOCK.x = BLOCK_WIDTH;
    }
    else if(BLOCK.horizontal_x == 0 && BLOCK.horizontal_z == 1)
    {
        BLOCK.y = BLOCK_WIDTH;
        BLOCK.z = BLOCK_WIDTH;
    }
    /*rect_pos = glm::vec3(0, 0, 0);
    floor_pos = glm::vec3(0, 0, 0);
    do_rot = 0;
    floor_rel = 1;*/

    GLFWwindow* window = initGLFW(width, height);
    initGL (window, width, height);

    // Eye - Location of camera. Don't change unless you are sure!!
    eye = TOWER_VIEW_EYE;
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );

    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    target = TOWER_VIEW_TARGET;
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    up = TOWER_VIEW_UP;

    last_update_time = glfwGetTime();
    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

	// clear the color and depth in the frame buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // OpenGL Draw commands
	current_time = glfwGetTime();
	if(do_rot)
	    camera_rotation_angle += 90*(current_time - last_update_time); // Simulating camera rotation
	if(camera_rotation_angle > 720)
	    camera_rotation_angle -= 720;
	last_update_time = current_time;

    if(FOLLOW_VIEW_FLAG || BLOCK_VIEW_FLAG)
    {
        eye = glm::vec3(BLOCK.x,BLOCK.y+5,BLOCK.z);
        if(FOLLOW_VIEW_FLAG)
            eye = glm::vec3(BLOCK.x-2,BLOCK.y+10,BLOCK.z);
        //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );

        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        target = glm::vec3(BLOCK.x+2,BLOCK.y+4,BLOCK.z);

        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        up = glm::vec3(0,1,0);
    
        up = eye*target;
    }

	draw(window, 0, 0, 1.0, 1.0, 1, 1, 1);
	//draw(window, 0.5, 0, 0.5, 0.5, 0, 1, 1);
	//draw(window, 0, 0.5, 0.5, 0.5, 1, 0, 1);
	//draw(window, 0.5, 0.5, 0.5, 0.5, 0, 0, 1);

        // Swap Frame Buffer in double buffering
        glfwSwapBuffers(window);

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    glfwTerminate();
    //    exit(EXIT_SUCCESS);
}
