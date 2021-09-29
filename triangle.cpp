#include "glad/glad.c"
#include <GLFW/glfw3.h>
#include <iostream>

void processQuitInput(GLFWwindow *window) //This function closes window if "X" button is pressed
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main()
{
    glfwInit(); //initialize glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //hint that we want openGL v3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //hint that we want openGL v3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //hint that we need openGL with core profile

    GLFWwindow* window = glfwCreateWindow(1440, 900, "triangle", glfwGetPrimaryMonitor(), NULL); //create new window
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); //make window main content on current thread

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //load the address of the OpenGL function pointers
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    float vertices[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    while(!glfwWindowShouldClose(window))
    {
        //input
        processQuitInput(window); //quit window if "X" is pressed

        //rendering commands here
        glClearColor(1.0f,1.0f,0.0f, 1.0f);    //set screen color setting as yellow
        glClear(GL_COLOR_BUFFER_BIT); //set screen 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        

        //check end call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    std::cout << "Program shut down" << std::endl;
    
    return 0;
}