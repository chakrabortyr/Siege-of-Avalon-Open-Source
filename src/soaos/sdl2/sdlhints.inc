{// from "SDL_hints.h"
 /*
  Simple DirectMedia Layer
  Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_hints.h
 *
 *  Official documentation for SDL configuration variables
 *
 *  This file contains functions to set and get configuration hints,
 *  as well as listing each of them alphabetically.
 *
 *  The convention for naming hints is SDL_HINT_X, where "SDL_X" is
 *  the environment variable that can be used to override the default.
 *
 *  In general these hints are just that - they may or may not be
 *  supported or applicable on any given platform, but they provide
 *  a way for an application or user to give the library a hint as
 *  to how they would like the library to work.
 */
}


(**
 *  \brief  A variable controlling how 3D acceleration is used to accelerate the SDL screen surface.
 *
 *  SDL can try to accelerate the SDL screen surface by using streaming
 *  textures with a 3D rendering engine.  This variable controls whether and
 *  how this is done.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable 3D acceleration
 *    "1"       - Enable 3D acceleration, using the default renderer.
 *    "X"       - Enable 3D acceleration, using X where X is one of the valid rendering drivers.  (e.g. "direct3d", "opengl", etc.)
 *
 *  By default SDL tries to make a best guess for each platform whether
 *  to use acceleration or not.
 *)
const
SDL_HINT_FRAMEBUFFER_ACCELERATION  = 'SDL_FRAMEBUFFER_ACCELERATION';

{/**
 *  \brief  A variable specifying which render driver to use.
 *
 *  If the application doesn't pick a specific renderer to use, this variable
 *  specifies the name of the preferred renderer.  If the preferred renderer
 *  can't be initialized, the normal default renderer is used.
 *
 *  This variable is case insensitive and can be set to the following values:
 *    "direct3d"
 *    "opengl"
 *    "opengles2"
 *    "opengles"
 *    "software"
 *
 *  The default varies by platform, but it's the first one in the list that
 *  is available on the current platform.
 */}
SDL_HINT_RENDER_DRIVER = 'SDL_RENDER_DRIVER';

{/**
 *  \brief  A variable controlling whether the OpenGL render driver uses shaders if they are available.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable shaders
 *    "1"       - Enable shaders
 *
 *  By default shaders are used if OpenGL supports them.
 */}
SDL_HINT_RENDER_OPENGL_SHADERS = 'SDL_RENDER_OPENGL_SHADERS';

  {**
   *  \brief  A variable controlling whether the Direct3D device is initialized for thread-safe operations.
   *
   *  This variable can be set to the following values:
   *    "0"       - Thread-safety is not enabled (faster)
   *    "1"       - Thread-safety is enabled
   *
   *  By default the Direct3D device is created with thread-safety disabled.
   *}
SDL_HINT_RENDER_DIRECT3D_THREADSAFE = 'SDL_RENDER_DIRECT3D_THREADSAFE';

  {**
   *  \brief  A variable controlling whether to enable Direct3D 11+'s Debug Layer.
   *
   *  This variable does not have any effect on the Direct3D 9 based renderer.
   *
   *  This variable can be set to the following values:
   *    "0"       - Disable Debug Layer use
   *    "1"       - Enable Debug Layer use
   *
   *  By default, SDL does not use Direct3D Debug Layer.
   *}
SDL_HINT_RENDER_DIRECT3D11_DEBUG = 'SDL_HINT_RENDER_DIRECT3D11_DEBUG';

{/**
 *  \brief  A variable controlling the scaling quality
 *
 *  This variable can be set to the following values:
 *    "0" or "nearest" - Nearest pixel sampling
 *    "1" or "linear"  - Linear filtering (supported by OpenGL and Direct3D)
 *    "2" or "best"    - Currently this is the same as "linear"
 *
 *  By default nearest pixel sampling is used
 */}
