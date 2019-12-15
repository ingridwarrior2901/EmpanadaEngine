#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 objectColor;
out vec2 texSampler;

uniform mat4 model;
uniform mat4 projection;


void main()
{
    gl_Position =  projection * model * vec4(position, 1.0);
    objectColor = color;
    texSampler = texCoord;
}
