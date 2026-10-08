/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "widgets.hpp"


int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	const int screenWidth = 1000;
	const int screenHeight = 700;
	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Control Panel");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

    //control panel values
    bool powerOn = true;
    bool shieldsOn = false;
    bool enginesOn = true;

    float gaugeValue = 0.65f;

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
        //Input
        if (IsKeyPressed(KEY_ONE))
            powerOn = !powerOn;

        if (IsKeyPressed(KEY_TWO))
            shieldsOn = !shieldsOn;

        if (IsKeyPressed(KEY_THREE))
            enginesOn = !enginesOn;

        
        if (IsKeyDown(KEY_RIGHT))
            gaugeValue += 0.01f;

        if (IsKeyDown(KEY_LEFT))
            gaugeValue -= 0.01f;

        gaugeValue = Clamp(gaugeValue, 0.0f, 1.0f);
        

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

        // Outer frame
        DrawRectangle(50, 40, 900, 600, PanelLight);

        // Main panel
        DrawRectangle(70, 60, 860, 560, PanelDark);

       //------------------------------------
       // Left Gauge
       //------------------------------------

        DrawGauge(215, 230, 75, gaugeValue, "POWER OUTPUT");


        //------------------------------------
        // Header     
        //------------------------------------
        DrawText("SYSTEMS CONTROL", 100, 85, 30, LIGHTGRAY);

        DrawText("D-17", 805, 88, 20, IndicatorRed);

        //header divider
        DrawLine(95, 125, 905, 125, PanelLight);

        //------------------------------------
        //Main Indicators
        //------------------------------------
        DrawText("SYSTEM STATUS", 490, 155, 22, LIGHTGRAY);

        DrawIndicator(530, 215, 22, IndicatorGreen, powerOn, "POWER");

        DrawIndicator(630, 215, 22, IndicatorBlue, shieldsOn, "SHIELDS");

        DrawIndicator(730, 215, 22, IndicatorRed, enginesOn, "ENGINE");


       //------------------------------------
       //Switches
       //------------------------------------

        DrawText("PRIMARY SYSTEMS", 100, 340, 22, LIGHTGRAY);

        DrawSwitch(110, 385, 110, 70, powerOn, "POWER");

        DrawSwitch(270, 385, 110, 70, shieldsOn, "SHIELDS");

        DrawSwitch(430, 385, 110, 70, enginesOn, "ENGINE");


       //------------------------------------
       // Lower Indicators
       //------------------------------------

        DrawRectangle(600, 345, 275, 150, Color{ 20, 22, 23, 255 });

        DrawRectangleLines(600, 345, 275, 150, PanelLight);

        DrawText("AUXILIARY", 620, 365, 18, LIGHTGRAY);

        DrawIndicator(650, 425, 12, IndicatorRed, true, "A");

        DrawIndicator(710, 425, 12, IndicatorRed, false, "B");

        DrawIndicator(770, 425, 12, IndicatorGreen, true, "C");

        DrawIndicator(830, 425, 12, IndicatorBlue, false, "D");

       //------------------------------------
       // Controls
       //------------------------------------

        DrawRectangle(100, 525, 800, 55, BLACK);

        DrawText("1: POWER", 120, 543, 16, LIGHTGRAY);

        DrawText("2: SHIELDS", 260, 543, 16, LIGHTGRAY);

        DrawText("3: ENGINE", 420, 543, 16, LIGHTGRAY);

        DrawText("ARROWS: POWER OUTPUT", 590, 543, 16, LIGHTGRAY);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}


	

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