SDL_HINT_RENDER_SCALE_QUALITY = 'SDL_RENDER_SCALE_QUALITY';

{/**
 *  \brief  A variable controlling whether updates to the SDL screen surface should be synchronized with the vertical refresh, to avoid tearing.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable vsync
 *    "1"       - Enable vsync
 *
 *  By default SDL does not sync screen surface updates with vertical refresh.
 */}
SDL_HINT_RENDER_VSYNC = 'SDL_RENDER_VSYNC';

{/**
 *  \brief  A variable controlling whether the screensaver is enabled. 
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable screensaver
 *    "1"       - Enable screensaver
 *
 *  By default SDL will disable the screensaver.
 */}
SDL_HINT_VIDEO_ALLOW_SCREENSAVER = 'SDL_VIDEO_ALLOW_SCREENSAVER';

{/**
 *  \brief  A variable controlling whether the X11 VidMode extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable XVidMode
 *    "1"       - Enable XVidMode
 *
 *  By default SDL will use XVidMode if it is available.
 */}
SDL_HINT_VIDEO_X11_XVIDMODE = 'SDL_VIDEO_X11_XVIDMODE';

{/**
 *  \brief  A variable controlling whether the X11 Xinerama extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable Xinerama
 *    "1"       - Enable Xinerama
 *
 *  By default SDL will use Xinerama if it is available.
 */}
SDL_HINT_VIDEO_X11_XINERAMA = 'SDL_VIDEO_X11_XINERAMA';

{/**
 *  \brief  A variable controlling whether the X11 XRandR extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable XRandR
 *    "1"       - Enable XRandR
 *
 *  By default SDL will not use XRandR because of window manager issues.
 */}
SDL_HINT_VIDEO_X11_XRANDR = 'SDL_VIDEO_X11_XRANDR';

{/**
 *  \brief  A variable controlling whether grabbing input grabs the keyboard
 *
 *  This variable can be set to the following values:
 *    "0"       - Grab will affect only the mouse
 *    "1"       - Grab will affect mouse and keyboard
 *
 *  By default SDL will not grab the keyboard so system shortcuts still work.
 */}
SDL_HINT_GRAB_KEYBOARD = 'SDL_GRAB_KEYBOARD';

{/**
 *  \brief  A variable controlling whether relative mouse mode is implemented using mouse warping
 *
 *  This variable can be set to the following values:
 *    "0"       - Relative mouse mode uses raw input
 *    "1"       - Relative mouse mode uses mouse warping
 *
 *  By default SDL will use raw input for relative mouse mode
 */}
SDL_HINT_MOUSE_RELATIVE_MODE_WARP = 'SDL_MOUSE_RELATIVE_MODE_WARP';

{/**
 *  \brief Minimize your SDL_Window if it loses key focus when in Fullscreen mode. Defaults to true.
 *
 */}
SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS = 'SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS';


{/**
 *  \brief  A variable controlling whether the idle timer is disabled on iOS.
 *
 *  When an iOS app does not receive touches for some time, the screen is
 *  dimmed automatically. For games where the accelerometer is the only input
 *  this is problematic. This functionality can be disabled by setting this
 *  hint.
 *
 *  This variable can be set to the following values:
 *    "0"       - Enable idle timer
 *    "1"       - Disable idle timer
 */}
SDL_HINT_IDLE_TIMER_DISABLED = 'SDL_IOS_IDLE_TIMER_DISABLED';

{/**
 *  \brief  A variable controlling which orientations are allowed on iOS.
 *
 *  In some circumstances it is necessary to be able to explicitly control
 *  which UI orientations are allowed.
 *
 *  This variable is a space delimited list of the following values:
 *    "LandscapeLeft", "LandscapeRight", "Portrait" "PortraitUpsideDown"
 */}
SDL_HINT_ORIENTATIONS = 'SDL_IOS_ORIENTATIONS';

