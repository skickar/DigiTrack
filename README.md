# DigiTrack
This is a $5 attack that does a couple things:

1) Inserts a Wi-Fi backdoor onto a victim computer, allowing you to connect to the computer at any time.
2) Steals a list of every network the victim has ever connected to (for tracking, classifying, and hijacking data connection)
3) Inserts a tracking job that send the IP address and currently connected network to a Grabify link every 60 seconds.

Notes: Grabify may go into "I'm under attack" mode and not allow checkin. Look for this line:

          <div class="cf-browser-verification cf-im-under-attack">
  <noscript><h1 data-translate="turn_on_js" style="color:#bd2426;">Please turn JavaScript on and reload the page.</h1></noscript>
  
 If you see it, then the IP address is being blocked by cloudflare.
