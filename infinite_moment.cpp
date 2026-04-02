#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

using namespace std;

// 1. ثوابت الألوان والتنسيق (تسهل القراءة وتسمح بتغيير اللون من مكان واحد)
const string CLEAR_SCREEN = "\033[2J\033[H";
const string RESET_CURSOR = "\033[H";
const string C_YELLOW     = "\033[1;33m";
const string C_CYAN       = "\033[1;36m";
const string C_RESET      = "\033[0m";
const string C_ITALIC     = "\033[3m";

// 2. ثوابت زخرفة الإطار (عزل الرموز المعقدة عن الكود الأساسي)
const string B_TOP    = "\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557";
const string B_MID    = "\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563";
const string B_BOTTOM = "\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d";
const string B_SIDE   = "\u2551";

int main() {
    // مسح الشاشة مرة واحدة فقط عند بدء التشغيل
    cout << CLEAR_SCREEN;

    while (true) {
        // --- أ. معالجة الوقت ---
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm *ltm = localtime(&now);

        int h = ltm->tm_hour;
        int m = ltm->tm_min;
        int s = ltm->tm_sec;
        string period = (h >= 12) ? "PM" : "AM";

        if (h > 12) h -= 12;
        if (h == 0) h = 12;

        // --- ب. العرض والطباعة ---
        cout << RESET_CURSOR << "\n\n\n";

        // رسم الجزء العلوي من الإطار
        cout << "\t\t   " << C_YELLOW << B_TOP << C_RESET << "\n";
        cout << "\t\t   " << C_YELLOW << B_SIDE << "         THE INFINITE MOMENT         " << B_SIDE << C_RESET << "\n";
        cout << "\t\t   " << C_YELLOW << B_MID << C_RESET << "\n";
        
        // رسم سطر الوقت
        cout << "\t\t   " << C_YELLOW << B_SIDE << "            " << C_CYAN;
        cout << setfill('0') << setw(2) << h << ":" 
             << setw(2) << m << ":" 
             << setw(2) << s << " " << period;
        cout << "             " << C_YELLOW << B_SIDE << C_RESET << "\n";
        
        // رسم الجزء السفلي من الإطار
        cout << "\t\t   " << C_YELLOW << B_BOTTOM << C_RESET << "\n\n";
        
        // طباعة المقولة بخط مائل
        cout << "\t\t " << C_ITALIC << "\"Time doesn't just pass; it cleanses.\"" << C_RESET << "\n";
        cout << "\t\t " << C_ITALIC << "\"Every second is a chance to be who you are,\"" << C_RESET << "\n";
        cout << "\t\t " << C_ITALIC << "\"without the weight of who you were.\"" << C_RESET << "\n";

        // --- ج. الإيقاف المؤقت ---
        this_thread::sleep_for(chrono::seconds(1)); 
    }
    return 0;
}
