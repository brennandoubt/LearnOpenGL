///*
//* Create new window using GLFW
//*
//*/
//
//// include GLAD before headers that require OpenGL
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//// our custom Shader class
//#include "Shader.h"
//
//// imported stb_image.h image loading library
//#include "stb_image.h"
//
//#include <iostream>
//
///*
//* Adjust window view when resized
//*/
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//
///*
//* Handle user input
//*/
//void processInput(GLFWwindow* window) {
//	// press ESC key to close window
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
///*
//* Print out error strings with error check function
//*/
//GLenum glCheckError_(const char* file, int line) {
//	GLenum errorCode;
//	while ((errorCode = glGetError()) != GL_NO_ERROR) {
//		std::string error;
//		switch (errorCode) {
//			case GL_INVALID_ENUM:
//				error = "INVALID_ENUM";
//				break;
//			case GL_INVALID_VALUE:
//				error = "INVALID_VALUE";
//				break;
//			case GL_INVALID_OPERATION:
//				error = "INVALID_OPERATION";
//				break;
//			case GL_STACK_OVERFLOW:
//				error = "STACK_OVERFLOW";
//				break;
//			case GL_STACK_UNDERFLOW:
//				error = "STACK_UNDERFLOW";
//				break;
//			case GL_OUT_OF_MEMORY:
//				error = "OUT_OF_MEMORY";
//				break;
//			case GL_INVALID_FRAMEBUFFER_OPERATION:
//				error = "INVALID_FRAMEBUFFER_OPERATION";
//				break;
//		}
//		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
//	}
//	return errorCode;
//}
//// pre-processor directives replaced at compile time with respective file and line compiled in
//#define glCheckError() glCheckError_(__FILE__, __LINE__)
//
//int main2() {
//	// initialize GLFW
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for MacOS
//
//	// create window object
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// initialize GLAD
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// set rendering window dimensions
//	glViewport(0, 0, 800, 600); // (lower-left coords, width, height)
//
//	// adjust viewport if user resizes window
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// create shaders using custom Shader class
//	Shader ourShader("shader.vs", "shader.fs");
//
//
//
//	// set vertex coordinates for a 2D triangle
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f, 0.5f, 0.0f
//	};
//
//	// set vertices for a 2D rectangle
//	float vertices2[] = {
//		// first triangle
//		0.5f, 0.5f, 0.0f, // top right
//		0.5f, -0.5f, 0.0f, // bottom right
//		-0.5f, 0.5f, 0.0f, // top left
//		// second triangle
//		0.5f, -0.5f, 0.0f, // bottom right
//		-0.5f, -0.5f, 0.0f, // bottom left
//		-0.5f, 0.5f, 0.0f // top left
//	};
//	// set vertices for a 2D rectangle (using Element Buffer Object)
//	float vertices3[] = {
//		0.5f, 0.5f, 0.0f, // top right
//		0.5f, -0.5f, 0.0f, // bottom right
//		-0.5f, -0.5f, 0.0f, // bottom left
//		-0.5f, 0.5f, 0.0f // top left
//	};
//	// specify vertex indices to draw a 2D rectangle
//	unsigned int indices3[] = {
//		0, 1, 3, // first triangle
//		1, 2, 3 // second triangle
//	};
//
//
//	float vertices4[] = {
//		// positions			// colors
//		0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	// bottom right
//		-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	// bottom left
//		0.0f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f	// top
//	};
//
//	// Vertex Buffer Object (VBO): store vertices in GPU's memory
//	// Vertex Array Object (VAO): store state configurations to be bound/unbound from state
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO); // generate with Buffer ID
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO); // bind vertex array object
//	glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind and set vertex buffer object
//	// copy vertex data into buffer's memory
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// color attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	// glBindVertexArray(0);
//
//	// ------------------------------------------------------------------------------------
//
//
//	//// Element Buffer Object (EBO): store vertex indices for indexed drawing
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);
//
//	//// set vertex attribute pointers
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(0);
//
//	//// Vertex Shader (VS): render shape from vertices
//	//unsigned int vertexShader;
//	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // attach shader source code
//	//glCompileShader(vertexShader); // compile shader object
//
//	//// check for compile-time errors
//	//int success;
//	//char infoLog[512];
//	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	//if (!success) {
//	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//	//// Fragment Shader (FS): calculate pixel color output
//	//unsigned int fragmentShader;
//	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	//glCompileShader(fragmentShader);
//
//	//// check for compile-time errors
//	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	//if (!success) {
//	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	//}
//
//	//// Shader Program (SP): link compiled shaders together
//	//unsigned int shaderProgram;
//	//shaderProgram = glCreateProgram();
//	//glAttachShader(shaderProgram, vertexShader);
//	//glAttachShader(shaderProgram, fragmentShader);
//	//glLinkProgram(shaderProgram);
//
//	//// debugging example
//	////glBindBuffer(GL_VERTEX_ARRAY, VBO);
//	////glCheckError();
//
//	//// check for linking errors
//	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	//if (!success) {
//	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	//	std::cout << "ERROR::PROGRAM::SHADER::LINK_FAILED\n" << infoLog << std::endl;
//	//}
//
//	//// delete shader objects once linked to program
//	//glDeleteShader(vertexShader);
//	//glDeleteShader(fragmentShader);
//
//
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // draw in wireframe mode
//	////glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // draw in fill mode (default)
//
//	// Render Loop (RL): run window frames until stopped
//	while (!glfwWindowShouldClose(window)) {
//		// take user input
//		processInput(window);
//
//		// clear color buffer with specified color
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// activate shader program to be used for every shade/render call
//		//glUseProgram(shaderProgram);
//		ourShader.use();
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3); // for drawing triangle
//
//		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // for drawing rectangle
//		//glBindVertexArray(0);
//
//		// poll IO events and swap buffers
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//
//	// de-allocate resources once they're no longer needed
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
