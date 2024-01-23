#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

// adapt vertex shader to accept a mat4 uniform variable
uniform mat4 transform;

void main() {
	// multiply position vector by the matrix uniform
	gl_Position = transform * vec4(aPos, 1.0f);

	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}