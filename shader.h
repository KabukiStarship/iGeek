/* Interactive Gym Environment and Educational Kit (IGEEK) @version 0.x
@link    https://github.com/kabuki-starship/igeek.git
@file    /shader.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//#include <_config.h>

#ifndef IGEEK_SHADER_DECLARATIONS
#define IGEEK_SHADER_DECLARATIONS

#include <GL/glew.h>

namespace _ {
class Shader {
 public:
  GLuint program;

  // Generates the shader on the fly.
  Shader(const GLchar* vertex_path, const GLchar* fragment_path) {
    // 1. Load the vertex/fragment source code form the file path.
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream v_shader_file;
    std::ifstream f_shader_file;

    // ensures ifstream objects can thrwo exceptions:
    v_shader_file.exceptions(std::ifstream::badbit);
    f_shader_file.exceptions(std::ifstream::badbit);
    try {
      v_shader_file.open(vertex_path);
      f_shader_file.open(fragment_path);
      std::stringstream v_shader_stream, f_shader_stream;
      // Read file's buffer contents into streams.
      v_shader_stream << v_shader_file.rdbuf();
      f_shader_stream << f_shader_file.rdbuf();
      v_shader_file.close();
      f_shader_file.close();
      // Convert the stream into a string.
      vertex_code = v_shader_stream.str();
      fragment_code = f_shader_stream.str();
    } catch (std::ifstream::failure e) {
      std::cout << "\nERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ!";
    }
    const GLchar* v_shader_code = vertex_code.c_str();
    const GLchar* f_shader_code = fragment_code.c_str();
    // 2. Compile shaders
    GLuint vertex, fragment;
    GLint success;
    enum { cInfoLogSize = 512 };
    GLchar info_log[cInfoLogSize];
    // Vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &v_shader_code, NULL);
    glCompileShader(vertex);
    // Print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(vertex, cInfoLogSize, NULL, info_log);
      std::cout << "\nERROR::SHADER::VERTEX::COMPILATION_FAILED!";
    }
    // Fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &f_shader_code, NULL);
    glCompileShader(fragment);
    // Print compile errors if any
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(fragment, cInfoLogSize, NULL, info_log);
      std::cout << "\nERROR::SHADER::FRAGMENT::COMPILATION_FAILED!";
    }

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success) {
      glGetProgramInfoLog(program, cInfoLogSize, NULL, info_log);
      std::cout << "\nERROR::SHAADER::PROGRAM::LINKING_FAILED\n" << info_log;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
  }

  void Use() { glUseProgram(program); }
};
}  // namespace _

#endif  //< IGEEK_SHADER_DECLARATIONS
