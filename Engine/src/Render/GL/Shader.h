#pragma once
#include "..\..\Core.h"

#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

//chase the shader
#include <unordered_map>
//MATH
#include "glm/glm.hpp"

struct shaderSource {
    std::string shaderVertex;
    std::string shaderFregment;
};

class Shader
{
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;
public:
    Shader (const std::string& filepath);
    ~Shader ();

    //bind
    void Bind () const;
    void Unbind () const;
    //Uniforms
    void SetUniform1i (const std::string& name, int value);
    void SetUniform1f (const std::string& name, float value);
    void SetUniform4f (const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f (const std::string& name, const glm::mat4& matrix);

private:
    shaderSource GetShader (const std::string path);
    int GetUniformLocation (const std::string& name);
    unsigned int CompileShader (unsigned int type, const std::string shaderSource);
    unsigned int CreateShader (const std::string &vertexShader, const std::string &fragmentShader);
};