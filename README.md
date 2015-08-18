## Delay Timer 1.0.0.0
### Author: Atiqur Rahman

#### Instructions
##### Windows
Please put the dll file on the same directory where you keep delay.exe
Otherwise you need to install Visual c++ 2013 redistributable: http://www.microsoft.com/en-us/download/details.aspx?id=40784

A powershell script that uses this executable for notifying user after timeout is here: https://gallery.technet.microsoft.com/scriptcenter/Powershell-Delay-Counter-3ade4a08

###### Usage Example
To delay 1 minutes and 5 seconds,

	C:\> DelayTimer.exe 1:05

To delay 30 seconds,

	C:\> DelayTimer.exe 30

To delay 1 hour and 10 seconds,

	C:\> DelayTimer.exe 1:0:10

To delay 25 hours and 4 minutes and 4 seconds,

	C:\> DelayTimer.exe 25:04:04


##### Linux
You can use latest gcc to compile for Unix/Linux

###### Usage Example
To delay 1 minutes and 5 seconds,

	$ ./DelayTimer 1:05

To delay 30 seconds,

	$ ./DelayTimer 30

To delay 1 hour and 10 seconds,

	$ ./DelayTimer 1:0:10

To delay 25 hours and 4 minutes and 4 seconds,

	$ ./DelayTimer 25:04:04
