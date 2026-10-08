#include "widgets.hpp"


// Light Indicator
void DrawIndicator(int x, int y, int radius, Color color, bool active, const char* label)
{
    // outer circle
    DrawCircle(x, y, radius + 7, DARKGRAY);

    // inner circle
    DrawCircle(x, y, radius + 3, BLACK);

    //light
   DrawCircle(x, y, radius, active ? color : PanelDark);
     
    //label
    int textWidth = MeasureText(label, 18);

    DrawText(label, x - textWidth / 2, y + radius + 15, 18, LIGHTGRAY);
}


//Moving Switch
void DrawSwitch(int x, int y, int width, int height, bool active, const char* label)
{
    //outer frame
    DrawRectangle(x - 5, y - 5, width + 10, height + 10, DARKGRAY);

    //inner panel
    DrawRectangle(x, y, width, height, PanelDark);

    //switch background
    DrawRectangle(x + 15, y + 10, width - 30, height - 20, BLACK);

    //switch position
    int knobY;

    if (active)
        knobY = y + 15;
    else
        knobY = y + height - 35;

    DrawRectangle(x + width / 2 - 12, knobY, 24, 25, active ? RED : PanelLight);

    //label
    int textWidth = MeasureText(label, 16);

    DrawText(label, x + width / 2 - textWidth / 2, y + height + 12, 16, LIGHTGRAY);
}

//Gauge with tick marks and needle
void DrawGauge(int x, int y, int radius, float value, const char* label)
{
    //gray outer ring
    DrawCircle(x, y, radius + 10, DARKGRAY);

    //black inner ring
    DrawCircle(x, y, radius + 4, BLACK);

    //gauge face
    DrawCircle(x, y, radius, PanelMedium);

    //tick marks
    for (int i = 0; i < 12; i++)
    {
        float angle = (float)i * 30.0f * DEG2RAD;

        int innerX = x + (int)(cosf(angle) * (radius - 12));
        int innerY = y + (int)(sinf(angle) * (radius - 12));

        int outerX = x + (int)(cosf(angle) * (radius - 4));
        int outerY = y + (int)(sinf(angle) * (radius - 4));

        DrawLine(innerX, innerY, outerX, outerY, LIGHTGRAY);
    }

    //needle
    float needleAngle = (-135.0f + value * 270.0f) * DEG2RAD;

    int needleX = x + (int)(cosf(needleAngle) * (radius - 15));
    int needleY = y + (int)(sinf(needleAngle) * (radius - 15));

    DrawLineEx(Vector2{ (float)x, (float)y }, Vector2{ (float)needleX, (float)needleY }, 4.0f, IndicatorRed);

    //center
    DrawCircle(x, y, 7, BLACK);
    DrawCircle(x, y, 4, IndicatorRed);

    //label
    int textWidth = MeasureText(label, 18);

    DrawText(label, x - textWidth / 2, y + radius + 20, 18, LIGHTGRAY);
}