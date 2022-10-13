#include <Spix/Events/Identifiers.h>

namespace spix
{
    std::string toStringKeyCode(int code) 
    {
        switch (code)
        {
        case KeyCodes::Escape            : return "Escape";
        case KeyCodes::Tab               : return "Tab";
        case KeyCodes::Backtab           : return "Backtab";
        case KeyCodes::Backspace         : return "Backspace";
        case KeyCodes::Return            : return "Return";
        case KeyCodes::Enter             : return "Enter";
        case KeyCodes::Insert            : return "Insert";
        case KeyCodes::Delete            : return "Delete";
        case KeyCodes::Pause             : return "Pause";
        case KeyCodes::Print             : return "Print";
        case KeyCodes::SysReq            : return "SysReq";
        case KeyCodes::Clear             : return "Clear";
        case KeyCodes::Home              : return "Home";
        case KeyCodes::End               : return "End";
        case KeyCodes::Left              : return "Left";
        case KeyCodes::Up                : return "Up";
        case KeyCodes::Right             : return "Right";
        case KeyCodes::Down              : return "Down";
        case KeyCodes::PageUp            : return "PageUp";
        case KeyCodes::PageDown          : return "PageDown";
        case KeyCodes::Shift             : return "Shift";
        case KeyCodes::Control           : return "Control";
        case KeyCodes::Meta              : return "Meta";
        case KeyCodes::Alt               : return "Alt";
        case KeyCodes::CapsLock          : return "CapsLock";
        case KeyCodes::NumLock           : return "NumLock";
        case KeyCodes::ScrollLock        : return "ScrollLock";
        case KeyCodes::F1                : return "F1";
        case KeyCodes::F2                : return "F2";
        case KeyCodes::F3                : return "F3";
        case KeyCodes::F4                : return "F4";
        case KeyCodes::F5                : return "F5";
        case KeyCodes::F6                : return "F6";
        case KeyCodes::F7                : return "F7";
        case KeyCodes::F8                : return "F8";
        case KeyCodes::F9                : return "F9";
        case KeyCodes::F10               : return "F10";
        case KeyCodes::F11               : return "F11";
        case KeyCodes::F12               : return "F12";
        case KeyCodes::F13               : return "F13";
        case KeyCodes::F14               : return "F14";
        case KeyCodes::F15               : return "F15";
        case KeyCodes::F16               : return "F16";
        case KeyCodes::F17               : return "F17";
        case KeyCodes::F18               : return "F18";
        case KeyCodes::F19               : return "F19";
        case KeyCodes::F20               : return "F20";
        case KeyCodes::F21               : return "F21";
        case KeyCodes::F22               : return "F22";
        case KeyCodes::F23               : return "F23";
        case KeyCodes::F24               : return "F24";
        case KeyCodes::F25               : return "F25";
        case KeyCodes::F26               : return "F26";
        case KeyCodes::F27               : return "F27";
        case KeyCodes::F28               : return "F28";
        case KeyCodes::F29               : return "F29";
        case KeyCodes::F30               : return "F30";
        case KeyCodes::F31               : return "F31";
        case KeyCodes::F32               : return "F32";
        case KeyCodes::F33               : return "F33";
        case KeyCodes::F34               : return "F34";
        case KeyCodes::F35               : return "F35";
        case KeyCodes::Super_L           : return "Super_L";
        case KeyCodes::Super_R           : return "Super_R";
        case KeyCodes::Menu              : return "Menu";
        case KeyCodes::Hyper_L           : return "Hyper_L";
        case KeyCodes::Hyper_R           : return "Hyper_R";
        case KeyCodes::Help              : return "Help";
        case KeyCodes::Direction_L       : return "Direction_L";
        case KeyCodes::Direction_R       : return "Direction_R";
        case KeyCodes::Space             : return "Space";
        case KeyCodes::Char_Exclam       : return "Char_Exclam";
        case KeyCodes::Char_QuoteDbl     : return "Char_QuoteDbl";
        case KeyCodes::Char_NumberSign   : return "Char_NumberSign";
        case KeyCodes::Char_Dollar       : return "Char_Dollar";
        case KeyCodes::Char_Percent      : return "Char_Percent";
        case KeyCodes::Char_Ampersand    : return "Char_Ampersand";
        case KeyCodes::Char_Apostrophe   : return "Char_Apostrophe";
        case KeyCodes::Char_ParenLeft    : return "Char_ParenLeft";
        case KeyCodes::Char_ParenRight   : return "Char_ParenRight";
        case KeyCodes::Char_Asterisk     : return "Char_Asterisk";
        case KeyCodes::Char_Plus         : return "Char_Plus";
        case KeyCodes::Char_Comma        : return "Char_Comma";
        case KeyCodes::Char_Minus        : return "Char_Minus";
        case KeyCodes::Char_Period       : return "Char_Period";
        case KeyCodes::Char_Slash        : return "Char_Slash";
        case KeyCodes::Num_0             : return "Num_0";
        case KeyCodes::Num_1             : return "Num_1";
        case KeyCodes::Num_2             : return "Num_2";
        case KeyCodes::Num_3             : return "Num_3";
        case KeyCodes::Num_4             : return "Num_4";
        case KeyCodes::Num_5             : return "Num_5";
        case KeyCodes::Num_6             : return "Num_6";
        case KeyCodes::Num_7             : return "Num_7";
        case KeyCodes::Num_8             : return "Num_8";
        case KeyCodes::Num_9             : return "Num_9";
        case KeyCodes::Char_Colon        : return "Char_Colon";
        case KeyCodes::Char_Semicolon    : return "Char_Semicolon";
        case KeyCodes::Char_Less         : return "Char_Less";
        case KeyCodes::Char_Equal        : return "Char_Equal";
        case KeyCodes::Char_Greater      : return "Char_Greater";
        case KeyCodes::Char_Question     : return "Char_Question";
        case KeyCodes::Char_At           : return "Char_At";
        case KeyCodes::Char_A            : return "Char_A";
        case KeyCodes::Char_B            : return "Char_B";
        case KeyCodes::Char_C            : return "Char_C";
        case KeyCodes::Char_D            : return "Char_D";
        case KeyCodes::Char_E            : return "Char_E";
        case KeyCodes::Char_F            : return "Char_F";
        case KeyCodes::Char_G            : return "Char_G";
        case KeyCodes::Char_H            : return "Char_H";
        case KeyCodes::Char_I            : return "Char_I";
        case KeyCodes::Char_J            : return "Char_J";
        case KeyCodes::Char_K            : return "Char_K";
        case KeyCodes::Char_L            : return "Char_L";
        case KeyCodes::Char_M            : return "Char_M";
        case KeyCodes::Char_N            : return "Char_N";
        case KeyCodes::Char_O            : return "Char_O";
        case KeyCodes::Char_P            : return "Char_P";
        case KeyCodes::Char_Q            : return "Char_Q";
        case KeyCodes::Char_R            : return "Char_R";
        case KeyCodes::Char_S            : return "Char_S";
        case KeyCodes::Char_T            : return "Char_T";
        case KeyCodes::Char_U            : return "Char_U";
        case KeyCodes::Char_V            : return "Char_V";
        case KeyCodes::Char_W            : return "Char_W";
        case KeyCodes::Char_X            : return "Char_X";
        case KeyCodes::Char_Y            : return "Char_Y";
        case KeyCodes::Char_Z            : return "Char_Z";
        }

        return "Unknown code"; 
    }

    std::string toStringKeyModifier(KeyModifier modifier)
    {
        switch (modifier)
        {
            case KeyModifiers::Alt: return "Alt";
            case KeyModifiers::Control: return "Control";
            case KeyModifiers::Meta: return "Meta";
            case KeyModifiers::None: return "None";
            case KeyModifiers::Shift: return "Shift";
        }

        return "Unknown modifier";
    }

    std::string toStringMouseButton(MouseButton button)
    {
        switch (button)
        {
            case MouseButtons::Left: return "Left";
            case MouseButtons::Middle: return "Midde";
            case MouseButtons::None: return "None";
            case MouseButtons::Right: return "Right";
        }

        return "Unknown button";
    }
}