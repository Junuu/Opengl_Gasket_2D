///*
//ctrl+k ctrl+c 전체주석처리
//ctrl+k ctrl+u 전체주석해제
//shader를 사용하여 gasket 2D를 출력하는 코드입니다.
//fshader.glsl 에서 색상을 바꿔줄 수 있습니다.
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
//	int subdivision_num=9; //나누어 주는 횟수 ==재귀함수 호출 횟수
//	GLFWwindow* window;
//	if (!glfwInit()) // glfw 라이브러리 초기화
//		return -1;
//
//	window = glfwCreateWindow(512, 512, "Gasket 2D", NULL, NULL);	// window 생성
//	if (!window)	// window 생성 실패 시 프로그램 종료
//	{
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window); // window context 생성
//
//	if (glewInit() != GLEW_OK) std::cout << "Error\n";	// glew 라이브러리 초기화 및 초기화 실패 시 에러 메세지
//														// glew 라이브러리는 반드시 window context 생성 후 초기화 아니면 에러
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//	float start_positions[] =		// 삼각형을 그리기 위한 3개의 vertex(x, y)에 대한 정보를 담은 1차원 배열
//	{					
//		-1.0f, -1.0f,	// 0
//		 0.0f,  1.0f,	// 1
//		 1.0f, -1.0f	// 2
//
//	};
//	divide_triangle(start_positions[0],start_positions[1],start_positions[2],start_positions[3],start_positions[4],start_positions[5],subdivision_num);
//	GLuint va;	// vertex array 선언, 메모리 할당, 바인드
//	glGenVertexArrays(1, &va);
//	glBindVertexArray(va);
//
//	GLuint vb;	// vertex buffer 선언, 메모리 할당, 바인드, data가 구성된 형식에 맞게 buffer data 준비
//	glGenBuffers(1, &vb);
//	glBindBuffer(GL_ARRAY_BUFFER, vb);
//	glBufferData(GL_ARRAY_BUFFER, 150000*sizeof(float), positions, GL_STATIC_DRAW);
//		// 6*2*sizeof(float) = (vertex 갯수)*(각 vertex의 요소 갯수)*(각 요소 데이터 타입의 크기) 5000으로 크게잡음
//
//	GLuint program = InitShader("vshader04.glsl", "fshader04.glsl");	// shader program 가져오기
//	glUseProgram(program);	// 어떤 shader program을 사용할 것인지
//
//	GLuint location = glGetAttribLocation(program, "vPosition");	// position vertex에 대한 정보를 shader program 안의 어떤 변수와 연결시킬 것인가
//	glEnableVertexAttribArray(location);
//	glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//	
/////////////////////////////////////////////////////////////////////////////
//// window 창이 종료될 때까지 무한루프 
//	while (!glfwWindowShouldClose(window))
//	{
//		glClear(GL_COLOR_BUFFER_BIT);
//
//	//////////////////////////////////////////////////////////////////////
//		glDrawArrays(GL_TRIANGLES, 0, 150000); //0~150000까지 점을 그려줌
//		// glDrawArrays 함수는 중복되는 vertex를 포함하는 vertex 정보를 사용함.
//		// vertex의 index를 참조해가는 방식이 아닌,
//		// vertex 정보가 들어있는 positions 배열을 차례로 읽어 3개씩 하나의 삼각형으로 처리하는 방식.
//
//	//////////////////////////////////////////////////////////////////////
//		glfwSwapBuffers(window);	// front buffer와 back buffer 교체
//		glfwPollEvents();
//	}
//	glfwTerminate();
//	
//	return 0;
//}