{/**
 *  \brief  A variable controlling whether an Android built-in accelerometer should be
 *  listed as a joystick device, rather than listing actual joysticks only.
 *
 *  This variable can be set to the following values:
 *    "0"       - List only real joysticks and accept input from them
 *    "1"       - List real joysticks along with the accelerometer as if it were a 3 axis joystick (the default).
 */}
SDL_HINT_ACCELEROMETER_AS_JOYSTICK = 'SDL_ACCELEROMETER_AS_JOYSTICK';

{/**
 *  \brief  A variable that lets you disable the detection and use of Xinput gamepad devices
 *
 *  The variable can be set to the following values:
 *    "0"       - Disable XInput timer (only uses direct input)
 *    "1"       - Enable XInput timer (the default)
 */}
SDL_HINT_XINPUT_ENABLED = 'SDL_XINPUT_ENABLED';

{**
 *  \brief  A hint that specifies that SDL should use the old axis and button mapping for XInput devices. 
 *  
 *  The variable can be set to the following values:
 *    0  use the old axis and button mapping for XInput devices
 *    1  do not use old axis and button mapping for XInput devices
 *  
 *  By default SDL does not use the old axis and button mapping for XInput devices. 
 *}
SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING = 'SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING';

{/**
 *  \brief  A variable that lets you manually hint extra gamecontroller db entries
 *
 *  The variable should be newline delimited rows of gamecontroller config data, see SDL_gamecontroller.h
 *
 *  This hint must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 *  You can update mappings after the system is initialized with SDL_GameControllerMappingForGUID() and SDL_GameControllerAddMapping()
 */}
SDL_HINT_GAMECONTROLLERCONFIG = 'SDL_GAMECONTROLLERCONFIG';


{/**
 *  \brief  A variable that lets you enable joystick (and gamecontroller) events even when your app is in the background.
 *
 *  The variable can be set to the following values:
 *    "0"       - Disable joystick & gamecontroller input events when the
 *                application is in the background.
 *    "1"       - Enable joystick & gamecontroller input events when the
 *                application is in the backgroumd.
 *
 *  The default value is "0".  This hint may be set at any time.
 */}
SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS = 'SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS';


{/**
 *  \brief If set to 0 then never set the top most bit on a SDL Window, even if the video mode expects it.
 *      This is a debugging aid for developers and not expected to be used by end users. The default is "1"
 *
 *  This variable can be set to the following values:
 *    "0"       - don't allow topmost
 *    "1"       - allow topmost
 */}
SDL_HINT_ALLOW_TOPMOST = 'SDL_ALLOW_TOPMOST';


{/**
 *  \brief A variable that controls the timer resolution, in milliseconds.
 *
 *  The higher resolution the timer, the more frequently the CPU services
 *  timer interrupts, and the more precise delays are, but this takes up
 *  power and CPU time.  This hint is only used on Windows 7 and earlier.
 *
 *  See this blog post for more information:
 *  http://randomascii.wordpress.com/2013/07/08/windows-timer-resolution-megawatts-wasted/
 *
 *  If this variable is set to "0", the system timer resolution is not set.
 *
 *  The default value is "1". This hint may be set at any time.
 */}
SDL_HINT_TIMER_RESOLUTION = 'SDL_TIMER_RESOLUTION';

{**
 *  \brief If set to 1, then do not allow high-DPI windows. ("Retina" on Mac)
 *}
SDL_HINT_VIDEO_HIGHDPI_DISABLED = 'SDL_VIDEO_HIGHDPI_DISABLED';

{**
 *  \brief  A hint that specifies if the SDL app should not be forced to become a foreground process on Mac OS X. 
 *  
 *  Possible values:
 *    0  force the SDL app to become a foreground process (default)
 *    1  do not force the SDL app to become a foreground process
 *}
SDL_HINT_MAC_BACKGROUND_APP = 'SDL_HINT_MAC_BACKGROUND_APP';

