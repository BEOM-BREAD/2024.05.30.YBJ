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

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>

using namespace std;
#include "Types.h"

// FrameWork
#include "FrameWork/Vector2.h"
#include "FrameWork/Rect.h"
#include "FrameWork/Circle.h"

// Program
#include"Program/Program.h"

// Scene
#include "Scene/Scene.h"
#include "Scene/PaintScene.h"


extern Vector2 mousePos;