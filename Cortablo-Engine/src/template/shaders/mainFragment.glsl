#version 330 core

layout (location = 0) out vec4 Color;

in Main
{
    vec4 Position;
    vec2 TexCoord;
    vec3 Normal;
} MainIn;

uniform sampler2D textureSampler;

void main()
{
    Color = texture(textureSampler, MainIn.TexCoord);
}
