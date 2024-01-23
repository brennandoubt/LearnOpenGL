//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include "stb_image.h"
//
//#include "Shader.h"
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//GLenum glCheckError_(const char* file, int line);
//#define glCheckError() glCheckError_(__FILE__, __LINE__)
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main2() {
//	// 0. initialize and configure GLFW
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	// 1. create window
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//
//	// 2. load all OpenGL function pointers
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//
//
//	// 3. build and compile shader program
//	Shader ourShader("texture.vs", "texture.fs");
//
//
//
//	// 4. set up vertex data (and buffer(s)) and configure vertex attributes
//	float vertices[] = {
//		// positions			// colors				// texture coords
//		0.5f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,	// top right
//		0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,	// bottom right
//		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,	// bottom left
//		-0.5f, 0.5f, 0.0f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f	// top left
//	};
//	unsigned int indices[] = {
//		0, 1, 3,	// first triangle
//		1, 2, 3		// second triangle
//	};
//
//	unsigned int VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// color attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	// texture coord attribute
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//
//	// 5. load and create a texture
//	unsigned int texture1, texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	
//	// set texture wrapping parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// set texture filtering parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// load image, create texture and generate mipmaps
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true); // flip loaded textures on y-axis
//	unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	// texture 2
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data) {
//		// note that awesomeface.png has transparency and thus an alpha channel, so tell OpenGL that the data type is of GL_RGBA
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	// tell OpenGL for each sampler to which texture unit/location it belongs to (only has to be done once)
//	ourShader.use();
//	glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // set it manually
//	ourShader.setInt("texture2", 1); // set it via shader class
//
//
//	// 6. render loop
//	while (!glfwWindowShouldClose(window)) {
//		// input
//		processInput(window);
//
//		// render
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// bind textures on corresponding texture units
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//		// render container
//		ourShader.use();
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		// swap buffers and poll IO events
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// de-allocate all resources once finished using them
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//
//	// terminate, clearing all previously allocated GLFW resources
//	glfwTerminate();
//	return 0;
//}
//
//// process all user input
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//
//// change viewport as window is resized
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	// ensure viewport matches new window dimensions
//	glViewport(0, 0, width, height);
//}
//
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
////#define glCheckError() glCheckError_(__FILE__, __LINE__)