{**
 *  \brief A variable that determines whether ctrl+click should generate a right-click event on Mac
 *  
 *  If present, holding ctrl while left clicking will generate a right click
 *  event when on Mac.
 *}
SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK = 'SDL_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK';

{**
 *  \brief  A variable specifying which shader compiler to preload when using the Chrome ANGLE binaries
 *
 *  SDL has EGL and OpenGL ES2 support on Windows via the ANGLE project. It
 *  can use two different sets of binaries, those compiled by the user from source
 *  or those provided by the Chrome browser. In the later case, these binaries require
 *  that SDL loads a DLL providing the shader compiler.
 *
 *  This variable can be set to the following values:
 *    "d3dcompiler_46.dll" - default, best for Vista or later.
 *    "d3dcompiler_43.dll" - for XP support.
 *    "none" - do not load any library, useful if you compiled ANGLE from source and included the compiler in your binaries.
 *
 *}
SDL_HINT_VIDEO_WIN_D3DCOMPILER = 'SDL_VIDEO_WIN_D3DCOMPILER';

{/**
 *  \brief  A variable that is the address of another SDL_Window* (as a hex string formatted with "%p").
 *  
 *  If this hint is set before SDL_CreateWindowFrom() and the SDL_Window* it is set to has
 *  SDL_WINDOW_OPENGL set (and running on WGL only, currently), then two things will occur on the newly 
 *  created SDL_Window:
 *
 *  1. Its pixel format will be set to the same pixel format as this SDL_Window.  This is
 *  needed for example when sharing an OpenGL context across multiple windows.
 *
 *  2. The flag SDL_WINDOW_OPENGL will be set on the new window so it can be used for
 *  OpenGL rendering.
 *
 *  This variable can be set to the following values:
 *    The address (as a string "%p") of the SDL_Window* that new windows created with SDL_CreateWindowFrom() should
 *    share a pixel format with.
 */}
SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT = 'SDL_VIDEO_WINDOW_SHARE_PIXEL_FORMAT';

  {**
   *  \brief A URL to a WinRT app's privacy policy
   *
   *  All network-enabled WinRT apps must make a privacy policy available to its
   *  users.  On Windows 8, 8.1, and RT, Microsoft mandates that this policy be
   *  be available in the Windows Settings charm, as accessed from within the app.
   *  SDL provides code to add a URL-based link there, which can point to the app's
   *  privacy policy.
   *
   *  To setup a URL to an app's privacy policy, set SDL_HINT_WINRT_PRIVACY_POLICY_URL
   *  before calling any SDL_Init functions.  The contents of the hint should
   *  be a valid URL.  For example, "http://www.example.com".
   *
   *  The default value is "", which will prevent SDL from adding a privacy policy
   *  link to the Settings charm.  This hint should only be set during app init.
   *
   *  The label text of an app's "Privacy Policy" link may be customized via another
   *  hint, SDL_HINT_WINRT_PRIVACY_POLICY_LABEL.
   *
   *  Please note that on Windows Phone, Microsoft does not provide standard UI
   *  for displaying a privacy policy link, and as such, SDL_HINT_WINRT_PRIVACY_POLICY_URL
   *  will not get used on that platform.  Network-enabled phone apps should display
   *  their privacy policy through some other, in-app means.
   *}
SDL_HINT_WINRT_PRIVACY_POLICY_URL = 'SDL_HINT_WINRT_PRIVACY_POLICY_URL';

  {**
   *  \brief Label text for a WinRT app's privacy policy link
   *
   *  Network-enabled WinRT apps must include a privacy policy.  On Windows 8, 8.1, and RT,
   *  Microsoft mandates that this policy be available via the Windows Settings charm.
   *  SDL provides code to add a link there, with it's label text being set via the
   *  optional hint, SDL_HINT_WINRT_PRIVACY_POLICY_LABEL.
   *
   *  Please note that a privacy policy's contents are not set via this hint.  A separate
   *  hint, SDL_HINT_WINRT_PRIVACY_POLICY_URL, is used to link to the actual text of the
   *  policy.
   *
   *  The contents of this hint should be encoded as a UTF8 string.
   *
   *  The default value is "Privacy Policy".  This hint should only be set during app
   *  initialization, preferably before any calls to SDL_Init.
   *
   *  For additional information on linking to a privacy policy, see the documentation for
   *  SDL_HINT_WINRT_PRIVACY_POLICY_URL.
   *}
