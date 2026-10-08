#pragma once
#include "raylib.h"
#include "raymath.h"

static Color PanelDark = { 25, 28, 30, 255 };
static Color PanelMedium = { 55, 58, 60, 255 };
static Color PanelLight = { 100, 100, 95, 255 };

static Color IndicatorRed = { 210, 35, 35, 255 };
static Color IndicatorGreen = { 40, 180, 80, 255 };
static Color IndicatorBlue = { 40, 100, 220, 255 };


void DrawIndicator(int x, int y, int radius, Color color, bool active, const char* label);

void DrawSwitch(int x, int y, int width, int height, bool active, const char* label);

void DrawGauge(int x, int y, int radius, float value, const char* label);