//#include <jni.h>
//
//#include "AndroidOut.h"
//#include "Renderer.h"
//#include <game-activity/GameActivity.cpp>
//#include <game-text-input/gametextinput.cpp>

extern "C" 
{
//#include <game-activity/native_app_glue/android_native_app_glue.c>

	struct android_app;

    //void handle_cmd(android_app* pApp, int cmd) {
    //    switch (cmd) {
    //    case APP_CMD_INIT_WINDOW:
    //        // A new window is created, associate a renderer with it. You may replace this with a
    //        // "game" class if that suits your needs. Remember to change all instances of userData
    //        // if you change the class here as a reinterpret_cast is dangerous this in the
    //        // android_main function and the APP_CMD_TERM_WINDOW handler case.
    //        pApp->userData = new Renderer(pApp);
    //        break;
    //    case APP_CMD_TERM_WINDOW:
    //        // The window is being destroyed. Use this to clean up your userData to avoid leaking
    //        // resources.
    //        //
    //        // We have to check if userData is assigned just in case this comes in really quickly
    //        if (pApp->userData) {
    //            //
    //            auto* pRenderer = reinterpret_cast<Renderer*>(pApp->userData);
    //            pApp->userData = nullptr;
    //            delete pRenderer;
    //        }
    //        break;
    //    default:
    //        break;
    //    }
    //}

	//bool motion_event_filter_func(const GameActivityMotionEvent* motionEvent) {
	//	auto sourceClass = motionEvent->source & AINPUT_SOURCE_CLASS_MASK;
	//	return (sourceClass == AINPUT_SOURCE_CLASS_POINTER ||
	//		sourceClass == AINPUT_SOURCE_CLASS_JOYSTICK);
	//}


    /////////////////////////////////////////////////////////////////////////////
    // @ 안드로이드 메인 함수.
    /////////////////////////////////////////////////////////////////////////////
    //void android_main(struct android_app* pApp) {
    //    // Can be removed, useful to ensure your code is running
    //    aout << "Welcome to android_main" << std::endl;

    //    // Register an event handler for Android events
    //    pApp->onAppCmd = handle_cmd;

    //    // Set input event filters (set it to NULL if the app wants to process all inputs).
    //    // Note that for key inputs, this example uses the default default_key_filter()
    //    // implemented in android_native_app_glue.c.
    //    android_app_set_motion_event_filter(pApp, motion_event_filter_func);

    //    // This sets up a typical game/event loop. It will run until the app is destroyed.
    //    int events;
    //    android_poll_source* pSource;
    //    do {
    //        // Process all pending events before running game logic.
    //        if (ALooper_pollAll(0, nullptr, &events, (void**)&pSource) >= 0) {
    //            if (pSource) {
    //                pSource->process(pApp, pSource);
    //            }
    //        }

    //        // Check if any user data is associated. This is assigned in handle_cmd
    //        if (pApp->userData) {

    //            // We know that our user data is a Renderer, so reinterpret cast it. If you change your
    //            // user data remember to change it here
    //            auto* pRenderer = reinterpret_cast<Renderer*>(pApp->userData);

    //            // Process game input
    //            pRenderer->handleInput();

    //            // Render a frame
    //            pRenderer->render();
    //        }
    //    } while (!pApp->destroyRequested);
    //}
}