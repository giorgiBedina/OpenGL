#include "glad/glad.c"
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height) //This function changes renderer size
{
    glViewport(0, 0, width, height);
} 

void processInput(GLFWwindow *window) //This function closes window if "X" button is pressed
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit(); // initialize GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //tell GLFW that 3.3 is the OpenGL version we want to use.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //tell GLFWto use the core-profile
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1200, 800, "Game v1.0", NULL, NULL); //create a window object
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//make the context of our window the main context on the current thread

    //GLAD
    //Initialize GLAD before we call any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //load the address of the OpenGL function pointers
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //ViewPort size
    glViewport(0, 0, 800, 600); //tell OpenGL the size of the rendering window

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //render loop
    while(!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);

        //rendering commands here
        glClearColor(1.0f,1.0f,0.0f, 1.0f);    //yellow
        glClear(GL_COLOR_BUFFER_BIT);
        

        //check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

  
    glfwTerminate();
    return 0;
}