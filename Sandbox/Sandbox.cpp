#include "Engine/Hollow.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Hollow {

	class Sandbox : public Application {
	      protected:
		unsigned int VAO, VBO;
		unsigned int shader;

		void OnInit() override {
			std::cout << "3D Renderer Init\n";

			glEnable(GL_DEPTH_TEST);

			const char *vs = R"(
			#version 460 core
			layout(location = 0) in vec3 aPos;

			uniform mat4 u_Model;
			uniform mat4 u_View;
			uniform mat4 u_Projection;

			void main() {
				gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
			}
		)";

			const char *fs = R"(
			#version 460 core
			out vec4 FragColor;
			void main() {
				FragColor = vec4(1.0, 0.3, 0.3, 1.0);
			}
		)";

			unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertex, 1, &vs, nullptr);
			glCompileShader(vertex);

			unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragment, 1, &fs, nullptr);
			glCompileShader(fragment);

			shader = glCreateProgram();
			glAttachShader(shader, vertex);
			glAttachShader(shader, fragment);
			glLinkProgram(shader);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			float vertices[] = {
			    -0.5f, -0.5f, -0.5f, 0.5f,	-0.5f, -0.5f, 0.5f,  0.5f,  -0.5f,
			    0.5f,  0.5f,  -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, -0.5f, -0.5f,

			    -0.5f, -0.5f, 0.5f,	 0.5f,	-0.5f, 0.5f,  0.5f,  0.5f,  0.5f,
			    0.5f,  0.5f,  0.5f,	 -0.5f, 0.5f,  0.5f,  -0.5f, -0.5f, 0.5f,

			    -0.5f, 0.5f,  0.5f,	 -0.5f, 0.5f,  -0.5f, -0.5f, -0.5f, -0.5f,
			    -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,  0.5f,

			    0.5f,  0.5f,  0.5f,	 0.5f,	0.5f,  -0.5f, 0.5f,  -0.5f, -0.5f,
			    0.5f,  -0.5f, -0.5f, 0.5f,	-0.5f, 0.5f,  0.5f,  0.5f,  0.5f,

			    -0.5f, -0.5f, -0.5f, 0.5f,	-0.5f, -0.5f, 0.5f,  -0.5f, 0.5f,
			    0.5f,  -0.5f, 0.5f,	 -0.5f, -0.5f, 0.5f,  -0.5f, -0.5f, -0.5f,

			    -0.5f, 0.5f,  -0.5f, 0.5f,	0.5f,  -0.5f, 0.5f,  0.5f,  0.5f,
			    0.5f,  0.5f,  0.5f,	 -0.5f, 0.5f,  0.5f,  -0.5f, 0.5f,  -0.5f};

			glCreateVertexArrays(1, &VAO);
			glCreateBuffers(1, &VBO);

			glNamedBufferData(VBO, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexArrayVertexBuffer(VAO, 0, VBO, 0, 3 * sizeof(float));
			glEnableVertexArrayAttrib(VAO, 0);
			glVertexArrayAttribFormat(VAO, 0, 3, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, 0, 0);
		}

		void OnUpdate(float dt) override {
			glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(shader);

			glm::mat4 view =
			    glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));

			glm::mat4 projection =
			    glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);

			glm::mat4 model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(),
						      glm::vec3(0.5f, 1.0f, 0.0f));

			glUniformMatrix4fv(glGetUniformLocation(shader, "u_Model"), 1, GL_FALSE,
					   glm::value_ptr(model));

			glUniformMatrix4fv(glGetUniformLocation(shader, "u_View"), 1, GL_FALSE,
					   glm::value_ptr(view));

			glUniformMatrix4fv(glGetUniformLocation(shader, "u_Projection"), 1,
					   GL_FALSE, glm::value_ptr(projection));

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		void OnShutdown() override {
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteProgram(shader);
			std::cout << "Renderer Shutdown\n";
		}
	};

} // namespace Hollow

std::unique_ptr<Hollow::Application> Hollow::CreateApplication() {
	return std::make_unique<Hollow::Sandbox>();
}