SDL_HINT_WINRT_PRIVACY_POLICY_LABEL = 'SDL_HINT_WINRT_PRIVACY_POLICY_LABEL';

  {**
   *  \brief If set to 1, back button press events on Windows Phone 8+ will be marked as handled.
   *
   *  TODO, WinRT: document SDL_HINT_WINRT_HANDLE_BACK_BUTTON need and use
   *  For now, more details on why this is needed can be found at the
   *  beginning of the following web page:
   *  http://msdn.microsoft.com/en-us/library/windowsphone/develop/jj247550(v=vs.105).aspx
   *}
SDL_HINT_WINRT_HANDLE_BACK_BUTTON = 'SDL_HINT_WINRT_HANDLE_BACK_BUTTON';

  {**
   *  \brief  A variable that dictates policy for fullscreen Spaces on Mac OS X.
   *
   *  This hint only applies to Mac OS X.
   *
   *  The variable can be set to the following values:
   *    "0"       - Disable Spaces support (FULLSCREEN_DESKTOP won't use them and
   *                SDL_WINDOW_RESIZABLE windows won't offer the "fullscreen"
   *                button on their titlebars).
   *    "1"       - Enable Spaces support (FULLSCREEN_DESKTOP will use them and
   *                SDL_WINDOW_RESIZABLE windows will offer the "fullscreen"
   *                button on their titlebars.
   *
   *  The default value is "1". Spaces are disabled regardless of this hint if
   *   the OS isn't at least Mac OS X Lion (10.7). This hint must be set before
   *   any windows are created.
   *}
SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES = 'SDL_VIDEO_MAC_FULLSCREEN_SPACES';

{**
 *  \brief  A hint that specifies the Android APK expansion main file version. 
 *  
 *  The variable should specify the Android APK expansion main file version (a string number like "1", "2" etc.).
 *  This hint must be set together with the hint SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION. 
 *  
 *  If both hints were set then SDL_RWFromFile() will look into expansion files 
 *  after a given relative path was not found in the internal storage and assets.
 *  By default this hint is not set and the APK expansion files are not searched. 
 *} 
SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION = 'SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION';

{**
 *  \brief  A hint that specifies the Android APK expansion patch file version. 
 *  
 *  The variable should specify the Android APK expansion patch file version (a string number like "1", "2" etc.).
 *  This hint must be set together with the hint SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION. 
 *  
 *  If both hints were set then SDL_RWFromFile() will look into expansion files 
 *  after a given relative path was not found in the internal storage and assets.
 *  By default this hint is not set and the APK expansion files are not searched. 
 *} 
SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION = 'SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION';

{**
 *  \brief  A hint that specifies a variable to control whether mouse and touch events are to be treated together or separately.
 *  
 *  Possible values:
 *    0  mouse events will be handled as touch events and touch will raise fake mouse events
 *    1  mouse events will be handled separately from pure touch events
 *  
 *  By default mouse events will be handled as touch events and touch will raise fake mouse events. 
 *  The value of this hint is used at runtime, so it can be changed at any time. 
 *}
SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH = 'SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH';

{**
 *  \brief A hint that specifies a value to override the binding element for keyboard inputs for Emscripten builds. 
 *  
 *  Possible values:
 *    #window      the JavaScript window object (this is the default)
 *    #document    the JavaScript document object
 *    #screen      the JavaScript window.screen object
 *    #canvas      the default WebGL canvas element
 *  
 *  Any other string without a leading # sign applies to the element on the page with that ID. 
 *  This hint only applies to the Emscripten platform. 
 *}
SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT = 'SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT';

{**
 *  \brief  A hint that specifies whether certain IMEs should handle text editing internally instead of sending SDL_TEXTEDITING events.
 *  
 *  Possible values: 
 *    0  SDL_TEXTEDITING events are sent, and it is the application's responsibility 
 *       to render the text from these events and differentiate it somehow from committed text. (default)
 *
 *    1  If supported by the IME then SDL_TEXTEDITING events are not sent,
 *       and text that is being composed will be rendered in its own UI.
 *}
SDL_HINT_IME_INTERNAL_EDITING = 'SDL_HINT_IME_INTERNAL_EDITING';

{**
 *  \brief  A hint that specifies not to catch the SIGINT or SIGTERM signals.
 *
 *  Possible values:
 *    0  SDL will install a SIGINT and SIGTERM handler, and when it catches a signal, convert it into an SDL_QUIT event (default)
 *    1  SDL will not install a signal handler at all
 *  
 *  This hint only applies to Unix-like platforms. 
 *} 
SDL_HINT_NO_SIGNAL_HANDLERS = 'SDL_HINT_NO_SIGNAL_HANDLERS';

{**
 *  \brief  A hint that specifies a variable specifying SDL's threads stack size in bytes or "0" for the backend's default size.
 *  
 *  Possible values for this hint are:
 *    0  use the backend's default threads stack size (default)
 *    X  use the provided positive threads stack size
 *  
 *  Use this hint in case you need to set SDL's threads stack size to other than the default.
 *  This is specially useful if you build SDL against a non glibc libc library (such as musl) 
 *  which provides a relatively small default thread stack size (a few kilobytes versus the default 8 MB glibc uses).
 *
 *  Support for this hint is currently available only in the pthread backend.
 *}
SDL_HINT_THREAD_STACK_SIZE = 'SDL_HINT_THREAD_STACK_SIZE';

{**
 *  \brief  A hint that specifies whether the windows message loop is processed by SDL.
 *  
 *  Possible values for this hint:
 *    0  the window message loop is not run
 *    1  the window message loop is processed in SDL_PumpEvents()  [default]
 *}
SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP = 'SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP';

{**
 *  \brief  A hint that specifies that SDL should not to generate SDL_WINDOWEVENT_CLOSE events for Alt+F4 on Microsoft Windows.
 *  
 *  Possible values for this hint:
 *    0  generate an SDL_WINDOWEVENT_CLOSE event for Alt+F4 (default)
 *    1  do not generate event and only do normal key handling for Alt+F4
 *}
SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4 = 'SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4';

{**
 *  \brief Prevent SDL from using version 4 of the bitmap header when saving BMPs.
 *
 * The bitmap header version 4 is required for proper alpha channel support and
 * SDL will use it when required. Should this not be desired, this hint can
 * force the use of the 40 byte header version which is supported everywhere.
 *
 * The variable can be set to the following values:
 *   "0"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file with an alpha mask. SDL will use the bitmap
 *               header version 4 and set the alpha mask accordingly.
 *   "1"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file without an alpha mask. The alpha channel data
 *               will be in the file, but applications are going to ignore it.
 *
 * The default value is "0".
 *}
SDL_HINT_BMP_SAVE_LEGACY_FORMAT = 'SDL_BMP_SAVE_LEGACY_FORMAT';

{**
 * \brief Tell SDL not to name threads on Windows.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will raise the 0x406D1388 Exception to name threads.
 *               This is the default behavior of SDL <= 2.0.4. (default)
 *   "1"       - SDL will not raise this exception, and threads will be unnamed.
 *               For .NET languages this is required when running under a debugger.
 *}
SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING = 'SDL_WINDOWS_DISABLE_THREAD_NAMING';  
{**
 *  \brief  A hint that specifies whether the window frame and title bar are interactive when the cursor is hidden. 
 *  
 *  Possible values for this hint:
 *    0  the window frame is not interactive when the cursor is hidden (no move, resize, etc)
 *    1  the window frame is interactive when the cursor is hidden
 *  
 *  By default SDL will allow interaction with the window frame when the cursor is hidden. 
 *}
SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN = 'SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN';

{/**
 *  \brief  An enumeration of hint priorities
 */}
type
  SDL_HintPriority = (SDL_HINT_DEFAULT, SDL_HINT_NORMAL, SDL_HINT_OVERRIDE);


{/**
 *  \brief Set a hint with a specific priority
 *
 *  The priority controls the behavior when setting a hint that already
 *  has a value.  Hints will replace existing hints of their priority and
 *  lower.  Environment variables are considered to have override priority.
 *
 *  \return SDL_TRUE if the hint was set, SDL_FALSE otherwise
 */}
function SDL_SetHintWithPriority( const name: PChar; const value: PChar; priority: SDL_HintPriority) : boolean; cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_SetHintWithPriority' {$ENDIF} {$ENDIF};

// extern DECLSPEC SDL_bool SDLCALL SDL_SetHintWithPriority(const char *name,
//                                                         const char *value,
//                                                         SDL_HintPriority priority);
{/**
 *  \brief Set a hint with normal priority
 *
 *  \return SDL_TRUE if the hint was set, SDL_FALSE otherwise
 */}
 function SDL_SetHint( const name: PChar; const value: PChar) : boolean; cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_SetHint' {$ENDIF} {$ENDIF};

 //extern DECLSPEC SDL_bool SDLCALL SDL_SetHint(const char *name,
  //                                           const char *value);

{/**
 *  \brief Get a hint
 *
 *  \return The string value of a hint variable.
 */}
function SDL_GetHint( const name: PChar): PChar; cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_GetHint' {$ENDIF} {$ENDIF};
 //extern DECLSPEC const char * SDLCALL SDL_GetHint(const char *name);


{/**
 *  \brief Add a function to watch a particular hint
 *
 *  \param name The hint to watch
 *  \param callback The function to call when the hint value changes
 *  \param userdata A pointer to pass to the callback function
 */}
type
TSDL_HintCallback = procedure(userdata: Pointer; const name: PChar; const oldValue: PChar; const newValue: PChar);
procedure SDL_AddHintCallback(const name: PChar; callback: TSDL_HintCallback; userdata: Pointer); cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_AddHintCallback' {$ENDIF} {$ENDIF};
 //typedef void (*SDL_HintCallback)(void *userdata, const char *name, const char *oldValue, const char *newValue);
//extern DECLSPEC void SDLCALL SDL_AddHintCallback(const char *name,
//                                                 SDL_HintCallback callback,
//                                                 void *userdata);

{/**
 *  \brief Remove a function watching a particular hint
 *
 *  \param name The hint being watched
 *  \param callback The function being called when the hint value changes
 *  \param userdata A pointer being passed to the callback function
 */}
procedure SDL_DelHintCallback(const name: PChar; callback: TSDL_HintCallback; userdata: Pointer); cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_DelHintCallback' {$ENDIF} {$ENDIF};
//extern DECLSPEC void SDLCALL SDL_DelHintCallback(const char *name,
//                                                 SDL_HintCallback callback,
//                                                 void *userdata);

{/**
 *  \brief  Clear all hints
 *
 *  This function is called during SDL_Quit() to free stored hints.
 */}
//extern DECLSPEC void SDLCALL SDL_ClearHints(void);
procedure SDL_ClearHints(); cdecl; external SDL_LibName {$IFDEF DELPHI} {$IFDEF MACOS} name '_SDL_ClearHints' {$ENDIF} {$ENDIF};
