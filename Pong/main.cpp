#include "pch.h"
#include "functional"



/*TODO: 좌표 처리 정수로 변환*/

void HideCMD(bool isHide)
{
	HWND hWnd = GetForegroundWindow();
	isHide ? ShowWindow(hWnd, SW_SHOW) : ShowWindow(hWnd, SW_HIDE);
}

int WINDOWSIZE = 100;

int32 SCREEN_WIDTH = 800;
int32 SCREEN_HEIGHT = 600;

GMPtr GM;

bool noGUI = false;

//박스는 항상 좌하단 좌표를 start로 넣을 것

void my_reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GameInit()
{
	GM = make_shared<GameManager>(SCREEN_WIDTH, SCREEN_HEIGHT);

	GM->noGUI(noGUI);
}

void GLInit() {
	SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
	SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);

	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);

	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);
	//string s = SCREEN_WIDTH + "x" + SCREEN_HEIGHT;
	//glutGameModeString(s.c_str());
	//if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
	//	glutEnterGameMode();
	glDisable(GL_LIGHTING);

	glutCreateWindow("Breakout 99");
	//glutSetCursor(GLUT_CURSOR_NONE);
	//glutFullScreen();
}

void ArgParseInit(int argc, char** argv)
{
	argparse::ArgumentParser program("Breakout");

	program.add_argument("-noGUI")
		.help("GUI Setting")
		.default_value(false)
		.implicit_value(true);

	program.add_argument("-d")
		.help("Dummy client enable")
		.default_value(false)
		.implicit_value(true);

	try {
		program.parse_args(argc, argv);
	}
	catch (const std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		std::exit(1);
	}

	if(program["-noGUI"] == true)
	{
		noGUI = true;
	}
}


int main(int argc, char** argv) {
	ArgParseInit(argc, argv);
	HideCMD(noGUI);

	if (noGUI == false) {
		glutInit(&argc, argv);
		GLInit();
		cout << "noGUI Enabled" << endl;
	}
	GameInit();


	GM->Start();

	return 0;
}

