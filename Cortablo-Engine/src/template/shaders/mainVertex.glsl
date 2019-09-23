#version 330 core

layout (location = 0) in vec4 Position;
layout (location = 1) in vec2 TexCoord;
layout (location = 2) in vec3 Normal;

out Main
{
    vec4 Position;
    vec2 TexCoord;
    vec3 Normal;
} MainOut;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix = mat4(1.0f);
uniform mat4 modelMatrix = mat4(1.0f);

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * Position;
    MainOut.Position = modelMatrix * Position;
    MainOut.TexCoord = TexCoord;
    MainOut.Normal = mat3(transpose(inverse(modelMatrix))) * Normal;
}
