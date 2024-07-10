#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#include "Types.h"

// FrameWork
#include "FrameWork/DisJointSet.h"
#include "Framework/Vector2.h"
#include "Framework/Line.h"
#include "Framework/Collider.h"
#include "Framework/RectCollider.h"
#include "Framework/CircleCollider.h"

// Program
#include "Program/Program.h"

// Scene
#include "Scene/Scene.h"
#include "Scene/PaintScene.h"

extern Vector2 mousePos;
extern HWND hWnd;