#version 330 core

layout (location = 0) out vec4 Color;

in Main
{
    vec4 Position;
    vec2 UV;
    vec3 Normal;
} MainIn;

uniform samplerCube textureSampler;

void main()
{
    Color = texture(textureSampler, MainIn.Position.xyz);
}
