#version 400 core

out vec4 FragColor;

in vec3 objectColor;
in vec2 texSampler;

uniform sampler2D Texture;
uniform bool enableTexture;

void main()
{
    if (enableTexture)
    {
        FragColor = texture(Texture, texSampler);
        if (FragColor.a <= 0.0) {
            discard;
        }
    }
    else
    {
        FragColor = vec4(objectColor, 1.0);
    }
}
