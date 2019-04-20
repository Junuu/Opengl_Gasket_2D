///*
//ctrl+k ctrl+c ��ü�ּ�ó��
//ctrl+k ctrl+u ��ü�ּ�����
//shader�� ����Ͽ� gasket 2D�� ����ϴ� �ڵ��Դϴ�.
//fshader.glsl ���� ������ �ٲ��� �� �ֽ��ϴ�.
//*/
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include "InitShader.h"
//#include <iostream>
//
//#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))
//
//float positions[150000];
//
//void triangle(float a_x,float a_y,float b_x,float b_y,float c_x,float c_y)
//{
//	static int i=0;
//	positions[i++]=a_x;
//	positions[i++]=a_y;
//	positions[i++]=b_x;
//	positions[i++]=b_y;
//	positions[i++]=c_x;
//	positions[i++]=c_y;
//	
//}
//void divide_triangle(float a_x,float a_y,float b_x,float b_y,float c_x,float c_y, int m)
//{
//	float ab_x,ab_y,ac_x,ac_y,bc_x,bc_y;
//	if(m>0)
//	{
//		ab_x=(a_x+b_x)/2;
//		ab_y=(a_y+b_y)/2;
//		ac_x=(a_x+c_x)/2;
//		ac_y=(a_y+c_y)/2;
//		bc_x=(b_x+c_x)/2;
//		bc_y=(b_y+c_y)/2;
//		divide_triangle(a_x,a_y,ab_x,ab_y,ac_x,ac_y, m-1);
//		divide_triangle(c_x,c_y,ac_x,ac_y,bc_x,bc_y, m-1);		
//		divide_triangle(b_x,b_y,bc_x,bc_y,ab_x,ab_y, m-1);
//		
//		
//	}
//	else
//	{
//		triangle(a_x,a_y,b_x,b_y,c_x,c_y);
//	}
//}
//int main()
//{
//	int subdivision_num=9; //������ �ִ� Ƚ�� ==����Լ� ȣ�� Ƚ��
//	GLFWwindow* window;
//	if (!glfwInit()) // glfw ���̺귯�� �ʱ�ȭ
//		return -1;
//
//	window = glfwCreateWindow(512, 512, "Gasket 2D", NULL, NULL);	// window ����
//	if (!window)	// window ���� ���� �� ���α׷� ����
//	{
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window); // window context ����
//
//	if (glewInit() != GLEW_OK) std::cout << "Error\n";	// glew ���̺귯�� �ʱ�ȭ �� �ʱ�ȭ ���� �� ���� �޼���
//														// glew ���̺귯���� �ݵ�� window context ���� �� �ʱ�ȭ �ƴϸ� ����
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//	float start_positions[] =		// �ﰢ���� �׸��� ���� 3���� vertex(x, y)�� ���� ������ ���� 1���� �迭
//	{					
//		-1.0f, -1.0f,	// 0
//		 0.0f,  1.0f,	// 1
//		 1.0f, -1.0f	// 2
//
//	};
//	divide_triangle(start_positions[0],start_positions[1],start_positions[2],start_positions[3],start_positions[4],start_positions[5],subdivision_num);
//	GLuint va;	// vertex array ����, �޸� �Ҵ�, ���ε�
//	glGenVertexArrays(1, &va);
//	glBindVertexArray(va);
//
//	GLuint vb;	// vertex buffer ����, �޸� �Ҵ�, ���ε�, data�� ������ ���Ŀ� �°� buffer data �غ�
//	glGenBuffers(1, &vb);
//	glBindBuffer(GL_ARRAY_BUFFER, vb);
//	glBufferData(GL_ARRAY_BUFFER, 150000*sizeof(float), positions, GL_STATIC_DRAW);
//		// 6*2*sizeof(float) = (vertex ����)*(�� vertex�� ��� ����)*(�� ��� ������ Ÿ���� ũ��) 5000���� ũ������
//
//	GLuint program = InitShader("vshader04.glsl", "fshader04.glsl");	// shader program ��������
//	glUseProgram(program);	// � shader program�� ����� ������
//
//	GLuint location = glGetAttribLocation(program, "vPosition");	// position vertex�� ���� ������ shader program ���� � ������ �����ų ���ΰ�
//	glEnableVertexAttribArray(location);
//	glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//	
/////////////////////////////////////////////////////////////////////////////
//// window â�� ����� ������ ���ѷ��� 
//	while (!glfwWindowShouldClose(window))
//	{
//		glClear(GL_COLOR_BUFFER_BIT);
//
//	//////////////////////////////////////////////////////////////////////
//		glDrawArrays(GL_TRIANGLES, 0, 150000); //0~150000���� ���� �׷���
//		// glDrawArrays �Լ��� �ߺ��Ǵ� vertex�� �����ϴ� vertex ������ �����.
//		// vertex�� index�� �����ذ��� ����� �ƴ�,
//		// vertex ������ ����ִ� positions �迭�� ���ʷ� �о� 3���� �ϳ��� �ﰢ������ ó���ϴ� ���.
//
//	//////////////////////////////////////////////////////////////////////
//		glfwSwapBuffers(window);	// front buffer�� back buffer ��ü
//		glfwPollEvents();
//	}
//	glfwTerminate();
//	
//	return 0;
//}